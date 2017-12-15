#pragma once
#include <iostream>
class Agent;
class State {
	enum stateName {HOME, MINE, BANK, SALOON};
public:
	virtual void Enter() = 0;
	virtual void Update(Agent*) = 0;
	virtual void Exit() = 0;
};