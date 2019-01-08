#include "Scene.h"
#include <algorithm>

Scene::Scene(std::initializer_list<Object> objList)
	: m_objects(objList) {}

void Scene::Init() {
	for (auto iter : m_objects)
		iter.Init();
}

void Scene::Update() {
	for (auto iter : m_objects)
		iter.Update();
}

void Scene::Clear() {
	for (auto iter : m_objects)
		iter.Clear();
}