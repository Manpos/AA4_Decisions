#pragma once
#include "State.h"
#include "Agent.h"

class HomeState : public State {
public:
	bool rested;
	HomeState();
	void Enter() override;
	void Update(Agent* a) override;
	//void Update(Agent*);
	void Exit() override;
};