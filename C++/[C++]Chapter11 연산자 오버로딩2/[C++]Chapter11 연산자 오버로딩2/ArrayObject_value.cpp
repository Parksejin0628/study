#include"ArrayObject_value.h"

ArrayObject_value::ArrayObject_value(int len) : arrlen(len)
{
	arr = new Person[len];
}

ArrayObject_value::~ArrayObject_value()
{
	delete[]arr;
}

Person& ArrayObject_value::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index error" << endl;
		return arr[arrlen - 1];
	}

	return arr[idx];
}