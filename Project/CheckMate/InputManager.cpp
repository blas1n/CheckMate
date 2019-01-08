#include "InputManager.h"

bool InputManager::GetKey(Key key) const noexcept {
	return GetAsyncKeyState(static_cast<int>(key)) & 0x8000;
}

Utility::Point InputManager::GetMousePos() const noexcept {
	return m_mousePos;
}

void InputManager::SetMousePos(Utility::Point pos) noexcept {
	m_mousePos = pos;
}

Utility::Point InputManager::m_mousePos{};