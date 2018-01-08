#pragma once

#include "Action.h"
#include "WorldStateVariables.h"
#include <vector>

using namespace std;

#define ACTIONS Actions::Instance()

enum ActionPosition { EXPLORE = 0, GET_CLOSE = 1, AIM = 2, SHOOT = 3, RELOAD = 4, ACTIVATE_BOMB = 5, FLEE_ENEMY = 6 };

class Actions {

public:

	static Actions& Instance() {
		static Actions instance;
		return instance;
	}

	vector<Action*> actionsList;

private:
	void AddActions();

};

class Explore : public Action {
public:
	Explore() { };
	void ExecuteAction();
	bool ReturnPrecondition();
	bool CheckPrecondition();
private:
};

class GetClose : public Action {
public:
	GetClose() { };
	void ExecuteAction();
	bool ReturnPrecondition();
	bool CheckPrecondition();
private:
};

class Aim : public Action {
public:
	Aim() { };
	void ExecuteAction();
	bool ReturnPrecondition();
	bool CheckPrecondition();
private:
};

class Shoot : public Action {
public:
	Shoot() { };
	void ExecuteAction();
	bool ReturnPrecondition();
	bool CheckPrecondition();
private:
};

class Reload : public Action {
public:
	Reload() { };
	void ExecuteAction();
	bool ReturnPrecondition();
	bool CheckPrecondition();
private:
};

class ActivateBomb : public Action {
public:
	ActivateBomb() { };
	void ExecuteAction();
	bool ReturnPrecondition();
	bool CheckPrecondition();
private:
};

class FleeEnemy : public Action {
public:
	FleeEnemy() { };
	void ExecuteAction();
	bool ReturnPrecondition();
	bool CheckPrecondition();
private:
};