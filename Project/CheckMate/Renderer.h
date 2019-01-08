#pragma once

#include "IComponent.h"
#include "Sprite.h"

class Renderer : public IComponent {
private:
	Sprite* sprite;

public:
	Renderer(Object* entity) : IComponent(entity) {}

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
};

