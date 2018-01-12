#include "SceneGOAP.h"
#include "Entity.h"

using namespace std;

SceneGOAP::SceneGOAP()
{
	// Initialize random seed
	srand(time(NULL));

	ACTIONS.AddActions();
	planner = new GOAP;
	InitialState();
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

void SceneGOAP::InitialState() {
	system("cls");

	current.RandomState();
	objective.RandomState();

	cout << "- Current World State -		- Objective World State -" << endl;
	cout << endl;
	cout << "  0. Agent alive: " << current.worldStatesList[A_ALIVE] << "		  0. Agent alive: " << objective.worldStatesList[A_ALIVE] << endl;
	cout << "  1. Agent has weapon: " << current.worldStatesList[A_HAS_WEAPON] << "	  1. Agent has weapon " << objective.worldStatesList[A_HAS_WEAPON] << endl;
	cout << "  2. Agent has bomb: " << current.worldStatesList[A_HAS_BOMB] << "		  2. Agent has bomb: " << objective.worldStatesList[A_HAS_BOMB] << endl;
	cout << "  3. Weapon reloaded: " << current.worldStatesList[W_RELOADED] << "		  3. Weapon reloaded: " << objective.worldStatesList[W_RELOADED] << endl;
	cout << "  4. Enemy visible: " << current.worldStatesList[E_VISIBLE] << "		  4. Enemy visible: " << objective.worldStatesList[E_VISIBLE] << endl;
	cout << "  5. Enemy aligned: " << current.worldStatesList[E_ALIGNED] << "		  5. Enemy aligned: " << objective.worldStatesList[E_ALIGNED] << endl;
	cout << "  6. Enemy close: " << current.worldStatesList[E_CLOSE] << "		  6. Enemy close: " << objective.worldStatesList[E_CLOSE] << endl;
	cout << "  7. Enemy alive: " << current.worldStatesList[E_ALIVE] << "		  7. Enemy alive: " << objective.worldStatesList[E_ALIVE] << endl;
	cout << endl;

	planner->Planner(&current, objective);
}

