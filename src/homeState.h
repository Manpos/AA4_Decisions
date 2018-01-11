#pragma once
#include "State.h"

class HomeState : public State {
public:
	HomeState();
	~HomeState();
	char* StateID() override;
	void Enter() override;
	void Run(Agent* a) override;
	void Exit() override;
};