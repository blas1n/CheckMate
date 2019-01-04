#pragma once

#include <list>
#include "IComponent.h"

class Object {
protected:
	using ComponentList = std::list<IComponent*>;

private:
	ComponentList* m_components;

public:
	Object() = default;
	virtual ~Object() = default;

public:
	void Create();
	void Init();
	void Update();
	void Clear();
	void Destroy();

protected:
	virtual void InitComponents(ComponentList*&) = 0;
};