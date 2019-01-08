#pragma once

namespace Utility {

	struct Point {
	private:
		float m_x, m_y;

	public:
		Point() = default;
		~Point() = default;

		Point(const float, const float);
		Point(const Point&);

	public:
		float GetX() const noexcept;
		void SetX(float) noexcept;

		float GetY() const noexcept;
		void SetY(float) noexcept;
	};

	Point operator+(const Point&, const Point&);
	Point operator-(const Point&, const Point&);
	Point operator*(const Point&, const Point&);
	Point operator/(const Point&, const Point&);
	Point operator*(const Point&, const float&);
	Point operator/(const Point&, const float&);
}