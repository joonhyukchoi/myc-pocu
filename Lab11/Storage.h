#pragma once
//#include <iostream>
#include <memory>

namespace lab11
{
	template<typename T>
	class Storage
	{
	public:
		Storage(unsigned int length);
		Storage(unsigned int length, const T& initialValue);
		Storage(Storage& s);
		Storage(Storage&& s);
		Storage<T>& operator=(Storage& s);
		Storage<T>& operator=(Storage&& s);

		bool Update(unsigned int index, const T& data);
		const std::unique_ptr<T[]>& GetData() const;
		unsigned int GetSize() const;
		
	private:
		std::unique_ptr<T[]> mArray;
		//T* mArray2;
		unsigned int mLength;
	};

	template<typename T>
	Storage<T>::Storage(unsigned int length)
		: mLength(length)
	{
		mArray = std::make_unique<T[]>(mLength);
	//	mArray2 = new T[mLength];
		for (unsigned int i = 0; i < mLength; i++)
		{
			mArray[i] = 0;
		//	mArray2[i] = 0;
		}
	//	std::cout << mArray[1];
	}

	template<typename T>
	Storage<T>::Storage(unsigned int length, const T& initialValue)
		: mLength(length)
	{
		mArray = std::make_unique<T[]>(mLength);
	//	mArray2 = new T[mLength];
		for (unsigned int i = 0; i < mLength; i++)
		{
			mArray[i] = initialValue;
		//	mArray2[i] = 0;
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage& s)
		: mLength(s.mLength)
	{
		mArray = std::make_unique<T[]>(mLength);

		for (unsigned int i = 0; i < mLength; i++)
		{
			mArray[i] = s.mArray[i];
		}
	}

	template<typename T>
	Storage<T>::Storage(Storage&& s)
		: mLength(s.mLength)
	{
		mArray = std::move(s.mArray);
		s.mLength = 0;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage& s)
	{
		if (this != &s)
		{
			mLength = s.mLength;

			for (unsigned int i = 0; i < mLength; i++)
			{
				mArray[i] = s.mArray[i];
			}
		}

		return *this;
	}

	template<typename T>
	Storage<T>& Storage<T>::operator=(Storage&& s)
	{
		if (this != &s)
		{
			delete mArray;

			mLength = s.mLength;
			mArray = std::move(s.mArray);

			s.mLength = 0;
		}

		return *this;
	}

	template<typename T>
	bool Storage<T>::Update(unsigned int index, const T& data)
	{
		if (index >= mLength)
		{
			return false;
		}
		
		mArray[index] = data;
	}

	template<typename T>
	const std::unique_ptr<T[]>& Storage<T>::GetData() const
	{
		return std::move(mArray);
	}

	template<typename T>
	unsigned int Storage<T>::GetSize() const
	{
		return mLength;
	}
}