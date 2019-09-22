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
	
}
