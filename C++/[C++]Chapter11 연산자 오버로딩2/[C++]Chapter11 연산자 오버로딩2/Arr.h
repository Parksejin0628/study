#pragma once
#include"Common.h"

class Array
{
private:
	int* arr;
	int arrlen;
	Array(Array& ref) {}
	Array& operator=(Array& ref) {}
public:
	Array(int len);
	~Array();
	int& operator[](int idx);
	int operator[](int idx) const;
};