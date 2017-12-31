#include "MineState.h"
#include "BankState.h"
#include "Agent.h"

MineState::MineState()
{
	Enter();
}
void MineState::Enter()
{
	//std::cout << "Mine State Enter" << std::endl;
}
void MineState::Update(Agent* a)
{
	a->statistics.SetGold(a->statistics.GetGold()+0.05f);
	//std::cout << "Mine State Update" << std::endl;
	if (a->statistics.PocketsFull(90))
	{
		a->changeState(new BankState);
	}
	Exit();
	
	
}
void MineState::Exit()
{
	//std::cout << "Mine State Exit" << std::endl;
}

char* MineState::StateID()
{
	return "Mine State";
}