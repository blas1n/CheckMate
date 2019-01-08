#include "Player.h"
#include "Transform.h"

Player::Player(Object* entity)
	: IComponent(entity),
	transform(GetEntity().GetComponent<Transform>()) {}

void Player::Init() {}

void Player::Update() {
	const auto& inputManager = GameDirector::GetGameDirector()->GetInputManager();

	if (inputManager.GetKey(InputManager::Key::LButton))
		transform.SetPos(inputManager.GetMousePos());

	if (inputManager.GetKey(InputManager::Key::Left))
		transform.SetPos(transform.GetPos().GetX() - (300.0f * Time::GetDeltaTime()), transform.GetPos().GetY());

	if (inputManager.GetKey(InputManager::Key::Right))
		transform.SetPos(transform.GetPos().GetX() + (300.0f * Time::GetDeltaTime()), transform.GetPos().GetY());

	if (inputManager.GetKey(InputManager::Key::Up))
		transform.SetPos(transform.GetPos().GetX(), transform.GetPos().GetY() - (300.0f * Time::GetDeltaTime()));

	if (inputManager.GetKey(InputManager::Key::Down))
		transform.SetPos(transform.GetPos().GetX(), transform.GetPos().GetY() + (300.0f * Time::GetDeltaTime()));
}

void Player::Clear() {}