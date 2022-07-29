#include"Arr.h"

Array::Array(int len) : arrlen(len)
{
	arr = new int[len];
	for (int i = 0; i < len; i++)
	{
		arr[i] = 0;
	}
}

Array::~Array()
{
	delete[]arr;
}

int& Array::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index error!" << endl;
		return arr[arrlen-1];
	}

	return arr[idx];
}

int Array::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "index error!" << endl;
		return arr[arrlen - 1];
	}

	return arr[idx];
}