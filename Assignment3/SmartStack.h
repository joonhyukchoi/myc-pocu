#pragma once
#include <stack>
#include <limits>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class SmartStack
	{
	public:
		SmartStack();
		void Push(T num);
		T Pop();
		T Peek() const;
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		double GetVariance() const;
		double GetStandardDeviation() const;
		unsigned int GetCount() const;
		
	private:
		std::stack<T> mNum;
		//std::stack<T> mNum2;
		std::stack<T> mMax;
		std::stack<T> mMin;
		T mSum;
		T mSum2;
	};


	template<typename T>
	SmartStack<T>::SmartStack()
		: mSum(0)
		, mSum2(0)
	{
	}

	template<typename T>
	void SmartStack<T>::Push(T num)
	{
		//double num2 = num 
		if (!mNum.empty())
		{
			if (num > mMax.top())
			{
				mMax.push(num);
			}
			else
			{
				mMax.push(mMax.top());
			}

			if (num < mMin.top())
			{
				mMin.push(num);
			}
			else
			{
				mMin.push(mMin.top());
			}

			mSum += num;
			mSum2 += num * num;
		}
		else
		{
			mMax.push(num);
			mMin.push(num);
			mSum = num;
			mSum2 = num * num;
		}

		mNum.push(num);
	}

	template<typename T>
	T SmartStack<T>::Pop()
	{
		T tp = mNum.top();

		mSum -= mNum.top();
		mSum2 -= mNum.top() * mNum.top();
		mNum.pop();
		mMax.pop();
		mMin.pop();
		return tp;
	}

	template<typename T>
	T SmartStack<T>::Peek() const
	{
		return mNum.top();
	}

	template<typename T>
	T SmartStack<T>::GetMax() const
	{
		if (!mNum.empty())
		{
			return mMax.top();
		}
		else
		{
			return std::numeric_limits<T>::lowest();
		}
	}

	template<typename T>
	T SmartStack<T>::GetMin() const
	{
		if (!mNum.empty())
		{
			return mMin.top();
		}
		else
		{
			return std::numeric_limits<T>::max();
		}
	}

	template<typename T>
	double SmartStack<T>::GetAverage() const
	{
		double avr;

		avr = static_cast<double>(mSum) / mNum.size();
		avr = std::round(avr * 1000) / 1000;
		return avr;
	}

	template<typename T>
	T SmartStack<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double SmartStack<T>::GetVariance() const
	{
		double avr;
		double var;

		avr = static_cast<double>(mSum) / mNum.size();
		avr = std::round(avr * 10000) / 10000;
		var = static_cast<double>(mSum2) / mNum.size() - avr * avr;
		var = std::round(var * 1000) / 1000;
		return var;
	}

	template<typename T>
	double SmartStack<T>::GetStandardDeviation() const
	{
		double avr;
		double var;
		double var2;

		avr = static_cast<double>(mSum) / mNum.size();
		avr = std::round(avr * 10000) / 10000;
		var = static_cast<double>(mSum2) / mNum.size() - avr * avr;
		var = std::round(var * 10000) / 10000;
		var2 = std::round(std::sqrt(var) * 1000) / 1000;
		return var2;
	}

	template<typename T>
	unsigned int SmartStack<T>::GetCount() const
	{
		return mNum.size();
	}
}