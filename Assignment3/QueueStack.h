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
		void Enqueue(T num);
		T Peek();
		T Dequeue();
		T GetMax() const;
		T GetMin() const;
		double GetAverage() const;
		T GetSum() const;
		unsigned int GetCount() const;
		unsigned int GetStackCount() const;

	private:
		std::queue<std::stack<T>> mNum;
		T mSum;
		unsigned int mSize;
		unsigned int mCnt;
		unsigned int mStackCnt;
	};


	template<typename T>
	QueueStack<T>::QueueStack(unsigned int init)
		: mSum(0)
		, mSize(init)
		, mCnt(0)
		, mStackCnt(0)
	{
	}

	template<typename T>
	void QueueStack<T>::Enqueue(T num)
	{
		mSum += num;

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