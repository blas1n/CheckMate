#pragma once

#include "IScene.h"
#include "Sprite.h"

class TitleScene : public IScene {
private:
	Sprite* sprite;

private:
	virtual void Create() override;
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render(Graphics& graphics) override;
	virtual void Clear() override;
	virtual void Destroy() override;
};

