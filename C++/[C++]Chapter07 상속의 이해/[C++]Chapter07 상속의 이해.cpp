#include<iostream>
#include<cstring>

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

namespace MyFriend_h
{
	//MyFriend.h
	class MyFriendInfo
	{
	private:
		char * name;
		int age;
	public:
		MyFriendInfo(char* name, int age);
		void ShowMyFriendInfo();
		~MyFriendInfo();
	};
	
	class MyFriendDetailInfo : public MyFriendInfo
	{
	private:
		char * addr;
		char * phone;
	public:
		MyFriendDetailInfo(char *name, int age, char* addr, char* phone);
		void ShowMyFriendDetailInfo();	
		~MyFriendDetailInfo();
	};
	
	//MyFriend.cpp
	//MyFriendInfo
	MyFriendInfo::MyFriendInfo(char* name, int age) : age(age)
	{
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
	}
	void MyFriendInfo::ShowMyFriendInfo()
	{
		cout<<"이름 : "<<name<<endl;
		cout<<"나이 : "<<age<<endl;
	}
	MyFriendInfo::~MyFriendInfo()
	{
		delete []name;
	}
	
	//MyFriendDetailInfo
	MyFriendDetailInfo::MyFriendDetailInfo(char *name, int age, char* addr, char* phone) : MyFriendInfo(name, age)
	{
		this->addr = new char[strlen(addr) + 1];
		strcpy(this->addr, addr);
		this->phone = new char[strlen(phone) + 1];
		strcpy(this->phone, phone);
	}
	void MyFriendDetailInfo::ShowMyFriendDetailInfo()
	{
		ShowMyFriendInfo();
		cout<<"주소: "<<addr<<endl;
		cout<<"전화: "<<phone<<endl<<endl; 
	}
	MyFriendDetailInfo::~MyFriendDetailInfo()
	{
		delete []addr;
		delete []phone;
	}
}

namespace Square_h
{
	//Square.h
	class Rectangle
	{
	private:
		int width;
		int height;
	public:
		Rectangle(int width, int height);
		void ShowAreaInfo() const;
	};
	class Square : public Rectangle
	{
	public:
		Square(int length);
	};
	
	//Square.cpp
	//Rectangle
	Rectangle::Rectangle(int width, int height) : width(width), height(height)
	{
		
	}
	void Rectangle::ShowAreaInfo() const
	{
		cout<<"면적: "<<width*height<<endl;
	}
	//Square
	Square::Square(int length) : Rectangle(length, length)
	{
		
	}
}

namespace Book_h
{
	//Book.h
	class Book
	{
	private:
		char * title;	// 책의 제목 
		char * isbn;	// 국제표준도서번호  
		int price;		// 책의 정가 
	public:
		Book(char * title, char * isbn, int price);
		void ShowBookInfo() const;
		~Book();
	};
	class Ebook : public Book
	{
	private:
		char * DRMKey;
	public:
		Ebook(char * title, char * isbn, int price, char * DRMKey);
		void ShowEBookInfo() const;
		~Ebook();
	};
	
	//Book.cpp
	//Book
	Book::Book(char * title, char * isbn, int price) : price(price)
	{
		this->title = new char[strlen(title) + 1];
		strcpy(this->title, title);
		this->isbn = new char[strlen(isbn) + 1];
		strcpy(this->isbn, isbn);
	}
	void Book::ShowBookInfo() const
	{
		cout<<endl<<"제목: "<<title<<endl;
		cout<<"ISBN: "<<isbn<<endl;
		cout<<"가격: "<<price<<endl; 
	}
	Book::~Book()
	{
		delete []title;
		delete []isbn;
	}
	
	//Ebook
	Ebook::Ebook(char * title, char * isbn, int price, char * DRMKey) : Book(title, isbn, price)
	{
		this->DRMKey = new char[strlen(DRMKey) + 1];
		strcpy(this->DRMKey, DRMKey);
	}
	void Ebook::ShowEBookInfo() const
	{
		ShowBookInfo();
		cout<<"인증키: "<<DRMKey<<endl;
	}
	Ebook::~Ebook()
	{
		delete []DRMKey;
	}
}

using namespace Car_h; 		// #include"Car.h"
using namespace MyFriend_h; // #include"MyFriend.h" 
using namespace Square_h; 	// #include"Square.h"
using namespace Book_h; 	// #include"Book.h"

void que7_1();
void que7_2(); 

int main(void)
{
	int end = 0;
	
	que7_1();
	que7_2();
	
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
	
	cout<<"일반 차 기름량 : "<<normalCar.GetGasGauge()<<endl;
	cout<<"하이브리드 차 기름량 : "<<hybridCar.GetGasGauge()<<endl;
	cout<<"하이브리드 전기량 : "<<hybridCar.GetElecGauge()<<endl; 
	cout<<"하이브리드 워터차 연료량"<<endl;
	hybridWaterCar.ShowCurrentGauge(); 
	
	/*
		<문제 2>
		다음 클래스 MyFriendInfo, MyFriendDetailInfo에 적절한 생성자와 소멸자를 정의한 후 이의 확인을 위한 코드를 작성해보자. 
	*/
	MyFriendInfo myFriendInfo("최광민", 22);
	MyFriendDetailInfo myFriendDetailInfo("조송연", 22, "봉일천", "010-2222-3333");
	
	myFriendInfo.ShowMyFriendInfo();
	cout<<endl;
	myFriendDetailInfo.ShowMyFriendInfo();
	cout<<endl;
	myFriendDetailInfo.ShowMyFriendDetailInfo(); 
	
	return;
}

