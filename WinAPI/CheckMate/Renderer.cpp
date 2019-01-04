#include "Renderer.h"
#include "resource.h"

void Renderer::Create() {
	sprite = new Sprite(MAKEINTRESOURCE(IDB_PNG1));
}

void Renderer::Init() {

}

void Renderer::Update() {
	sprite->Draw(0, 0);
}

void Renderer::Clear() {

}

void Renderer::Destroy() {

}