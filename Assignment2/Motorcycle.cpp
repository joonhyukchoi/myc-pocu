#include "Motorcycle.h"
#include "cmath"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double sum;
		unsigned int left;

		sum = static_cast<double>(GetSumWeight());
		left = static_cast<unsigned int>(400 + 2 * sum - (sum / 15) * (sum / 15) * (sum / 15) + 0.5);

		if (left >= 0)
		{
			return left;
		}
		else
		{
			return 0;
		}
	}

	unsigned int Motorcycle::GetMaxSpeed() const
	{
		return GetDriveSpeed();
	}

	eTravelName Motorcycle::GetName() const
	{
		return MOTORCYCLE;
	}

	Motorcycle::~Motorcycle()
	{
	}
}