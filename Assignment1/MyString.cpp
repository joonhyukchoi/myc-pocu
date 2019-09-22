#include "MyString.h"

namespace assignment1
{
	MyString::MyString(const char* s)
		: mLen(0)
	{	
		unsigned int i = 0;
		
		while (*(s + i) != '\0')
		{
			mLen += 1;
			i++;
		}
		//len은 null값뺀 전체 길이
		mStr = new char[mLen + 1];
		i = 0;

		while (i <= mLen)
		{
			mStr[i] = s[i];
			i++;
		}
	}

	MyString::MyString(const MyString& other)
		: mLen(other.mLen)
	{
		unsigned i = 0;
		mStr = new char[mLen + 1];
		while (i <= mLen)
		{
			mStr[i] = other.mStr[i];
			i++;
		}
	}

	MyString::~MyString()
	{
		delete[] mStr;
	}

	unsigned int MyString::GetLength() const
	{
		return mLen;
	}

	const char* MyString::GetCString() const
	{
		return mStr;
	}

	void MyString::Append(const char* s)
	{
		MyString nstr = MyString(mStr);
		delete[] mStr;
		unsigned int i = 0;
		unsigned int nlen = 0;
		unsigned int len2 = 0;

		while (*(s + i) != '\0')
		{
			nlen += 1;
			i++;
		}

		len2 = mLen + nlen;
		mStr = new char[len2 + 1];

		i = 0;

		while (i < mLen)
		{
			mStr[i] = nstr.mStr[i];
			i++;
		}

		i = 0;

		while (i <= mLen)
		{
			mStr[mLen + i] = s[i];
			i++;
		}
		//delete[] nstr.str;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		int i = 0;
		int nlen = 0;
		int len2 = 0;

		MyString nstr = MyString(mStr);
		MyString nstr2 = MyString(mStr);

		while (*(other.mStr + i) != '\0')
		{
			nlen += 1;
			i++;
		}

		len2 = mLen + nlen;
		nstr.mStr = new char[len2 + 1];
		i = 0;

		while (i < mLen)
		{
			nstr.mStr[i] = nstr2.mStr[i];
			i++;
		}

		i = 0;

		while (i <= nlen)
		{
			nstr.mStr[mLen + i] = other.mStr[i];
			i++;
		}

		return MyString(nstr.mStr);
	}

	int MyString::IndexOf(const char* s)
	{
		int index = 0;
		int i;
		int j;
		int k = 0;
		unsigned int slen = MyString(s).GetLength();
		
		if (slen == 0)
		{
			return 0;
		}

		if (mLen == 0 && mLen != slen)
		{
			return -1;
		}

		for (i = 0; i < mLen; i++)
		{
			if (mStr[i] == s[0])
			{	
				for (j = 0; j < slen; j++)
				{
					if (mStr[i + j] == s[j])
					{
						k += 1;
					}
				}

				if (k == slen)
				{
					index = i;
					break;
				}
				else
				{
					k = 0;
					index = -1;
				}
			}
			else
			{
				index = -1;
			}
		}

		return index;
	}

	int MyString::LastIndexOf(const char* s)
	{
		int index = 0;
		int i;
		int j;
		int k = 0;
		unsigned int slen = MyString(s).GetLength();

		if (mLen == 0 && mLen != slen)
		{
			return -1;
		}

		if (mLen == 0 && mLen == slen)
		{
			return 0;
		}

		if (slen == 0)
		{
			return mLen;
		}

		for (i = mLen - 1; i >= 0; i--)
		{
			if (mStr[i] == s[slen - 1])
			{
				for (j = slen - 1; j >= 0; j--)
				{
					if (mStr[i - k] == s[j])
					{
						k += 1;
					}
				}

				if (k == slen)
				{
					index = i - k + 1;
					break;
				}
				else
				{
					k = 0;
					index = -1;
				}
			}
			else
			{
				index = -1;
			}
		}

		return index;
	}

