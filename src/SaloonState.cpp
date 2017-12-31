#include "SaloonState.h"
#include "MineState.h"
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
	a->statistics.SetThirst(a->statistics.GetThrist() - 0.1);
	a->statistics.SetRest(a->statistics.GetRest() - 0.02);

	if (!a->statistics.Thirsty(20)) {
		Exit();
		a->changeState(new MineState);
	}
	//Exit();
	//a->changeState(new HomeState);
}
void SaloonState::Exit()
{
	//std::cout << "Saloon State Exit" << std::endl;
}

char* SaloonState::StateID()
{
	return "Saloon State";
}