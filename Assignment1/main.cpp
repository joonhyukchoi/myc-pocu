#include <iostream>
#include <cassert>
#include "MyString.h"

using namespace assignment1;
using namespace std;

int main()
{
	
		assignment1::MyString my1("pope pope");
		std::string s1("pope pope");

		const char* cString = my1.GetCString();
		assignment1::MyString copied(my1);


		cout << my1.IndexOf("") << endl;
		cout << s1.find("") << endl;
		cout << my1.LastIndexOf("") << endl;
		cout << s1.rfind("") << endl;
		// E2, E3
		assert(my1.IndexOf("pope pope") == s1.find("pope pope"));
		assert(my1.LastIndexOf("") == s1.rfind(""));

		// E4
		assert(my1 == copied);					// value
		assert(my1.GetCString() == cString);				// reference

		cout << "-----------------------" << endl;
		cout << "operator+" << endl;
		MyString s41("Hello");
		MyString s42(" World");
		MyString s43 = s41 + s42;
		//s2 = s2 + s1;  소멸자 오류(이번 과제에서는 체크하지 않음)
		cout << s43.GetCString() << endl;   //Hello World

		 /* operator+ Ex */
		//s2 = s2 + s1;  ??? ??(?? ????? ???? ??)
		assert(s43 == MyString("Hello World"));

		MyString appendTestOperator1("");
		MyString appendTestOperator2(" World");
		MyString appendTestOperator3 = appendTestOperator1 + appendTestOperator2;
		std::cout << "문자열 이어 붙히기 연산자 반환 : " << appendTestOperator3.GetCString() << std::endl;
	//	assert(strcmp(appendTestOperator3.GetCString(), "Hello World") == 0);

	
}
