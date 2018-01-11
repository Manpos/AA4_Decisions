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
	cost = 2.f;
	effects[E_VISIBLE] = true;
	preconditions[E_VISIBLE] = false;
}
void Explore::ExecuteAction(worldStateVariables WST) { 
	WST.worldStatesList[E_VISIBLE] = true;
}
bool Explore::CheckPrecondition(worldStateVariables WST) {
	return false;
}

// GET CLOSE
GetClose::GetClose() {
	name = "Get Close";
	effects[E_CLOSE] = true;
	preconditions[E_VISIBLE] = true;
}
void GetClose::ExecuteAction(worldStateVariables WST) {
	WST.worldStatesList[E_CLOSE] = true;
}
bool GetClose::CheckPrecondition(worldStateVariables WST) {
	return false;
}

// AIM
Aim::Aim() {
	name = "Aim";
	cost = 1.5f;
	effects[E_ALIGNED] = true;
	preconditions[E_VISIBLE] = true;
}
void Aim::ExecuteAction(worldStateVariables WST) {
	WST.worldStatesList[E_ALIGNED] = true;
}
bool Aim::CheckPrecondition(worldStateVariables WST) {
	return false;
}

// SHOOT
Shoot::Shoot() {
	name = "Shoot";
	effects[E_ALIVE] = false;
	effects[W_RELOADED] = false;
	preconditions[E_ALIGNED] = true;
	preconditions[A_HAS_WEAPON] = true;
	preconditions[W_RELOADED] = true;
}
void Shoot::ExecuteAction(worldStateVariables WST) {
	WST.worldStatesList[E_ALIVE] = false;
}
bool Shoot::CheckPrecondition(worldStateVariables WST) {
	return false;
}

// RELOAD
Reload::Reload() {
	name = "Reload";
	cost = 1.2;
	effects[W_RELOADED] = true;
	preconditions[W_RELOADED] = false;
	preconditions[A_HAS_WEAPON] = true;
}

void Reload::ExecuteAction(worldStateVariables WST) {
	WST.worldStatesList[W_RELOADED] = true;
}
bool Reload::CheckPrecondition(worldStateVariables WST) {
	return false;
}

// ACTIVATE BOMB
ActivateBomb::ActivateBomb() {
	name = "Activate bomb";
	effects[A_HAS_BOMB] = false;
	preconditions[A_HAS_BOMB] = true;
}
void ActivateBomb::ExecuteAction(worldStateVariables WST) {
	WST.worldStatesList[A_HAS_BOMB] = false;
}
bool ActivateBomb::CheckPrecondition(worldStateVariables WST) {
	return false;
}

// FLEE ENEMY
FleeEnemy::FleeEnemy() {
	name = "Flee enemy";
	effects[E_CLOSE] = false;
	effects[E_VISIBLE] = false;
	preconditions[E_CLOSE] = true;
	preconditions[W_RELOADED] = false;
}
void FleeEnemy::ExecuteAction(worldStateVariables WST) {
	WST.worldStatesList[E_CLOSE] = false;
	WST.worldStatesList[E_VISIBLE] = false;
}
bool FleeEnemy::CheckPrecondition(worldStateVariables WST) { 
	return false;
}