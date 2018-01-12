#pragma once
#include <map>
#include <iostream>

using namespace std;

enum WS { A_ALIVE, A_HAS_WEAPON, A_HAS_BOMB, W_RELOADED, E_VISIBLE, E_ALIGNED, E_CLOSE, E_ALIVE };

class WorldStateVariables
{
public:
	
	WorldStateVariables() {
		InitialState();
	}

	map<WS, bool> worldStatesList;

	void InitialState();
	void RandomState();


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