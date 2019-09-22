#include <iostream>
#include <cassert>
#include <string>
#include "MyString.h"

using namespace assignment1;
using namespace std;

int main()
{
	int beforeAddress1;
	int beforeAddress2;

	/* GetLength() Ex */
	/* GetCString() Ex */
	MyString s2("Hello");
	assert(s2 == MyString("Hello"));

	/* Append() Ex */
	MyString s3("Hello");
	s3.Append(" World");
	std::cout << "111111111111 : " << s3.GetCString() << std::endl;
	std::cout << "111111111111 : " << MyString("Hello World").GetCString() << std::endl;
	assert(s3 == MyString("Hello World"));

	/* operator+ Ex */
	MyString s41("Hello");
	MyString s42(" World");
	MyString s43 = s41 + s42;
	assert(s43 == MyString("Hello World"));

	MyString str(nullptr);
	str.Append("hello");
	assert(strcmp(str.GetCString(), "hello") == 0);
	std::cout << "nullptr 생성 이후 append : " << str.GetCString() << std::endl;


	MyString constructortest("hello");
	std::cout << "문자열 생성 : " << constructortest.GetCString() << std::endl;
	std::cout << "문자열 생성 길이 : " << constructortest.GetLength() << std::endl;
	assert(strcmp(constructortest.GetCString(), "hello") == 0);
	assert(constructortest.GetLength() == 5);


	std::cout << std::hex;
	MyString originalStr("Hello");
	MyString copyStr(originalStr);
	int originalStrAddress = reinterpret_cast<int>(originalStr.GetCString());
	int copyStrAddress = reinterpret_cast<int>(copyStr.GetCString());
	std::cout << "원본 : " << originalStr.GetCString() << ", 원본 주소 : " << originalStrAddress << std::endl;
	std::cout << "복사본 : " << copyStr.GetCString() << ", 복사본 주소 : " << copyStrAddress << std::endl;
	assert(originalStrAddress != copyStrAddress);
	assert(strcmp(originalStr.GetCString(), "Hello") == 0);
	assert(strcmp(copyStr.GetCString(), "Hello") == 0);


	MyString appendTestFunctional("Hello");
	appendTestFunctional.Append(" World");
	std::cout << "문자열 이어 붙히기 함수형 내부값 변경 : " << appendTestFunctional.GetCString() << std::endl;
	assert(strcmp(appendTestFunctional.GetCString(), "Hello World") == 0);


	MyString appendTestOperator1("Hello");
	MyString appendTestOperator2(" World");
	MyString appendTestOperator3 = appendTestOperator1 + appendTestOperator2;
	std::cout << "문자열 이어 붙히기 연산자 반환 : " << appendTestOperator3.GetCString() << std::endl;
	assert(strcmp(appendTestOperator3.GetCString(), "Hello World") == 0);


	MyString indexOfTest("Hello");
	assert(indexOfTest.IndexOf("el") == 1);
	assert(indexOfTest.IndexOf("ll") == 2);
	assert(indexOfTest.IndexOf("l") == 2);
	assert(indexOfTest.IndexOf("asd") == -1);
	assert(indexOfTest.IndexOf("") == 0);
	assert(indexOfTest.IndexOf(nullptr) == -1);
	assert(indexOfTest.IndexOf("lo") == 3);

	assert(indexOfTest.LastIndexOf("l") == 3);
	assert(indexOfTest.LastIndexOf("asd") == -1);
	assert(indexOfTest.LastIndexOf("") == indexOfTest.GetLength());
	assert(indexOfTest.LastIndexOf(nullptr) == -1);
	assert(indexOfTest.LastIndexOf("He") == 0);

	MyString emptyIndexOfTest("");
	assert(emptyIndexOfTest.IndexOf("a") == -1);
	assert(emptyIndexOfTest.IndexOf("") == 0);
	assert(emptyIndexOfTest.LastIndexOf("") == emptyIndexOfTest.GetLength());


	MyString interLeaveTest("Hello");
	interLeaveTest.Interleave(" World");
	std::cout << "문자열 번갈아가며 끼워맞추기 : " << interLeaveTest.GetCString() << std::endl;
	assert(strcmp(interLeaveTest.GetCString(), "H eWlolrold") == 0);


	int previousInterLeaveTestStrAddress = reinterpret_cast<int>(interLeaveTest.GetCString());
	interLeaveTest.Interleave("");
	int currentInterLeaveTestStrAddress = reinterpret_cast<int>(interLeaveTest.GetCString());
	assert(previousInterLeaveTestStrAddress == currentInterLeaveTestStrAddress);

	MyString testString1("Happy Happy Days");
	MyString testString2("Happy Days");
	MyString testString3("Happy Days");
	MyString testString4("");

	beforeAddress1 = (int)testString1.GetCString();
	testString1.Interleave("");
	assert(beforeAddress1 == (int)testString1.GetCString());
	std::cout << "M3_NoMallocInInterleaveEmpty 통과" << std::endl;

	MyString s7("Hello");
	s7.Interleave(" World");
	assert(s7 == MyString("H eWlolrold"));

	MyString s72("A");
	s72.Interleave("BCDEF");
	assert(s72 == MyString("ABCDEF"));

	MyString s73("bcdef");
	s73.Interleave("a");
	assert(s73 == MyString("bacdef"));

	std::cout << std::boolalpha;
	MyString removeTest("Hello");
	bool b1 = removeTest.RemoveAt(0); // s는 "ello", b1은 true
	std::cout << "Hello의 첫글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b1 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ello") == 0);
	assert(b1 == true);


	bool b2 = removeTest.RemoveAt(3); // s는 "ell", b2은 true
	std::cout << "ello의 네번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b2 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b2 == true);


	bool b3 = removeTest.RemoveAt(4); // s는 "ell", b3은 false
	std::cout << "ell의 다섯번째 글자 지우기 : " << removeTest.GetCString() << ", 성공여부 : " << b3 << std::endl;
	assert(strcmp(removeTest.GetCString(), "ell") == 0);
	assert(b3 == false);


	MyString padLeftTest1("Hello");
	int previousPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	padLeftTest1.PadLeft(2); // s1: "Hello"
	int currentPadLeftTest1StrAddress = reinterpret_cast<int>(padLeftTest1.GetCString());
	std::cout << padLeftTest1.GetCString() << std::endl;
	assert(previousPadLeftTest1StrAddress == currentPadLeftTest1StrAddress);
	assert(strcmp(padLeftTest1.GetCString(), "Hello") == 0);


	padLeftTest1.PadLeft(8); // s1: "   Hello"
	assert(strcmp(padLeftTest1.GetCString(), "   Hello") == 0);
	std::cout << padLeftTest1.GetCString() << std::endl;


	MyString padLeftTest2("Hello");
	int previousPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	padLeftTest2.PadLeft(3, '-'); // s1: "Hello"
	int currentPadLeftTest2StrAddress = reinterpret_cast<int>(padLeftTest2.GetCString());
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(previousPadLeftTest2StrAddress == currentPadLeftTest2StrAddress);
	assert(strcmp(padLeftTest2.GetCString(), "Hello") == 0);


	padLeftTest2.PadLeft(7, '-'); // s1: "   Hello"
	std::cout << padLeftTest2.GetCString() << std::endl;
	assert(strcmp(padLeftTest2.GetCString(), "--Hello") == 0);


	MyString padRightTest1("Hello");
	int previousPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	padRightTest1.PadRight(2); // s1: "Hello"
	int currentPadRightTest1StrAddress = reinterpret_cast<int>(padRightTest1.GetCString());
	std::cout << padRightTest1.GetCString() << std::endl;
	assert(previousPadRightTest1StrAddress == currentPadRightTest1StrAddress);
	assert(strcmp(padRightTest1.GetCString(), "Hello") == 0);

	padRightTest1.PadRight(8); // s1: "   Hello"
	std::cout << padRightTest1.GetCString() << "I" << std::endl;
	assert(strcmp(padRightTest1.GetCString(), "Hello   ") == 0);


	MyString padRightTest2("Hello");
	int previousPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	padRightTest2.PadRight(3, '-'); // s1: "Hello"
	int currentPadRightTest2StrAddress = reinterpret_cast<int>(padRightTest2.GetCString());
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(previousPadRightTest2StrAddress == currentPadRightTest2StrAddress);
	assert(strcmp(padRightTest2.GetCString(), "Hello") == 0);

	padRightTest2.PadRight(7, '-'); // s1: "   Hello"
	std::cout << padRightTest2.GetCString() << std::endl;
	assert(strcmp(padRightTest2.GetCString(), "Hello--") == 0);
