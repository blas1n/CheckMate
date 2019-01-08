#pragma once

#include <memory>
#include "WindowWrapper.h"

class SceneManager;

class GameDirector : public WindowWrapper {
private:
	std::unique_ptr<SceneManager> m_pSceneManager;
	std::unique_ptr<Graphics> m_pGraphics;

private:
	GameDirector();

public:
	static GameDirector* GetGameDirector();
	SceneManager& GetSceneManager() const noexcept;
	Graphics& GetGraphics() const noexcept;

public:
	virtual void Process() override;
};