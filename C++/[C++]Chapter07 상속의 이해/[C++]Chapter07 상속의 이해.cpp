#include<iostream>
using std::cin;
using std::cout;
using std::endl;

namespace Car_h
{
	//Car.h	
	class Car
	{
	private:
		int gasolineGauge;
	public:
		Car(int gasoline = 0);
		int GetGasGauge() const;
	};
	
	class HybridCar : public Car
	{
	private:
		int electricGauge;
	public:
		HybridCar(int electric = 0, int gasoline = 0);
		int GetElecGauge() const;
	};
	
	class HybridWaterCar : public HybridCar
	{
	private:
		int waterGauge;
	public:
		HybridWaterCar(int water = 0, int electric = 0, int gasoline = 0);
		void ShowCurrentGauge() const;	
	};
	
	//Car.cpp
	//Car
	Car::Car(int gasoline) : gasolineGauge(gasoline)
	{
		
	}
	int Car::GetGasGauge() const
	{
		return gasolineGauge;
	}
	
	//HybridCar
	HybridCar::HybridCar(int electric, int gasoline) : Car(gasoline), electricGauge(electric)
	{
		
	}
	int HybridCar::GetElecGauge() const
	{
		return electricGauge;
	}
	
	//HybridWaterCar
	HybridWaterCar::HybridWaterCar(int water, int electric, int gasoline) : HybridCar(electric, gasoline), waterGauge(water)
	{
		
	}
	void HybridWaterCar::ShowCurrentGauge() const
	{
		cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
		cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
		cout<<"잔여 워터량: "<<waterGauge<<endl; 
	}
	
} 

using namespace Car_h; //#include"Car.h"

void que7_1();

int main(void)
{
	int end = 0;
	
	que7_1();
	
	
	cin>>end;
	
	return 0;
}

void que7_1()
{
	/*
		<문제1>
		앞서 상속관계에 놓여있는 클래스의 생성자 정의 및 호출 방식에 대해 설명하였다. 이 내용을 바탕으로 다음 클래스에 적절한 생성자를 삽입해보자.
		참고로 Car 클래스는 가솔린으로 동작하는 자동차를, HybridCar 클래스는 가솔린과 전기로 동작하는 자동차를, HybridWaterCar 클래스는 가솔린과 전기뿐만 아니라, 물도 동시에 연료로 사용될 수 있는 가상의 자동차를 표현한 것이다. 
		그리고 이의 확인을 위해 정의한 클래스를 사용하는 코드를 만들어보자. 
	*/
	Car normalCar(30);
	HybridCar hybridCar(20, 40);
	HybridWaterCar hybridWaterCar(10, 40, 70);
	
	cout<<"일반 차 기름량 : ";
	normalCar.GetGasGauge();
	cout<<"하이브리드 차 기름량 : ";
	hybridCar.GetGasGauge();
	cout<<"하이브리드 차 연료량 : "; 
	hybridCar.GetElecGauge();
	cout<<"하이브리드 워터차 연료량 : ";
	hybridWaterCar.ShowCurrentGauge(); 
	
	return;
}

