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
	Array();
	Array(int len);
	~Array();
	Array& init(int len);
	int& operator[](int idx);
	int operator[](int idx) const;
};