#include "stdafx.h"
#include "GameDirector.h"
#include "SceneManager.h"
#include "Time.h"

GameDirector::GameDirector()
	: m_pInputManager(std::make_unique<InputManager>()),
	m_pSceneManager(std::make_unique<SceneManager>()),
	m_pGraphics(nullptr),
	m_frameInterval(10) {}

GameDirector* GameDirector::GetGameDirector() {
	static GameDirector director;
	return &director;
}

const InputManager& GameDirector::GetInputManager() const noexcept {
	return *m_pInputManager;
}

SceneManager& GameDirector::GetSceneManager() const noexcept {
	return *m_pSceneManager;
}

Graphics& GameDirector::GetGraphics() const noexcept {
	return *m_pGraphics;
}

DWORD GameDirector::GetFrameInterval() const noexcept {
	return m_frameInterval;
}

void GameDirector::SetFrameInterval(DWORD frameInterval) noexcept {
	m_frameInterval = frameInterval;
}

void GameDirector::Process() {
	static auto prevFrameTime = static_cast<DWORD>(0);

	if (GetTickCount() - prevFrameTime <= m_frameInterval) return;

	Time::SetDeltaTime(static_cast<float>(GetTickCount() - prevFrameTime) * 0.001f);
	
	RECT wndRect;
	GetClientRect(GetHWnd(), &wndRect);

	auto hDC = GetDC(GetHWnd());
	auto hMemDC = CreateCompatibleDC(hDC);
	auto hMyBitmap = CreateCompatibleBitmap(hDC, wndRect.right, wndRect.bottom);

	SelectObject(hMemDC, hMyBitmap);
	FillRect(hMemDC, &wndRect, reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)));

	m_pGraphics.reset(Graphics::FromHDC(hMemDC));
	m_pSceneManager->Update();

	BitBlt(hDC, 0, 0, wndRect.right, wndRect.bottom, hMemDC, 0, 0, SRCCOPY);

	m_pGraphics.reset();
	DeleteObject(hMyBitmap);
	DeleteDC(hMemDC);
	ReleaseDC(GetHWnd(), hDC);
	
	prevFrameTime = GetTickCount();
}