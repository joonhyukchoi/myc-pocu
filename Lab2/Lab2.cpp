#include "Lab2.h"
#include <iomanip>

namespace lab2
{
	void PrintIntegers(std::istream& in, std::ostream& out)
	{
		out << "         " << "oct" << "        " << "dec" << "      " << "hex" << "\n";
		out << "------------ " << "---------- " << "--------" << "\n";

		while (true)
		{
			int number;
			in >> number;

			if (!in.fail())
			{
				out << std::uppercase << std::oct << std::setw(12) << number;
				out << std::uppercase << std::dec << std::setw(11) << number;
				out << std::uppercase << std::hex << std::setw(9) << number << std::endl;
			}

			if (in.eof())
			{
				break;
			}

			if (in.fail())
			{
				in.clear();
				in.ignore(LLONG_MAX, ' ');
				continue;
			}
		}
		in.clear();
	}

	void PrintMaxFloat(std::istream& in, std::ostream& out)
	{
		float bigNumber = LLONG_MIN;

		while (true)
		{
			float number;
			in >> number;

			if (!in.fail())
			{
				out << "     ";
				out << std::showpos << std::showpoint << std::setw(15) << std::internal << std::fixed << std::setprecision(3) << number;
				out << std::endl;
			}

			if (number > bigNumber)
			{
				bigNumber = number;
			}

			if (in.eof())
			{
				break;
			}

			if (in.fail())
			{
				in.clear();
				in.ignore(LLONG_MAX, ' ');
				continue;
			}
		}
		in.clear();
		out << "max: ";
		out << std::showpos << std::showpoint << std::setw(15) << std::internal << std::fixed << std::setprecision(3) << bigNumber;
		out << std::endl;
	}
}