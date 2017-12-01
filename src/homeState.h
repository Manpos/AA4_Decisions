#pragma once
#include "State.h"

class homeState : public State {
public:
	void Enter();
	void Update();
	void Exit();
};