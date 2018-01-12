#pragma once
#include "Actions.h"

class Node {
public:
	float cost;
	Action *action;
	vector<Node*> nextNodes;
	void SetAction(Action *a);
	Node(Action *a);
	void SetNextNodes(vector<Node*> nL, WorldStateVariables wS);
private:
};