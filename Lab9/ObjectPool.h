#pragma once

#include <vector>

namespace lab9
{
	template<typename T>
	class ObjectPool final
	{
	public:
		ObjectPool(size_t maxPoolSize);
		ObjectPool(const ObjectPool<T>& obj) = delete;
		~ObjectPool();
		ObjectPool<T>& operator=(const ObjectPool<T>& obj)  = delete;
		T* Get();
		void Return(T* obj);
		const size_t GetFreeObjectCount() const;
		const size_t GetMaxFreeObjectCount() const;

	private:
		std::vector<T*> mObject;
		size_t mMaxPoolSize;
		size_t mCurrentPoolSize;
	};

	template<typename T>
	ObjectPool<T>::ObjectPool(size_t maxPoolSize)
		: mMaxPoolSize(maxPoolSize)
		, mCurrentPoolSize(0)
	{
		mObject.reserve(maxPoolSize);
	}

	template<typename T>
	ObjectPool<T>::~ObjectPool()
	{
		for (auto it = mObject.begin(); it != mObject.end(); ++it)
		{
			delete (*it);
		}

		mObject.clear();
	}

	template<typename T>
	T* ObjectPool<T>::Get()
	{
		if (mCurrentPoolSize == 0)
		{
			T* i1 = new T();
			return i1;
		}
		
		T* i1 = mObject[0];

		for (auto it = mObject.begin(); it != mObject.end() - 1; ++it)
		{
			*it = *(it + 1);
		}

		mObject.pop_back();
		--mCurrentPoolSize;
		
		return i1;
	}

	template<typename T>
	void ObjectPool<T>::Return(T* obj)
	{
		if (mCurrentPoolSize == mMaxPoolSize)
		{
			delete obj;
		}
		else
		{
			mObject.push_back(obj);
			++mCurrentPoolSize;
		}
	}
	
		
	template<typename T>
	const size_t ObjectPool<T>::GetFreeObjectCount() const
	{
		return mCurrentPoolSize;
	}

	template<typename T>
	const size_t ObjectPool<T>::GetMaxFreeObjectCount() const
	{
		return mMaxPoolSize;
	}
}
