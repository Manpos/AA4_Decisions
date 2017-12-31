#pragma once
#include "State.h"

class BankState : public State {
public:
	BankState();
	char* StateID() override;
	void Enter() override;
	void Update(Agent* a) override;
	void Exit() override;
};