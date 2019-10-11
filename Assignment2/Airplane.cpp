#include "Airplane.h"
#include "Boat.h"
#include "Boatplane.h"
#include "cmath"
//#include "iostream"

namespace assignment2
{
	Airplane::Airplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Airplane::~Airplane()
	{
	}

	unsigned int Airplane::GetDriveSpeed() const
	{
		unsigned int sum;
		double ex;
		unsigned int speed;

		sum = GetSumWeight();
		ex = exp(static_cast<double>(400 - sum) / 70);
		speed = static_cast<unsigned int>(4 * ex + 0.5);
		
		return speed;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int sum;
		unsigned int speed;
		double numerator;

		sum = GetSumWeight();
		numerator = 800 - sum;
		speed = static_cast<unsigned int>(200 * exp(numerator / 500) + 0.5);

		return speed;
	}

	unsigned int Airplane::GetMaxSpeed() const
	{
		unsigned int driveSpeed;
		unsigned int flySpeed;

		driveSpeed = GetDriveSpeed();
		flySpeed = GetFlySpeed();

		if (driveSpeed >= flySpeed)
		{
			return driveSpeed;
		}
		else
		{
			return flySpeed;
		}
	}

	Boatplane Airplane::operator+(Boat& boat)
	{
		unsigned int sumCurrent;
		unsigned int sumMax;
		unsigned int i;
		unsigned int j;
		unsigned int k;

		j = 0;
		k = 0;
		sumCurrent = boat.GetPassengersCount() + this->GetPassengersCount();
		sumMax = boat.GetMaxPassengersCount() + this->GetMaxPassengersCount();
		
		Boatplane bp(sumMax);
		//std::cout << this->GetPassenger(0) << std::endl;
		//bp.AddPassenger2(this->GetPassenger(0));
		for (i = 0; i < this->GetPassengersCount(); i++)
		{
			bp.AddPassenger2(this->GetPassenger(i));
			k = i;
		}

		for (i = k - 1; i < sumCurrent; i++)
		{
			bp.AddPassenger2(boat.GetPassenger(j));
			j++;
		}
	
		boat.InitializePassenger();
		this->InitializePassenger();

		return bp;
	}

	eTravelName Airplane::GetName() const
	{
		return AIRPLANE;
	}
}