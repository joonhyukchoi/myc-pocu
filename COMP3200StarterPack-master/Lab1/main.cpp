#include "Add.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main()
{
	int result;
	int a = 1;
	int b = 2;
	result = lab1::Add(a, b);
	cout << result;
	system("pause");
}