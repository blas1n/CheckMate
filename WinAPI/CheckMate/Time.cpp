#include "Time.h"

Time* Time::GetTime() {
	static Time time;
	return &time;
}

float Time::GetDeltaTime() const noexcept {
	return deltaTime;
}

void Time::SetDeltaTime(float deltaTime) noexcept {
	this->deltaTime = deltaTime;
}