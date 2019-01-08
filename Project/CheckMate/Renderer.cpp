#include "Renderer.h"

Renderer::Renderer(Object* entity)
	: IComponent(entity),
	m_sprite(new Sprite()) {}

void Renderer::Init() {}

void Renderer::Update() {
	m_sprite->Draw(0, 0);
}

void Renderer::Clear() {}

const Sprite& Renderer::GetSprite() const noexcept {
	return *m_sprite;
}

bool Renderer::SetSprite(LPWSTR id) noexcept {
	return m_sprite->LoadSprite(id);
}