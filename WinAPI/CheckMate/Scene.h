#pragma once

#include "stdafx.h"
#include <list>
#include "Object.h"

class Scene {
protected:
	using ObjectList = std::list<Object*>;

private:
	ObjectList* m_objects;

public:
	Scene() = default;
	virtual ~Scene() = default;

private:
	friend class SceneManager;

	void Create();
	void Init();
	void Update();
	void Clear();
	void Destroy();

protected:
	virtual void InitObjects(ObjectList*&) = 0;
};