#include "RectangleLawn.h"

namespace lab5
{
	RectangleLawn::RectangleLawn(unsigned int width, unsigned int height)
		: mWidth(width)
		, mHeight(height)
	{
		mArea = GetArea();
	}

	unsigned int RectangleLawn::GetArea() const
	{
		unsigned int area = 0;

		area = mWidth * mHeight;

		return area;
	}

	unsigned int RectangleLawn::GetMinimumFencesCount() const
	{
		unsigned int countW = 0;
		double doubleCountW = 0;
		double errorW = 0;
		unsigned int countH = 0;
		double doubleCountH = 0;
		double errorH = 0;

		doubleCountW = static_cast<double>(mWidth) / 0.25;
		countW = static_cast<unsigned int>(doubleCountW);
		errorW = doubleCountW - countW;
		doubleCountH = static_cast<double>(mHeight) / 0.25;
		countH = static_cast<unsigned int>(doubleCountH);
		errorH = doubleCountH - countH;

		countW = countW * 2;
		countH = countH * 2;

		if (mWidth == 0)
		{
			countW = 0;
		}

		if (mWidth == 0)
		{
			countH = 0;
		}

		return countW + countH;
	}

	unsigned int RectangleLawn::GetFencePrice(eFenceType fenceType) const
	{
		unsigned int price = 0;
		unsigned int count = GetMinimumFencesCount();

		switch (fenceType)
		{
		case RED_CEDAR:
			price = count * 6 / 4;
			break;
		case SPRUCE:
			price = count * 7 / 4;
			break;
		default:
			break;
		}

		return price;
	}

}