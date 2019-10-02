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

		doubleArea = static_cast<double>(mRad) * static_cast<double>(mRad) * 3.14;
		area = static_cast<unsigned int>(doubleArea);
		error = doubleArea - area;

		if (error >= 0.5)
		{
			area++;
		}

		return area;
	}
}
	