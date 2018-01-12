#include "WorldStateVariables.h"

void WorldStateVariables::InitialState() {

	worldStatesList.emplace(A_ALIVE, agent_alive = false);
	worldStatesList.emplace(A_HAS_WEAPON, agent_hasWeapon = false);
	worldStatesList.emplace(A_HAS_BOMB, agent_hasBomb = false);

	worldStatesList.emplace(W_RELOADED, weapon_reloaded = false);

	worldStatesList.emplace(E_VISIBLE, enemy_visible = false);
	worldStatesList.emplace(E_ALIGNED, enemy_aligned = false);
	worldStatesList.emplace(E_CLOSE, enemy_close = false);
	worldStatesList.emplace(E_ALIVE, enemy_alive = false);

}

void WorldStateVariables::RandomState() {
	int holder;
	worldStatesList[(WS)0] = true;
	worldStatesList[(WS)1] = true;
	for (int i = 2; i < worldStatesList.size(); i++) {
		holder = rand() % 2;
		if (holder == 1) {
			worldStatesList[(WS)i] = true;
		}		
	}
}