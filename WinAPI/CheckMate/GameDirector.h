#pragma once

#include "WindowWrapper.h"

class SceneManager;

class GameDirector : public WindowWrapper {
private:
	SceneManager* m_sceneManager;
	Graphics* m_graphics;

private:
	GameDirector();
	~GameDirector();

public:
	static GameDirector* GetGameDirector();
	SceneManager* GetSceneManager() const noexcept;
	Graphics* GetGraphics() const noexcept;

public:
	virtual void Process() override;
};

