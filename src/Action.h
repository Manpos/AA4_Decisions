#pragma once
#include "WorldStateVariables.h"
#include <string>

class Action
{
public:
	string name;
	float cost = 1.f;
	virtual void ExecuteAction(worldStateVariables WST) = 0;
	virtual bool CheckPrecondition(worldStateVariables WST) = 0;
	map<WS, bool>* GetEffects() { return &effects; }
	map<WS, bool>* GetPreconditions() { return &preconditions; }
protected:
	map<WS, bool> effects;
	map<WS, bool> preconditions;
};