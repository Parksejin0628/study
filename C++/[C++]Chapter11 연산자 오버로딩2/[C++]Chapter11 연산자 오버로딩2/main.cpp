#include<iostream>
#include"Person.h"
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	return 0;
}