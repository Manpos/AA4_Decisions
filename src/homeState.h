#pragma once
#include "State.h"

class HomeState : public State {
public:
	bool rested;
	void Enter();
	void Update();
	void Exit();
};