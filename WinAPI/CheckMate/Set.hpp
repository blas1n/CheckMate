#include "GameDirector.h"
#include "SceneManager.h"
#include "SettingValue.h"
#include "Object.h"
#include "Sprite.h"
#include "resource.h"
#include "Renderer.h"
#include <memory>

void SettingWindow(SettingValue& value) {
	value.lpszClassName = value.lpszMenuName = TEXT("CheckMate");

	value.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	value.hCursor = LoadCursor(nullptr, IDC_ARROW);
	value.hIcon = LoadIcon(value.hInstance, MAKEINTRESOURCE(IDI_ICON1));
}

void SettingGame() {
	auto objList = { Object(std::string("Player")) };
	const_cast<Object*>(objList.begin())->AddComponent<Renderer>();

	auto& sceneManager = GameDirector::GetGameDirector()->GetSceneManager();

	sceneManager.RegisterScene("Title", std::make_shared<Scene>(objList));
	sceneManager.ReserveChangeScene("Title");
}