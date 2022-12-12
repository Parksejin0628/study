#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

struct Point
{
	int xpos;
	int ypos;
	
	void MovePos(int addX, int addY)
	{
		xpos += addX;
		ypos += addY;
	}
	
	void ShowPosition()
	{
		cout<<"["<<xpos<<" ,"<<ypos<<"]"<<endl;
	}
	
	void AddPoint(const Point &otherPoint)
	{
		xpos += otherPoint.xpos;
		ypos += otherPoint.ypos;
	}
};

class Calculator
{
	private:
		int countAdd;
		int countMin;
		int countMul;
		int countDiv;
	public:
		double Add(double num1, double num2);
		double Min(double num1, double num2);
		double Mul(double num1, double num2);
		double Div(double num1, double num2);	
		void init();
		void ShowOpCount();
};

class Printer
{
	private:
		char savedString[50];
	public:
		void SetString(char* string);
		void ShowString();	
};

void que3_1();
void que3_2();

int main(void) 
{
	int num;
	que3_1();
	que3_2();
	
	cin>>num;
	
	return 0;
}

void que3_1()
{
	/*문제 : 2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 정의한 뒤 해당 구조체를 기반으로 함수를 정의한다.
	 		 단, 구조체 안에 함수를 정의하여 다음의 형태로 구성해야 한다. (구조체 함수 정의하기 문제)
	*/
	Point pos1 = {12, 4};
	Point pos2 = {20, 30};
	
	pos1.MovePos(-7, 10);
	pos1.ShowPosition();	//[5, 14] 출력 
	
	pos1.AddPoint(pos2);	//[25, 44] 출력  
	pos1.ShowPosition();
	 
	return;
}

void que3_2()
{
	/*
	문제1 : 계산기 기능의 Calculator 클래스를 정의해 보자. 기본적으로 지니는 기능은 덧셈, 뺄셈, 곱셈 그리고 나눗셈이며, 연산을 할때마다 어떠한 연산을 몇 번 수행했는지 기록되어야 한다.
	 	    단, 멤버변수는 private로, 멤버함수는 public으로 선언하자. 
	*/
	Calculator cal;
	cal.init();
	cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
	cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
	cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
	cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
	cal.ShowOpCount(); 
	
	/*
	문제2 : 문자열 정보를 내부에 저장하는 Printer라는 이름의 클래스를 디자인하자. 이 클래스의 두가지 기능은 문자열 저장, 문자열 출력이다.
	        멤버변수는 private으로, 멤버함수는 public으로 선언하자. 
	*/
	Printer pnt;
	pnt.SetString("Hello world!");
	pnt.ShowString();
	
	pnt.SetString("I love C++");
	pnt.ShowString();
	
	return;
}

double Calculator::Add(double num1, double num2)
{
	countAdd++;
	return num1 + num2;
}

double Calculator::Min(double num1, double num2)
{
	countMin++;
	return num1 - num2;
}

double Calculator::Mul(double num1, double num2)
{
	countMul++;
	return num1 * num2;
}

double Calculator::Div(double num1, double num2)
{
	countDiv++;
	return num1 / num2;
}

void Calculator::init()
{
	countAdd = 0;
	countMin = 0;
	countMul = 0;
	countDiv = 0;
}

void Calculator::ShowOpCount()
{
	cout<<"덧셈:"<<countAdd;
	cout<<" 뺄셈:"<<countMin;
	cout<<" 곱셈:"<<countMul;
	cout<<" 나눗셈:"<<countDiv;
	cout<<endl;
	
	return; 
}

void Printer::SetString(char* string)
{
	strcpy(savedString, string);
	
	return;
}

void Printer::ShowString()
{
	cout<<savedString<<endl;
}

