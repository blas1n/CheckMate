#include "stdafx.h"
#include "GameDirector.h"
#include "SceneManager.h"
#include "Time.h"

GameDirector::GameDirector()
	: m_graphics(nullptr) {

	m_sceneManager = new SceneManager();
}

GameDirector::~GameDirector() {
	Erase(m_sceneManager);
}

GameDirector* GameDirector::GetGameDirector() {
	static GameDirector director;
	return &director;
}

SceneManager* GameDirector::GetSceneManager() const noexcept {
	return m_sceneManager;
}

Graphics* GameDirector::GetGraphics() const noexcept {
	return m_graphics;
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

	m_graphics = Graphics::FromHDC(hMemDC);
	m_sceneManager->Update();

	BitBlt(hDC, 0, 0, wndRect.right, wndRect.bottom, hMemDC, 0, 0, SRCCOPY);

	DeleteObject(hMyBitmap);
	DeleteDC(hMemDC);
	ReleaseDC(GetHWnd(), hDC);
	
	prevFrameTime = GetTickCount();
}