#include "DeusExMachina.h"
//#include "iostream"

namespace assignment2
{
	DeusExMachina* DeusExMachina::mInstance = nullptr;
	Vehicle* DeusExMachina::mVeh[10] = { nullptr };
	unsigned int DeusExMachina::mCnt = 0;
	unsigned int DeusExMachina::mTravel[10] = { 0 };
	unsigned int DeusExMachina::mTravelGo[10] = { 0 };
	bool DeusExMachina::mbFlag = false;

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
		mbFlag = true;
		//std::cout << mCnt;
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
			mCnt++;

			return true;
		}
		else
		{
			return false;
		}
	}

	bool DeusExMachina::RemoveVehicle(unsigned int i)
	{
		if (i == 0 && mCnt == 1)
		{
			delete mVeh[i];
			mTravel[i] = 0;
			mTravelGo[i] = 0;
			mCnt--;
			mbFlag = false;

			return true;
		}

		if (i < mCnt)
		{
			unsigned int j;
			mCnt--;
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
		else
		{
			return false;
		}
	}

	const Vehicle* DeusExMachina::GetFurthestTravelled() const
	{
		unsigned int max;
		unsigned int i;
		unsigned int num;

		num = 0;

		if (mCnt == 0 || mbFlag == false)
		{
			return NULL;
		}

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
	
		return mVeh[i];
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