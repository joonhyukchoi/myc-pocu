#include <cmath>
#include "EquilateralTriangleLawn.h"

namespace lab5
{
	EquilateralTriangleLawn::EquilateralTriangleLawn(unsigned int len)
		: mLen(len)
	{
		mArea = GetArea();
	}

	unsigned int EquilateralTriangleLawn::GetArea() const
	{
		unsigned int area = 0;
		double doubleArea = 0;
		double error = 0;

		doubleArea = static_cast<double>(mLen) * static_cast<double>(mLen) * sqrt(3) / 4;
		area = static_cast<unsigned int>(doubleArea);
		error = doubleArea - area;

		if (error >= 0.5)
		{
			area++;
		}

		return area;
	}

	unsigned int EquilateralTriangleLawn::GetMinimumFencesCount() const
	{
		unsigned int count = 0;
		double doubleCount = 0;
		double error = 0;

		doubleCount = static_cast<double>(mLen) / 0.25;
		count = static_cast<unsigned int>(doubleCount);
		error = doubleCount - count;

		count = count * 3;
		
		if (mLen == 0)
		{
			count = 0;
		}

		return count;
	}

	unsigned int EquilateralTriangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int price = 0;

		switch (fenceType)
		{
		case RED_CEDAR:
			price = GetMinimumFencesCount() * 6 / 4;
			break;
		case SPRUCE:
			price = GetMinimumFencesCount() * 7 / 4;
			break;
		default:
			break;
		}

		return price;
	}

}