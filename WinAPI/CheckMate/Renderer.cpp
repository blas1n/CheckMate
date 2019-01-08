#include "Renderer.h"
#include "resource.h"

void Renderer::Init() {
	sprite = new Sprite(MAKEINTRESOURCE(IDB_PNG1));
}

void Renderer::Update() {
	sprite->Draw(0, 0);
}

void Renderer::Clear() {

}