#pragma once

#include "stdafx.h"

class IScene {
public:
	IScene() = default;
	virtual ~IScene() = default;

private:
	virtual void Create() = 0;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render(Graphics& graphics) = 0;
	virtual void Clear() = 0;
	virtual void Destroy() = 0;

	friend class SceneManager;
};