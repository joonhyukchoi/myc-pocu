#pragma once
#include "Vehicle.h"
#include "IDrivable.h"

namespace assignment2
{
	class Motorcycle : public Vehicle, public IDrivable
	{
	public:
		Motorcycle();
		Motorcycle(Motorcycle& bp);
		~Motorcycle();

		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		eTravelName GetName() const;
		Motorcycle operator=(Motorcycle& bp);
	};
}