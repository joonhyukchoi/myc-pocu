#pragma once
#include <string>

namespace assignment2
{
	class Person
	{
	public:
		Person(const char* name, unsigned int weight);
		Person(const Person* ps);
		~Person();

		const std::string& GetName() const;
		char* GetName2() const;
		unsigned int GetWeight() const;
		bool operator==(const Person& ps) const;

	private:
		char* mName;
		unsigned int mWeight;
		std::string mName2;
	};
}