#pragma once

#include "IComponent.h"
#include "Vector2.h"

class Transform : public IComponent {
private:
	Utility::Vector2 m_pos;

public:
	Transform(const Object*, const Utility::Vector2 = Utility::Vector2());

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;

public:
	const Utility::Vector2 GetPos() const noexcept;
	void SetPos(const Utility::Vector2) noexcept;
	void SetPos(const float x, const float y) noexcept;
};