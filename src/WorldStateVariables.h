#pragma once

#define WST worldStateVariables::Instance()

class worldStateVariables
{
public:
	static worldStateVariables& Instance() {
		static worldStateVariables instance;
		return instance;
	}
	bool agent_alive;
	bool agent_hasWeapon;
	bool agent_hasBomb;

	bool weapon_reloaded;

	bool enemy_visible;
	bool enemy_aligned;
	bool enemy_close;
	bool enemy_alive;

	void InitialState() {

		agent_alive = false;
		agent_hasWeapon = false;
		agent_hasBomb = false;

		weapon_reloaded = false;

		enemy_visible = false;
		enemy_aligned = false;
		enemy_close = false;
		enemy_alive = false;
	}
};