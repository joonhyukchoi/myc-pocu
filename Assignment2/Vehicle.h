#pragma once
#include "Person.h"
#include "eTravelName.h"

namespace assignment2
{
	class Vehicle
	{
	public:
		Vehicle(unsigned int maxPassengersCount);
		~Vehicle();

		virtual unsigned int GetMaxSpeed() const = 0; 
		virtual eTravelName GetName() const = 0;

		bool AddPassenger(const Person* person);
		bool AddPassenger2(const Person* person);
		bool RemovePassenger(unsigned int i);
		const Person* GetPassenger(unsigned int i) const;
		unsigned int GetPassengersCount() const;
		unsigned int GetMaxPassengersCount() const;
		unsigned int GetSumWeight() const;
		void PassengerInitialize();
		void PassengerInitialize2();
		void Setter(unsigned int max, unsigned int current, unsigned int sum);
		void Setter2(unsigned int i, const Person* ps);

	private:
		const Person* mPerson[100];
		unsigned int mCountMax;
		unsigned int mCountCurrent;
		unsigned int mSumWeight;
	};
}