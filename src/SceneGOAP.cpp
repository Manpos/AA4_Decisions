#include "SceneGOAP.h"
#include "Entity.h"

using namespace std;

SceneGOAP::SceneGOAP()
{
	ACTIONS.AddActions();
	planner = new GOAP;
	current.worldStatesList[E_ALIVE] = true;
	current.worldStatesList[A_HAS_WEAPON] = true;
	objective.worldStatesList[E_ALIVE] = false;
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

