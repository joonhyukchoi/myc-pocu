#pragma once
#include "Vehicle.h"
#include "IDrivable.h"
#include "Trailer.h"

namespace assignment2
{
	class Trailer;

	class Sedan : public Vehicle, public IDrivable, public Trailer
	{
	public:
		Sedan();
		~Sedan();

		bool AddTrailer(const Trailer* trailer);
		bool RemoveTrailer();
		unsigned int GetDriveSpeed() const;
		unsigned int GetMaxSpeed() const;
		eTravelName GetName() const;
		Sedan operator=(Sedan& bp);

	private:
		const Trailer* mTr;
	};
}