#pragma once
#include <vector>
#include <time.h>
#include "Scene.h"
#include "GOAP.h"

class SceneGOAP :
	public Scene
{
public:
	SceneGOAP();
	~SceneGOAP();
	GOAP *planner;
	worldStateVariables objective;
	worldStateVariables current;
	void update(float dtime, SDL_Event *event);
	void draw();
	const char* getTitle();
private:

};