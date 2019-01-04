#include "Point.h"

namespace Utility {
	Point::Point(const int x, const int y)
		: m_x(x), m_y(y) {}

	Point::Point(const Point& other)
		: m_x(other.GetX()), m_y(other.GetY()) {}

	int Point::GetX() const noexcept {
		return m_x;
	}

	void Point::SetX(int x) noexcept {
		m_x = x;
	}

	int Point::GetY() const noexcept {
		return m_y;
	}

	void Point::SetY(int y) noexcept {
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

	Point operator*(const Point& lhs, const int& rhs) {
		return Point(lhs.GetX() * rhs, lhs.GetY() * rhs);
	}

	Point operator/(const Point& lhs, const int& rhs) {
		return Point(lhs.GetX() / rhs, lhs.GetY() / rhs);
	}
}