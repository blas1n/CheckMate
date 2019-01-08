#pragma once

#include <memory>
#include "WindowWrapper.h"
#include "InputManager.h"

class SceneManager;

class GameDirector : public WindowWrapper {
private:
	std::unique_ptr<InputManager> m_pInputManager;
	std::unique_ptr<SceneManager> m_pSceneManager;
	std::unique_ptr<Graphics> m_pGraphics;
	DWORD m_frameInterval;

private:
	GameDirector();

public:
	static GameDirector* GetGameDirector();
	const InputManager& GetInputManager() const noexcept;
	SceneManager& GetSceneManager() const noexcept;
	Graphics& GetGraphics() const noexcept;

	DWORD GetFrameInterval() const noexcept;
	void SetFrameInterval(DWORD) noexcept;

public:
	virtual void Process() override;
};