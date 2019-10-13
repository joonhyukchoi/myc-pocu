#include "DeusExMachina.h"
//#include "iostream"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;
	Vehicle* DeusExMachina::mVeh[10] = { nullptr };
	unsigned int DeusExMachina::mCnt = 0;
	unsigned int DeusExMachina::mTravel[10] = { 0 };
	unsigned int DeusExMachina::mTravelGo[10] = { 0 };

	DeusExMachina* DeusExMachina::GetInstance()
	{
		if (mInstance != nullptr)
		{ 
			return mInstance;
		}

		mInstance = new DeusExMachina();
		mCnt = 0;
		unsigned int i;

		for (i = 0; i < 10; i++)
		{
			mTravel[i] = 0;
			mTravelGo[i] = 0;
		}

		return mInstance;
	}

	DeusExMachina::~DeusExMachina()
	{
		unsigned int cnt;
		
		for (cnt = 0; cnt < mCnt; cnt++)
		{
			delete mVeh[cnt];
		}

		delete mInstance;
	}

	void DeusExMachina::Travel() const
	{
		unsigned int i;
		//std::cout << mCnt;
		//std::cout << mCnt << std::endl;
		for (i = 0; i < mCnt; i++)
		{
			mTravel[i]++;
			switch (mVeh[i]->GetName())
			{
			case AIRPLANE:
				if ((mTravel[i] - 1) % 4 == 0)
				{
					mTravelGo[i] += mVeh[i]->GetMaxSpeed();
				}

				break;
			case BOAT:
				if (mTravel[i] % 3 != 0)
				{
					mTravelGo[i] += mVeh[i]->GetMaxSpeed();
				}

				break;
			case BOATPLANE:
				if ((mTravel[i] - 1) % 4 == 0)
				{
					mTravelGo[i] += mVeh[i]->GetMaxSpeed();
				}

				break;
			case UBOAT:
				if ((mTravel[i] - 1) % 6 == 0 || (mTravel[i] - 2) % 6 == 0)
				{
					mTravelGo[i] += mVeh[i]->GetMaxSpeed();
				}

				break;
			case MOTORCYCLE:
				if (mTravel[i] % 6 != 0)
				{
					mTravelGo[i] += mVeh[i]->GetMaxSpeed();
				}

				break;
			case SEDAN:
				if (mTravel[i] % 6 != 0)
				{
					mTravelGo[i] += mVeh[i]->GetMaxSpeed();
				}

				break;
			case SEDANT:
				if (mTravel[i] % 6 != 0 && mTravel[i] % 7 != 0)
				{
					mTravelGo[i] += mVeh[i]->GetMaxSpeed();
				}

				break;
			default:
				break;
			}
		}
	}

	bool DeusExMachina::AddVehicle(Vehicle* vehicle)
	{
		if (vehicle == nullptr)
		{
			return false;
		}

		if (mCnt < 10)
		{
			mVeh[mCnt] = vehicle;
			mTravel[mCnt] = 0;
			mTravelGo[mCnt] = 0;
			++mCnt;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i >= mCnt)
		{
			return false;
		}

		if (i == 0 && mCnt == 1)
		{
			delete mVeh[i];
			mTravel[i] = 0;
			mTravelGo[i] = 0;
			--mCnt;

			return true;
		}

		unsigned int j;
		--mCnt;
		delete mVeh[i];

		for (j = i; j < mCnt; j++)
		{
			mVeh[j] = mVeh[j + 1];
			mTravel[j] = mTravel[j + 1];
			mTravelGo[j] = mTravelGo[j + 1];
		}

		mTravel[mCnt] = 0;
		mTravelGo[mCnt] = 0;

		return true;
	
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		unsigned int max;
		unsigned int i;
		unsigned int num;
		unsigned int nogo;

		num = 0;
		nogo = 0;
		//std::cout << mbFlag << std::endl;
		if (mCnt == 0)
		{
			return NULL;
		}

		for (i = 0; i < mCnt; i++)
		{
			if (mTravelGo[i] == 0)
			{
				++nogo;
			}
		}

		if (nogo == mCnt)
		{
			return mVeh[0];
		}

		//std::cout << mbFlag << std::endl;
		max = mTravelGo[0];

		for (i = 0; i < mCnt; i++)
		{
			if (max <= mTravelGo[i])
			{
				max = mTravelGo[i];
				num = i;
			}
			//std::cout << mTravelGo[i] << std::endl;
		}
		//std::cout << max << std::endl;
		return mVeh[num];
	}

	bool DeusExMachina::operator==(DeusExMachina* deus) const
	{
		if (this != nullptr && deus != nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}