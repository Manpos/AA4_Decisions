#include "SaloonState.h"
#include "HomeState.h"
#include "Agent.h"

SaloonState::SaloonState()
{
	Enter();
}
void SaloonState::Enter()
{
	//std::cout << "Saloon State Enter" << std::endl;
}
void SaloonState::Update(Agent* a)
{
	//std::cout << "Saloon State Update" << std::endl;
	Exit();
	a->changeState(new HomeState);
}
void SaloonState::Exit()
{
	//std::cout << "Saloon State Exit" << std::endl;
}

char* SaloonState::StateID()
{
	return "Saloon State";
}