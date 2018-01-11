#pragma once
#include <map>

using namespace std;

enum WS { A_ALIVE, A_HAS_WEAPON, A_HAS_BOMB, W_RELOADED, E_VISIBLE, E_ALIGNED, E_CLOSE, E_ALIVE };

class worldStateVariables
{
public:
	
	worldStateVariables() {
		InitialState();
	}

	map<WS, bool> worldStatesList;

	void InitialState() {

		worldStatesList.emplace(A_ALIVE, agent_alive = false);
		worldStatesList.emplace(A_HAS_WEAPON, agent_hasWeapon = false);
		worldStatesList.emplace(A_HAS_BOMB, agent_hasBomb = false);

		worldStatesList.emplace(W_RELOADED, weapon_reloaded = false);

		worldStatesList.emplace(E_VISIBLE, enemy_visible = false);
		worldStatesList.emplace(E_ALIGNED, enemy_aligned = false);
		worldStatesList.emplace(E_CLOSE, enemy_close = false);
		worldStatesList.emplace(E_ALIVE, enemy_alive = false);

	}

private:
	bool agent_alive;
	bool agent_hasWeapon;
	bool agent_hasBomb;

	bool weapon_reloaded;

	bool enemy_visible;
	bool enemy_aligned;
	bool enemy_close;
	bool enemy_alive;

};