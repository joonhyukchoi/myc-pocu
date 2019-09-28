#pragma once

namespace lab4
{
	class Point
	{
	public:
		Point(float x, float y);
		Point(Point& point);
		~Point();

		Point operator+(const Point& other) const;
		Point operator-(const Point& other) const;
		float Dot(const Point& other) const;
		Point operator*(float operand) const;
		friend Point operator*(float operand, const Point& p);

		float GetX() const;
		float GetY() const;
		void SetX(const float x);
		void SetY(const float y);
	
	private:
		float mx;
		float my;

	};
}