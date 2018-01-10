#pragma once
#include "Node.h"
#include <iostream>
#include <queue>
#include <vector>

class GOAP {
public:

	GOAP();
	void AStar(worldStateVariables *current, worldStateVariables objective);
	void FillList();
	float Heuristic(std::map<WS, bool> *objective, Node *n);
	vector<Node*> nodeList;
private:
	
	
};