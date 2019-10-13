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


	Vehicle::Vehicle(Vehicle& vc)
	{
		mCountMax = vc.GetMaxPassengersCount();
		mCountCurrent = vc.GetPassengersCount();
		mSumWeight = vc.GetSumWeight();

		unsigned int i;

		for (i = 0; i < mCountCurrent; i++)
		{
			mPerson[i] = new Person(vc.GetPassenger(i));
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
		unsigned int cnt;

		if (person == nullptr || mCountCurrent == mCountMax)
		{
			return false;
		}

		for (cnt = 0; cnt < mCountCurrent; cnt++)
		{
			if (mPerson[cnt] == person)
			{
				return false;
			}
		}

		mPerson[mCountCurrent] = person;
		mCountCurrent++;
		mSumWeight += person->GetWeight();

		return true;
	}

	bool Vehicle::AddPassenger2(const Person* person)
	{
		if (person == nullptr || mCountCurrent == mCountMax)
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
		if (i >= mCountCurrent)
		{
			return false;
		}

		if (i == 0 && mCountCurrent == 1)
		{
			--mCountCurrent;
			mSumWeight -= mPerson[i]->GetWeight();
			delete mPerson[i];
			mPerson[i] = nullptr;

			return true;
		}

		--mCountCurrent;
		mSumWeight -= mPerson[i]->GetWeight();
		delete mPerson[i];
		unsigned int cnt;

		for (cnt = i; cnt < mCountCurrent; cnt++)
		{
			mPerson[cnt] = mPerson[cnt + 1];
		}

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
		if (i >= mCountCurrent)
		{
			return NULL;
		}

		return mPerson[i];
	}

	unsigned int Vehicle::GetSumWeight() const
	{
		return mSumWeight;
	}

	void Vehicle::InitializePassenger()
	{
		mCountMax = 0;
		mCountCurrent = 0;
		mSumWeight = 0;
	}

	void Vehicle::InitializePassenger2()
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

	void Vehicle::Set(unsigned int max, unsigned int current, unsigned int sum)
	{
		mCountMax = max;
		mCountCurrent = current;
		mSumWeight = sum;
	}

	void Vehicle::Set2(unsigned int i, const Person* ps)
	{
		mPerson[i] = ps;
	}

	void Vehicle::Set3(unsigned int i, const Person* ps)
	{
		mPerson[i] = new Person(ps);
	}

	bool Vehicle::operator==(const Vehicle& vc) const
	{
		unsigned int i;
		unsigned int j = 0;

		if (mCountMax != vc.mCountMax || mCountCurrent != vc.mCountCurrent || mSumWeight != vc.mSumWeight)
		{
			return false;
		}

		if (mCountCurrent == 0 && vc.mCountCurrent == 0)
		{
			return true;
		}

		for (i = 0; i < mCountCurrent; i++)
		{
			if (*mPerson[i] == *vc.mPerson[i])
			{
				j++;
			}
		}

		if (j == mCountCurrent)
		{
			return true;
		}
		else
		{
			return false;

		}
	}

	//Vehicle Vehicle::operator=(Vehicle& bp)
	//{
	//	if (*this == bp)
	//	{
	//		return *this;
	//	}

	//	unsigned int i;

	//	InitializePassenger2();
	//	Set(bp.GetMaxPassengersCount(), bp.GetPassengersCount(), bp.GetSumWeight());

	//	for (i = 0; i < GetPassengersCount(); i++)
	//	{
	//		Set2(i, bp.GetPassenger(i));
	//	}

	//	return *this;
	//}
}