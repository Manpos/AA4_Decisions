#include "Entity.h"
#include <iostream>

using namespace std;

Entity::Entity(Vector2D pos) : spriteW(0), spriteH(0), numFrames(0), position(pos){};
Entity::~Entity() 
{ 
	delete(&tex); 
};

void Entity::Run() {

}
void Entity::Draw() 
{
	Uint32 sprite = (int)(SDL_GetTicks() / (10)) % numFrames;

	SDL_Rect srcrect = { (int)sprite * spriteW, 0, spriteW, spriteH };
	SDL_Rect dstrect = { (int)position.x - (spriteW / 2), (int)position.y - (spriteH / 2), spriteW, spriteH };
	SDL_Point center = { spriteW / 2, spriteH / 2 };
	SDL_RenderCopyEx(TheApp::Instance()->getRenderer(), tex, &srcrect, &dstrect, 0, &center, SDL_FLIP_NONE);
}

bool Entity::LoadSpriteTexture(char* filename, int _num_frames)
{
	if (_num_frames < 1) return false;

	SDL_Surface *image = IMG_Load(filename);
	if (!image) {
		cout << "IMG_Load: " << IMG_GetError() << endl;
		return false;
	}
	tex = SDL_CreateTextureFromSurface(TheApp::Instance()->getRenderer(), image);

	numFrames = _num_frames;
	spriteW = image->w / numFrames;
	spriteH = image->h;

	if (image)
		SDL_FreeSurface(image);

	return true;
}