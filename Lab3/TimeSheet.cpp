#include "TimeSheet.h"
#include <cmath>

namespace lab3
{
	TimeSheet::TimeSheet(const char* name, unsigned int maxEntries)
		: mSize(strlen(name) + 1)
		, mEntries(maxEntries)
		, mCount(0)
	{
		unsigned int i = 0;

		mName = new char[mSize];
		memcpy(mName, name, mSize);
		mHours = new unsigned int[mEntries + 1];
		
		while (i < mSize - 1)
		{
			mName2 += mName[i];
			i++;
		}
		
	}

	TimeSheet::TimeSheet(const TimeSheet& sheet)
		: mSize(sheet.mSize)
		, mEntries(sheet.mEntries)
		, mCount(sheet.mCount)
	{
		unsigned int i = 0;
		unsigned int j = 0;

		mName = new char[sheet.mSize];
		memcpy(mName, sheet.mName, sheet.mSize);
		mHours = new unsigned int[sheet.mEntries + 1];
		
		while (i < sheet.mSize - 1)
		{
			mName2 += mName[i];
			i++;
		}

		while (j < mCount)
		{
			mHours[j] = sheet.mHours[j];
			j++;
		}
	}

	TimeSheet::~TimeSheet()
	{
		delete[] mName;
	}

	void TimeSheet::AddTime(int timeInHours)
	{
		if (timeInHours <= 10 && timeInHours >= 1) 
		{
			if (mCount <= mEntries - 1)
			{
				mHours[mCount] = timeInHours;
				mCount++;
			}
		}
	}

	int TimeSheet::GetTimeEntry(unsigned int index) const
	{
		if (index > mCount - 1 || mCount == 0)
		{
			return -1;
		}

		return mHours[index];
	}

	int TimeSheet::GetTotalTime() const
	{
		int sum = 0;
		unsigned int i = 0;

		while (i <= mCount - 1)
		{
			sum += mHours[i];
			i++;
		}

		return sum;
	}

	float TimeSheet::GetAverageTime() const
	{
		float avr = 0;
		unsigned int i = 0;

		if (mCount > 0)
		{
			while (i <= mCount - 1)
			{
				avr += mHours[i];
				i++;
			}

			avr /= mCount;
		}
		
		return avr;
	}

	float TimeSheet::GetStandardDeviation() const
	{
		float avr = 0;
		float sd = 0;
		unsigned int i = 0;
		unsigned int j = 0;

		if (mCount > 0)
		{
			while (i <= mCount - 1)
			{
				avr += mHours[i];
				i++;
			}

			avr /= mCount;

			while (j <= mCount - 1)
			{
				sd += (mHours[j] - avr) * (mHours[j] - avr);
				j++;
			}

			sd /= mCount;
			sd = sqrt(sd);
		}

		return sd;
	}

	const std::string& TimeSheet::GetName() const
	{	
		const std::string& asd = mName2;
		return asd;
	}
}