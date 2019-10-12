#include "Person.h"

namespace assignment2
{
	Person::Person(const char* name, unsigned int weight)
		: mWeight(weight)
	{
		unsigned int len;
		unsigned int i;
		len = strlen(name) + 1;
		
		mName = new char[len];
		memcpy(mName, name, len);

		for (i = 0; i < len - 1; i++)
		{
			mName2 += mName[i];
		}
	}

	Person::Person(const Person* ps)
		: mWeight(ps->GetWeight())
	{
		unsigned int len;
		unsigned int i;
		len = strlen(ps->GetName2()) + 1;

		mName = new char[len];
		memcpy(mName, ps->GetName2(), len);

		for (i = 0; i < len - 1; i++)
		{
			mName2 += mName[i];
		}
	}

	Person::~Person()
	{
		delete[] mName;
	}

	const std::string& Person::GetName() const
	{
		return mName2;
	}

	char* Person::GetName2() const
	{
		return mName;
	}

	unsigned int Person::GetWeight() const
	{
		return mWeight;
	}

	bool Person::operator==(const Person& vc) const
	{
		if (mWeight == vc.mWeight && mName2 == vc.mName2)
		{
			return true;
		}
		else
		{
			return false;

		}
	}
}