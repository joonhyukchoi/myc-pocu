#include "Vehicle.h"
#include "Boatplane.h"

namespace assignment2
{
	Vehicle::Vehicle(unsigned int maxPassengersCount)
		: mCountMax(maxPassengersCount)
		, mCountCurrent(0)
		, mSumWeight(0)
		, mPerson()
	{
		unsigned int i;
		
		for (i = 0; i < 100; i++)
		{
			mPerson[i] = nullptr;
		}
	}

	Vehicle::~Vehicle()
	{
		unsigned int i;

		for (i = 0; i < mCountCurrent; i++)
		{
			if (mPerson[i] == nullptr)
			{
				break;
			}
			delete mPerson[i];
		}
	}

	bool Vehicle::AddPassenger(const Person* person)
	{
		if (person == nullptr)
		{
			return false;
		}

		mPerson[mCountCurrent] = person;
		mCountCurrent++;
		mSumWeight += person->GetWeight();

		return true;
	}

	bool Vehicle::AddPassenger2(const Person* person)
	{
		if (person == nullptr)
		{
			return false;
		}

		mPerson[mCountCurrent] = new Person(person);
		mCountCurrent++;
		mSumWeight += person->GetWeight();

		return true;
	}

	bool Vehicle::RemovePassenger(unsigned int i)
	{
		if (i > mCountCurrent - 1)
		{
			return false;
		}

		delete mPerson[i];
		unsigned int cnt;

		for (cnt = i; cnt < mCountCurrent; cnt++)
		{
			mPerson[cnt] = mPerson[cnt + 1];
		}

		mPerson[mCountCurrent - 1] = nullptr;

		return true;
	}

	unsigned int Vehicle::GetPassengersCount() const
	{
		return mCountCurrent;
	}

	unsigned int Vehicle::GetMaxPassengersCount() const
	{
		return mCountMax;
	}

	const Person* Vehicle::GetPassenger(unsigned int i) const
	{
		return mPerson[i];
	}

	unsigned int Vehicle::GetSumWeight() const
	{
		return mSumWeight;
	}

	void Vehicle::PassengerInitialize()
	{
		mCountMax = 0;
		mCountCurrent = 0;
	}

	void Vehicle::PassengerInitialize2()
	{
		unsigned int i;

		for (i = 0; i < mCountCurrent; i++)
		{
			if (mPerson[i] == nullptr)
			{
				break;
			}
			delete mPerson[i];
		}
	}

	void Vehicle::Setter(unsigned int max, unsigned int current, unsigned int sum)
	{
		mCountMax = max;
		mCountCurrent = current;
		mSumWeight = sum;
	}

	void Vehicle::Setter2(unsigned int i, const Person* ps)
	{
		mPerson[i] = new Person(ps);
	}

}