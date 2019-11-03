#pragma once

#include <iostream>
#include <vector>
#include <map>

namespace lab7
{
	template <typename K, class V>
	std::map<K, V> ConvertVectorsToMap(const std::vector<K>& keys, const std::vector<V>& values)
	{
		std::map<K, V> m;
		size_t sz;

		if (keys.size() > values.size())
		{
			sz = values.size();
		}
		else
		{
			sz = keys.size();
		}

		for (size_t i = 0; i < sz; i++)
		{
			m.insert(std::pair<K, V>(keys[i], values[i]));
		}

		return m;
	}

	template <typename K, class V>
	std::vector<K> GetKeys(const std::map<K, V>& m)
	{
		std::vector<K> v;

		v.reserve(m.size());

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->first);
		}
		
		return v;
	}

	template <typename K, class V>
	std::vector<V> GetValues(const std::map<K, V>& m)
	{
		std::vector<V> v;

		v.reserve(m.size());

		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			v.push_back(iter->second);
		}

		return v;
	}

	template <typename T>
	std::vector<T> Reverse(const std::vector<T>& v)
	{
		std::vector<T> rv;

		rv.reserve(v.size());

		for (typename std::vector<T>::const_reverse_iterator iter = v.rbegin(); iter != v.rend(); ++iter)
		{
			rv.push_back(*iter);
		}

		return rv;
	}

	template <typename T>
	std::vector<T> operator+(const std::vector<T>& v1, const std::vector<T>& v2)
	{
		std::vector<T> combined;
		bool bFlag;
	
		bFlag = false;
		combined.reserve(v1.size() + v2.size());

		for (typename std::vector<T>::const_iterator itr = v1.begin(); itr != v1.end(); ++itr)
		{
			for (typename std::vector<T>::const_iterator itr2 = v1.begin(); itr2 != itr; ++itr2)
			{
				if (*itr == *itr2)
				{
					bFlag = true;
				}
			}

			if (bFlag == false)
			{
				combined.push_back(*itr);
			}
			else
			{
				bFlag = false;
			}
		}

		//틀린코드
		//for (typename std::vector<T>::const_iterator itr = combined.begin(); itr != combined.end(); ++itr)
		//{
		//	++cnt;
		//	typename std::vector<T>::const_iterator itr2 = itr + 1;

		//	while (itr2 != combined.end())
		//	{
		//		if (*itr == *itr2)
		//		{
		//			combined.erase(itr2);
		//		}
		//		else
		//		{
		//			++itr2;
		//		}
		//	}
		//}
		bFlag = false;

		for (typename std::vector<T>::const_iterator itr = v2.begin(); itr != v2.end(); ++itr)
		{
			for (typename std::vector<T>::const_iterator itr2 = v1.begin(); itr2 != v1.end(); ++itr2)
			{
				if (*itr == *itr2)
				{
					bFlag = true;
				}
			}
			
			if (bFlag == false)
			{
				combined.push_back(*itr);
			}
			else
			{
				bFlag = false;
			}
		}
			
		return combined;
	}

	template <typename K, class V>
	std::map<K, V> operator+(const std::map<K, V>& m1, const std::map<K, V>& m2)
	{
		std::map<K, V> combined;
		bool bFlag;

		bFlag = false;

		for (typename std::map<K, V>::const_iterator itr = m1.begin(); itr != m1.end(); ++itr)
		{
			combined.insert(std::pair<K, V>(itr->first, itr->second));
		}

		for (typename std::map<K, V>::const_iterator itr = m2.begin(); itr != m2.end(); ++itr)
		{
			for (typename std::map<K, V>::const_iterator itr2 = m1.begin(); itr2 != m1.end(); ++itr2)
			{
				if (itr->first == itr2->first)
				{
					bFlag = true;
				}
			}

			if (bFlag == false)
			{
				combined.insert(std::pair<K, V>(itr->first, itr->second));
			}
			else
			{
				bFlag = false;
			}
		}

		return combined;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& v)
	{
		for (typename std::vector<T>::const_iterator iter = v.begin(); iter != v.end(); ++iter)
		{
			if (iter == v.end() - 1)
			{
				os << *iter;
				break;
			}

			os << *iter << ", ";
		}

		return os;
	}

	template <typename K, class V>
	std::ostream& operator<<(std::ostream& os, const std::map<K, V>& m)
	{
		for (typename std::map<K, V>::const_iterator iter = m.begin(); iter != m.end(); ++iter)
		{
			os << "{ " << iter->first << ", " << iter->second << " }" << std::endl;
		}

		return os;
	}
}