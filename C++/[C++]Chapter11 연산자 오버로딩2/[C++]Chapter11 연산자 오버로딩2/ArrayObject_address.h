#pragma once
#include"Common.h"
#include"Person.h"

typedef Person* PERSON_PTR;

class ArrayObject_address
{
private:
	PERSON_PTR* arr;
	int arrlen;
public:
	ArrayObject_address(int len);
	~ArrayObject_address();
	PERSON_PTR& operator[](int idx);
};