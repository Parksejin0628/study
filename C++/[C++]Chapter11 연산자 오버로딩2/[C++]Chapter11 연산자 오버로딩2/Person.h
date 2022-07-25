#pragma once
#include<iostream>
#include<cstring>
#pragma warning(disable:4996)

using std::cout;
using std::cin;
using std::endl;

class Person
{
private:
	char *name;
	int age;
public:
	Person(const char *myname, int myage);
	~Person();
	void ShowPersonInfo() const;
	Person& operator=(const Person& ref);
};