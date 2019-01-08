#pragma once

#include "IComponent.h"
#include "Point.h"

class Transform : public IComponent {
private:
	Utility::Point m_pos;

public:
	Transform(const Object*, const Utility::Point = Utility::Point());

public:
	virtual void Init() override;
	virtual void Update() override;
	virtual void Clear() override;

public:
	const Utility::Point GetPos() const noexcept;
	void SetPos(const Utility::Point) noexcept;
	void SetPos(const float x, const float y) noexcept;
};