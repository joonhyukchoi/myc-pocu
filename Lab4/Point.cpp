#include "Point.h"

namespace lab4
{
	Point::Point()
		: mX(0)
		, mY(0)
	{
	}

	Point::Point(float x, float y)
		: mX(x)
		, mY(y)
	{
	}

	Point::Point(const Point& point)
		: mX(point.mX)
		, mY(point.mY)
	{
	}

	Point::~Point()
	{
	}

	Point Point::operator+(const Point& other) const
	{
		float x = mX;
		float y = mY;

		x = mX + other.mX;
		y = mY + other.mY;
		return Point(x, y);
	}

	Point Point::operator-(const Point& other) const
	{
		float x = mX;
		float y = mY;

		x = mX - other.mX;
		y = mY - other.mY;
		return Point(x, y);
	}

	float Point::Dot(const Point& other) const
	{
		float x = mX;
		float y = mY;

		x = mX * other.mX;
		y = mY * other.mY;
		return x + y;
	}

	Point Point::operator*(float operand) const
	{
		float x = mX;
		float y = mY;

		x = mX * operand;
		y = mY * operand;
		return Point(x, y);
	}

	Point operator*(float operand, const Point& p)
	{
		return Point(operand * p.mX, operand * p.mY);
	}

	Point Point::operator=(const Point& other)
	{
		mX = other.mX;
		mY = other.mY;

		return Point(mX, mY);
	}

	float Point::GetX() const
	{
		return mX;
	}

	float Point::GetY() const
	{
		return mY;
	}

	void Point::SetX(const float x)
	{
		mX = x;
	}

	void Point::SetY(const float y)
	{
		mY = y;
	}

}