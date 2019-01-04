#pragma once

class IComponent {
public:
	IComponent() = default;
	virtual ~IComponent() = default;

public:
	virtual void Create() = 0;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Clear() = 0;
	virtual void Destroy() = 0;
};