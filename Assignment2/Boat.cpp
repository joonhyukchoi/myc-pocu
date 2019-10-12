#include "Boat.h"
#include "Airplane.h"
#include "cmath"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::Boat(Boat& bp)
		: Vehicle(bp.GetMaxPassengersCount())
	{
		unsigned int i;

		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set3(i, bp.GetPassenger(i));
		}
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int sum;
		int left;

		sum = GetSumWeight();
		left = 800 - 10 * sum;
		
		if (left >= 20)
		{
			return left;
		}
		else
		{
			return 20;
		}
	}

	unsigned int Boat::GetMaxSpeed() const
	{
		return GetSailSpeed();
	}

	Boatplane Boat::operator+(Airplane& plane)
	{
		unsigned int sumCurrent;
		unsigned int sumMax;
		unsigned int i;
		unsigned int j;
		unsigned int k;
		
		j = 0;
		k = 0;
		sumCurrent = plane.GetPassengersCount() + this->GetPassengersCount();
		sumMax = plane.GetMaxPassengersCount() + this->GetMaxPassengersCount();

		Boatplane bp(sumMax);
	
		for (i = 0; i < plane.GetPassengersCount(); i++)
		{ 
			bp.AddPassenger(plane.GetPassenger(i));
			k = i;
		}

		for (i = k - 1; i < sumCurrent; i++)
		{
			bp.AddPassenger(this->GetPassenger(j));
			j++;
		}

		plane.InitializePassenger();
		this->InitializePassenger();

		return bp;
	}

	eTravelName Boat::GetName() const
	{
		return BOAT;
	}

	Boat Boat::operator=(Boat& bp)
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