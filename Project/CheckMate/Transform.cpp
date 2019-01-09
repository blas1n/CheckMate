#include "Transform.h"
#include "GameDirector.h"

Transform::Transform(const Object* entity, const Utility::Vector2 pos)
	: IComponent(entity),
	m_pos(pos) {}

void Transform::Init() {}

void Transform::Update() {}

void Transform::Clear() {}

const Utility::Vector2 Transform::GetPos() const noexcept {
	return m_pos;
}

void Transform::SetPos(const Utility::Vector2 pos) noexcept {
	m_pos = pos;
}

void Transform::SetPos(const float x, const float y) noexcept {
	SetPos(Utility::Vector2(x, y));
}