#include<iostream>
#include"Person.h"
#pragma warning(disable:4996)

using std::cin;
using std::cout;
using std::endl;

void que1();

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();

	que1();

	return 0;
}

void que1()
{
	/*
	[문제1]
	Chapter 07에서는 예제 HASCComposite.cpp를 통해서 다음의 두 클래스를 정의하였다.
	*/

	return;
}

/*
[Chapter11 연산자 오버로딩2]
<11.1. 반드시 해야 하는 대입 연산자의 오버로딩>
1. 대입 연산자의 대표적인 특성 및 오버로딩
 1) 대입 연산자의 특성은 복사 생성자와 매우 유사하다.
	- 정의하지 않으면 디폴트 대입 연산자가 삽입된다.
	- 디폴트 대입 연산자는 멤버 대 멤버의 복사를 진행한다. (얕은 복사)
	- 깊은 복사가 필요한 경우 직접 정의해야 한다.
 2) 복사 생성자 호출과 다른 점은 이미 생성 및 초기화를 끝낸 객체들을 대상으로 진행한다.
	ex) obj2 = obj1 이 문장의 경우
		> obj1만 초기화가 끝난 객체인 경우 : 복사 생성자 호출
		> obj1, obj2 모두 초기화가 끝난 객체인 경우 : 대입 연산자 호출(오버로딩)
 3) 디폴트 대입 연산자는 멤버 대 멤버의 복사를 진행하며 호출한 객체를 참조형으로 반환한다.
	- 다른 연산자 오버로딩처럼 obj1 = obj2 는 obj1.operator=(obj2) 로 해석된다.
2. 디폴트 대입 연산자의 문제점 및 해결법
 1) 복사 생성자의 유사한 문제점이 존재한다.
	- 유사하게 얕은 복사가 진행되기에 참조형 변수를 복사할 때 서로 다른 객체가 같은 주소를 가리키게 되는 문제가 있다.
		> 즉, 동적할당을 하는 변수가 있을 경우 객체가 소멸할 때 같은 공간을 두 번 소멸하게 된다.
	- 이미 정의된 객체를 대상으로 복사가 이루어지기 때문에 기존에 가리키던 공간의 주소값을 잃게 된다.
		> 주소값을 잃은 공간은 다시 접근이 불가능하기에 소멸도 불가능하게 된다. 이는 메모리 누수로 이어진다.
 2) 복사 생성자의 문제를 해결하기 위해서는 복사 생성자의 문제를 해결할 때와 유사하게 접근해야 한다.
	- 따로 정의하여 깊은 복사를 진행하도록 해야 한다.
	- 복사를 진행하기 전 메모리 누수를 방지하기 위해 기존에 가리키던 공간의 메모리를 해제시켜야 한다.
3. 상속 구조에서의 대입 연산자 호출
 1) 대입 연산자는 복사 생성자와 다르게 유도 클래스에서 대입 연산자가 호출되어도 기초 클래스의 대입 연산자가 호출되지 않는다.
	- 이는 유도 클래스의 대입 연산자 부분에서 기초 클래스의 대입 연산자 호출을 따로 명시해야 한다는 의미이다.
	- 따로 명시하지 않을 경우 기초 클래스의 대입 연산자는 호출되지 않아 유도 클래스의 멤버만 복사되는 경우가 발생하낟.
4. 이니셜라이저가 성능 향상에 도움을 주는 이유
 1) 이니셜라이저는 생성과 동시에 초기화가 이루어진다.
	> 따라서, 초기화 과정에서 생성자만 호출된다.
 2) 단순한 대입 연산자를 통한 초기화는 생성과 초기화가 따로 이루어진다.
	- 즉, 선언과 초기화를 별도의 문장에서 진행하는 형태로 이루어진다.
	- 이는 선언을 할 때 생성자가, 초기화를 할 때 대입 연산자가 호출되어 함수를 2번 이상 호출하게 한다.
 3) 위 같은 이유 때문에 이니셜라이저를 이용하면 함수의 호출 횟수가 줄어들어 성능향상이 된다.
*/