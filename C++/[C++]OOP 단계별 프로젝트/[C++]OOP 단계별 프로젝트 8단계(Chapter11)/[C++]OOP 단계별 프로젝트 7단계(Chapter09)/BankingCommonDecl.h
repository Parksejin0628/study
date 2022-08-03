/*
파일이름 : BankingCommonDecl.h
작성자 : 박세진
업데이트 정보 : [22-08-03]
*/


#pragma once

#include<iostream>
#include<cstring>
#include<cstdlib>

#pragma warning(disable:4996)

namespace funcNum
{
	enum { OPEN = 1, DEPOSIT, WITHDRAW, CHECKMONEY, EXIT };
	enum creditInfo { CREDIT_A = 7, CREDIT_B = 4, CREDIT_C = 1 };
	enum { NORMAL = 1, CREDIT = 2 };
}

using std::cin;
using std::cout;
using std::endl;
const int NAME_LEN = 20;