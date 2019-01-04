#include "stdafx.h"
#include "GameDirector.h"
#include "SceneManager.h"
#include "Time.h"

GameDirector::GameDirector() {
	m_sceneManager = new SceneManager();
}

GameDirector::~GameDirector() {
	Destroy(m_sceneManager);
}

GameDirector* GameDirector::GetGameDirector() {
	static GameDirector director;
	return &director;
}

SceneManager* GameDirector::GetSceneManager() const noexcept {
	return m_sceneManager;
}

void GameDirector::Process() {
	static auto prevFrameTime = static_cast<DWORD>(0);

	Time::GetTime()->SetDeltaTime(static_cast<float>(GetTickCount()) - static_cast<float>(prevFrameTime) * 0.001f);
	
	Update();
	Render();
	
	prevFrameTime = GetTickCount();
}

void GameDirector::Update() {
	m_sceneManager->Update();
}

void GameDirector::Render() {
	RECT wndRect;
	GetClientRect(GetHWnd(), &wndRect);
	
	auto hDC = GetDC(GetHWnd());
	auto hMemDC = CreateCompatibleDC(hDC);
	auto hMyBitmap = CreateCompatibleBitmap(hDC, wndRect.right, wndRect.bottom);
	
	SelectObject(hMemDC, hMyBitmap);
	FillRect(hMemDC, &wndRect, reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH)));

	Graphics graphics(hMemDC);
	m_sceneManager->Render(graphics);

	BitBlt(hDC, 0, 0, wndRect.right, wndRect.bottom, hMemDC, 0, 0, SRCCOPY);

	DeleteObject(hMyBitmap);
	DeleteDC(hMemDC);
	ReleaseDC(GetHWnd(), hDC);
}