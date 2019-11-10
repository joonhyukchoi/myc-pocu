#pragma once
 
namespace lab8
{
	template<typename T, size_t N>
	class FixedVector
	{
	public:
		FixedVector();

		bool Add(const T t);
		bool Remove(const T t);
		T Get(unsigned int num) const;
		T& operator[](unsigned int num);
		int GetIndex(const T t) const;
		size_t GetSize() const;
		size_t GetCapacity() const;

	private:
		size_t mSize;
		T mArray[N];
	};

	template<typename T, size_t N>
	FixedVector<T, N>::FixedVector()
		: mSize(0)
	{
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Add(const T t)
	{
		if (mSize >= N)
		{
			return false;
		}

		mArray[mSize++] = t;

		return true;
	}

	template<typename T, size_t N>
	bool FixedVector<T, N>::Remove(const T t)
	{
		bool bFlag = false;

		for (unsigned int i = 0; i < mSize; ++i)
		{
			if (mArray[i] == t)
			{
				bFlag = true;
			}

			if (bFlag)
			{
				mArray[i] = mArray[i + 1];
			}
		}

		if (bFlag)
		{
			--mSize;
			return true;
		}
		else
		{
			return false;
		}
	}

	template<typename T, size_t N>
	T FixedVector<T, N>::Get(unsigned int num) const
	{
		return mArray[num];
	}

	template<typename T, size_t N>
	T& FixedVector<T, N>::operator[](unsigned int num)
	{
		return mArray[num];
	}

	template<typename T, size_t N>
	int FixedVector<T, N>::GetIndex(const T t) const
	{
		int idx;
		bool bIndex = false;

		for (size_t i = 0; i < mSize; ++i)
		{
			if (mArray[i] == t)
			{
				bIndex = true;
				idx = i;
				break;
			}
		}

		if (bIndex)
		{
			return idx;
		}
		else
		{
			return -1;
		}

	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetSize() const
	{
		return mSize;
	}

	template<typename T, size_t N>
	size_t FixedVector<T, N>::GetCapacity() const
	{
		return N;
	}
}