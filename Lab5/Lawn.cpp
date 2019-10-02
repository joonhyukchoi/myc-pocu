#include "Lawn.h"

namespace lab5
{
	Lawn::Lawn()
		: mArea(0)
	{
	}

	Lawn::~Lawn()
	{
	}

	unsigned int Lawn::GetGrassPrice(eGrassType grassType) const
	{
		unsigned int price = 0;

		switch (grassType)
		{
		case BERMUDA:
			price = mArea * 800;
			break;
		case BAHIA:
			price = mArea * 500;
			break;
		case BENTGRASS:
			price = mArea * 300;
			break;
		case PERENNIAL_RYEGRASS:
			price = mArea * 250;
			break;
		case ST_AUGUSTINE:
			price = mArea * 450;
			break;
		default:
			break;
		}

		if (price % 100 != 0)
		{
			price = price / 100;
			price = price + 1;
		}
		else
		{
			price = price / 100;
		}

		return price;
	}

	unsigned int Lawn::GetMinimumSodRollsCount() const
	{
		unsigned int count = 0;
		double doubleCount = 0;
		double error = 0;

		count = mArea / 0.3;
		doubleCount = mArea / 0.3;
		error = doubleCount - count;

		if (error != 0)
		{
			count = count + 1;
		}

		if (mArea == 0)
		{
			count = 0;
		}

		return count;
	}
}