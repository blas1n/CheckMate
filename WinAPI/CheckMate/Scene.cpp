#include "Scene.h"

void Scene::Create() {
	InitObjects(m_objects);

	for (auto iter : *m_objects)
		iter->Create();
}

void Scene::Init() {
	for (auto iter : *m_objects)
		iter->Init();
}

void Scene::Update() {
	for (auto iter : *m_objects)
		iter->Update();
}

void Scene::Clear() {
	for (auto iter : *m_objects)
		iter->Clear();
}

void Scene::Destroy() {
	for (auto iter : *m_objects)
		iter->Destroy();

	Erase(m_objects);
}