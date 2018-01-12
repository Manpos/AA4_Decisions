#pragma once
#include "WorldStateVariables.h"
#include <string>

class Action
{
public:
	string name;
	float cost = 3.f;
	virtual void ExecuteAction(WorldStateVariables WST) = 0;
	map<WS, bool>* GetEffects() { return &effects; }
	map<WS, bool>* GetPreconditions() { return &preconditions; }
protected:
	map<WS, bool> effects;
	map<WS, bool> preconditions;
};