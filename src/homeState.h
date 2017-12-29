#pragma once
#include "State.h"

class HomeState : public State {
public:
	HomeState();
	~HomeState();
	void Enter() override;
	void Update(Agent* a) override;
	void Exit() override;
};