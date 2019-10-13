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

	Airplane::Airplane(Airplane& bp)
		: Vehicle(bp.GetMaxPassengersCount())
	{
		unsigned int i;

		Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

		for (i = 0; i < GetPassengersCount(); i++)
		{
			Set3(i, bp.GetPassenger(i));
		}
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
		ex = exp((400 - static_cast<double>(sum)) / 70);
		speed = static_cast<unsigned int>(4 * ex + 0.5);
		
		return speed;
	}

	unsigned int Airplane::GetFlySpeed() const
	{
		unsigned int sum;
		unsigned int speed;

		sum = GetSumWeight();
		speed = static_cast<unsigned int>(200 * exp(static_cast<double>(800 - sum) / 500) + 0.5);

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

		j = 0;
		sumCurrent = boat.GetPassengersCount() + this->GetPassengersCount();
		sumMax = boat.GetMaxPassengersCount() + this->GetMaxPassengersCount();
		
		Boatplane bp(sumMax);
		
		for (i = 0; i < this->GetPassengersCount(); i++)
		{
			bp.AddPassenger(this->GetPassenger(i));
		}

		for (i = i - 1; i < sumCurrent; i++)
		{
			bp.AddPassenger(boat.GetPassenger(j));
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

	Airplane Airplane::operator=(Airplane& bp)
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