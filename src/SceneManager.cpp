#include "SceneManager.h"
using namespace std;

#define FPS 30

SceneManager::~SceneManager()
{
	currentScene = new ScenePlanning;
	delete(currentScene);
}
void SceneManager::Run()
{
	SDL_Event event;
	int this_tick = 0;
	int next_tick = 1000 / FPS;
	bool quit = false;

	SDL_SimpleApp* app = SDL_SimpleApp::Instance();
	Scene* curr_scene;
	curr_scene = new ScenePlanning;

	//currentScene = curr_scene;

	app->setWindowTitle(curr_scene->getTitle());

	while (!quit)
	{
		this_tick = SDL_GetTicks();
		if (this_tick < next_tick)
		{
			SDL_Delay(next_tick - this_tick);
		}
		next_tick = this_tick + (1000 / FPS);

		// run app frame by frame
		event = app->run(curr_scene);

		/* Keyboard events */
		switch (event.type)
		{
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_1)
			{
				delete(curr_scene);
				curr_scene = new ScenePlanning;
				app->setWindowTitle(curr_scene->getTitle());
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_2)
			{
				delete(curr_scene);
				curr_scene = new SceneGOAP;
				app->setWindowTitle(curr_scene->getTitle());
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_3)
			{
			}
			if ((event.key.keysym.scancode == SDL_SCANCODE_Q) || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
			{
				quit = true;
			}
			if (event.key.keysym.scancode == SDL_SCANCODE_F)
			{
				app->setFullScreen();
			}
			break;
		case SDL_QUIT:
			quit = true;
			break;
		}
	}
}
Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}