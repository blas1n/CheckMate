#include "stdafx.h"
#include "Object.h"

Object::Object(std::string name)
	: m_name(name),
	m_components() {}

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