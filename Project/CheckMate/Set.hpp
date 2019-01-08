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
	auto& sceneManager = GameDirector::GetGameDirector()->GetSceneManager();

	sceneManager.RegisterScene("Title", std::make_shared<Scene>());
	sceneManager.ReserveChangeScene("Title");

	auto& player = sceneManager.GetScene("Title").AddObject("Player");
	player.AddComponent<Renderer>().SetSprite(MAKEINTRESOURCE(IDB_PNG1));
}