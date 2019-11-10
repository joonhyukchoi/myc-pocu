#pragma once
#include <cstdint>

namespace lab8
{
	template<size_t N>
	class FixedVector<bool, N>
	{
	public:
		FixedVector();

		bool Add(bool t);
		bool Remove(bool t);
		bool Get(int32_t num) const;
		bool operator[](int32_t num);
		int32_t GetIndex(bool t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		int32_t mArray[(N + 31) / 32];
	};

	template<size_t N>
	FixedVector<bool, N>::FixedVector()
		: mSize(0)
	{
		for (size_t i = 0; i < (N + 31) / 32; ++i)
		{
			mArray[i] = 0;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::Add(bool t)
	{
		if (mSize >= N)
		{
			return false;
		}

		if (t)
		{
			mArray[mSize / 32] |= (1 << mSize++);
		}
		else
		{
			mArray[mSize / 32] &= ~(1 << mSize++);
		}

		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Remove(bool t)
	{
		int32_t idx = 1 << 0;
		size_t i = 0;
		bool bFlag = false;
		bool bFlag2 = false;

		for (i; i < mSize; ++i)
		{
			idx *= 2;

			if (i % 32 == 0)
			{
				idx = 1 << 0;
			}

			bFlag = mArray[i / 32] & idx;

			if (t == bFlag)
			{
				bFlag2 = true;
				break;
			}
		}

		if (!bFlag2)
		{
			return false;
		}

		int32_t idx2 = GetIndex(t) % 32;
		int32_t num1 = 1 << 0;
		int32_t num2 = 0;

		for (int32_t i = 0; i < idx2; ++i)
		{
			num1 *= 2;
		}

		num1 -= 1;
		num2 = mArray[i / 32] & num1;
		num1 = (~num1) & mArray[i / 32];
		num1 = num1 >> 1;
		mArray[i / 32] = num1 + num2;
		--mSize;

		return true;
	}

	template<size_t N>
	bool FixedVector<bool, N>::Get(int32_t num) const
	{
		int32_t idx = 1;

		for (int32_t i = 0; i < (num % 32); ++i)
		{
			idx *= 2;
		}
		
		if (mArray[num / 32] & idx)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template<size_t N>
	bool FixedVector<bool, N>::operator[](int32_t num)
	{
		int32_t idx = 1;

		for (int32_t i = 0; i < (num % 32); ++i)
		{
			idx *= 2;
		}

		if (mArray[num / 32] & idx)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	template<size_t N>
	int32_t FixedVector<bool, N>::GetIndex(bool t) const
	{
		int32_t idx = 1 << 0;
		bool bFlag;

		for (size_t i = 0; i < mSize; ++i)
		{

			if (i % 32 == 0)
			{
				idx = 1 << 0;
				bFlag = mArray[i / 32] & idx;

				if (t == bFlag)
				{
					return i;
				}

				continue;
			}

			idx = 1 << (i % 32);
			bFlag = mArray[i / 32] & idx;

			if (t == bFlag)
			{
				return i;
			}
		}

		return -1;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetSize() const
	{
		return mSize;
	}

	template<size_t N>
	size_t FixedVector<bool, N>::GetCapacity() const
	{
		return N;
	}
}