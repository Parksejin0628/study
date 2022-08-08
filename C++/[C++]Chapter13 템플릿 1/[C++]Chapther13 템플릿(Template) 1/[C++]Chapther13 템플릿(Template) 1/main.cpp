#include"Common.h"
#include"Point.h"

void que1();
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


/*
[Chatper13 템플릿(Template) 1]
<13.1. 템플릿(Template)에 대한 이해와 함수 템플릿>
1. 함수 템플릿
 1) 함수 템플릿
	- 함수 템플릿은 함수를 만들어 내는 틀과 같다.
	- 함수의 기능은 결정되어 있지 않지만 자료형은 결정되어 있지 않아 호출시 결정해야 한다.
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

*/