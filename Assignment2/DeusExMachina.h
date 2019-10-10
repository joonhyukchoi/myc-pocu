#pragma once
#include "Vehicle.h"

namespace assignment2
{
	class DeusExMachina
	{
	public:
		static DeusExMachina* GetInstance();
		void Travel() const;
		bool AddVehicle(Vehicle* vehicle);  
		bool RemoveVehicle(unsigned int i);
		const Vehicle* GetFurthestTravelled() const;
		bool operator==(DeusExMachina* deus) const;
		~DeusExMachina();

	private:
		static DeusExMachina* mInstance;
		static Vehicle* mVeh[10];
		static unsigned int mCnt;
		static unsigned int mTravel[10];
		static unsigned int mTravelGo[10];
	};
}