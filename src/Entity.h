#pragma once
#include <SDL_image.h>
#include "SDL_SimpleApp.h"

class Entity {
public:
	Entity() = delete;
	Entity(Vector2D pos);
	~Entity();
	SDL_Texture* tex;
	int numFrames;
	int spriteW;
	int spriteH;

	Vector2D GetPosition() { return position; }
	void Draw();
	void Run();

	bool LoadSpriteTexture(char* filename, int num_frames);
private:
	Vector2D position;
	
};