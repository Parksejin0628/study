#include"ArrayObject_address.h"

ArrayObject_address::ArrayObject_address(int len) : arrlen(len)
{
	arr = new PERSON_PTR[len];
}

ArrayObject_address::~ArrayObject_address()
{
	delete[]arr;
}

PERSON_PTR& ArrayObject_address::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index error" << endl;
		return arr[arrlen - 1];
	}
	return arr[idx];
}