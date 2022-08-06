#include"Common.h"
#include"String.h"

int main(void)
{
	String str1 = "I like ";
	String str2 = "String class";
	String str3 = str1 + str2;

	cout << str1 << endl;
	cout << str2 << endl;
	cout << str3 << endl;

	str1 += str2;
	if (str1 == str3)
	{
		cout << "동일 문자열!" << endl;
	}
	else
	{
		cout << "동일하지 않은 문자열!" << endl;
	}

	String str4;
	cout << "문자열 입력: ";
	cin >> str4;
	cout << "입력한 문자열: " << str4 << endl;
	return 0;
}
/*
[Chapter12 String 클래스의 디자인]
<12.1. C++의 표준과 표준 string 클래스>
1. string 클래스
 1) string 클래스는 C++ 표준 라이브러리에 정의되어 있는 문자열의 처리를 목적으로 정의된 클래스이다.
	- 사용을 위해서는 <string>을 포함해야 한다.
	- 문자의 덧셈, 비교, 대입 등 다양한 기능을 포함하고 있다.
 2) 이번 챕터의 목적은 이 string 클래스를 직접 구현하고자 한다.
<12.2. 문자열 처리 클래스의 정의
 1) String 클래스 정의를 위해 필요한 기능들
	- 문자열을 인자로 받는 생성자 정의
	- 생성자, 소멸자, 복사 생성자, 대입 연산자 정의 (메모리 동적 할당을 위한)
	- 결합된 문자열로 초기화된 객체를 반환하는 + 연산자의 오버로딩
	- 문자열을 덧붙이는 += 연산자의 오버로딩
	- 내용비교를 진행하는 == 연산자의 오버로딩
	- 콘솔 입출력이 가능하도록 <<, >> 연산자의 오버로딩


*/