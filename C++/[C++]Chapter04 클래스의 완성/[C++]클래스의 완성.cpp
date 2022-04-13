#include<iostream>
using std cout;
using std cin;
using std endl;

class FruitSeller
{
private:
	int APPLE_PRICE;
	int numOfApples;
	int myMoney;
		
public:
	void InitMembers(int price, int num, int money)
	{
		APPLE_PRICE = price;
		numOfApples = num;
		myMoney = money;
	}
	int SaleApples(int money)
	{
		int num = money / APPLE_PRICE;
		numOfApples -= num;
		myMoney += money;
		
		return num;
	}
	void ShowSalesResult()
	{
		cout<<"남은 사과: "<<numOfApples<<endl;
		cout<<"판매 수익: "<<myMoney<<endl;<<endl;
	}
};

class FruitBuyer
{
	int myMoney;
	int numOfApples;
	
public:
	void InitMembers(int price, int num, int money)
	{
		myMoney = money;
		numOfApples = 0;
	}
	void BuyApples(FruitSeller &seller, int money)
	{
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
	}
	void ShowBuyResult()
	{
		cout<<"현재 잔액: "<<myMoney<<endl;
		cout<<"사과 개수: "<<numOfApples<<endl<<endl; 
	}
};

void que4_1();

int main(void)
{
	int num = 0;
	
	que4_1();
	
	cin>>num; 
	
	return 0;
}

void que4_1()
{
	/*
	 문제 : Chapter03에서 제시한 과일장수 시뮬레이션 예제 FruitSaleSim1.cpp에서 정의한 두 클래스의 멤버변수를 0보다 작은 수를 전달할 수 없는 조건을 추가하자.
	        그리고 예제의 안전성을 높일 수 있도록 일부 함수를 const로 선언해보자. 
	*/	 
	//현재 기존 예제를 가져온것까지 진행
	//문제의 해결을 진행함과 동시에 코드의 가독성이 증가되도록 작업할 것 
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
