#include<iostream>
#include"Point.h"

using std::cout;
using std::cin;
using std::endl;

void que1();

int main(void)
{
	que1();

	return 0;
}

void que1()
{
	//문제1,2,3 동시풀이
	/*
	<문제1>
	Point 클래스에 대해서 다음 조건을 만족하는 형태로 - 연산자를 오버로딩 해보자.
		> 전역함수 기반으로 오버로딩
		> 멤버 별 - 연산의 결과를 담은 Point 객체 변환
	<문제2>
	Point 클래스에 대해서 다음 조건을 만족하는 형태로 +=연산자와 -=연산자를 오버로딩 해보자.
		> 멤버함수 기반으로 오버로딩
		> 연산 'pos1 += pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 증가
		> 연산 'pso1 -= pos2'의 결과로 pos1의 멤버변수 값이 pos2의 멤버변수 값만큼 멤버 별 감소
		> 연산의 결과로 값이 증가 및 감소한 pos1의 객체를 반환하도록 (이왕이면 참조형으로 반환하도록) 연산자 오버로딩
	<문제3>
	Point 클래스에 대해서 다음 조건을 만족하는 형태로 == 연산자와 != 연산자를 오버로딩 해보자.
		> 둘 다 전역함수의 형태로 오버로딩
		> 연산 'pos1 == pos2'의 결과로 모든 멤버의 값이 같다면 true, 그렇지 않다면 false 반환
		> 연산 'pos1 != pos2'의 결과로 모든 멤버의 값이 같다면 false, 그렇지 않다면 true 반환
		> 연산자 == 를 먼저 오버로딩 한 다음에, 이를 이용하는 형태로 != 연산자를 오버로딩
	*/
	Point pos1(2, 5);
	Point pos2(1, 3);
	Point pos3 = pos1 - pos2;
	bool result;

	cout << "-연산 결과 : ";
	pos3.printPos();

	pos3 = pos1 += pos2;
	cout << "+=연산 결과 : ";
	pos3.printPos();

	pos3 = pos1 -= pos2;
	cout << "-=연산 결과 : ";
	pos3.printPos();

	result = pos1 == pos2;
	cout << "==연산 결과 : "<<result<<endl;

	result = pos1 != pos2;
	cout << "!=연산 결과 : " << result << endl;
}

/*
[Chapter10 연산자 오버로딩1]
<10.1. 연산자 오버로딩의 이해와 유형>
1. 연산자 오버로딩
 1) 연산자 오버로딩은 'operator' 키워드와 '연산자'를 묶어 함수의 이름을 정의하면 객체에서도 연산자를 이용한 함수의 호출이 가능하게 해준다.
	> 사용방법 : operator+ 와 같이 operator와 연산자로 구성된 함수를 정의해야 한다.
		ex) Point operator+(const Point &ref) { Point pos(xpos + ref.xpos, ypos + ref.ypos);  return pos} 와 같은 함수가 있을 때 Point 객체인 pos1, pos2도 pos1 + pos2연산이 가능하다.
	> 원리 : 기본 자료형(int, double 등)이 아닌 객체에서 연산자를 사용한다고 가정하자.
			pos1+pos2 라는 문장이 있다면 컴파일러는 각각 + -> .operator+ 와 pos2 -> (pos2) 로 변환하여 pos1+pos2 -> pos1.operator+(pos2)로 변환시키는 것이다.
	> -, *, 등 다른 연산자도 operator-, operator* 함수가 있다면 객체끼리 연산이 가능해진다.
 2) 연산자 오버로딩이라 불리는 이유는 같은 연산자를 사용해도 피연산자가 기본자료형이냐 객체이냐에 따라 결과가 달라지기 때문이다.
2. 연산자 오버로딩의 두 가지 방법
 1) 멤버함수에 의한 연산자 오버로딩
    > 컴파일러가 해석하는 방법 : pos1+pos2 -> pos1.operator+(pos2)
	> 방법 : 멤버함수 자리에 연산자 함수를 정의하면 된다.
 2) 전역함수에 의한 연산자 오버로딩
	> 컴파일러가 해석하는 방법 : pos1+pos2 -> operator+(pos1, pos2)
	> 방법 : 전역함수 자리에 연산자 함수를 정의한다. 단, 객체의 멤버에 접근할 수 있도록 해당 함수는 객체 내에서 friend 선언을 해두는 것이 좋다.
		ex) Point operator+(...)함수가 있을 경우 객체 내에서 friend Point operator+(...)를 선언해두어 전역함수에서도 멤버에 접근을 할 수 있게 해둔다.
 3) 우선순위 : 전역함수 기반과 멤버함수 기반으로 동시에 오버로딩 되어있을 경우 멤버함수 기반으로 오버로딩된 함수가 더 우선순위를 갖고 호출된다.
3. 오버로딩이 불가능한 연산자
 > . / .* / :: / ?: / sizeof / typeid / static_cast / dynamic_cast / cosnt_cast / reinterpret_cast
4. 연산자 오버로딩의 주의사항
 1) 연산자 오버로딩 함수도 const로 선언하는 것이 좋다. 보통 피연산자의 값은 변경하지 않기 때문이다.
 2) 본래 의도를 벗어난 형태의 연산자 오버로딩은 좋지 않다.
	ex) +연산인데 피연산자를 곱하는 경우 혼란을 가져올 수 있다.
 3) 연산자의 우선수위와 결합성은 바뀌지 않는다.
	> 즉, + 보다 *가 먼저 연산이 된다.
 4) 연산자 함수에는 매개변수의 디폴트 값을 설정할 수 없다.
 5) 기본 자료형의 연산자는 간섭할 수 없다.

*/