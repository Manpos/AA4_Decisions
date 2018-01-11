#pragma once
#include "State.h"

class SaloonState : public State {
public:
	SaloonState();
	char* StateID() override;
	void Enter() override;
	void Run(Agent* a) override;
	void Exit() override;
};