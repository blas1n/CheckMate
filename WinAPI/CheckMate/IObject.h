#pragma once

class IObject {
public:
	virtual void Create() = 0;
	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
	virtual void Clear() = 0;
	virtual void Destroy() = 0;
};