//
//int beforeAddress1;
//int beforeAddress2;
//MyString testString1("Happy Happy Days");
//MyString testString2("Happy Days");
//MyString testString3("Happy Days");
//MyString testString4("");
////
//MyString my1("pope pope");
//string s1("pope pope");
//
//const char* cString = my1.GetCString();
//MyString copied(my1);
//
//// E0, E1
//assert(my1.IndexOf("p") == s1.find("p"));
//assert(my1.LastIndexOf("p") == s1.rfind("p"));
//
//assert(my1.IndexOf("pop") == s1.find("pop"));
//assert(my1.LastIndexOf("pop") == s1.rfind("pop"));
//
//assert(my1.IndexOf("popen") == s1.find("popen"));
//
//assert(my1.LastIndexOf("popen") == s1.rfind("popen"));
//
//assert(my1.IndexOf("pope pope love") == s1.find("pope pope love"));
//assert(my1.LastIndexOf("pope pope love") == s1.rfind("pope pope love"));
//
//assert(my1.IndexOf(" pope") == s1.find(" pope"));
//assert(my1.LastIndexOf("pope ") == s1.rfind("pope "));
//
//// E2, E3
//assert(my1.IndexOf("") == s1.find(""));
//assert(my1.LastIndexOf("") == s1.rfind(""));
//
//// E4
//assert(my1 == copied);					// value
//assert(my1.GetCString() == cString);				// reference
//
//
////	Operator == 관련
//beforeAddress1 = (int)testString2.GetCString();
//beforeAddress2 = (int)testString3.GetCString();
//if (testString2 == testString3);
//assert(beforeAddress1 == (int)testString2.GetCString());
//assert(beforeAddress2 == (int)testString3.GetCString());
//cout << "D2_NoMallocInCompareSameLength 통과" << endl;
//
//beforeAddress1 = (int)testString1.GetCString();
//beforeAddress2 = (int)testString2.GetCString();
//if (testString1 == testString2);
//assert(beforeAddress1 == (int)testString1.GetCString());
//assert(beforeAddress2 == (int)testString2.GetCString());
//cout << "D5_NoMallocInCompareDifferentLength 통과" << endl;
//
////	IndexOf, LastOfIndex 관련
//beforeAddress1 = (int)testString1.GetCString();
//testString1.IndexOf("Happy");
//testString1.IndexOf("");
//assert(beforeAddress1 == (int)testString1.GetCString());
//
//beforeAddress1 = (int)testString1.GetCString();
//testString1.LastIndexOf("Happy");
//testString1.LastIndexOf("");
//assert(beforeAddress1 == (int)testString1.GetCString());
//cout << "E5_NoMallocInIndexOf 통과" << endl;
//
////	ToUpper, ToLower 관련
//beforeAddress1 = (int)testString1.GetCString();
//testString1.ToUpper();
//testString1.ToLower();
//assert(beforeAddress1 == (int)testString1.GetCString());
//cout << "F3_NoMallocInUpperLower 통과" << endl;

