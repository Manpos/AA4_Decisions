#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
#include <vector>

class GOAP {
public:

	GOAP();
	void Planner(WorldStateVariables *current, WorldStateVariables objective);
	void FillList();
	float Heuristic(std::map<WS, bool> *objective, Node *n, WorldStateVariables current);
	vector<Node*> nodeList;
private:
	
	
};