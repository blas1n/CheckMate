#pragma once

#include "stdafx.h"
#include <string>
#include <map>

using std::string;
using std::map;

class Scene;

class SceneManager {
private:
	map<string, Scene*> m_sceneContainer;
	
	Scene* m_reservedScene;
	Scene* m_currentScene;

public:
	SceneManager();
	~SceneManager();

public:
	void RegisterScene(const string& sceneName, Scene* scene);
	void ReserveChangeScene(const string& sceneName);

public:
	void Update();
};

