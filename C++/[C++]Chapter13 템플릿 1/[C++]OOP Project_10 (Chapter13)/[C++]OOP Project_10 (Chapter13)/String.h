/*
�����̸� : String.h
�ۼ��� : �ڼ���
������Ʈ ���� : [22-08-07]
*/
#pragma once

#include"BankingCommonDecl.h"

class String
{
private:
	char* str;
	int len;
public:
	String();
	String(const char* istr);
	String(const String& cpy);
	~String();
	String& operator=(const String& cpy);
	String operator+(const String& other) const;
	String& operator+=(const String& other);
	bool operator==(const String& other) const;
	friend istream& operator>>(istream& ist, String& s);
	friend ostream& operator<<(ostream& ost, const String& s);
};