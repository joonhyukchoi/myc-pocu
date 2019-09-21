#include <iostream>

#include "TimeSheet.h"

int main()
{
	lab3::TimeSheet employee1("John", 10);
	employee1.AddTime(4);
	employee1.AddTime(7);
	employee1.AddTime(6);
	employee1.AddTime(5);
	employee1.AddTime(1);
	employee1.AddTime(2);
	std::cout << "Employee: " << employee1.GetName() 
		<< " / AverageTime: " << employee1.GetAverageTime() 
		<< " / TotalTime: " << employee1.GetTotalTime()
		<< " / TotalTime: " << employee1.GetTimeEntry(1)
		<< " / TotalTime: " << employee1.GetStandardDeviation()
		<< std::endl;

	return 0;
}