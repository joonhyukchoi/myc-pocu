#include "MyString.h"
//#include <iostream>

namespace assignment1
{
	MyString::MyString(const char* s)
		: mLen(0)
	{	
		unsigned int i = 0;
		
		if (s != nullptr)
		{
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
		else
		{
			mStr = new char[1];
			mStr = nullptr;
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
		//std::cout << "111111111111 : " << mLen << std::endl;
		return mStr;
	}

	void MyString::Append(const char* s)
	{
		if (*s != '\0')
		{
			MyString nstr = MyString(mStr);
			MyString str = MyString(s);
			delete[] mStr;
			unsigned int i = 0;
			unsigned int len2 = 0;
			unsigned int nlen = str.GetLength();

			len2 = mLen + nlen;
			mStr = new char[len2 + 1];

			i = 0;

			while (i < mLen)
			{
				mStr[i] = nstr.mStr[i];
				i++;
			}

			i = 0;

			while (i <= nlen)
			{
				mStr[mLen + i] = s[i];
				i++;
			}

			mLen = mLen + nlen;
		}
	}

	MyString MyString::operator+(const MyString& other) const
	{
		if (other.mLen == 0)
		{
			return *this;
		}

		unsigned int i = 0;
		unsigned int nlen = 0;
		int len2 = 0;

		MyString nstr = MyString(mStr);

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
			nstr.mStr[i] = mStr[i];
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
		unsigned int i = 0;
		int j = 0;
		int slen = 0;
		int k = 0;
		int index = 0;

		if (s != nullptr)
		{
			while (*(s + i) != '\0')
			{
				slen += 1;
				i++;
			}
		}
		
		if (mLen == 0 && mLen != slen)
		{
			return -1;
		}

		if (mLen == 0 && mLen == slen || slen == 0)
		{
			return 0;
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
		int i = 0;
		int j = 0;
		unsigned int slen = 0;
		int k = 0;
		int index = 0;

		if (s != nullptr)
		{
			while (*(s + i) != '\0')
			{
				slen += 1;
				i++;
			}
		}

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
		if (*s != '\0')
		{
			MyString st = MyString(s);
			unsigned int slen = st.GetLength();
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

			mLen = mLen + nlen;
		}
	}

	bool MyString::RemoveAt(unsigned int index)
	{
		if (mLen == 0)
		{
			return false;
		}

		if (index > mLen - 1)
		{
			return false;
		}

		MyString nstr = MyString(mStr);
		delete[] mStr;
		unsigned int i = 0;
		unsigned int j = 0;
		unsigned int len2 = 0;

		mStr = new char[mLen];

		for (i = 0; i < mLen; i++)
		{
			if (i == index)
			{
				j++;
				continue;
			}

			mStr[i - j] = nstr.mStr[i];
		}

		mStr[mLen - 1] = '\0';

		mLen = mLen - 1;

		return true;
	}

	void MyString::PadLeft(unsigned int totalLength)
	{
		if (totalLength > mLen)
		{
			MyString nstr = MyString(mStr);
			delete[] mStr;
			unsigned int i;

			mStr = new char[totalLength + 1];

			for (i = 0; i < totalLength - mLen; i++)
			{
				mStr[i] = ' ';
			}

			for (i = totalLength - mLen; i < totalLength + 1; i++)
			{
				mStr[i] = nstr.mStr[i - totalLength + mLen];
			}

			mLen = totalLength;
		}
	}

	void MyString::PadLeft(unsigned int totalLength, const char c)
	{
		if (totalLength > mLen)
		{
			MyString nstr = MyString(mStr);
			delete[] mStr;
			unsigned int i;

			mStr = new char[totalLength + 1];

			for (i = 0; i < totalLength - mLen; i++)
			{
				mStr[i] = c;
			}

			for (i = totalLength - mLen; i < totalLength + 1; i++)
			{
				mStr[i] = nstr.mStr[i - totalLength + mLen];
			}

			mLen = totalLength;
		}
	}

	void MyString::PadRight(unsigned int totalLength)
	{
		if (totalLength > mLen)
		{
			MyString nstr = MyString(mStr);
			delete[] mStr;
			unsigned int i;

			mStr = new char[totalLength + 1];

			for (i = 0; i < mLen; i++)
			{
				mStr[i] = nstr.mStr[i];
			}

			for (i = mLen; i < totalLength + 1; i++)
			{
				if (i == totalLength)
				{
					mStr[i] = '\0';
					break;
				}
				mStr[i] = ' ';
			}

			mLen = totalLength;
		}
	}

	void MyString::PadRight(unsigned int totalLength, const char c)
	{
		if (totalLength > mLen)
		{
			MyString nstr = MyString(mStr);
			delete[] mStr;
			unsigned int i;

			mStr = new char[totalLength + 1];

			for (i = 0; i < mLen; i++)
			{
				mStr[i] = nstr.mStr[i];
			}

			for (i = mLen; i < totalLength + 1; i++)
			{
				if (i == totalLength)
				{
					mStr[i] = '\0';
					break;
				}
				mStr[i] = c;
			}

			mLen = totalLength;
		}
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
		if (mStr == rhs.mStr)
		{
			return *this;
		}
		unsigned int i = 0;

		delete[] mStr;

		mLen = rhs.mLen;
		mStr = new char[rhs.mLen + 1];

		while (i < mLen)
		{
			mStr[i] = rhs.mStr[i];
			i++;
		}

		mStr[mLen] = '\0';

		return *this;
	}

	void MyString::ToLower()
	{
		unsigned int i;

		for (i = 0; i < mLen; i++)
		{
			if (mStr[i] >= 'A' && mStr[i] <= 'Z')
			{
				mStr[i] = mStr[i] + 32;
			}
		}
	}

	void MyString::ToUpper()
	{
		unsigned int i;

		for (i = 0; i < mLen; i++)
		{
			if (mStr[i] >= 'a' && mStr[i] <= 'z')
			{
				mStr[i] = mStr[i] - 32;
			}
		}
	}
}