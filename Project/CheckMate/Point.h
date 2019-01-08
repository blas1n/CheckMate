#pragma once

namespace Utility {

	struct Point {
	private:
		int m_x, m_y;

	public:
		Point() = default;
		~Point() = default;

		Point(const int, const int);
		Point(const Point&);

	public:
		int GetX() const noexcept;
		void SetX(int) noexcept;

		int GetY() const noexcept;
		void SetY(int) noexcept;
	};

	Point operator+(const Point&, const Point&);
	Point operator-(const Point&, const Point&);
	Point operator*(const Point&, const Point&);
	Point operator/(const Point&, const Point&);
	Point operator*(const Point&, const int&);
	Point operator/(const Point&, const int&);
}