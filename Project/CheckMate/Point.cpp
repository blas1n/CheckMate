#include "Point.h"

namespace Utility {
	Point::Point(const float x, const float y)
		: m_x(x), m_y(y) {}

	Point::Point(const Point& other)
		: m_x(other.GetX()), m_y(other.GetY()) {}

	float Point::GetX() const noexcept {
		return m_x;
	}

	void Point::SetX(float x) noexcept {
		m_x = x;
	}

	float Point::GetY() const noexcept {
		return m_y;
	}

	void Point::SetY(float y) noexcept {
		m_y = y;
	}

	Point operator+(const Point& lhs, const Point& rhs) {
		return Point(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY());
	}

	Point operator-(const Point& lhs, const Point& rhs) {
		return Point(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY());
	}

	Point operator*(const Point& lhs, const Point& rhs) {
		return Point(lhs.GetX() * rhs.GetX(), lhs.GetY() * rhs.GetY());
	}

	Point operator/(const Point& lhs, const Point& rhs) {
		return Point(lhs.GetX() / rhs.GetX(), lhs.GetY() / rhs.GetY());
	}

	Point operator*(const Point& lhs, const float& rhs) {
		return Point(lhs.GetX() * rhs, lhs.GetY() * rhs);
	}

	Point operator/(const Point& lhs, const float& rhs) {
		return Point(lhs.GetX() / rhs, lhs.GetY() / rhs);
	}
}