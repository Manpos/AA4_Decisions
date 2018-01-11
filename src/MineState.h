#pragma once
#include "State.h"

class MineState : public State {
public:
	MineState();
	char* StateID() override;
	void Enter() override;
	void Run(Agent* a) override;
	void Exit() override;
};