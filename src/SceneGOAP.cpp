#include "SceneGOAP.h"
#include "Entity.h"

using namespace std;

SceneGOAP::SceneGOAP()
{
	ACTIONS.AddActions();
	planner = new GOAP;
	objective.worldStatesList[E_VISIBLE] = true;
	objective.worldStatesList[W_RELOADED] = true;
	planner->AStar(&current, objective);
}

SceneGOAP::~SceneGOAP()
{

}

void SceneGOAP::update(float dtime, SDL_Event *event)
{


}

void SceneGOAP::draw()
{


}

const char* SceneGOAP::getTitle()
{
	return "SDL Steering Behaviors :: PathFinding1 Demo";
}

