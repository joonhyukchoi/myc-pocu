#include "Boat.h"
#include "Airplane.h"
#include "cmath"

namespace assignment2
{
	Boat::Boat(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boat::~Boat()
	{
	}

	unsigned int Boat::GetSailSpeed() const
	{
		unsigned int sum;
		unsigned int left;

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

		plane.PassengerInitialize(); 
		this->PassengerInitialize();

		return bp;
	}

	eTravelName Boat::GetName() const
	{
		return BOAT;
	}

}