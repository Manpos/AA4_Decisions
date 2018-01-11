#include "Node.h"

Node::Node(Action *a) {
	action = a;
	cost = a->cost;
}

 void Node::SetAction(Action *a){
	action = a;
}

void Node::SetNextNodes(vector<Node*> nL, worldStateVariables current) {
	 for (int i = 0; i < nL.size(); i++) {
		 for (map<WS, bool>::iterator it = action->GetPreconditions()->begin(); it != action->GetPreconditions()->end(); it++) {
			 if (nL[i]->action->GetEffects()->find(it->first) != nL[i]->action->GetEffects()->end()) {
				 if (nL[i]->action->GetEffects()->at(it->first) == action->GetPreconditions()->at(it->first) && current.worldStatesList.at(it->first) != action->GetPreconditions()->at(it->first)) {
					 nextNodes.push_back(nL[i]);
				 }
			 }
		 }
	 }
 }

 bool operator<(const Node& n1, const Node& n2) {
	 return n1.cost < n2.cost;
 }