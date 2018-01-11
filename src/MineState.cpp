#include "MineState.h"
#include "BankState.h"
#include "SaloonState.h"
#include "GoToState.h"
#include "Agent.h"
#include "SceneManager.h"

#include <iostream>

MineState::MineState()
{
	Enter();
}
void MineState::Enter()
{
	//std::cout << "Mine State Enter" << std::endl;
}
void MineState::Run(Agent* a)
{
	a->statistics.SetGold(a->statistics.GetGold()+0.2f);
	a->statistics.SetThirst(a->statistics.GetThrist() + 0.1f);
	a->statistics.SetRest(a->statistics.GetRest() - 0.03f);
	//std::cout << "Mine State Run" << std::endl;
	if (a->statistics.Thirsty(90))
	{
		Exit();
		a->changeState(new SaloonState);
		//a->changeState(new GoToState(a, SALOON, dynamic_cast<ScenePlanning*>(SM->GetCurrentScene())->entSaloon->GetPosition()));
	}

	if (a->statistics.PocketsFull(90))
	{
		Exit();
		a->changeState(new BankState);
	}	
	
}
void MineState::Exit()
{
	//std::cout << "Mine State Exit" << std::endl;
}

char* MineState::StateID()
{
	return "Mine State";
}