#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	
	
	return 0;
}

/*
[Chapter06 friend와 static 그리고 const]
<6-1. const와 관련해서 아직 못다한 이야기> 
1. const 객체
 1) 객체로 변수처럼 상수화가 가능하다. 이는, 이 객체의 데이터 변경을 허용하지 않는다는 의미이다. 
 	ex) const SimpleClass obj(20);
 2) 상수화된 객체는 멤버함수 중 const 선언이 된 멤버함수만 호출이 가능하다.
 	- 데이터 변경이 이루어지는 경우가 아에 없도록 하기 위해서이다.
	- 이 때문에 우리는 가능하다면 데이터를 변경하지 않는 함수를 const로 선언함으로써 const 객체도 사용할 수 있도록 해야한다. 
2. const선언 함수 오버로딩
 1) const 선언 유무만으로도 함수 오버로딩이 될 수 있다.
 	ex) SimpleFunc(int num) / SimpleFunc(int num) const 가 존재할 때 이 둘은 함수 오버로딩이 된 다른 함수이다.
 2) 인자의 종류와 갯수가 같으나 const 선언만 다른 함수 오버로딩이 호출되는 조건은 다음과 같다.
 	- 호출하는 객체가 일반 객체일 경우 일반 함수를 호출한다.
	- 호출하는 객체가 const 객체일 경우 const 함수를 호출한다. 
	
<6-2. 클래스와 함수에 대한 friend 선언>
1. friend란?
 1) friend는 friend로 선언한 대상(객체나 함수)이 해당 선언이 있는 클래스의 private 멤버 접근을 허용한다는 의미이다.
 	ex) SimpleClass 안에서 'friend 함수' 선언을 할 경우 해당 함수에서 SimpleClass의 private 멤버에 접근할 수 있다.
		Simpleclass 안에서 'firend 객체' 선언을 할 경우 해당 객체에서 SimpleClass의 private 멤버에 접근할 수 있다.
 2) friend 선언은 한 방향이다. 따라서, 양쪽 객체의 private 멤버를 공유하려면 양쪽 다 friend 선언을 해야한다.
 	ex) 클래스 A에서 firend B를 하면 B에서는 A의 private에 접근할 수 있으나 A가 B의 private에 접근할 수 있다는 의미는 아니다.
 3) 하지만, friend 선언은 정보은닉을 무너뜨리기에 가급적 사용하지 않아야 한다.
 	- 나름의 기준이 설 때 까지는 아에 사용하지 않는 것이 좋다.
2.클래스 이름 선언
 1) 함수 선언처럼 클래스 이름만 미리 선언하는 방법이 있다.
 	ex) class SimpleClass;
	- 이 경우 다른 곳에서도 해당 클래스가 있다는 사실을 인지할 수 있다.
 2) 클래스 안에서 friend class Girl 와 같은 문장을 선언할 경우
 	- Girl은 클래스 이름이다.
	- 그리고 friend로 선언한다.
 3) 클래스의 이름을 미리 선언하는 습관을 들이면 좋아 보인다.  


*/
