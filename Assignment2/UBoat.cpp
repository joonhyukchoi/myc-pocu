#include "UBoat.h"
#include "cmath"

namespace assignment2
{
	UBoat::UBoat()
		: Vehicle(50)
	{
	}

	UBoat::UBoat(UBoat& bp)
		: Vehicle(bp.GetMaxPassengersCount())
	{
		unsigned int i;

		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set3(i, bp.GetPassenger(i));
		}
	}

	unsigned int UBoat::GetSailSpeed() const
	{
		unsigned int sum;
		double left;

		sum = GetSumWeight();
		left = 550 - static_cast<double>(sum) / 10;

		if (left >= 195.5)
		{
			return static_cast<unsigned int>(left + 0.5);
		}
		else
		{
			return 200;
		}
	}

	unsigned int UBoat::GetDiveSpeed() const
	{
		unsigned int sum;
		unsigned int speed;
		double logx;
		double sum2;

		sum = GetSumWeight();
		logx = log((150 + static_cast<double>(sum)) / 150);
		sum2 = 500 * logx + 30;
		speed = static_cast<unsigned int>(sum2 + 0.5);

		return speed;
	}

	unsigned int UBoat::GetMaxSpeed() const
	{
		unsigned int sailSpeed;
		unsigned int diveSpeed;

		sailSpeed = GetSailSpeed();
		diveSpeed = GetDiveSpeed();

		if (diveSpeed >= sailSpeed)
		{
			return diveSpeed;
		}
		else
		{
			return sailSpeed;
		}
	}

	UBoat::~UBoat()
	{
	}

	eTravelName UBoat::GetName() const
	{
		return UBOAT;
	}

	UBoat UBoat::operator=(UBoat& bp)
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
			Set3(i, bp.GetPassenger(i));
		}

		return *this;
	}
}