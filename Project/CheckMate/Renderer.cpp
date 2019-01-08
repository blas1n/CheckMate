#include "Renderer.h"
#include "Transform.h"
#include "Object.h"

Renderer::Renderer(Object* entity)
	: IComponent(entity),
	m_sprite(new Sprite()) {}

void Renderer::Init() {}

void Renderer::Update() {
	auto pos = GetEntity().GetComponent<Transform>().GetPos();
	m_sprite->Draw(pos.GetX(), pos.GetY());
}

void Renderer::Clear() {}

const Sprite& Renderer::GetSprite() const noexcept {
	return *m_sprite;
}

bool Renderer::SetSprite(LPWSTR id) noexcept {
	return m_sprite->LoadSprite(id);
}