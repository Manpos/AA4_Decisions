#include "Actions.h"

void Actions::AddActions() {
	actionsList.push_back(new Explore());
	actionsList.push_back(new GetClose());
	actionsList.push_back(new Aim());
	actionsList.push_back(new Shoot());
	actionsList.push_back(new Reload());
	actionsList.push_back(new ActivateBomb());
	actionsList.push_back(new FleeEnemy());
}

void Explore::ExecuteAction() { 
	int randomizer = rand() % 2;
	if (randomizer == 0) {
		WST.enemy_visible = false;
	}else WST.enemy_visible = true;
	
}
bool Explore::ReturnPrecondition() { 
	return precondition;
}
bool Explore::CheckPrecondition() { 
	return false;
}

void GetClose::ExecuteAction() {
	WST.enemy_close = true;
}
bool GetClose::ReturnPrecondition() { 
	return precondition;
}
bool GetClose::CheckPrecondition() { 
	return false;
}

void Aim::ExecuteAction() { }
bool Aim::ReturnPrecondition() { 
	return precondition;
}
bool Aim::CheckPrecondition() { 
	return false;
}

void Shoot::ExecuteAction() { }
bool Shoot::ReturnPrecondition() { 
	return precondition;
}
bool Shoot::CheckPrecondition() { 
	return false;
}

void Reload::ExecuteAction() { }
bool Reload::ReturnPrecondition() { 
	return precondition;
}
bool Reload::CheckPrecondition() { 
	return false;
}

void ActivateBomb::ExecuteAction() { }
bool ActivateBomb::ReturnPrecondition() { 
	return precondition;
}
bool ActivateBomb::CheckPrecondition() { 
	return false;
}

void FleeEnemy::ExecuteAction() { }
bool FleeEnemy::ReturnPrecondition() { 
	return precondition;
}
bool FleeEnemy::CheckPrecondition() { 
	return false;
}