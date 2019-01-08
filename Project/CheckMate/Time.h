#pragma once

#include "GameDirector.h"

class Time {
private:
	Time() = default;
	~Time() = default;

	friend void GameDirector::Process();

public:
	static Time* GetTime();

public:
	float deltaTime;
	float GetDeltaTime() const noexcept;

private:
	void SetDeltaTime(float) noexcept;
};

