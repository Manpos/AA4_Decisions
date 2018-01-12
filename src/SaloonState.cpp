#include "SaloonState.h"
#include "MineState.h"
#include "GoToState.h"
#include "Agent.h"

SaloonState::SaloonState()
{
	Enter();
}
void SaloonState::Enter()
{
	//std::cout << "Saloon State Enter" << std::endl;
}
void SaloonState::Run(Agent* a)
{
	//std::cout << "Saloon State Run" << std::endl;
	a->statistics.SetThirst(a->statistics.GetThrist() - 0.1);
	a->statistics.SetRest(a->statistics.GetRest() - 0.02);

	if (!a->statistics.Thirsty(20)) {
		Exit();
		//a->changeState(new MineState);
		a->changeState(new GoToState(a, MINE, Vector2D(12, 2) * 32));
	}

}
void SaloonState::Exit()
{
	//std::cout << "Saloon State Exit" << std::endl;
}

char* SaloonState::StateID()
{
	return "Saloon State";
}