void que7_2()
{
	/*
	문제 1
	정사각형을 의미하는 Square 클래스와 직사각형을 의미하는 Rectangle 클래스를 정의하고자 한다.
	그런데 정사각형은 직사각형의 일종이므로 다음의 형태로 클래스의 상속관계를구성하고자 한다.
	class Rectangle / class Square : public Rectangle
	이에 다음 코드와 함께 실행이 가능하도록 클래스를 완성해보자. 
	*/
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();
	/*
	문제 2
	'책'을 의미하는 Book 클래스와 '전자 책'을 의미하는 Ebook 클래스를 정의하고자 한다. 
	그런데 '전자 책'도 '책'의 일종이므로, 다음의 형태로 클래스의 상속관계를 구성하고자 한다. (책 참고)
	다음 코드와 함께 실행이 가능하도록 클래스를 완성해보자. 
	*/
	Book book("좋은 C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	Ebook ebook("좋은 C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	
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
 
<7.3. protected 선언과 세 가지 형태의 상속>
1. protected 선언의 의미
 1) protected는 public과 private를 이은 세번째 접근제어지시자이다.
 2) protected 접근제어 지시자의 의미는 'protected로 선언된 멤버변수는 이를 상속하는 유도 클래스에서만 접근이 가능하다.'
 	> 즉, 해당 클래스와 이를 상속하는 유도클래스만 접근할 수 있게된다.
	> private에서 상속을 예외로 둔 것이다.
	> private와 public의 중간이라고 보면된다.
 3) 하지만, 기초클래스와 유도클래스 사이에서도 정보은닉은 지켜지는 것이 좋기에 최소화하려고 노력하는 것이 좋다.
 
2. 세 가지 형태의 상속
 - 상속을 할 때는 세 가지 형태로 상속이 가능하다.
 1) public 상속 : private는 접근불가로 상속하고 나머지는 그냥 그대로 상속한다.
  	> 즉, 기초 클래스의 접근제어지시자가 모두 보존되는 것이다. (단, 기초클래스의 private 멤버는 접근이 불가한 형태로 상속한다.) 
	> 특별한 경우를 제외하고 대부분의 상속은 public 상속이다.
 2) protected 상속 : protected보다 접근의 범위가 넓은 멤버는 protected로 변경시켜서 상속한다.
 	> 즉, 기초클래스의 public 멤버변수를 protected 멤버 변수로 상속받는다는 의미이다. (단, 기초클래스의 private 멤버는 접근이 불가한 형태로 상속한다.) 
 3) private 상속 : private보다 접근의 범위가 넓은 멤버는 private로 변경시켜서 상속한다.
 	> 즉, 기초클래스의 모든 멤버변수를 private 멤버 변수로 상속받는다는 의미이다. (단, 기초클래스의 private 멤버는 접근이 불가한 형태로 상속한다.) 
 	> private 상속이 이루어진 클래스를 상속할 경우 모든 멤버가 이미 private이기에 접근이 불가한 형태로 상속이 되고 사실상 의미 없는 상속이 된다. 

<7.4. 상속을 위한 조건>
1. 상속의 기본 조건 IS-A 관계
 1) 상속의 기본 조건인 IS-A 관계를 성립하지 못한다면 상속을 하지 않는 것만 못하게 된다.
 2) 유도클래스는 기초클래스의 모든 것을 가지고 자신만의 추가적인 특성이 더해지기에 IS-A관계가 필수적이다.
 3) IS-A관계는 '유도클래스 IS A 기초클래스'조건을 성립한다는 의미로 유도클래스가 일종의 기초클래스 (유도클래스가 기초클래스에 포함)이어야 한다.
 	ex) 스마트폰은 전화기이다. (스마트폰 IS A 전화기) 여기서는 스마트폰이 유도클래스, 전화기가 기초클래스가 되는 것이다.
	ex) 노트북은 전자기기이다. (노트북 IS A 전자기기) 여기서는 노트북이 유도클래스, 전자기기가 기초클래스가 되는 것이다.
 4) 이러한 관계는 상속의 깊이가 아무리 깊어도 가장 얕은 단계의 기초클래스와 가장 깊은 단계의 유도클래스 사이에서도 성립되어야 한다.
 	ex) 스마트폰은 전화기이다. / 전화기는 전자기기이다. / 스마트폰은 전자기기이다. (모두성립)

2. 상속이 가능한 HAS-A 관계
 1) 언뜻 보면 HAS-A 관계 즉, 상속하는 대상을 포함하는 것도 가능한 것처럼 보인다.
 	ex) 경찰 HAS A 총 여기서 경찰이 유도클래스, 총이 기초클래스가 된다. 
 2) 가능은 하겠지만, HAS-A 단계는 다른 방식으로도 표현이 가능하며 상속을 사용하면 오히려 문제점이 생긴다.
 3) HAS-A 관계로 이루어진 상속관계는 유연성과 확장성 모두 떨어지기 때문에 문제가 발생한다.
 	> 이는 상속으로 묶인 두 개의 클래스가 강한 연관성을 띄기 때문이다. 
 	ex) 경찰->총 상속관계에서 총을 들지 않은 경찰을 표현하려면 큰 수정이 필요하기에 유연성이 떨어진다.
	ex) 경찰->총 상속관계에서 전자봉을 든 경찰을 표현하려면 다중상속까지 고려하는 큰 공사가 필요하기에 확장성도 떨어진다.
 4) 결국 상속은 IS-A 관계에서만 사용하는 것이 좋다.
 	> 전문가의 의견에 따르면 IS-A / HAS-A 관계를 제외하고는 절대 상속을 사용하지 말라고 강조한다. 
*/ 