	void MyString::Interleave(const char* s)
	{
		unsigned int i = 0;
		unsigned int div = 0;
		unsigned int nlen = 0;
		unsigned int len2 = 0;
		unsigned int val1 = 0;
		unsigned int val2 = 0;
		MyString nstr = MyString(mStr);
		delete[] mStr;


		while (*(s + i) != '\0')
		{
			nlen += 1;
			i++;
		}

		len2 = mLen + nlen;
		mStr = new char[len2 + 1];
		i = 0;

		if (mLen <= nlen)
		{
			while (i < mLen * 2)
			{
				if (i % 2 == 0)
				{
					mStr[i] = nstr.mStr[i / 2];
					i++;
				}
				else
				{
					mStr[i] = s[i / 2];
					i++;
				}
			}

			i = 0;

			while (i <= nlen - mLen)
			{
				mStr[mLen * 2 + i] = s[mLen + i];
				i++;
			}
		}
		else
		{
			while (i < nlen * 2)
			{
				if (i % 2 == 0)
				{
					mStr[i] = nstr.mStr[i / 2];
					i++;
				}
				else
				{
					mStr[i] = s[i / 2];
					i++;
				}
			}

			i = 0;

			while (i <= mLen - nlen)
			{
				mStr[nlen * 2 + i] = nstr.mStr[nlen + i];
				i++;
			}
		}
		//if (len >= nlen)
		//{
		//	val1 = nlen * 2;
		//	val2 = nlen + len;
		//}
		//else
		//{
		//	val1 = len * 2;
		//	val2 = nlen + len;
		//}

		//str = new char[len2 + 1];

		//for (i = 0; i < val1; i++)
		//{
		//	div = i / 2;

		//	if (i % 2 == 0)
		//	{
		//		str[i] = nstr.str[div];
		//		
		//	}
		//	else
		//	{
		//		str[i] = s[div];
		//	}
		//}

		//if (len > nlen)
		//{
		//	for (i = val1; i < val2; i++)
		//	{
		//		str[i] = nstr.str[i - 1];
		//	
		//	}
		//}
		//else if (len < nlen)
		//{
		//	for (i = val1; i < val2; i++)
		//	{
		//		str[i] = s[i - 1];
		//	}
		//}

		//for (i = 0; i < len2; i++)
		//{
		//	std::cout << nstr[i] << std::endl;
		//}
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		//MyString nstr = MyString(str);
		//delete[] str;
		//unsigned int i = 0;
		//unsigned int nlen = 0;
		//unsigned int len2 = 0;

		////unsigned int i = 0;
		////unsigned int j = 0;
		////unsigned int l = len;
		////MyString nstr = MyString(str);

		//str = new char[len + 1];

		////if (index >= len || len == 0)
		////{
		////	return false;
		////}

		//for (i = 0; i < len; i++)
		//{
		//	str[i] = nstr.str[2];
		//}

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		MyString nstr = MyString(mStr);
		delete[] mStr;
		mStr = new char[mLen + 1];
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
	}

	void MyString::PadRight(unsigned int totalLength)
	{
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
	}

	void MyString::Reverse()
	{
		int i;
		char temp;
		int len = mLen / 2;

		for (i = 0; i < len; i++)
		{
			temp = mStr[i];
			mStr[i] = mStr[mLen - i - 1];
			mStr[mLen - i - 1] = temp;
		}
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		unsigned int i;
		unsigned int j = 0;

		if (mLen != rhs.mLen)
		{
			return false;
		}

		if (mLen == 0 && rhs.mLen == 0)
		{
			return true;
		}

		for (i = 0; i < mLen; i++)
		{
			if (mStr[i] != rhs.mStr[i])
			{
				j++;
			}
		}

		if (j == 0)
		{
			return true;
		}
		else
		{
			return false;

		}
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		unsigned int i = 0;

		delete[] mStr;

		mLen = rhs.mLen;
		mStr = new char[rhs.mLen + 1];

		while (i < mLen)
		{
			mStr[i] = rhs.mStr[i];
			i++;
		}

		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}
}