#include"Common.h"
#include"Point.h"
#include"SmartPtr.h"

void que1();
void que2();


template <typename T>
void SwapData(T& pos1, T& pos2)
{
	T temp;
	temp = pos1;
	pos1 = pos2;
	pos2 = temp;

	return;
}

template <typename T>
T SumArray(T arr[], int len)
{
	T sum = 0;
	for (int i = 0; i < len; i++)
	{
		sum += arr[i];
	}
	return sum;
}

int main(void)
{
	que1();
	que2();

	return 0;
}

void que1()
{
	/*
	[문제 1]
	 - 인자로 전달되는 두 변수에 저장된 값을 서로 교환하는 SwapData라는 이름의 함수를 템플릿으로 정의해보자.
	   정의된 Point 클래스를 대상으로 값의 교환이 이뤄짐을 확인할 수 있도록 함수를 구성해보자.
	*/
	Point pos1(2, 5);
	Point pos2(3, 7);

	cout << "스왑 전" << endl;
	cout << "pos1 : ";
	pos1.ShowPosition();
	cout << "pos2 : ";
	pos2.ShowPosition();

	SwapData<Point>(pos1, pos2);

	cout << "스왑 후" << endl;
	cout << "pos1 : ";
	pos1.ShowPosition();
	cout << "pos2 : ";
	pos2.ShowPosition();

	/*
	[문제 2]
	 - 문제에 있는 SumArray 함수를 템플릿으로 정의하라. 그리고, 다양한 자료형의 배열을 대상으로 합을 계산하는 예제를 작성해보자.
	*/
	int num[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	cout << "int 형 합계 : " << SumArray<int>(num, 10) << endl;

	double numF[10] = { 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9, 11 };
	cout << "double형 합계 : " << SumArray<double>(numF, 10) << endl;

	return;
}

void que2()
{
	/*
	[문제]
	 - 앞선 챕터 11에서 공부한 스마트 포인터를 템플릿 형태로 정의해 어떤 객체도 참조할 수 있는 포인터가 되도록 해보자.
	*/
	SmartPtr<Point> sptr1(new Point(1, 2));
	SmartPtr<Point> sptr2(new Point(3, 4));
	sptr1->ShowPosition();
	sptr2->ShowPosition();
	sptr1->SetPos(10, 20);
	sptr2->SetPos(30, 40);
	sptr1->ShowPosition();
	sptr2->ShowPosition();


	return;
}

/*
[Chapter13 템플릿(Template) 1]
<13.1. 템플릿(Template)에 대한 이해와 함수 템플릿>
1. 함수 템플릿은 자료형이 결정되어 있지 않은 함수이다. 따라서, 호출시 자료형을 결정한다.
	> 기본 형태(T의 이름은 상관없으며 typename -> class로 교체 가능)
		template <typename T>
		T add(T num1, T num2)
		{
			return num1 + num2;
		}
	> 호출 방식 : 함수명<자료형>(매개변수);
		ex) add<double>(2.5, 9.5)
2. 함수 템플릿 선언의 특징
	> 매개변수에 템플릿 타입을 사용하지 않아도 된다.
		ex)	template <typename T>
			void ShowData(double num)
			{
				cout<<(T1)num<<endl;
			}
	> 템플릿 타입이 명시할 때 쉼표를 이용해 둘 이상도 가능하다.
		ex)	template <typename T1, typename T2>
			void print(T1 num1, T2 num2)
			{
				cout<<num1<<" "<<num2<<endl;
			}
3. 특정 자료형인 경우 다른 기능을 수행하고 싶다면 template<>를 선언하고 함수명 뒤에 <자료형>을 붙여 정의한다.
	ex)	template <>
		char* add<char*>(char* a, char* b)
		{
			strcat(a, b)
			return a;
		}

<13.2. 클래스 템플릿(Class Template)>
1. 함수 템플릿과 유사하게 클래스도 템플릿으로 정의가 가능하다.
	> 기본 형태
		template <typename T>
		class Point
		{
		private:
			T xpos, ypos;
		public:
			Point(T x=0, T y=0) : xpos(x), ypos(y) { }
		}
	> 호출 방식
		Point<int>(2, 3)
2. 기존 클래스처럼 선언은 클래스 안에서, 정의는 클래스 밖에서 할 수 있다. 단, T에 대한 정의와 클래스 명 뒤에 <T>가 붙어야 한다.
	ex)	template <typename T>
		T SimpleTemplate<T>::SimpleFunc(const T& ref)
		{ ... }
3. 헤더파일과 소스파일을 나눌 경우 컴파일 과정에서 헤더파일에 함수 몸통 부분이 와야하는데 (매크로처럼) 컴파일은 파일단위로 하기 때문에 (다른 파일을 참조하지 않기 때문에) 소스파일에 있는 템플릿 클래스가 만들어 질 수 없다.
	> 헤더파일에 선언, 정의를 모두 넣는 방법이 있다.
	> 정의에 대한 내용이 있는 소스파일을 include 한다.
*/

/*
[Chatper13 템플릿(Template) 1]
<13.1. 템플릿(Template)에 대한 이해와 함수 템플릿>
1. 함수 템플릿
 1) 함수 템플릿
	- 함수 템플릿은 함수를 만들어 내는 틀과 같다.
	- 함수의 기능은 결정되어 있지만 자료형은 결정되어 있지 않아 호출시 결정해야 한다.
 2) 기본 형태
	- 함수 템플릿의 기본 형태는 다음과 같다.
		template <typename T>
		T add(T num1, T num2)
		{
			return num1 + num2
		}
	- 기본 형태에서 중요한 것은 T의 타입을 나중에 결정한다는 template <typename T>의 선언과 T가 함수에 사용되었다는 점이다.
	- typename을 class로 바꿔도 된다.
	- 꼭 자료형의 이름이 T일 필요가 없다.
 3) 호출 방식
	- 템플릿 함수를 호출할 때는 함수명 뒤에 <자료형>을 붙여 함수의 자료형을 결정한다.
		ex) cout<< add<int>(15, 20) << endl;
			cout<< add<double>(15.5, 20.2) << endl;
	- <자료형>을 붙이지 않아도 매개변수 자료형에 따라 알아서 호출할 수 있다.
	- 하지만, 특정 상황에서는 <자료형>을 무조건 붙여야 하며 템플릿 함수라는 직관성을 얻을 수 있으므로 되도록이면 붙이는 것이 좋다.
 4) 템플릿 함수
	- 함수 템플릿에 의해 만들어진 함수를 '템플릿 함수'라고 한다.
	- 템플릿 함수는 호출될 때 전달된 자료형에 따라 함수가 만들어진다.
		ex) add<int>(15, 20)이라는 호출이 나오면
			int add<int>(int num1, int num2)
			{
				return num1 + num2
			}
			이라는 함수가 만들어지는 것이다.
	- 같은 형태의 함수를 호출하면 새로 만드는 것이 아닌 기존에 만든 함수를 재활용한다.
	- 함수를 만드는 것은 컴파일 과정에서 이루어지기 때문에 컴파일 속도가 느려질 뿐 실행속도에는 문제가 없다.
	- 일반 함수와 구별이 되기 때문에 일반함수와 함수명, 자료형이 같아도 구별되게 호출된다.
	- 템플릿 함수는 '생성된 함수(Generated Function)'으로도 불린다.
2. 다양한 템플릿 선언
 1) 매개변수가 기본자료형인 템플릿 선언
	- 매개변수에 템플릿 타입을 사용하지 않아도 함수 템플릿을 선언할 수 있다.
		ex) template <typename T>
			void ShowData(double num)
			{
				cout<<(T1)num<<endl;
			}
	- 단, 매개변수를 통해 자료형을 파악할 수 없기에 호출할 때 자료형을 반드시 지정해주어야 한다.
		ex) ShowData<int>(2.5)	(o)
			ShowData(2.5)		(x)
 2) 둘 이상의 형에 대한 템플릿 선언
	- 템플릿 타입을 명시할 때 쉼표를 이용해 둘 이상의 형에 대해 템플릿을 선언할 수 있다.
		ex) template <typename T1, typename T2>
			void print(T1 num1, T2 num2)
			{
				cout<<num1<<" "<<num2<<endl;
			}
		호출) print<int, double>(3, 2.5)
 3) 특수 상황에 대한 예외를 위한 템플릿 선언
	- 같은 이름의 템플릿 함수여도 특정 자료형에 따라 다른 기능을 수행하게 하고자 할 때 사용한다.
	- template<> 을 선언한 뒤 자료형타입을 결정한 함수를 정의한다.'
		ex) template <>
			char* add<char*>(char* a, char* b)
			{
				strcat(a, b)
				return a
			}
		> 이런식으로 특수 상황에 대처하기 위해 사용한다.
		> 호출 때 add<char*>(...)를 한다면 위 함수가 대신 호출되는 것이다.
		> <char *>는 생략해도 되지만 직관성을 위해 생략하지 않는 편이 좋다.
<13.2. 클래스 템플릿(Class Template)>
1. 클래스 템플릿
 1) 클래스 템플릿 정의
	- 함수를 템플릿으로 정의하듯 클래스도 템플릿으로 정의가 가능하다. 이 때 템플릿으로 정의된 템플릿을 클래스 템플릿(Class template) 라고 한다.
	- 정의 방법 : 함수와 유사하게 template<typename T>를 앞줄에 추가하고 나중에 정의할 자료형에 T를 사용하면 된다.
		ex) template <typename T>
			class Point
			{
			private:
				T xpos, ypos;
			public:
				Point(T x=0, T y=0) : xpos(x), ypos(y) { }
			};
	- 이러한 템플릿으로 만들어진 클래스를 템플릿 클래스(template class)라고 한다.
 2) 유의점
	- 템플릿 클래스를 호출할 때 역시 클래스 명 뒤에 자료형을 <자료형> 형태로 명시해야 한다.
		ex) Point<int>(2, 3)
	- 단, 템플릿 클래스를 호출할 때는 템플릿 함수와는 다르게 <자료형>을 생략할 수 없다.
2. 클래스 템플릿의 선언과 정의의 분리
 1) 선언과 정의 분리하기
	- 기존 클래스와 유사하게 멤버 함수를 클래스에 선언하고 외부에 정의하는 방식으로 선언과 정의를 분리할 수 있다.
	- 외부에 정의할 때는 앞줄에 template <typename T>를 붙여 T가 무엇인지 정의하고, 클래스명뒤에<T>를 붙여야 한다.
		ex) template <typename T>
			T SimpleTemplate<T>::SimpleFunc(const T& ref)
			{
				...
			}
	- template<typename T>를 붙이는 이유는 클래스의 선언과 다른 곳에 분리되어 있기 때문에 컴파일러가 T에 대한 정보를 찾을 수 없기 때문이다.
	- 클래스 뒤에 <T>를 붙이는 이유는 템플릿화된 클래스의 함수를 정의한다는 것을 명시하기 위해서이다.
 2) 파일 분리에 따른 문제점과 해결 방법
	- 헤더파일과 소스파일을 나눌 경우 컴파일이 파일 단위로 되기 때문에 컴파일 과정에서 템플릿 클래스가 만들어질 때 헤더파일에서는 파일 정보를 알 수 없다.
		> 헤더파일에는 멤버함수의 정의가 포함되어 있지 않기 때문이다.
		> 컴파일 과정에서는 다른 파일을 참조하지 않는다.
	- 이에 대한 해결방법은 크게 두 가지 이다.
		> 헤더파일에 생성자, 멤버함수의 정의를 모두 넣는다.
		> 해당 클래스를 사용하는 파일에 소스파일도 include한다.
			ex) #include "PointTemplate.h"
				#include "PointTemplate.cpp"
*/