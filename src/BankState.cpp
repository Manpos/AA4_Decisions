#include "BankState.h"
#include "HomeState.h"
#include "MineState.h"
#include "GoToState.h"
#include "Agent.h"

BankState::BankState()
{
	Enter();
}
void BankState::Enter()
{
	//std::cout << "Bank State Enter" << std::endl;
}
void BankState::Run(Agent* a)
{
	a->statistics.SetWhealth(a->statistics.GetWhealth() + a->statistics.GetGold());
	a->statistics.SetGold(0);

	if (a->statistics.Whealthy(90))
	{
		Exit();
		//a->changeState(new HomeState);
		a->changeState(new GoToState(a, HOME, Vector2D(7, 10) * 32));
	}
	else
	{
		Exit();
		//a->changeState(new MineState);
		a->changeState(new GoToState(a, MINE, Vector2D(12, 2) * 32));
	}

	if (!a->statistics.Rested(20))
	{
		Exit();
		//a->changeState(new HomeState);
		a->changeState(new GoToState(a, HOME, Vector2D(7, 10) * 32));
	}
}
void BankState::Exit()
{
	//std::cout << "Bank State Exit" << std::endl;
}

char* BankState::StateID()
{
	return "Bank State";
}