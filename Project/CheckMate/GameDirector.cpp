#include "stdafx.h"
#include "GameDirector.h"
#include "SceneManager.h"
#include "Time.h"

GameDirector::GameDirector()
	: m_pSceneManager(std::make_unique<SceneManager>()),
	m_pGraphics(nullptr) {}

GameDirector* GameDirector::GetGameDirector() {
	static GameDirector director;
	return &director;
}

SceneManager& GameDirector::GetSceneManager() const noexcept {
	return *m_pSceneManager;
}

Graphics& GameDirector::GetGraphics() const noexcept {
	return *m_pGraphics;
}

void GameDirector::Process() {
	static auto prevFrameTime = static_cast<DWORD>(0);

	Time::GetTime()->SetDeltaTime(static_cast<float>(GetTickCount()) - static_cast<float>(prevFrameTime) * 0.001f);
	
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