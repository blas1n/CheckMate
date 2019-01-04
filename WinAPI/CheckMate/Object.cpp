#include "stdafx.h"
#include "Object.h"

void Object::Create() {
	InitComponents(m_components);

	for (auto iter : *m_components)
		iter->Create();
}

void Object::Init() {
	for (auto iter : *m_components)
		iter->Init();
}

void Object::Update() {
	for (auto iter : *m_components)
		iter->Update();
}

void Object::Clear() {
	for (auto iter : *m_components)
		iter->Clear();
}

void Object::Destroy() {
	for (auto iter : *m_components)
		iter->Destroy();

	Erase(m_components);
}