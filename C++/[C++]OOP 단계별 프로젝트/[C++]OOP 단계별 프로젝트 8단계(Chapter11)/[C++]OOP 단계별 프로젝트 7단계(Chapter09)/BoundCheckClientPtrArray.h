/*
파일이름 : BoundCheckClientPtrArray.h
작성자 : 박세진
업데이트 정보 : [22-08-03]
*/



#pragma once
#include"BankingCommonDecl.h"
#include"Client.h"

typedef Client* CLIENT_PTR;

class BoundCheckClientPtrArray
{
private:
	CLIENT_PTR* arr;
	int arrlen;

	BoundCheckClientPtrArray(const BoundCheckClientPtrArray& arr) { }
	BoundCheckClientPtrArray& operator=(const BoundCheckClientPtrArray& arr) { }
public:
	BoundCheckClientPtrArray(int len);
	CLIENT_PTR& operator[](int idx);
	CLIENT_PTR operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckClientPtrArray();
};