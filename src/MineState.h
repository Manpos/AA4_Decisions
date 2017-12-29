#pragma once
#include "State.h"

class MineState : public State {
public:
	MineState();
	void Enter() override;
	void Update(Agent* a) override;
	void Exit() override;
};