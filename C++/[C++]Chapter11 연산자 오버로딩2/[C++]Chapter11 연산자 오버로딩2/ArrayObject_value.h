#pragma once
#include"Common.h"
#include"Person.h"

class ArrayObject_value
{
private:
	Person* arr;
	int arrlen;
public:
	ArrayObject_value(int len);
	~ArrayObject_value();
	Person& operator[](int idx);
};
