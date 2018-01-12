#include "GoToState.h"
#include "Agent.h"
#include "SaloonState.h"
#include "MineState.h"
#include "HomeState.h"
#include "BankState.h"
#include <string>

GoToState::GoToState(Agent* a, StateType nextState, Vector2D targetPosition) {
	//a->setTarget(targetPosition);
	a->path->points.push_back(targetPosition);
	this->nextState = nextState;
	this->targetPosition = targetPosition;
	Enter();
}
GoToState::~GoToState()
{

}

void GoToState::Enter() {
	//std::cout << "Home state Enter" << std::endl;
	
}

void GoToState::Run(Agent* a) {
	//a->statistics.SetThirst(a->statistics.GetThrist() + 0.01);
	
	
	if (Vector2D::Distance(a->getPosition(), targetPosition) <= 5)
		switch (nextState)
		{
			case MINE:
			{
				a->changeState(new MineState);
			}
				break;
			case SALOON:
			{
				a->changeState(new SaloonState);
			}
				break;
			case BANK:
			{
				a->changeState(new BankState);
			}
				break;
			case HOME:
			{
				a->changeState(new HomeState);
			}
				break;
			default:
				break;
		}

}

void GoToState::Exit() {
	//std::cout << "Home state Exit" << std::endl;
}

char* GoToState::StateID()
{
	return "Traveling State";
}