#include "Motorcycle.h"
#include "cmath"

namespace assignment2
{
	Motorcycle::Motorcycle()
		: Vehicle(2)
	{
	}

	Motorcycle::Motorcycle(Motorcycle& bp)
		: Vehicle(bp.GetMaxPassengersCount())
	{
		unsigned int i;

		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set3(i, bp.GetPassenger(i));
		}
	}

	unsigned int Motorcycle::GetDriveSpeed() const
	{
		double sum;
		double left;

		sum = static_cast<double>(GetSumWeight());
		left = 400 + 2 * sum - (sum / 15) * (sum / 15) * (sum / 15);

		if (left >= 0)
		{
			return static_cast<unsigned int>(left + 0.5);
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

	Motorcycle Motorcycle::operator=(Motorcycle& bp)
	{
		if (*this == bp)
		{
			return *this;
		}

		unsigned int i;

		InitializePassenger2();
		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set2(i, bp.GetPassenger(i));
		}

		return *this;
	}
}