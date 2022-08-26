#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main(void)
{


	return 0;
}

/*
[Chapter14 템플릿(Template) 2]
<14.1. Chapter 13에서 공부한 내용의 확장>
1. 템플릿 클래스의 객체를 자료형으로 하는 템플릿 클래스
 1) 이름이 독특한 객체일 뿐이다.
	- 템플릿 클래스의 객체는 '객체명<자료형>'으로 이름이 정해진 객체라고 생각하면 간단하다.
	- 즉, 템플릿 클래스의 객체를 자료형으로 하는 또다른 템플릿 클래스는 그저 자료형에 해당 템플릿 클래스의 객체를 넣으면 된다.
		ex) BoundCheckArray<Point<int>> ...
 2) typedef로 간편하게 바꾸기
	- typedef를 통해 템플릿 클래스의 객체의 이름을 간단히 할 수 있다.
		ex) typedef Point<int> Point_INT
		ex) typedef Point<int>* Point_PTR;
2. 특정 템플릿 클래스의 객체를 인자로 받는 일반함수 정의 및 friend 선언
 1) 템플릿 클래스의 객체를 자료형으로 일반함수를 정의할 수 있으며 이 함수를 friend 선언하는 것도 가능하다.
	ex) Point<int> exampleFunction(const Point<int>& pos1, const Point<int>& pos2)
	ex) friend Point<int> exampleFunction(const Point<int>& pos1, const Point<int>& pos2)

<14.2. 클래스 템플릿의 특수화(Class Template Specialization) >
1. 클래스 템플릿의 특수화
 1) 클래스 템플릿 특수화의 정의 및 이점
	- 클래스 템플릿의 특수화는 특정 자료형에 대한 템플릿을 정의하여 특정 자료형을 기반으로 클래스 템플릿을 만들 경우 다른 기능을 적용할 수 있게 해주는 것이다.
	- 클래스 템플릿의 특수화 특정 자료형이 필요로 하는 기능을 추가하는 등 예외상황을 처리하는데 큰 도움을 준다.
 2) 클래스 템플릿 특수화 방법
	- 이미 정의된 클래스 템플릿이 있을 때, template<>를 먼저 선언해 특수화임을 명시하고 클래스 템플릿 이름 뒤에 <특정 자료형>을 붙여 정의한다.
		ex) template<>
			class exampleClass<int>
			{
				특정 기능
			};
2. 클래스 템플릿의 부분 특수화
 1) 클래스 템플릿의 부분 특수화
	- 결정되지 않은 자료형의 수가 늘어나더라도 특수화가 가능하다.
		ex) template<typename T1, typename T2>
			class exampleClass<T1, T2>
			{
			...
			}
			template<>
			class exampleClass<int, char>		이 부분
			{
				...
			}
	- 결정되지 않은 자료형의 수가 2개 이상일 경우 전부 특수화를 하는 것이 아닌 부분만 특수화를 할 수 있는데 이것을 클래스 템플릿의 부분 특수화라고 한다.(class template partial specialization)
		ex) template <typename T1>			결정되지 가않은 자료형인 T1을 명시하고
			class exapmleClass<T1, int>		2번째 자료형인 int만 특수화
			> 이런 경우 두 번째 인수가 int인 경우 해당 특수화된 클래스를 정의하게 된다.
 2) 전체 특수화 vs 부분 특수화
	- 만약 모든 자료형을 결정하여 특수화 한 것과 부분 특수화 한 클래스 템플릿이 자료형이 겹칠 때가 있다.
		ex) exampleClass<char, int>특수화와 exampleClass<T1, int> 특수화가 존재할 경우
	- 이런 상황에서는 전체 특수화가 부분 특수화보다 우선순위가 높다.
		ex) 위 예시에서는 결국 exampleClass<char, int>특수화가 적용된다.
		> 특수화 깊이가 더 깊을수록 우선순위인 것이다. <T1, int>는 int만 2번째에 있으면 되는 특수화이므로 얕은 반면 <char, int>는 딱 하나의 경우만 있는 깊은 특수화이기에 우선순위가 높게 된 것이다.
*/                                               