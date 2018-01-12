#pragma once

#include "Action.h"
#include "WorldStateVariables.h"
#include <map>
#include <vector>

using namespace std;

#define ACTIONS Actions::Instance()

enum ActionName { EXPLORE = 0, GET_CLOSE = 1, AIM = 2, SHOOT = 3, RELOAD = 4, ACTIVATE_BOMB = 5, FLEE_ENEMY = 6 };

class Actions {

public:

	static Actions& Instance() {
		static Actions instance;
		return instance;
	}

	map<ActionName,Action*> actionsList;

	void AddActions();
private:

	

};

class Explore : public Action {
public:
	Explore();
	void ExecuteAction(WorldStateVariables WST);
private:
};

class GetClose : public Action {
public:
	GetClose();
	void ExecuteAction(WorldStateVariables WST);
private:
};

class Aim : public Action {
public:
	Aim();
	void ExecuteAction(WorldStateVariables WST);
private:
};

class Shoot : public Action {
public:
	Shoot();
	void ExecuteAction(WorldStateVariables WST);
private:
};

class Reload : public Action {
public:
	Reload();
	void ExecuteAction(WorldStateVariables WST);
private:
};

class ActivateBomb : public Action {
public:
	ActivateBomb();
	void ExecuteAction(WorldStateVariables WST);
private:
};

class FleeEnemy : public Action {
public:
	FleeEnemy();
	void ExecuteAction(WorldStateVariables WST);
private:
};