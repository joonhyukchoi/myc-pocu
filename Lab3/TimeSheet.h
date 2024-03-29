#pragma once
#include <string>

namespace lab3
{
	class TimeSheet
	{
	public:
		TimeSheet(const char* name, unsigned int maxEntries);
		TimeSheet(const TimeSheet& sheet);
		~TimeSheet();

		void AddTime(int timeInHours);
		int GetTimeEntry(unsigned int index) const;
		int GetTotalTime() const;
		float GetAverageTime() const;
		float GetStandardDeviation() const;
		const std::string& GetName() const;

		TimeSheet& operator=(const TimeSheet sheet);

	private:
		char* mName;
		unsigned int mSize;
		unsigned int mEntries;
		unsigned int* mHours;
		unsigned int mCount;
		std::string mName2;
		//std::string& mName3 = mName2;
	};
}