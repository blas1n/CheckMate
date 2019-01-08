#pragma once

#include "stdafx.h"
#include "Object.h"
#include <string>
#include <list>

class Scene {
private:
	using ObjectList = std::list<Object>;
	ObjectList m_objects;

public:
	Scene(std::initializer_list<Object>);
	virtual ~Scene() = default;

private:
	friend class SceneManager;

	void Init();
	void Update();
	void Clear();
};