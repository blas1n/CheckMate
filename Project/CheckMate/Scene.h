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
	virtual ~Scene() = default;

private:
	friend class SceneManager;

	void Init();
	void Update();
	void Clear();

public:
	Object& FindObject(const std::string& name) const;
	Object& AddObject(const std::string& name);
};