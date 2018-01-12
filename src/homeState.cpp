#include "HomeState.h"
#include "MineState.h"
#include "GoToState.h"
#include "Agent.h"

HomeState::HomeState() {
	Enter();
}
HomeState::~HomeState()
{

}

void HomeState::Enter() {
	//std::cout << "Home state Enter" << std::endl;
}

void HomeState::Run(Agent* a) {
	//a->statistics.SetThirst(a->statistics.GetThrist() + 0.01);
	a->statistics.SetRest(a->statistics.GetRest() + 0.02);

	if (a->statistics.Rested(100) && !a->statistics.Whealthy(100))
	{
		Exit();
		//a->changeState(new MineState);
		a->changeState(new GoToState(a, MINE, Vector2D(12, 2) * 32));
	}
	
}

void HomeState::Exit() {
	//std::cout << "Home state Exit" << std::endl;
}

char* HomeState::StateID()
{
	return "Home State";
}