/*
[Chapter07 상속(Inheritance)의이해]
<7.1. 상속에 들어가기에 앞서> 
1. 상속을 배우기 앞서
 - 상속은 문법적 요소보다도 상속이 가져다 주는 이점, 상속을 적용해야 할 때를 아는 것이 중요하다.
 - 따라서, 상속이 필요하게 된 문제를 제공하며 학습을 시작한다.
2. 좋은 소프트웨어의 조건
 - 모든 소프트웨어 설계에 있어서 중요시하는 것 중 일부는 다음과 같다.
	> 요구사항 변경에 대응하는 프로그램의 유연성
	> 기능의 추가에 따른 프로그램의 확장성
 - 좋은 프로그램은 사용자의 추가 요구에 대처가 가능해야 한다.
 	> 다시 말해, 요구를 들어주기 위해 프로그램의 대부분을 고치는 일은 없어야 한다.
	ex) 고용직 관리 프로그램에서 고용직/영업직/임시직 관리 프로그램으로 확장될 때 기존 프로그램에 영업직/임시직 내용 추가를 위해 대부분의 함수를 건든다면 유연성/확장성이 좋은 것이 아니다.
	> 최대한 적은 부분의 수정으로 프로그램을 변경/확장 시킬 수 있어야 좋은 프로그램이라 할 수 있다. 
 - 물론, 100% 유연성과 확장성을 만족할 수는 없지만, 조금이라도 더 유연하게 노력할 뿐이다. 
 - 이러한 필요에 의해 '상속(Inheritance)'의 필요성이 제기되었다. 

<7.2. 상속의 문법적인 이해>
1. 상속의 의미
 1) 상속은 다른 클래스의 멤버까지 객체 내에 포함하게 하는 기능이다.
 	> 단어의 의미처럼 다른 클래스의 멤버를 물려받는 것이다.
 	> 상속을 받은 클래스는 상속을 한 클래스의 멤버 변수, 멤버 함수를 포함한다. 
 2) 상속을 정의하는 방법은 다음과 같다. 
 	class 클래스이름 : public(private/protected) 상속을 주는 클래스이름
	ex) class SimpleClass : public otherClass
		{
			...
		};
 3) 상속을 해주는 클래스를 기초클래스, 상속을 받는 클래스를 유도클래스라고 한다.
 	> 나에게 익숙한 표현으로는 기초클래스->부모클래스, 유도클래스->자식클래스 이다. 
2. 기초클래스 멤버 사용 및 초기화
 1) 기초클래스의 멤버를 초기화 할때는 유도클래스 생성자의 이니셜라이저에서 기초클래스의 생성자를 호출하는 방식으로 진행한다.
 	ex) class derivedClass : public baseClass
	 	{
		 	...
			derivedClass(int n1, int n2) : baseClass(n1), num(n2)
			...
		};
	> 만약, 이니셜라이저에서 기초클래스의 생성자를 호출하지 않는 경우 인자가 없는 생성자를 호출한다.
		>> 즉, 위 예시에서 baseClass(n1)이 없으면 기초클래스의 baseClass()를 호출하는 것이다.
	> 결국, 유도클래스는 생성자가 2번 호출되는 셈이다. 
	> 이는 '클래스의 멤버는 해당 클래스의 생성자를 통해서 초기화해야 한다.'는 기본 원칙이 적용된다는 것을 알 수 있다. 
 2) 유도클래스가 기초클래스의 멤버를 포함하더라도 기초클래스의 멤버가 private로 선언된 경우는 직접 접근할 수 없다.
 	> private의 접근제한은 클래스 단위이기 때문에 다른 클래스인 유도클래스에서도 직접 접근할 수 없는 것이다. (상속은 객체 내에 포함이지 클래스 내에 포함이 아니다.) 
 	> 그러므로, 기초클래스의 함수를 이용하는 등 간접적으로 접근을 해야 한다.
	> 이는, 정보의 은닉이 상속을 주고 받는 객체 내에서도 진행이 된다는 것을 알 수 있다. 
 3) 생성자가 2번 호출되는 것처럼 소멸자도 2번 호출된다.
 	> 유도 클래스의 소멸자가 호출된 후 기초 클래스의 소멸자가 호출된다. 
3. 유도클래스의 객체 생성 과정 
 1) 객체에 대한 메모리가 할당된다.
 2) 유도클래스의 생성자를 호출하면서 이니셜라이저를 살핀다.
 3) 이니셜라이저에서 기초클래스의 생성자를 호출한다.
 	> 유도클래스의 이니셜라이저에 기초클래스의 생성자 호출 부분이 없다면 기초 클래스의 void 생성자를 대신 호출한다.
 4) 유도클래스의 이니셜라이저를 끝낸 뒤 생성자를 수행하면서 객체 생성이 완료된다.
4. 유도클래스의 생성/소멸 과정의 유의점
 1) 유도클래스의 생성 과정에서는 항상 기초클래스의 멤버 초기화가 유도클래스보다 먼저 실행된다.
 2) 유도클래스의 소멸 과정에서는 항상 유도클래스의 소멸자가 기초클래스의 소멸자보다 먼저 실행된다. 

*/ 
