#pragma once

#include "stdafx.h"
#include <string>
#include <map>

using std::string;
using std::map;

class IScene;

class SceneManager {
private:
	map<string, IScene*> m_sceneContainer;
	
	IScene* m_reservedScene;
	IScene* m_currentScene;

public:
	SceneManager();
	~SceneManager();

public:
	void RegisterScene(const string& sceneName, IScene* scene);
	void ReserveChangeScene(const string& sceneName);

public:
	void Update();
	void Render(Graphics& graphics);
};

