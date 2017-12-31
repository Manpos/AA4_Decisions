#include "BankState.h"
#include "HomeState.h"
#include "Agent.h"

BankState::BankState()
{
	Enter();
}
void BankState::Enter()
{
	//std::cout << "Bank State Enter" << std::endl;
}
void BankState::Update(Agent* a)
{
	//std::cout << "Bank State Update" << std::endl;
	Exit();
	a->changeState(new HomeState);
}
void BankState::Exit()
{
	//std::cout << "Bank State Exit" << std::endl;
}

char* BankState::StateID()
{
	return "Bank State";
}