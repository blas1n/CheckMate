#include "Scene.h"
#include <algorithm>

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

Object& Scene::FindObject(const std::string& name) const {
	for (auto& iter : m_objects) {
		if (iter.GetName().compare(name))
			return const_cast<Object&>(iter);
	}

	throw;
}

Object& Scene::AddObject(const std::string& name, const Utility::Point pos) {
	m_objects.emplace_back(Object(name, pos));
	return m_objects.back();
}