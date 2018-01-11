#pragma once
#include <iostream>

enum StateType {MINE, SALOON, BANK, HOME};

class Agent;
class State {
public:
	virtual char* StateID() = 0;
	virtual void Enter() = 0;
	virtual void Run(Agent* a) = 0;
	virtual void Exit() = 0;
};