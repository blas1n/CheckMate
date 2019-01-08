#pragma once

#include "Object.h"
#include "Sprite.h"
#include "Renderer.h"
#include "IComponent.h"

class Transform;

class Player : public IComponent {
private:
	Transform& transform;

public:
	Player(Object*);

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
};

