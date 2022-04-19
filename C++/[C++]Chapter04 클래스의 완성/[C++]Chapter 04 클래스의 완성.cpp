#include<iostream>
using std::cout;
using std::cin;
using std::endl;

namespace FruitClass_h
{
	//FruitClass.h
	class FruitSeller
	{
	private:
		int APPLE_PRICE;
		int numOfApples;
		int myMoney;
		
	public:
		void InitMembers(int price, int num, int money);
		int SaleApples(int money);
		void ShowSalesResult() const;	
		bool setNumOfApples(int num);
		bool setMyMoney(int num);
		int getNumOfApples() const;
		int getMyMoney() const;
	};

	class FruitBuyer
	{
		int myMoney;
		int numOfApples;
	
	public:
		void InitMembers(int money);
		bool BuyApples(FruitSeller &seller, int money);
		void ShowBuyResult() const;
		bool setNumOfApples(int num);
		bool setMyMoney(int num);
		int getNumOfApples() const;
		int getMyMoney() const;
	};
	
	
	
	//FruitClass.cpp
	//FruitSeller
	void FruitSeller::InitMembers(int price, int num, int money)
	{
			APPLE_PRICE = price;
			numOfApples = num;
			myMoney = money;
	}
	int FruitSeller::SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
			
		return num;
	}
	void FruitSeller::ShowSalesResult() const
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl<<endl;
	}
	
	//FruitBuyer
	void FruitBuyer::InitMembers(int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	bool FruitBuyer::BuyApples(FruitSeller &seller, int money)
	{
		if(money < 0)
		{
			cout<<"잘못된 입력입니다."<<endl;
			return false;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
		
		return true;
	}
	void FruitBuyer::ShowBuyResult() const
	{
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl; 
	}
}

namespace Ring_h
{
	//ring.h
	class Point
	{
	private:
		int xpos, ypos;
	public:
		Point(int x, int y);
		void ShowPointInfo() const;
	};
	
	class Circle
	{
	private:
		Point pos;
		int radius;
	public:
		Circle(int x, int y, int rad);
		void ShowCircleInfo() const;
	};
	
	class Ring
	{
	private:
		Circle innerCircle;
		Circle outterCircle;
	public:
		Ring(int iX, int iY, int iRad, int oX, int oY, int oRad);
		void ShowRingInfo() const;
	};
	
	
	
	//ring.cpp
	//Point
	Point::Point(int x, int y) : xpos(x), ypos(y)
	{
		
	}
	void Point::ShowPointInfo() const
	{
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
	
	//Circle
	Circle::Circle(int x, int y, int rad) : pos(x, y), radius(rad)
	{
		
	}
	void Circle::ShowCircleInfo() const
	{
		cout<<"radius : "<<radius<<endl;
		pos.ShowPointInfo();
	}
	
	//Ring
	Ring::Ring(int iX, int iY, int iRad, int oX, int oY, int oRad) : innerCircle(iX, iY, iRad), outterCircle(oX, oY, oRad)
	{
		
	}
	void Ring::ShowRingInfo() const
	{
		cout<<"Inner Circle Info..."<<endl;
		innerCircle.ShowCircleInfo();
		cout<<"Outter Circle Info..."<<endl;
		outterCircle.ShowCircleInfo();
	}
	
}
using namespace FruitClass_h; //#include"FruitSeller.h"
using namespace Ring_h; //#include"ring.h"

void que4_1();
void que4_2(); 
void que4_3();

int main(void)
{
	int num = 0;
	
	que4_1();
	que4_2();
	que4_3();
	
	cin>>num; 
	
	return 0;
}

void que4_1()
{
	/*
	 문제 : Chapter03에서 제시한 과일장수 시뮬레이션 예제 FruitSaleSim1.cpp에서 정의한 두 클래스의 멤버변수를 0보다 작은 수를 전달할 수 없는 조건을 추가하자.
	        그리고 예제의 안전성을 높일 수 있도록 일부 함수를 const로 선언해보자. 
	*/	 
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"과일 판매자의 현황"<<endl;
	seller.ShowSalesResult();
	cout<<"과일 구매자의 현황"<<endl;
	buyer.ShowBuyResult(); 
		
	return;
}

void que4_2()
{
	/*
	문제 : Point 클래스를 기반으로 하여 (문제에서 제공하는 클래스) 원을 의미하는 Circle 클래스를 정의하자.
	 	   Circle 객체에는 좌표상의 위치 정보(원의 중심좌표)와 반지름의 길이 정보를 저장 및 출력할 수 있어야 한다.
		   그리고 정의한 Circle 클래스를 기반으로 Ring 클래스도 정의하자. 링은 두 개의 원으로 표현 가능하므로(바깥쪽 원과 안쪽 원), 두 개의 Circle 객체를 기반으로 정의가 가능하다.
		   참고로 안쪽 원과 바깥쪽 원의 중심좌표가 동일하다면 두께가 일정한 링을 표현하는 셈이 되며, 중심좌표가 동일하지 않다면 두께가 일정하지 않은 링을 표현하는 셈이 된다.
		   다음 문장에서 Init의 함수호출을 통해 전달된 1, 1, 4는 안쪽 원의 정보에 해당하며 (X, Y, 반지름), 이어서 전달된 2, 2, 9는 바깥쪽 원의 정보에 해당한다.
		   실행결과는 책에 예시와 같거나 유사해야 한다. 캡슐화에 따라 답이 달라지니 클래스를 정의할 때 캡슐화를 고민해보자. 그리고 나의 코드와 답을 비교해보자. 
	메모
	 - 목적은 Ring 클래스를 정의하는 것이다. 
	 - 반지는 각각 안쪽 원과 바깥쪽 원이 존재하기에 Circle 객체 2개가 필요할 것이다. 
	 - Circle안에 반지름, 위치 정보를 출력하는 기능을 넣는 것이 좋을 것이며 이는 Point클래스에서 해소할 수 있다. 
	 <Circle>
	  > 멤버변수 : Point pos / int radius 
	  > 멤버함수 : Init(int x, int y, int radius) (Point 변수에 좌표 설정, 반지름 설정) / ShowCircleInfo() (원의 반지름 출력 및 좌표 출력)
	 <Ring>
	  > 멤버변수 : Circle innerCircle / Circle outterCircle
	  > 멤버함수 : Init(int iX, int iY, int iRadius, int oX, int oY, int oRadius) / ShowRingInfo() 
	*/
	//현재 Circle, Ring 객계체 설계 및 구현을 해야 하는 단 
	Ring ring(1, 1, 4, 2, 2, 9);
	//ring.Init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	
	//주석처리 된 부분은 que4_3을 위해 수정한 것이다. 
	return;
}

void que4_3()
{
	/*
	문제1 : 앞에 제시한 que4_2의 클래스에 생성자를 정의해보자. 
	*/
	//문제 2부터 공부  
}


/*
[Chapter 04 클래스의 완성]
<4-1. 정보은닉(Information Hiding)>
1. 정보은닉의 등장 배경  
  - 좋은 클래스가 되기 위한 최소한의 조건을 꼽는다면 '정보은닉'과 '캡슐화'이다.
  - 개발하는 과정에서는 처음 개발자의 의도와 다르게 변수를 설정하는 실수가 많이 발생한다.
  	ex) xPos 변수에는 0~100의 값만 넣기로 했으나 개발 도중 실수로 -5를 넣었다.
  - 이러한 실수가 많이 발생하자 프로그래머의 실수에 대한 대책의 필요성이 나타났다.
  - 이러한 대책 중 하나로 '제한된 방법으로만 멤버변수에 접근을 허용하여 잘못된 값이 저장되지 않도록 돕고 실수가 쉽게 발견되도록 하는 것'이라는 개념이 등장했는데 이것이 바로 정보은닉이다.
2. 정보은닉
  - 정보은닉은 멤버변수를 private로 선언한 뒤 해당 변수에 접근하는 함수를 별도로 선언하여 안전한 형태로 멤버 변수의 접근을 유도하는 것이다.
   > 특정 함수라는 제한된 방법을 제외하고는 멤버 변수에 접근할 수 없도록 한다.
   > 외부 침투로부터 변수를 안전하게 보호한다. 
  - 멤버변수에 접근하는 함수에는 값의 조건을 설정한다.
   > 프로그래머의 실수를 방지한다.
  - 멤버 변수에 접근하는 함수는 반환값을 bool로 설정한다.
   > 만약 값의 조건에 어긋나는 값이 들어올 경우 false를 반환하고 에러 메시지를 보냄으로써 실수가 쉽게 발견되도록 한다.
3. 엑세스 함수
  - 멤버변수를 private로 선언하면서 클래스 외부에서의 멤버변수 접근을 목적으로 정의된 함수들이다.
  	ex) GetX : X값을 가져오는 함수 / SetX : X값을 설정하는 함수 
  - 엑세스 함수는 호출하지 않아도 정의를 해둔다.
   > 클래스의 정의 과정에서 당장은 필요하지 않아도 나중에 필요할 수 있다고 판단되는 함수들은 멤버에 포함시켜 정의해놓는 경우가 많다.
   > 엑세스 함수도 이러한 예씨 중 하나이다.
4. const 함수(const가 함수 명 뒤에)
  - 함수 뒤에 const가 붙는 경우가 있다.
  	ex) int GetX() const;
  - 이const는 이 함수 내에서는 '멤버변수'에 저장된 값을 변경하지 않는다는 의미이다. 
   > 다른 변수가 아닌 클래스의 '멤버변수'이다. 
  - const로 선언된 함수 내에서 멤버변수의 값을 변경하는 내용이 있을 경우 컴파일 에러를 발생한다.
   > 이를 통해 실수로 멤버변수의 값을 변경시키려 할 경우 컴파일 에러를 통해 바로 알 수 있다.
  - 또한, const로 선언된 함수 내에서는 const로 선언된 함수만 호출할 수 있다.
   > 멤버변수의 값이 변경될 가능성이 있는 경우를 모두 배제하는 것이다.
   > 이러한 기능은 해킹 등 외부 공격으로 부터 상당한 효과를 보일 것이다.
  - 심지어, 다른 클래스에서 const 참조자를 통해 객체를 받은 경우라도 해당 객체의 멤버함수가 const 선언이 아니라면 호출할 수 없다.
   > 효과는 위와 같다.
  - 따라서, 하나의 const를 사용하면 많은 부분에 const를 추가해야 하지만 그만큼 코드의 안전성은 높아진다.
  - 컴파일 에러 해결의 목적만으로 const를 쓸 것이 아니라 코드의 안정성을 위해 값의 변화가 없는 모든 함수에는 const를 추가하는 습관을 들이자. 
 
 <4-2. 캡슐화(Encapsulation)>
1. 캡슐화
 - 캡슐화의 의미 : 하나의 목적 하에 둘 이상의 기능이 모여 하나의 목적을 달성하는 것이다.
 - 같은 목적을 이루기 위한 기능들을 한 곳에 모으는 것이다.
  > 코드가 간결해지는 효과가 있다.
  > 객체들의 상호작용을 쉽게 파악할 수 있다. 
 - 간단히 말해 관련 있는 함수와 변수를 하나의 클래스로 묶는 것이다. 
2. 캡슐화가 무너지면 발생하는 문제
 1) 클래스의 상호관계가 복잡해지면서 프로그램 전체의 복잡도를 높인다.
 2) 객체의 활용이 매우 어려워진다.
 3) 진행순서가 중요한 경우 매우 위험한 구조가 될 수 있다. 
3. 캡슐화 자체는 개념이 어렵지 않지만 캡슐화의 범위를 결정하는 일이 쉽지 않기 때문에 캡슐화는 어려운 개념이다.
 - 경험 많은 객체지향 프로그래머를 구분하는 첫 번째 기준이 캡슐화일 정도이다.
 - 정답이란 것이 딱히 없이 프로그램의 성격과 특성에 따라 적용하는 범위가 달라지는 개념이기 때문이다. 
   
<4-3. 생성자(Constructor)와 소멸자(Destructor)>
1. 생성자 
 - 객체 생성시 딱 한번 호출되는 함수이다.
 - 클래스의 이름과 함수의 이름이 동일하고, 반환형을 선언하지 않으면 생성자로 정의된다. 
 	ex) class Simple Class { SimpleClass() { num1 = 0; num 2= 0; } (이부분이 생성자) };
 - 주로 객체의 생성과 동시에 초기화를 할 때 많이 사용한다.
 - 생성자를 정의할 경우 객체를 생성할 때 인자를 전달해야 한다.
 	ex) SimpleClass sc(20, 30);
	ex) SimpleClass sc = new SimpleClass(20, 30); 
2. 생성자의 오버로딩 / 디폴트값
 - 생성자도 함수이므로 오버로딩과 디폴트 값이 가능하다. 
 - 단, 오버로딩 혹은 디폴트 값을 사용할 때 매개변수를 아무것도 주지 않는 경우 객체 생성을 주의해야 한다.
  > SimpleClass sc();와 같이 인자를 주지 않는 void형태로 객체를 생성해서는 안된다.
  > SimpleClass sc;와 같이 괄호를 생략한 형태로 객체를 생성해야 한다. 
  > SimpleClass sc(); 이 문장이 SimpleClass 객체를 반환형으로 하는 함수의 원형을 선언한 것인지, 객체를 생성한 것인지 구별이 불가능하기 때문이다.
 - 매개변수를 아무것도 주지 않는 객체 생성은 다음 형태 중 하나를 선택해야 한다.
  > SimpleClass sc;
  > SimpleClass *ptr = new SimpleClass;
  > SimpleClass *ptr = new SimpleClass();
 - 따라서, 매개변수가 없는 객체를 생성할 때는 괄호를 생략하는 습관을 들이자.
3. 멤버 이니셜라이저 
 - 생성자에서 멤버변수를 선언과 동시에 초기화할 수 있는 기능이다. (객체의 경우 생성자를 호출한다는 의미이다.) 
  > 생성자 몸체에서 멤버변수를 초기화할 경우 선언과 초기화를 별도의 문장에서 하는 것으로 인식한다. 
 - 생성자 뒤에 : 변수/객체(값/인자) 형식으로 사용한다.
 	ex) SimpleClass(int num) : val(30) 				(변수 초기화) 
 	ex) SimpleClass(int num) : otherClass(20, 30)	(객체 초기화, 멤버변수로 이용되는 객체의 생성자를 호출한다는 의미) 
 - 멤버 이니셜라이저를 이용하다 보면 생서아즈이 몸체 부분이 비는 경우가 종종 발생한다. 
4. 멤버 이니셜라이저의 이점
 - 프로그래머는 일반적으로 이니셜라이저를 통해서 멤버변수를 초기화한다. 이는 다음 두 가지 이점 때문이다.
  1) 초기화의 대상을 명확히 인식할 수 있다. : 생성자 몸체부분에 num = 1로 하는 것보다 멤버 이니셜라이저를 사용하는게 초기화한다는 의미를 좀 더 명확하게 줄 수 있다. 
  2) 성능에 약간의 이점이 있다. : 후에 설명할 수 있다.
 - 멤버 이니셜라이저는 멤버변수 선언과 동시에 초기화하기 때문에 const 변수 및 참조자 선언이 가능하다!
  > 반대로 말하자면, const 변수를 사용하면 무조건 멤버 이니셜라이저를 사용해야 한다.
  	ex) const int APPLE_PRICE; ... SimpleClass() : APPLE_PRICE(30)
  > 참조자 또한 선언과 동시에 참조를 해야하기 때문에 멤버 이니셜라이저를 사용해야 한다.
  	ex) class BBB{ AAA &ref ... BBB(AAA &r) : ref(r) ... };
5. 디폴트 생성자 및 생성자 심화
 - 객체의 생성과정은 다음 3단계로 이루어진다.
  1단계) 메모리 공간의 할당
  2단계) 이니셜라이저를 이용한 멤버변수(객체)의 초기화
  3단계) 생성자의 몸체부분 실행
 - 모든 객체는 위의 세가지 과정중 메모리 공간 할당과 생성자의 호출까지 완료되어야 객체라고 할 수 있다. (이니셜라이저는 생략이 가능하다.)
  > 즉, 객체가 되기 위해서는 반드시 하나의 생성자가 호출되어야 한다. 
 - 따라서, 생성자가 없는 객체에도 디폴트 생성자라는 것이 자동으로 삽입된다. (아무런 기능을 수행하지 않는다.)
  > 생성자가 없는 경우에만 삽입되기 때문에 디폴트 생성자를 함수 오버로딩으로 사용하려는 목적은 불가능하다.
  > malloc 함수는 메모리 공간만 할당하기 때문에 생성자를 호출하지 않는다. 따라서, malloc 함수로 할당한 객체는 사실 객체가 아니기 때문에 malloc을 사용해서는 안된다.
 - 일반적으로, 생성자들은 객체의 생성이 클래스 외부에서 발생하기 때문에 public이지만, 클래스 내부에서만 생성자를 생성하는 경우에는 private로 선언이 가능하다.
  > 예를 들어, 함수 오버로딩을 통해 클래스 내부에서만 사용되는 생성자를 만든 경우 그 생성자는 private로 선언해도 된다.
  > 이러한 private 생성자 선언은 객체의 생성방법을 제한하고자 하는 경우에 매우 유용하게 사용된다. 즉, 정보은닉에 도움이 된다. 
  	ex) static 메소드를 사용하여 객체의 생성이 필요하지 않는 경우 실수로 객체를 선언하는 것을 방지하기 위해 사용
	ex) 프로그램에서 해당 객체를 하나만 사용하고 이 하나를 전부 공유해서 사용하는 경우 처음 객체 하나를 생성하는 멤버함수를 만든 후 객체를 선언하지 못하도록 하기 위해 사용 (싱클톤 기법) 
	ex) 두 개의 인자를 사용하는 생성자이지만 외부로부터 하나의 인자만 받고 싶을 때 public으로 하나의 인자를 받는 생성자를 선언하고 private로 두 개의 인자를 받는 생성자를 선언하여 클래스 내에서 생성자 호츨
6. 소멸자
 - 생성자와 반대로 객체가 소멸할 때 딱 한 번 호출되는 함수이다.
 - 클래스의 이름과 동일하게 함수의 이름을 설정하되 함수 앞에 '~'를 붙인다.
 	ex) ~SimpleClass()
 - 소멸할 때 호출되기에 매개변수가 없고 반환도 없으며 따라서 반환형도 선언하지 않는다. 따라서, 함수 오버로딩과 디폴트 값 설정이 불가능하다.
 - 생성자와 마찬가지로 객체에 소멸자가 없으면 디폴트 소멸자가 삽입된다.
 - 보통 클래스 내에서 new 연산을 통해 메모리를 할당한 경우 클래스가 소멸하며 delete를 사용해 메모리를 반납할 때 사용한다. 
	  
*/
