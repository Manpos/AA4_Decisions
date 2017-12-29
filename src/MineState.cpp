#include "MineState.h"
#include "HomeState.h"
#include "Agent.h"

MineState::MineState()
{
	Enter();
}
void MineState::Enter()
{
	std::cout << "Mine State Enter" << std::endl;
}
void MineState::Update(Agent* a)
{
	std::cout << "Mine State Update" << std::endl;
	Exit();
	a->changeState(new HomeState);
}
void MineState::Exit()
{
	std::cout << "Mine State Exit" << std::endl;
}