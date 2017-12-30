#include "BankState.h"
#include "HomeState.h"
#include "Agent.h"

BankState::BankState()
{
	Enter();
}
void BankState::Enter()
{
	std::cout << "Saloon State Enter" << std::endl;
}
void BankState::Update(Agent* a)
{
	std::cout << "Saloon State Update" << std::endl;
	Exit();
	a->changeState(new HomeState);
}
void BankState::Exit()
{
	std::cout << "Saloon State Exit" << std::endl;
}