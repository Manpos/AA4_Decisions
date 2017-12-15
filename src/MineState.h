#pragma once
#include "State.h"
#include "Agent.h"

class MineState : public State {
public:
	void Enter();
	void Update(Agent);
	void Exit();
};