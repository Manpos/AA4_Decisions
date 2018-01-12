#include "Actions.h"

void Actions::AddActions() {
	actionsList.emplace(EXPLORE, new Explore());
	actionsList.emplace(GET_CLOSE, new GetClose());
	actionsList.emplace(AIM, new Aim());
	actionsList.emplace(SHOOT, new Shoot());
	actionsList.emplace(RELOAD, new Reload());
	actionsList.emplace(ACTIVATE_BOMB, new ActivateBomb());
	actionsList.emplace(FLEE_ENEMY, new FleeEnemy());
}

// EXPLORE
Explore::Explore() {
	name = "Explore";
	effects[E_VISIBLE] = true;
	preconditions[E_VISIBLE] = false;
	preconditions[A_ALIVE] = true;
}
void Explore::ExecuteAction(WorldStateVariables WST) { 
	WST.worldStatesList[E_VISIBLE] = true;
}

// GET CLOSE
GetClose::GetClose() {
	name = "Get Close";
	effects[E_CLOSE] = true;
	preconditions[E_VISIBLE] = true;
	preconditions[A_ALIVE] = true;
}
void GetClose::ExecuteAction(WorldStateVariables WST) {
	WST.worldStatesList[E_CLOSE] = true;
}

// AIM
Aim::Aim() {
	name = "Aim";
	effects[E_ALIGNED] = true;
	preconditions[E_VISIBLE] = true;
	preconditions[A_ALIVE] = true;
}
void Aim::ExecuteAction(WorldStateVariables WST) {
	WST.worldStatesList[E_ALIGNED] = true;
}

// SHOOT
Shoot::Shoot() {
	name = "Shoot";
	effects[E_ALIVE] = false;
	effects[W_RELOADED] = false;
	preconditions[E_ALIGNED] = true;
	preconditions[A_HAS_WEAPON] = true;
	preconditions[W_RELOADED] = true;
	preconditions[A_ALIVE] = true;
}
void Shoot::ExecuteAction(WorldStateVariables WST) {
	WST.worldStatesList[E_ALIVE] = false;
}

// RELOAD
Reload::Reload() {
	name = "Reload";
	effects[W_RELOADED] = true;
	preconditions[W_RELOADED] = false;
	preconditions[A_HAS_WEAPON] = true;
	preconditions[A_ALIVE] = true;
}

void Reload::ExecuteAction(WorldStateVariables WST) {
	WST.worldStatesList[W_RELOADED] = true;
}

// ACTIVATE BOMB
ActivateBomb::ActivateBomb() {
	name = "Activate bomb";
	effects[A_HAS_BOMB] = false;
	preconditions[A_HAS_BOMB] = true;
	preconditions[A_ALIVE] = true;
}
void ActivateBomb::ExecuteAction(WorldStateVariables WST) {
	WST.worldStatesList[A_HAS_BOMB] = false;
}

// FLEE ENEMY
FleeEnemy::FleeEnemy() {
	name = "Flee enemy";
	effects[E_CLOSE] = false;
	preconditions[E_CLOSE] = true;
	preconditions[A_ALIVE] = true;
}
void FleeEnemy::ExecuteAction(WorldStateVariables WST) {
	WST.worldStatesList[E_CLOSE] = false;
	WST.worldStatesList[E_VISIBLE] = false;
}