////	Reverse 관련
//beforeAddress1 = (int)testString1.GetCString();
//testString1.Reverse();
//testString1.Reverse();
//assert(beforeAddress1 == (int)testString1.GetCString());
//beforeAddress1 = (int)testString4.GetCString();
//testString4.Reverse();
//assert(beforeAddress1 == (int)testString4.GetCString());
//cout << "G4_NoMallocInReverse 통과" << endl;
//
////	Append 관련
//beforeAddress1 = (int)testString1.GetCString();
//testString1.Append("");
//assert(beforeAddress1 == (int)testString1.GetCString());
//cout << "H3_NoMallocInAppendEmpty 통과" << endl;
//
////	 RemoveAt 관련
//beforeAddress1 = (int)testString4.GetCString();
//testString4.RemoveAt(0);
//assert(beforeAddress1 == (int)testString4.GetCString());
//cout << "J2_RemoveAtNoMallocOnEmpty 통과" << endl;
//
////	PadLeft, PadRight 관련
//beforeAddress1 = (int)testString1.GetCString();
//testString1.PadLeft(16);
//testString1.PadLeft(16, '*');
//assert(beforeAddress1 == (int)testString1.GetCString());
//cout << "K4_NoMallocInPadLeftShorter 통과" << endl;
//
//beforeAddress1 = (int)testString1.GetCString();
//testString1.PadRight(16);
//testString1.PadRight(16, '*');
//assert(beforeAddress1 == (int)testString1.GetCString());
//cout << "L4_NoMallocInPadRightShorter 통과" << endl;
//
////	InterLeave 관련
//beforeAddress1 = (int)testString1.GetCString();
//testString1.Interleave("");
//assert(beforeAddress1 == (int)testString1.GetCString());
//cout << "M3_NoMallocInInterleaveEmpty 통과" << endl;
//
//return 0;

}