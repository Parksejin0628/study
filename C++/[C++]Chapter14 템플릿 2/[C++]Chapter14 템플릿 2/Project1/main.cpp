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
<14.3. 템플릿 인자>
1. 템플릿 매개변수, 템플릿 인자
	1) 템플릿 매개변수 : 템플릿을 정의할 때 결정되지 않은 자료형을 의미하는 T, T1/T2 등과 같은 문자를 '템플릿 매개변수'라고 한다.
		ex) template<typename T> 여기서 T를 템플릿 매개변수라고 보면 된다.
	2) 템플릿 인자 : 템플릿 매개변수로 전달되는 자료형 정보를 '템플릿 인자'라고 한다.
		ex) exampleFunction<int>(2, 3) 에서 int를 템플릿 인자라고 보면 된다.
2. 템플릿 매개변수에 변수 선언
	1) 템플릿 매개변수에 변수 선언
		- 템플릿 매개변수에는 함수처럼 변수를 선언할 수 있다.
			ex) template<typename T, int len>	이 부분에서 int len을 말한다.
		- 템플릿 매개변수에 변수를 선언하게 되면 그 자료형에 해당하는 템플릿 인자를 받게 된다.
			ex) 위 예시를 사용한 템플릿 함수의 경우 exampleFunction<double, 7> 와 같이 int형인 7을 템플릿 인자로 넘긴다.
		- 템플릿 매개변수에 변수를 선언할 경우 같은 자료형이라도 다른 값이 오면 다른 자료형으로 인식한다.
			ex) exampleFunction<int, 5>와 exampleFunction<int, 7>은 자료형인 int가 같지만 숫자가 다르므로 다른 자료형으로 인식하게 된다.
			> 만약 대입연산자 오버로딩으로 exampleFunction<int, len>.operator=(exampleFunction<int, len> other)와 같이 정의한 경우 
			  <int, 5>와 <int, 7>은 다른 자료형이므로 <int, 5> 템플릿 클래스 대입연산자에 <int, 7> 템플릿이 올 수 없는 것이다.
			> 이러한 성질은 다른 성질을 가진 템플릿 클래스끼리의 대입연산자 경우를 따로 만들지 않아도 컴파일 에러를 내기 때문에 따로 코드를 추가할 필요가 없다는 장점이 있다.
3. 템플릿 매개변수에 디폴트 값 지정
	1) 함수의 매개변수에 디폴트 값을 지정하듯 템플릿 매개변수에도 디폴트 값을 지정할 수 있다.
		ex) template<typename T = int, int len = 7>와 같이 선언
		ex) ExampleClass<> obj; 처럼 템플릿 클래스를 선언하면 전달하는 템플릿 인자가 없으므로 자동으로 ExampleClass<int, 7>로 정의되는 것이다.
<14.4. 템플릿과 static>
1. 함수 템플릿과 static 지역 변수
	1) 함수에서의 static 지역 변수
		- 함수에서 static 지역 변수를 사용한다면 한 번 초기화된 후 해당 함수 어디서든 그 값을 유지한다.
	2) 함수 템플릿의 static 지역 변수
		- 템플릿 함수는 전달된 템플릿 인자에 따라 다른 함수로 인식한다.
		- 따라서, 같은 템플릿 인자인 템플릿 함수에서는 같은 static 변수 값을 가진다.
			ex) exmapleFunction<int>함수의 static num값을 5로 초기화 한 후 7로 바꾸면 나중에 사용되는 exampleFunction<int>함수의 num값도 7인 것이다.
			ex) exampleFunction<int>함수에서 static num값을 7로 바꿔도 exampleFunction<double>함수에서는 static num 값이 다르다.
2. 클래식 템플릿과 static 지역 변수
	1) 클래스에서의 static 지역 변수
		- 클래스에서 static 지역 변수를 사용한다면 해당 클래스로 만들어진 모든 객체가 해당 static 지역 변수를 공유하게 된다.
	2) 클래스 템플릿의 static 지역 변수
		- 템플릿 클래스는 전달된 템플릿 인자에 따라 다른 객체로 인식한다.
		- 따라서, 같은 템플릿 인자인 템플릿 클래스에서는 같은 static 변수 값을, 다른 템플릿 인자인 템플릿 크랠스에서는 다른 static 변수 값을 지닌다.
			ex) ExampleClass<int>함수의 static num값은 모든 ExampleClass<int> 객체에서 공유한다.
			ex) ExmapleClass<int>함수의 static num값과 ExampleClass<double>함수의 static num 값은 공유하지 않고 서로 다르다.
3. static 멤버변수 초기화의 특수화
	1) 특정 템플릿 인자는 다르게 초기화하기
		- 다른 특수화와 마찬가지로 T값을 미리 정하면 된다.
			ex) template<>
				void ShowStaticValue<double>(void)
				{
					static double num = 3;
				};
			> 이렇게 하면 ShowStaticValue<int>에서는 원래 초기화 값으로 static 변수가 초기화되지만, ShowStaticValue<double>에서만 3으로 초기화 된다.
4. template<>를 언제 사용하는가?
	1) template<typename T> / template<> 각각 선언하는 경우
		- 일단, 템플릿 관련 정의를 할 때 템플릿의 일부 혹은 전부를 정의한다고 컴파일러에게 알리는 역할이다.
		- T에 대한 정보가 필요하면 <typename T>를 붙이고 필요하지 않다면 template<>만 선언한다.
	2) 간단하게 생각하기
		- 템플릿에 관련된 정의를 할 때 template<이 안에는 결정되지 않은 자료형에 대한 템플릿 매개변수 이름만 넣는다>
*/                                               