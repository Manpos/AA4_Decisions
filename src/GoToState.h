#pragma once
#include "State.h"
#include "Vector2D.h"

class GoToState : public State {
public:
	GoToState(Agent* a, StateType targetState, Vector2D targetPosition);
	~GoToState();
	char* StateID() override;
	void Enter() override;
	void Run(Agent* a) override;
	void Exit() override;
private:
	StateType nextState;
	Vector2D targetPosition;
};