#include "Boatplane.h"
#include "cmath"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::Boatplane(Boatplane& bp)
		: Vehicle(bp.GetMaxPassengersCount())
	{
		unsigned int i;

		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set2(i, bp.GetPassenger(i));
		}
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		unsigned int sum;
		unsigned int speed;
		double ex;

		sum = GetSumWeight();
		ex = exp(static_cast<double>(500 - sum) / 300);
		speed = 150 * static_cast<unsigned int>(ex);

		return speed;
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		unsigned int sum;
		unsigned int left;

		sum = GetSumWeight();
		left = 800 - static_cast< unsigned int>(1.7 * static_cast<double>(sum));

		if (left >= 20)
		{
			return left;
		}
		else
		{
			return 20;
		}
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int sailSpeed;
		unsigned int flySpeed;

		sailSpeed = GetSailSpeed();
		flySpeed = GetFlySpeed();

		if (sailSpeed >= flySpeed)
		{
			return sailSpeed;
		}
		else
		{
			return flySpeed;
		}
	}

	eTravelName Boatplane::GetName() const
	{
		return BOATPLANE;
	}

	Boatplane Boatplane::operator=(Boatplane& bp)
	{
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