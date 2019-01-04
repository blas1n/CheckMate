#include "stdafx.h"
#include "SceneManager.h"
#include "Scene.h"

SceneManager::SceneManager()
	: m_currentScene(nullptr),
	m_reservedScene(nullptr)
{}

SceneManager::~SceneManager() {
	for (auto& iter : m_sceneContainer) {
		iter.second->Destroy();
		Erase(iter.second);
	}
}

void SceneManager::RegisterScene(const string& sceneName, Scene* scene) {
	if (!scene || !sceneName.compare(""))
		return;

	scene->Create();
	m_sceneContainer.emplace(std::make_pair(sceneName, scene));
}

void SceneManager::ReserveChangeScene(const string& sceneName) {
	auto iter = m_sceneContainer.find(sceneName);

	if (iter != m_sceneContainer.end())
		m_reservedScene = iter->second;

	else m_reservedScene = nullptr;
}

void SceneManager::Update() {
	if (m_reservedScene) {
		if (m_currentScene)
			m_currentScene->Clear();

		m_reservedScene->Init();
		m_currentScene = m_reservedScene;
		m_reservedScene = nullptr;
	}

	if (m_currentScene)
		m_currentScene->Update();
}
