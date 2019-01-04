#pragma once

#include "WindowWrapper.h"

class SceneManager;

class GameDirector : public WindowWrapper {
private:
	SceneManager* m_sceneManager;

private:
	GameDirector();
	~GameDirector();

public:
	static GameDirector* GetGameDirector();
	SceneManager* GetSceneManager() const noexcept;

public:
	virtual void Process() override;

private:
	void Update();
	void Render();
};

