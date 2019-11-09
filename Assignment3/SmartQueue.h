#pragma once
#include <queue>
#include <limits>
#include <stack>
#include <cmath>
#include <iostream>

namespace assignment3
{
	template<typename T>
	class SmartQueue
	{
	public:
		SmartQueue();
		SmartQueue<T> operator=(const SmartQueue<T>& ss);
		void Enqueue(T num);
		T Peek();
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
		//void Test(T num);

	private:
		std::queue<T> mNum;
		T mSum;
		T mSum2;
	};

	//template<typename T>
	//void SmartQueue<T>::Test(T num)
	//{
	//	std::stack<T> asd;
	//	asd.push(0);
	//	mTest.push(asd);
	//	mTest.front().push(num);
	//}

	template<typename T>
	SmartQueue<T>::SmartQueue()
		: mSum(0)
		, mSum2(0)
	{
	}

	template<typename T>
	SmartQueue<T> SmartQueue<T>::operator=(const SmartQueue<T>& ss)
	{
		mSum = ss.mSum;
		mSum2 = ss.mSum2;
		mNum = ss.mNum;
	}

	template<typename T>
	void SmartQueue<T>::Enqueue(T num)
	{
		mSum += num;
		mSum2 += num * num;
		mNum.push(num);
	}

	template<typename T>
	T SmartQueue<T>::Peek()
	{
		return mNum.front();
	}

	template<typename T>
	T SmartQueue<T>::Dequeue()
	{
		T value = mNum.front();
		mSum -= mNum.front();
		mSum2 -= mNum.front() * mNum.front();
		mNum.pop();

		return value;
	}

	template<typename T>
	T SmartQueue<T>::GetMax() const
	{
		if (mNum.empty())
		{
			return std::numeric_limits<T>::lowest();
		}
		else
		{
			std::queue<T> copy = mNum;
			unsigned int size = copy.size();
			T max = copy.front();

			while (size)
			{
				if (copy.front() > max)
				{
					max = copy.front();
				}

				copy.pop();
				--size;
			}

			return max;
		}
	}

	template<typename T>
	T SmartQueue<T>::GetMin() const
	{
		if (mNum.empty())
		{
			return std::numeric_limits<T>::max();
		}
		else
		{
			std::queue<T> copy = mNum;
			unsigned int size = copy.size();
			T min = copy.front();

			while (size)
			{
				if (copy.front() < min)
				{
					min = copy.front();
				}
	
				copy.pop();
				--size;
			}

			return min;
		}
	}

	template<typename T>
	double SmartQueue<T>::GetAverage() const
	{
		double avr;

		avr = mSum / mNum.size();
		avr = std::round(avr * 1000) / 1000;
		return avr;
	}

	template<typename T>
	T SmartQueue<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double SmartQueue<T>::GetVariance() const
	{
		double avr;
		double var;

		avr = mSum / mNum.size();
		avr = std::round(avr * 10000) / 10000;
		var = mSum2 / mNum.size() - avr * avr;
		var = std::round(var * 1000) / 1000;
		return var;
	}

	template<typename T>
	double SmartQueue<T>::GetStandardDeviation() const
	{
		double avr;
		double var;
		double var2;

		avr = mSum / mNum.size();
		avr = std::round(avr * 10000) / 10000;
		var = mSum2 / mNum.size() - avr * avr;
		var = std::round(var * 10000) / 10000;
		var2 = std::round(std::sqrt(var) * 1000) / 1000;
		return var2;
	}

	template<typename T>
	unsigned int SmartQueue<T>::GetCount() const
	{
		return mNum.size();
	}
}