/*
[Chapter03 클래스의 기본]
3.1. C++에서의 구조체
 1) 구조체 안에 함수를 삽입하면 데이터를 전달하지 않아도 구조체 안에있는 데이터에 접근이 가능하다.
 2) 특정 구조체만을 위한 enum상수를 선언하기 위해서는 두가지 방법이 있다. 구조체 안에 직접 선언하는 방법과 이름공간을 이용해 상수가 사용되는 영역을 명시하는 방법이 있다.
 3) 구조체는 클래스의 일종이다.

3.2. 클래스(Class)와 객체(Object)
 1) 클래스는 기본적으로 외부에서 접근을 허용하지 않는 변수와 함수의 집합체이다.
   - 멤버변수 : 클래스를 구성하는 변수
   - 멤버함수 : 클래스를 구성하는 함수
 2) 클래스는 선언과 동시에 초기화가 불가능하며 변수와 함수의 접근 허용 범위를 별도로 선언해야한다.
   - private: 클래스 내에서만 접근 허용
   - public: 어디서나 접근 가능
   - protected: 상속관계 혹은 유도클래스에서만 접근 허용
 3) 클래스로 선언된 변수를 객체라고 한다.

3.3. 객체지향 프로그래밍의 이해
 1) 객체지향 프로그래밍은 현실에 존재하는 것을 객체로 등장시키고 객체의 행위를 실체화 시키는 프로그래밍이다.
 2) 객체는 상태(state)와 행동(behavior)으로 구성되어있다.
   - 상태(state) : 객체의 상태정보, 데이터 등을 의미한다. 주로 멤버변수로 표현된다.
   - 행동(behavior) : 객체의 행동, 기능 등을 의미한다. 주로 멤버함수로 표현된다.
 3) C++에서 정의하는 객체 생성 방법은 두가지이다.
   - 일반적인 변수의 선언 방식 : ClassName objname;
   - 동적 할당 방식 : ClassName *ptrObj = new ClassName;

*/


