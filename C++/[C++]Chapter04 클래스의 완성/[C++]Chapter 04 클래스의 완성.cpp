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
		void Init(int x, int y);
		void ShowPointInfo() const;
	};
	class Circle
	{
	private:
		
	public:
		void ShowCircleInfo() const;
	};
	class Ring
	{
		
	};
	
	
	
	//ring.cpp
	//Point
	void Point::Init(int x, int y)
	{
		xpos = x;
		ypos = y;
	}
	void Point::ShowPointInfo() const
	{
		cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
	}
	
}
using namespace FruitClass_h; //#include"FruitSeller.h"
using namespace Ring_h; //#include"ring.h"

void que4_1();
void que4_2(); 

int main(void)
{
	int num = 0;
	
	que4_1();
	que4_2();
	
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
	*/
	//현재 Circle, Ring 객계체 설계 및 구현을 해야 하는 단 
	Ring ring;
	ring.init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	
	return;
}


/*
[Chapter 04 클래스의 완성]
<4-1. 정보은닉>
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
 
*/
