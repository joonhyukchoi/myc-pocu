#include "Point.h"

namespace lab4
{
	Point::Point(float x, float y)
		: mx(x)
		, my(y)
	{
	}

	Point::Point(Point& point)
		: mx(point.mx)
		, my(point.my)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		float x = mx;
		float y = my;

		x = mx + other.mx;
		y = my + other.my;
		return Point(x, y);
	}

	Point Point::operator-(const Point& other) const
	{
		float x = mx;
		float y = my;

		x = mx - other.mx;
		y = my - other.my;
		return Point(x, y);
	}

	float Point::Dot(const Point& other) const
	{
		float x = mx;
		float y = my;

		x = mx * other.mx;
		y = my * other.my;
		return x + y;
	}

	Point Point::operator*(float operand) const
	{
		float x = mx;
		float y = my;

		x = mx * operand;
		y = my * operand;
		return Point(x, y);
	}

	Point operator*(float operand, const Point& p)
	{
		return Point(operand * p.mx, operand * p.my);
	}

	float Point::GetX() const
	{
		return mx;
	}

	float Point::GetY() const
	{
		return my;
	}

	void Point::SetX(const float x)
	{
		mx = x;
	}

	void Point::SetY(const float y)
	{
		my = y;
	}

}