/*
[Chapter 03 클래스의 기본]
// 배우는 내용이 많은 것에 비해 실습할 문제는 적으므로 따로 하나의 예시를 만들면 좋을 듯 하다. 
3.1. C++에서의 구조체
 1) C와 비교되는 C++에서의 구조체 변수 선언  
  - C++는 typedef 선언을 하지 않아도 구조체 변수를 선언할 때 struct를 붙이지 않아도 된다. (정의가 아닌 선언이다.)
  	ex) C에서의 구조체 변수 선언 : struct Car basicCar 
  		C++에서의 구조체 변수 선언 : Car BasicCar (typedef 별도 사용 X)
 2) 구조체 안에 함수 삽입
  - 데이터를 묶은 구조체가 생긴다면 해당 구조체만을 위한 함수가 필요할 수 있다. (종속적인 함수)
  - 기존 C언어에서는 전역함수의 형태로 만들어야 했기 때문에 구조체에 종속되었다는 느낌도 잘 들지 않고 다른 데이터에서 함수에 접근할 가능성도 있었다.
  - C++에서는 구조체 안에 함수를 삽입할 수 있어서 구조체에 종속된 함수를 만들 수 있다.
  - 구조체안에 함수를 종속하면 별도로 데이터를 전달하지 않아도 구조체 안에 있는 데이터에 직접접근할 수 있다.
  	ex) C언어에서 전역함수로 선언한 경우 : void Fun1(struct Car basicCar);
	  	C++언어에서 종속된 함수로 선언한 경우 : void Fun1();
		즉, 데이터를 전달하지 않아도 구조체의 데이터를 사용할 수 있다.
  - 구조체 변수를 여러 개 만들더라도 함수가 여러개 생성되는 것이 아닌 하나의 함수를 구조체들이 공유하는 형태로 한다.
  - 구조체에 함수가 있다 해도 초기화의 대상은 변수이기 때문에 초기화 방법은 달라지지 않는다. 
 3) 구조체 안에 enum 상수 선언
  - 해당 구조체 안에서만 필요한 상수들이 존재할 수 있다. 기존 C언어에서는 define하거나 enum으로 전역범위에서 열거했어야 했다.
  - C++에서는 구조체 안에 열거형 enum을 선언해서 구조체 내에서만 유효한 상수를 정의할 수 있다.
 4) 또다른 enum 상수 선언, 이름공간 이용
  - 구조체 안에 열거형을 넣는 방법 외에도 이름 공간을 이용해 상수가 사용되는 영역을 명시하는 것도 또 다른 방법이다.
  	ex) namespace CAR_CONST { enum { ID_LEN = 20, ...}; } / struct CAR{ char gameID[CAR_CONST::ID_LEN]; ... } 
	    이처럼 이름 공간에 상수가 사용되는 영역을 명시한 후 구조체 안에서 사용하면 된다.
  - 이렇게 이름 공간을 사용함으로써 구조체 안에 enum이 있는 것 보다 가독성이 좋아지며 몇몇 구조체들 사이에서만 사용하는 상수를 선언할 때도 유용하다.
 5) 구조체 안에 삽입한 함수를 외부에서 정의하기
  - 프로그램을 분석할 때는 흐름, 골격 위주로 분석하는 경우가 많다.
  - 따라서, 구조체를 보는 순간 구조체 안에 선언된 변수, 정의되어 있는 함수의 정보가 한 눈에 들어와야 한다. 그러나, 구조체 안에 함수를 정의하면 한 눈에 함수 정보가 들어오지 않는다.
  - 이러한 문제를 해결하기 위해 구조체 안에만 함수 원형을 선언하고, 정의를 외부에서 할 수 있다.
  - 구조체 외부에서 구조체::함수명() { ... } 와 같은 형태를 통해 구조체 외부에서 함수를 정의할 수 있다.
  	ex) struct Car{... void ShowCarState();...} / void Car::ShowCarState() { ... } 이처럼 구조체 밖에서 정의할 수 있다.
  - 구조체 안에 함수가 정의되어 있으면 함수를 인라인으로 처리한다는 의미이다. 그런데, 구조체 밖으로 빼내면 이러한 의미가 사라진다.  따라서, 키워드 inline을 이용해 인라인 처리를 명시적으로 지시할 필요가 있다.
  	ex) inline void Car::ShowCarState() { ... } 
 6) 사실 구조체는 클래스의 일종
  - C++에서 구조체는 클래스의 일종으로 간주된다.
  - 때문에, 구조체 안에 함수를 정의할 수 있었다.
 
3.2. 클래스(Class)와 객체(Object)
 1) 클래스란?
  - 내가 여태까지 익힌 구조체에서 struct 대신 class를 쓰면 클래스가 된다.
  	ex) struct Car -> class Car
 2) 구조체와 비교되는 클래스의 특징
  - 함수 선언과 동시에 초기화가 불가능하다.
  	ex) Car car3; (O) / Car car5 = { ... }; 
  - 별도로 접근과 관련한 선언을 하지 않으면, 클래스 내에 선언된 변수와 함수는 클래스 밖에서 접근하는 것을 허용하지 않는다.
  	> 즉, 여태까지 구조체에서 했던 것 처럼 메인함수에서 클래스의 변수와 함수에 접근하는 것은 일반적으로 불가능하다.
  - 따라서, 클래스는 정의를 하는 과정에서 각각의 변수와 함수의 접근 허용범위를 별도로 선언해야한다. 이것이 구조체와 클래스의 유일한 차이점이다.
  - 이러한 접근 허용범위는 접근제어 지시자를 통해 선언한다. 
 3) 접근제어 지시자(접근제어 레이블)
  - C++에서의 접근제어 지시자는 세가지가 존재한다. 
   > public : 어디서나 접근이 가능하다 
   > protected : 상속관계 혹은 유도클래스에서 접근을 허용한다. 이 부분은 상속과 관련이 있으니 나중에 살펴본다. 
   > private : 클래스 내에서만 접근허용
  - 접근제어 지시자를 통해 선언하는 방법은 크게 두가지이다.
   > 자료형 앞에 명시하는 경우
   	ex) private int num = 0;
   > 이전에 :연산자를 통해 이후에 등장하는 변수나 함수의 접근을 선언해둔경우
   	ex) private:
	   		int num = 0;
			int ...
  - 만약 클래스 내에 함수의 선언만 있고 정의는  밖으로 빼낸 경우도 함수가 클래스 내에 있으므로 private로 선언된 변수나 함수에 접근할 수 있다. 
  - 구조체는 변수나 함수가 기본적으로 public, 클래스는 변수나 함수가 기본적으로 private로 선언된다. 
  - 접근제어 지시자는 특정 위치정보르르 알리는 레이블(라벨)이기 때문에 콜론(:)이 붙는다. 
 4) 객체
  - 앞에서 다룬 구조체와 클래스는 C++에서 변수를 넘어선 기능을 가지고 있다. 따라서, C++에서는 이들을 변수가 아닌 '객체(Object)'라고 부른다.
  - 클래스를 구성하는 변수를 '멤버변수'라고 한다.
  - 클래스를 구성하는 함수를 '멤버함수'라고 한다.
 5) 파일분할
  - 클래스를 사용하는 프로그램에서 파일분할을 할 때는 클래스의 변수, 함수선언은 헤더파일에, 함수에 대한 정의는 소스파일에 저장한다.
   > 다른 문장에서 해당 클래스를 사용할 때 필요한 변수, 함수의 선언부분만 헤더파일에 저장을 해서 쉽게 파악이 될 수 있고 쉽게 포함될 수 있도록 한다.
   > 다른 문장에서 컴파일 할 때 영향을 주지 않는 함수의 정의부분은 소스파일에 저장을 하여 링커를 이용해 하나의 실행파일로 묶는다. 
   	ex) Car.h에는 int fuelGauge / void Accel(); 정도의 내용만 들어간다.
	    Car.cpp에는 Accel()함수에 대한 정의가 담겨져 있다.
  - 만약 멤버함수에 인라인 함수가 있을 경우 해당 인라인 함수의 정의 부분은 선언부분과 같은 파일에 있어야 한다.
   > 인라인 함수는 컴파일하는 과정에서 함수의 몸체 부분이 선언 부분을 대체하는데, 파일을 분리해둘 경우 컴파일 할 때 대체할 몸체부분이 없으므로 오류가 발생한다. 
   
3.3. 객체지향 프로그래밍의 이해
 1) 객체지향 프로그래밍이란?
  - C++은 객체지향 언어이다. 따라서, 객체지향에 대한 이해가 필요하고 이에 앞서 객체에 대한 이해가 필요하다.
  - 객체(Object)란 우리 주변에 존재하는 모든 사물, 물건 등 대상을 의미한다. 
  	ex) 나는 친구와 밥을 먹는다. 에서 객체는 나, 친구, 밥 이다.
  - 객체지향 프로그램밍에서는 현실에 존재하는 객체를 등장시키고 객체의 행위도 실체화 시키는 프로그래밍이다. 
  	ex) 객체 지향 프로그래밍에서는 '친구' 라는 객체를 등장시키고 '밥을 먹다'라는 객체의 행위까지 실체화 시킨다.
 2) 객체의 구성
  - 객체는 크게 상태(state)와 행동(behavior)으로 구성되어있다.
   > 상태(state) : 객체의 상태정보, 데이터 등을 의미한다. 주로 멤버변수로 표현된다. 
   	ex) 친구의 '나이', '몸무게' 
   > 행동(behavior) : 객체의 행동, 기능 등을 의미한다. 주로 멤버함수로 표현된다.
    ex) 친구가 하는 행동인 '밥먹기', '걷기'
 3) 객체의 정의 
  - 객체를 생성하기 위해서는 객체의 틀을 정의할 필요가 있다. 이는 우리가 앞서 배운 클래스이다.
   > 클래스는 멤버변수와 멤버함수를 갖고 있는데 이는 각각 객체에서 상태(state), 행동(behavior)을 가리킨다.
  - 객체 즉, 클래스를 정의할 때 상수로써 사용하기 위한 변수가 필요할텐데 이 때는 변수를 대문자로 선언한다.
  	ex) int APPLE_PRICE;
   > const로 상수화 하고 싶지만 그럴 수 없다. 상수는 선언과 동시에 초기화를 해야하지만, 클래스는 멤버변수의 선언에서 초기화를 허용하지 않는다. 
   > 이는 나중에 생성자에서 답을 찾을 수 있을 것이다. 
  - 객체 즉, 클래스에서는 접근 지시 제어자를 사용하지 않은 경우 기본적으로 private로 선언되기 때문에 private를 따로 명시하지 않고 생략하는 경우도 있다.
 4) 객체의 생성
  - 정의한 클래스의 이름으로 함수를 호출하는 것은 불가능하다. 가능해 보이지만 이는 객체가 아닌 객체의 '틀'이기 때문이다.
  - 따라서, 클래스의 접근 혹은 호출을 위해서는 객체를 생성해야 한다.
  - C++에서 정의하는 객체생성 방법은 두 가지이다.
   > 일반적인 변수의 선언 방식
   	ex) ClassName objname;
   > 동적 할당방식(new)
    ex) ClassName *ptrObj = new ClassName;
 5) 메시지 전달(Message Passing)
  - 하나의 객체가 또다른 객체에 메시지를 전달하는 방법은 함수를 통해 이루어진다.
  - 함수의 매개변수에 다른 객체를 포함시켜 함수를 호출시키는 방법이다.
  	ex) FruitBuyer::BuyApples(FruitSeller &seller, int money)
	  여기서 &seller를 통해 다른 객체를 호출한다.
  - 이러한 형태의 함수 호출을 '메시지 전달(Message Passing)'이라고 한다. 
 


*/
