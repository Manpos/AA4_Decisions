#include "Scene.h"
#include "ScenePlanning.h"

#define SM SceneManager::Instance()

class SceneManager
{
public:
	inline static SceneManager* Instance() { static SceneManager* instance; return instance; }
	void Run();
	~SceneManager();
	Scene* GetCurrentScene();
private:
	SceneManager()=default;
	Scene* currentScene;

};