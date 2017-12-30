#pragma once
#include "State.h"

class SaloonState : public State {
public:
	SaloonState();
	void Enter() override;
	void Update(Agent* a) override;
	void Exit() override;
};