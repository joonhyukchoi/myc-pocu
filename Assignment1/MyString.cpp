#include "MyString.h"
#include "iostream"

namespace assignment1
{
	MyString::MyString(const char* s)
		: len(0)
	{	
		unsigned int i = 0;
		
		while (*(s + i) != '\0')
		{
			len += 1;
			i++;
		}
		//len은 null값뺀 전체 길이
		str = new char[len + 1];
		i = 0;

		while (i <= len)
		{
			str[i] = s[i];
			i++;
		}
	}

	MyString::MyString(const MyString& other)
		: len(other.len)
	{
		unsigned i = 0;
		str = new char[len + 1];
		while (i <= len)
		{
			str[i] = other.str[i];
			i++;
		}
	}

	MyString::~MyString()
	{
		delete[] str;
	}

	unsigned int MyString::GetLength() const
	{
		return len;
	}

	const char* MyString::GetCString() const
	{
		return str;
	}

	void MyString::Append(const char* s)
	{
		MyString nstr = MyString(str);
		delete[] str;
		unsigned int i = 0;
		unsigned int nlen = 0;
		unsigned int len2 = 0;

		while (*(s + i) != '\0')
		{
			nlen += 1;
			i++;
		}

		len2 = len + nlen;
		str = new char[len2 + 1];

		i = 0;

		while (i < len)
		{
			str[i] = nstr.str[i];
			i++;
		}

		i = 0;

		while (i <= nlen)
		{
			str[len + i] = s[i];
			i++;
		}
		//delete[] nstr.str;
	}

	MyString MyString::operator+(const MyString& other) const
	{
		int i = 0;
		int nlen = 0;
		int len2 = 0;

		MyString nstr = MyString(str);
		MyString nstr2 = MyString(str);

		while (*(other.str + i) != '\0')
		{
			nlen += 1;
			i++;
		}

		len2 = len + nlen;
		nstr.str = new char[len2 + 1];
		i = 0;

		while (i < len)
		{
			nstr.str[i] = nstr2.str[i];
			i++;
		}

		i = 0;

		while (i <= nlen)
		{
			nstr.str[len + i] = other.str[i];
			i++;
		}

		return MyString(nstr.str);
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

		if (len == 0 && len != slen)
		{
			return -1;
		}

		for (i = 0; i < len; i++)
		{
			if (str[i] == s[0])
			{	
				for (j = 0; j < slen; j++)
				{
					if (str[i + j] == s[j])
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

		if (len == 0 && len != slen)
		{
			return -1;
		}

		if (len == 0 && len == slen)
		{
			return 0;
		}

		if (slen == 0)
		{
			return len;
		}

		for (i = len - 1; i >= 0; i--)
		{
			if (str[i] == s[slen - 1])
			{
				for (j = slen - 1; j >= 0; j--)
				{
					if (str[i - k] == s[j])
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
		MyString nstr = MyString(str);
		delete[] str;


		while (*(s + i) != '\0')
		{
			nlen += 1;
			i++;
		}

		len2 = len + nlen;
		str = new char[len2 + 1];
		i = 0;

		if (len <= nlen)
		{
			while (i < len * 2)
			{
				if (i % 2 == 0)
				{
					str[i] = nstr.str[i / 2];
					i++;
				}
				else
				{
					str[i] = s[i / 2];
					i++;
				}
			}

			i = 0;

			while (i <= nlen - len)
			{
				str[len * 2 + i] = s[len + i];
				i++;
			}
		}
		else
		{
			while (i < nlen * 2)
			{
				if (i % 2 == 0)
				{
					str[i] = nstr.str[i / 2];
					i++;
				}
				else
				{
					str[i] = s[i / 2];
					i++;
				}
			}

			i = 0;

			while (i <= len - nlen)
			{
				str[nlen * 2 + i] = nstr.str[nlen + i];
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
		MyString nstr = MyString(str);
		delete[] str;
		str = new char[len + 1];
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
	}

	bool MyString::operator==(const MyString& rhs) const
	{
		return false;
	}

	MyString& MyString::operator=(const MyString& rhs)
	{
		return *this;
	}

	void MyString::ToLower()
	{
	}

	void MyString::ToUpper()
	{
	}
}