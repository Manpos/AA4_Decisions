#pragma once
#include <iostream>
class Agent;
class State {
public:
	virtual char* StateID() = 0;
	virtual void Enter() = 0;
	virtual void Update(Agent* a) = 0;
	virtual void Exit() = 0;
};