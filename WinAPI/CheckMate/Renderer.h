#pragma once

#include "IComponent.h"
#include "Sprite.h"

class Renderer : public IComponent {
private:
	Sprite* sprite;

public:
	virtual void Create() override;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;
	virtual void Destroy() override;
};

