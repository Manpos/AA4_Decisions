#pragma once
#include <iostream>
#include <minmax.h>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL_SimpleApp.h"
#include "Vector2D.h"
#include "utils.h"
#include "SteeringBehavior.h"
#include "State.h"
#include "Path.h"


class AgentStats {
public:
	AgentStats() = default;
	AgentStats(float maxR, float maxT, float maxG, float maxW);

	void ClampValues();

	bool Rested(float percentOffset);
	bool Thirsty(float percentOffset);
	bool PocketsFull(float percentOffset);
	bool Whealthy(float percentOffset);

	void SetGold(float g) { gold = g; }
	void SetRest(float r) { rest = r; }
	void SetThirst(float t) { thirst = t; }
	void SetWhealth(float w) { wealth = w; }

	float GetGold() { return gold; }
	float GetRest() { return rest; }
	float GetThrist() { return thirst; }
	float GetWhealth() { return wealth; }

	float GetMaxGold() { return maxGold; }
	float GetMaxRest() { return maxRest; }
	float GetMaxThrist() { return maxThirst; }
	float GetMaxWhealth() { return maxWealth; }

private:

	float GetPercent(float percent, float value);

	float rest;
	float thirst;
	float gold;
	float wealth;

	float maxRest;
	float maxThirst;
	float maxGold;
	float maxWealth;	
};

class Agent
{
	friend class SteeringBehavior;
	
private:
	SteeringBehavior *steering_behavior;
	Vector2D position;
	Vector2D velocity;
	Vector2D target;

	//Current state
	State *currentState;

	float mass;
	float orientation;
	float max_force;
	float max_velocity;

	SDL_Color color;

	SDL_Texture *sprite_texture;
	bool draw_sprite;
	int sprite_num_frames;
	int sprite_w;
	int sprite_h;

public:
	Agent(Path* p);
	~Agent();

	AgentStats statistics;

	Path* path;

	SteeringBehavior *Behavior();
	Vector2D getPosition();
	Vector2D getTarget();
	Vector2D getVelocity();
	float getMaxVelocity();
	void setPosition(Vector2D position);
	void setTarget(Vector2D target);
	void setVelocity(Vector2D velocity);
	void setMass(float mass);
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	void update(Vector2D steering_force, float dtime, SDL_Event *event);
	void draw();
	bool Agent::loadSpriteTexture(char* filename, int num_frames=1);

	void changeState(State* next);
};
