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
			changeList.emplace(it->first,objective.worldStatesList[it->first]);
			cout << "World State " << it->first << " needs to be changed" << endl;
		}
	}

	for (int i = 0; i < nodeList.size(); i++) {
		nodeList[i]->SetNextNodes(nodeList, *current);
		frontier.push(nodeList[i]);
	}

	visited.push_back(nodeList[0]);
	costSoFar.emplace(nodeList[0], 0.f);

	Node *currentNode;

	while (!frontier.empty())
	{
		currentNode = frontier.top();
		frontier.pop();
	}

	for (int i = 0; i < nodeList.size(); i++) {
		std::cout << "The cost of the node " << nodeList[i]->action->name << " is: " << Heuristic(&changeList, nodeList[i]) << std::endl;
	}
}

// Fills node list with all the different actions
void GOAP::FillList() {
	system("cls");
	std::cout << "Actions available: " << std::endl;
	for (int i = 0; i < ActionName::SIZE; i++) {
		nodeList.push_back(new Node(ACTIONS.actionsList[(ActionName)i]));
		std::cout << "Action " << i + 1 << ": " << nodeList[i]->action->name << std::endl;
	}	
}

float GOAP::Heuristic(std::map<WS, bool> *objective, Node *n) {
	float cost = 1.f;
	for (map<WS, bool>::iterator it = objective->begin(); it != objective->end(); it++) {
		if (n->action->GetEffects()->find(it->first) != n->action->GetEffects()->end()) {
			if (n->action->GetEffects()->at(it->first) == objective->at(it->first)) {
				for (map<WS, bool>::iterator it2 = n->action->GetPreconditions()->begin(); it2 != n->action->GetPreconditions()->end(); it2++) {
					objective->emplace(it2->first, n->action->GetPreconditions()->at(it2->first));
				}					
				cost -= 0.2;
			}
		}
	}
	return cost;
}