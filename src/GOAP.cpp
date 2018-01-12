#include "GOAP.h"

GOAP::GOAP() {
	FillList();
}

void GOAP::Planner(WorldStateVariables *current, WorldStateVariables objective)
{
	std::priority_queue<std::pair<Node*, float>> frontier;

	std::map<WS, bool> changeList;
	std::map<WS, bool> possibleChangeList;
	std::vector<Node*> visited;
	std::map<Node*, float> costSoFar;

	std::map<Node*, float> toQueue;

	bool notPossible = true;

	WorldStateVariables holder = *current;

	// Fills the changeList with the conditions that need to be changed to achieve the objective world state
	for (map<WS, bool>::iterator it = objective.worldStatesList.begin(); it != objective.worldStatesList.end(); it++) {
		if (objective.worldStatesList[it->first] != holder.worldStatesList[it->first]) {
			changeList.emplace(it->first, objective.worldStatesList[it->first]);
			for (int i = 0; i < ACTIONS.actionsList.size(); i++) {
				if (ACTIONS.actionsList[(ActionName)i]->GetEffects()->find(it->first) != ACTIONS.actionsList[(ActionName)i]->GetEffects()->end() && ACTIONS.actionsList[(ActionName)i]->GetEffects()->at(it->first) == objective.worldStatesList.at(it->first)) {
					possibleChangeList.emplace(it->first, objective.worldStatesList[it->first]);
					cout << "World State " << it->first << " needs to be changed" << endl;
				}
			}
		}
	}

	if (changeList == possibleChangeList) {
		notPossible = false;
	}


	if (!possibleChangeList.empty() && !notPossible) {

		// Checks which of the nodes fit better the required changes
		for (int i = 0; i < nodeList.size(); i++) {
			nodeList[i]->SetNextNodes(nodeList, holder);

			for (map<WS, bool>::iterator it = possibleChangeList.begin(); it != possibleChangeList.end(); it++) {
				if (nodeList[i]->action->GetEffects()->find(it->first) != nodeList[i]->action->GetEffects()->end() 
					&& nodeList[i]->action->GetEffects()->at(it->first) == possibleChangeList.at(it->first)
					&& toQueue.find(nodeList[i]) == toQueue.end()) {
					//cout << "Added " << nodeList[i]->action->name << " to the queue" << endl;
					toQueue.emplace(nodeList[i], 0.f);
					frontier.push(make_pair(nodeList[i], 0.f));
				}
			}
		}
	

		Node *currentNode;


		while (!frontier.empty()) {
			currentNode = frontier.top().first;
			frontier.pop();
			toQueue.erase(currentNode);

			visited.push_back(currentNode);
			costSoFar.emplace(currentNode, 0.f);

			if (possibleChangeList.empty()) {
				break;
			}

			// Updates changeList to fit the current node preconditions
			vector<WS> eraseList;
			for (map<WS, bool>::iterator it = possibleChangeList.begin(); it != possibleChangeList.end(); it++) {
				if (currentNode->action->GetEffects()->find(it->first) != currentNode->action->GetEffects()->end() 
					&& currentNode->action->GetEffects()->at(it->first) == possibleChangeList.at(it->first)) {
					//cout << "Action " << currentNode->action->name << " will complete objective: " << it->first << endl;
					eraseList.push_back(it->first);
					currentNode->action->ExecuteAction(holder);
					for (map<WS, bool>::iterator it2 = currentNode->action->GetPreconditions()->begin(); it2 != currentNode->action->GetPreconditions()->end(); it2++) {
						if (holder.worldStatesList[it2->first] != it2->second) {
							possibleChangeList.emplace(it2->first, currentNode->action->GetPreconditions()->at(it2->first));
							//cout << "New objective: " << it2->first << " to complete Action: " << currentNode->action->name << endl;
						}
					}
				}
			}

			// We update the possible next nodes
			currentNode->SetNextNodes(nodeList, holder);

			for (int i = 0; i < eraseList.size(); i++) {
				possibleChangeList.erase(eraseList[i]);
			}

			// A* algorithm
			for each(Node* next in currentNode->nextNodes) {

				float newCost = costSoFar[currentNode] + next->cost;
				if (costSoFar.count(next) == 0 || newCost < costSoFar[next]) {
					float priority = Heuristic(&possibleChangeList, next, *current) + newCost;
					frontier.push(make_pair(next, -priority));
					costSoFar.emplace(next, newCost);
				}
			}

		}

		// Writes the final plan if there's any
		if (possibleChangeList.empty()) {
			cout << "The plan is: ";
			for (int i = visited.size() - 1; i >= 0; i--) {
				if (i != 0) {
					cout << visited[i]->action->name << " -> ";
				}
				else cout << visited[i]->action->name << endl;
			}
		} else cout << "There's no possible plan" << endl;

	}

	else cout << "There's no possible plan" << endl;

}

// Fills node list with all the different actions
void GOAP::FillList() {
	system("cls");
	//std::cout << "Actions available: " << std::endl;
	for (int i = 0; i < ACTIONS.actionsList.size(); i++) {
		nodeList.push_back(new Node(ACTIONS.actionsList[(ActionName)i]));
		//std::cout << "Action " << i + 1 << ": " << nodeList[i]->action->name << std::endl;
	}
}

// Calculates which will be the minimum cost to complete all preconditions
float GOAP::Heuristic(std::map<WS, bool> *objective, Node *n, WorldStateVariables current) {
	float cost = 0.f;
	for each (Node* n in n->nextNodes) {
		cost += n->cost;
	}
	return cost;
}

bool operator<(const std::pair<Node*, float>& c1, const std::pair<Node*, float>& c2) {
	return c1.second < c2.second;
}