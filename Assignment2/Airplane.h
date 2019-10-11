#pragma once
#include "Vehicle.h"
#include "Boatplane.h"
#include "IDrivable.h"
#include "IFlyable.h"

namespace assignment2
{
	class Boat;

	class Airplane : public Vehicle, public IDrivable, public IFlyable
	{
	public:
		Airplane(unsigned int maxPassengersCount);
		~Airplane();

		unsigned int GetDriveSpeed() const;
		unsigned int GetFlySpeed() const;
		unsigned int GetMaxSpeed() const;
		Boatplane operator+(Boat& boat);
		eTravelName GetName() const;
		Airplane operator=(Airplane& bp);
	};
}