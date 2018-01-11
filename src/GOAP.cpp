#include "GOAP.h"

GOAP::GOAP() {
	FillList();
}

void GOAP::AStar(worldStateVariables *current, worldStateVariables objective)
{
	std::priority_queue<Node*> frontier;

	std::map<WS, bool> changeList;
	std::vector<Node*> visited;
	std::map<Node*,float> costSoFar;

	for (map<WS, bool>::iterator it = objective.worldStatesList.begin(); it != objective.worldStatesList.end(); it++) {
		if (objective.worldStatesList[it->first] != current->worldStatesList[it->first]) {
			for (int i = 0; i < ACTIONS.actionsList.size(); i++) {
				if (ACTIONS.actionsList[(ActionName)i]->GetEffects()->find(it->first) != ACTIONS.actionsList[(ActionName)i]->GetEffects()->end() && ACTIONS.actionsList[(ActionName)i]->GetEffects()->at(it->first) == objective.worldStatesList.at(it->first)) {
					changeList.emplace(it->first, objective.worldStatesList[it->first]);
					cout << "World State " << it->first << " needs to be changed" << endl;
				}
			}
		}
	}

	for (int i = 0; i < nodeList.size(); i++) {
		nodeList[i]->SetNextNodes(nodeList, *current);
		frontier.push(nodeList[i]);
	}

	visited.push_back(nodeList[0]);
	costSoFar.emplace(nodeList[0], nodeList[0]->cost);

	Node *currentNode;

	while (!frontier.empty()) {
		currentNode = frontier.top();
		frontier.pop();

		if (changeList.empty()) {
			break;
		}

		vector<WS> eraseList;
		for (map<WS, bool>::iterator it = changeList.begin(); it != changeList.end(); it++) {
			if (currentNode->action->GetEffects()->find(it->first) != currentNode->action->GetEffects()->end() && currentNode->action->GetEffects()->at(it->first) == changeList.at(it->first)) {
				cout << "Action  " << currentNode->action->name << " will complete objective:  " << it->first << endl;
				eraseList.push_back(it->first);
				for (map<WS, bool>::iterator it2 = currentNode->action->GetPreconditions()->begin(); it2 != currentNode->action->GetPreconditions()->end(); it2++) {
					if (current->worldStatesList[it2->first] != it2->second) {
						changeList.emplace(it2->first, currentNode->action->GetPreconditions()->at(it2->first));
						cout << "New objective: " << it2->first << " to complete Action: " << currentNode->action->name << endl;
					}
				}
			}
		}

		for (int i = 0; i < eraseList.size(); i++) {
			changeList.erase(eraseList[i]);
		}

		for each(Node* next in currentNode->nextNodes) {			

			float newCost = costSoFar[currentNode] + next->cost;
			if (costSoFar.count(next) == 0 || newCost < costSoFar[next]) {
				costSoFar.emplace(next, newCost);
				float priority = Heuristic(&changeList, next, *current) + newCost;
				next->cost = -priority;
				frontier.push(next);
				visited.push_back(next);
			}
		}
	}

	//for (int i = 0; i < nodeList.size(); i++) {
	//	std::cout << "The cost of the node " << nodeList[i]->action->name << " is: " << Heuristic(&changeList, nodeList[i]) << std::endl;
	//}
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

float GOAP::Heuristic(std::map<WS, bool> *objective, Node *n, worldStateVariables current) {
	float cost = 1.f;
	/*vector<WS> eraseList;
	for (map<WS, bool>::iterator it = objective->begin(); it != objective->end(); it++) {
		if (n->action->GetEffects()->find(it->first) != n->action->GetEffects()->end() && n->action->GetEffects()->at(it->first) == objective->at(it->first)) {
			cout << "Action  " << n->action->name << " will complete objective:  " << it->first << endl;
			eraseList.push_back(it->first);
			for (map<WS, bool>::iterator it2 = n->action->GetPreconditions()->begin(); it2 != n->action->GetPreconditions()->end(); it2++) {
				if (current.worldStatesList[it2->first] != it2->second) {
					objective->emplace(it2->first, n->action->GetPreconditions()->at(it2->first));
					cout << "New objective: " << it2->first << " to complete Action: " << n->action->name << endl;
				}
			}
			cost -= 0.2;
		}
	}
	for (int i = 0; i < eraseList.size(); i++) {
		objective->erase(eraseList[i]);
	}	*/
	return cost;
}