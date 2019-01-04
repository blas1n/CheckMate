#include "stdafx.h"
#include "TitleScene.h"
#include "resource.h"

void TitleScene::Create() {
	sprite = new Sprite(MAKEINTRESOURCE(IDB_PNG1));
}

void TitleScene::Init() {

}

void TitleScene::Update() {

}

void TitleScene::Render(Graphics& graphics) {
	sprite->Draw(graphics, 0, 0);
}

void TitleScene::Clear() {

}

void TitleScene::Destroy() {

}