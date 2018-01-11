#include "BankState.h"
#include "HomeState.h"
#include "MineState.h"
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
		a->changeState(new HomeState);
	}
	else
	{
		Exit();
		a->changeState(new MineState);
	}

	if (!a->statistics.Rested(20))
	{
		Exit();
		a->changeState(new HomeState);
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