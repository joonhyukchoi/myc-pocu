#pragma once
#include "Vehicle.h"
#include "ISailable.h"
#include "IDivable.h"

namespace assignment2
{
	class UBoat : public Vehicle, public ISailable, public IDivable
	{
	public:
		UBoat();
		UBoat(UBoat& bp);
		~UBoat();

		unsigned int GetSailSpeed() const;
		unsigned int GetDiveSpeed() const;
		unsigned int GetMaxSpeed() const;
		eTravelName GetName() const;
		UBoat operator=(UBoat& bp);
	};
}