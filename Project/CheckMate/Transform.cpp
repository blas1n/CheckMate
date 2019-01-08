#include "Transform.h"

Transform::Transform(const Object* entity, const Utility::Point pos)
	: IComponent(entity),
	m_pos(pos) {}

void Transform::Init() {}

void Transform::Update() {}

void Transform::Clear() {}

const Utility::Point Transform::GetPos() const noexcept {
	return m_pos;
}

void Transform::SetPos(const Utility::Point pos) noexcept {
	m_pos = pos;
}