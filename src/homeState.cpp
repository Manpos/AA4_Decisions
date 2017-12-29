#include "HomeState.h"
#include "MineState.h"
#include "Agent.h"

HomeState::HomeState() {
	Enter();
}
HomeState::~HomeState()
{

}

void HomeState::Enter() {
	std::cout << "Home state Enter" << std::endl;
}

void HomeState::Update(Agent* a) {
	std::cout << "Home state Update" << std::endl;
	//if (a->statistics.rested) {
	Exit();
	a->changeState(new MineState);
	//}
}

void HomeState::Exit() {
	std::cout << "Home state Exit" << std::endl;
}