#include "Lab6.h"

namespace lab6
{
	int Sum(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		int sum = 0;

		for (size_t i = 0; i < v.size(); i++)
		{
			sum += v[i];
		}

		return sum;
	}

	int Min(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MAX;
		}

		int min = v[0];

		for (size_t i = 1; i < v.size(); i++)
		{
			if (min >= v[i])
			{
				min = v[i];
			}
		}

		return min;
	}

	int Max(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return INT_MIN;
		}

		int max = v[0];

		for (size_t i = 1; i < v.size(); i++)
		{
			if (max <= v[i])
			{
				max = v[i];
			}
		}

		return max;
	}

	float Average(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		int sum = Sum(v);
		float avr = static_cast<float>(sum) / static_cast<float>(v.size());

		return avr;
	}

	int NumberWithMaxOccurrence(const std::vector<int>& v)
	{
		if (v.size() == 0)
		{
			return 0;
		}

		std::vector<int> arr;
		arr.reserve(v.size());
		int max = 0;
		int index = 0;
		int cnt = 0;

		for (size_t i = 0; i < v.size(); i++)
		{
			cnt = 0;

			for (size_t j = 0; j < v.size(); j++)
			{
				if (v[i] == v[j])
				{
					++cnt;
				}
			}

			arr.push_back(cnt);
		}

		max = Max(arr);

		for (size_t i = 0; i < arr.size(); i++)
		{
			if (arr[i] == max)
			{
				index = i;
			}
		}

		return v[index];
	}

	void SortDescending(std::vector<int>& v)
	{
		int temp;

		if (v.size() != 0)
		{
			for (size_t i = 0; i < v.size(); i++)
			{
				for (size_t j = i; j < v.size(); j++)
				{
					if (v[i] <= v[j])
					{
						temp = v[i];
						v[i] = v[j];
						v[j] = temp;
					}
				}
			}
		}
	}

}