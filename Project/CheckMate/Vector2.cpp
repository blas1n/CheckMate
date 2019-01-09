#include "Vector2.h"
#include "Math.h"

namespace Utility {

	Vector2::Vector2(const float x, const float y)
		: m_x(x), m_y(y) {}

	void Vector2::Set(const float x, const float y) noexcept {
		m_x = x;
		m_y = y;
	}

	float Vector2::GetX() const noexcept {
		return m_x;
	}

	void Vector2::SetX(const float x) noexcept {
		m_x = x;
	}

	float Vector2::GetY() const noexcept {
		return m_y;
	}

	void Vector2::SetY(const float y) noexcept {
		m_y = y;
	}

	Vector2 Vector2::operator+=(const Vector2& rhs) noexcept {
		return (*this = *this + rhs);
	}

	Vector2 Vector2::operator-=(const Vector2& rhs) noexcept {
		return (*this = *this - rhs);
	}

	Vector2 Vector2::operator*=(const float& rhs) noexcept {
		return (*this = *this * rhs);
	}

	Vector2 Vector2::operator/=(const float& rhs) noexcept {
		return (*this = *this / rhs);
	}

	float Vector2::GetLength() const noexcept {
		return std::sqrtf(m_x * m_x + m_y * m_y);
	}

	float Vector2::GetSqrLength() const noexcept {
		return m_x * m_x + m_y * m_y;
	}

	Vector2 Vector2::GetNormalize() const noexcept {
		return (*this / GetLength());
	}

	Vector2& Vector2::Normalize() noexcept {
		*this /= GetLength();
		return *this;
	}

	Vector2 operator+(const Vector2& lhs, const Vector2& rhs) {
		return Vector2(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
	}

	Vector2 operator-(const Vector2& lhs, const Vector2& rhs) {
		return Vector2(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY());
	}

	Vector2 operator*(const Vector2& lhs, const float& rhs) {
		return Vector2(lhs.GetX() * rhs, lhs.GetY() * rhs);
	}

	Vector2 operator/(const Vector2& lhs, const float& rhs) {
		return Vector2(lhs.GetX() / rhs, lhs.GetY() / rhs);
	}

	bool operator==(const Vector2& lhs, const Vector2& rhs) {
		return (lhs.GetX() == rhs.GetX()) && (lhs.GetY() == rhs.GetY());
	}

	bool operator!=(const Vector2& lhs, const Vector2& rhs) {
		return !(lhs == rhs);
	}

	float Dot(const Vector2& lhs, const Vector2& rhs) {
		return lhs.GetX() * rhs.GetX() + lhs.GetY() * rhs.GetY();
	}

	Vector2 Max(const Vector2& lhs, const Vector2& rhs) {
		return (lhs.GetX() - rhs.GetX()) + (lhs.GetY() - rhs.GetY()) > 0 ? lhs : rhs;
	}

	Vector2 Min(const Vector2& lhs, const Vector2& rhs) {
		return Max(lhs, rhs) == rhs ? lhs : rhs;
	}

	float GetAngle(const Vector2& lhs, const Vector2& rhs) {
		return std::Rad2Deg(std::acosf(Dot(lhs.GetNormalize(), rhs.GetNormalize())));
	}

	float GetDistance(const Vector2& lhs, const Vector2& rhs) {
		return (lhs - rhs).GetLength();
	}

}