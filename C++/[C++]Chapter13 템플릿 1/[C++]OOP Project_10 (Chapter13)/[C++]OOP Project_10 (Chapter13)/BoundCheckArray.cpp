/*
파일이름 : BoundCheckArray.h
작성자 : 박세진
업데이트 정보 : [22-08-13]
*/



#include"BoundCheckArray.h"

BoundCheckClientPtrArray::BoundCheckClientPtrArray(int len) : arrlen(len)
{
	arr = new CLIENT_PTR[len];
}

CLIENT_PTR& BoundCheckClientPtrArray::operator[](int idx)
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}
CLIENT_PTR BoundCheckClientPtrArray::operator[](int idx) const
{
	if (idx < 0 || idx >= arrlen)
	{
		cout << "Array index out of bound exception" << endl;
		exit(1);
	}
	return arr[idx];
}

int BoundCheckClientPtrArray::GetArrLen() const
{
	return arrlen;
}

BoundCheckClientPtrArray::~BoundCheckClientPtrArray()
{
	delete[]arr;
}
