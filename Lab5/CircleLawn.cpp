#include "CircleLawn.h"

namespace lab5
{
	CircleLawn::CircleLawn(unsigned int rad)
		: mRad(rad)
	{
		mArea = GetArea();
	}

	unsigned int CircleLawn::GetArea() const
	{
		unsigned int area = 0;
		double doubleArea = 0;
		double error = 0;

		area = mRad * mRad * 3.14;
		doubleArea = mRad * (double)mRad * 3.14;
		error = doubleArea - area;

		if (error >= 0.5)
		{
			area++;
		}

		return area;
	}
}
	