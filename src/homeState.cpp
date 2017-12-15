#include "HomeState.h"

HomeState::HomeState() {

}

void HomeState::Enter() {
	std::cout << "Home state Enter" << std::endl;
}

//void HomeState::Update(Age) { }

void HomeState::Update(Agent* a) {
	std::cout << "Home state Update" << std::endl;
	if (a->statistics.rested) {
		//a->changeState();
	}
}

void HomeState::Exit() {
	std::cout << "Home state Exit" << std::endl;
}