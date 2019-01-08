#include "stdafx.h"
#include "Object.h"
#include "Transform.h"

Object::Object(std::string name, const Utility::Point pos)
	: m_name(name),
	m_components() {

	AddComponent<Transform>().SetPos(pos);
}

void Object::Init() {
	for (auto iter : m_components)
		iter->Init();
}

void Object::Update() {
	for (auto iter : m_components)
		iter->Update();
}

void Object::Clear() {
	for (auto iter : m_components)
		iter->Clear();
}

const std::string& Object::GetName() const noexcept {
	return m_name;
}