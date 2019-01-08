#pragma once

class Object;

class IComponent {
private:
	Object* m_pEntity;

protected:
	const Object& GetEntity() const noexcept {
		return *m_pEntity;
	}

public:
	IComponent() = default;
	virtual ~IComponent() = default;

public:
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;
};