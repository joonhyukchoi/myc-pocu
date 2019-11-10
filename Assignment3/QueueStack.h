#pragma once
#include <queue>
#include <limits>
#include <stack>
#include <cmath>

namespace assignment3
{
	template<typename T>
	class QueueStack
	{
	public:
		QueueStack(unsigned int init);
		~QueueStack();
		//QueueStack(const QueueStack<T>& ss);
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
		unsigned int GetStackCount() const;

	private:
		std::queue<std::stack<T>> mNum;
		T mSum;
		T mSum2;
		unsigned int mSize;
		unsigned int mCnt;
		unsigned int mStackCnt;
	};


	template<typename T>
	QueueStack<T>::QueueStack(unsigned int init)
		: mSum(0)
		, mSum2(0)
		, mSize(init)
		, mCnt(0)
		, mStackCnt(0)
	{
	}

	template<typename T>
	QueueStack<T>::~QueueStack()
	{
	}

	//template<typename T>
	//QueueStack<T>::QueueStack(const QueueStack<T>& ss)
	//	: mSum(ss.mSum)
	//	, mSum2(ss.mSum2)
	//	, mSize(ss.mSize)
	//	, mCnt(ss.mCnt)
	//	, mStackCnt(ss.mStackCnt)
	//	, mNum(ss.mNum)
	//{
	//}

	template<typename T>
	void QueueStack<T>::Enqueue(T num)
	{
		mSum += num;
		mSum2 += num * num;

		if (mNum.empty())
		{
			std::stack<T> st1;
			mNum.push(st1);
			mNum.back().push(num);
			++mStackCnt;
			++mCnt;
		}
		else if (!mNum.empty() && mNum.back().size() < mSize)
		{
			mNum.back().push(num);
			++mCnt;
		}
		else if (!mNum.empty() && mNum.back().size() == mSize)
		{
			std::stack<T> st1;
			mNum.push(st1);
			mNum.back().push(num);
			++mStackCnt;
			++mCnt;
		}
	}

	template<typename T>
	T QueueStack<T>::Peek()
	{
		return mNum.front().top();
	}

	template<typename T>
	T QueueStack<T>::Dequeue()
	{
		T num = mNum.front().top();
		mNum.front().pop();
		mSum -= num;
		mSum2 -= num * num;
		--mCnt;

		if (mNum.front().empty())
		{
			mNum.pop();
			--mStackCnt;
		}

		return num;
	}

	template<typename T>
	T QueueStack<T>::GetMax() const
	{
		if (mNum.empty())
		{
			return std::numeric_limits<T>::lowest();
		}
		else
		{
			unsigned int cnt1 = mCnt;
			unsigned int cnt2 = mStackCnt;
			std::queue<std::stack<T>> copy = mNum;
			T max = copy.front().top();

			while (!copy.empty())
			{
				while (!copy.front().empty())
				{
					if (copy.front().top() > max)
					{
						max = copy.front().top();
					}

					copy.front().pop();
				}

				copy.pop();
			}

			return max;
		}
	}

	template<typename T>
	T QueueStack<T>::GetMin() const
	{
		if (mNum.empty())
		{
			return std::numeric_limits<T>::max();
		}
		else
		{
			unsigned int cnt1 = mCnt;
			unsigned int cnt2 = mStackCnt;
			std::queue<std::stack<T>> copy = mNum;
			T min = copy.front().top();

			while (!copy.empty())
			{
				while (!copy.front().empty())
				{
					if (copy.front().top() < min)
					{
						min = copy.front().top();
					}

					copy.front().pop();
				}

				copy.pop();
			}

			return min;
		}
	}

	template<typename T>
	double QueueStack<T>::GetAverage() const
	{
		double avr;

		avr = static_cast<double>(mSum) / mCnt;
		avr = std::round(avr * 1000) / 1000;
		return avr;
	}

	template<typename T>
	T QueueStack<T>::GetSum() const
	{
		return mSum;
	}

	template<typename T>
	double QueueStack<T>::GetVariance() const
	{
		double avr;
		double var;

		avr = static_cast<double>(mSum) / mCnt;
		avr = std::round(avr * 10000) / 10000;
		var = static_cast<double>(mSum2) / mCnt - avr * avr;
		var = std::round(var * 1000) / 1000;
		return var;
	}

	template<typename T>
	double QueueStack<T>::GetStandardDeviation() const
	{
		double avr;
		double var;
		double var2;

		avr = static_cast<double>(mSum) / mCnt;
		avr = std::round(avr * 10000) / 10000;
		var = static_cast<double>(mSum2) / mCnt - avr * avr;
		var = std::round(var * 10000) / 10000;
		var2 = std::round(std::sqrt(var) * 1000) / 1000;
		return var2;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetCount() const
	{
		return mCnt;
	}

	template<typename T>
	unsigned int QueueStack<T>::GetStackCount() const
	{
		return mStackCnt;
	}
}