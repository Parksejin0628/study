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
		cout<<"�ܿ� ���ָ�: "<<GetGasGauge()<<endl;
		cout<<"�ܿ� ���ⷮ: "<<GetElecGauge()<<endl;
		cout<<"�ܿ� ���ͷ�: "<<waterGauge<<endl; 
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
		cout<<"�̸� : "<<name<<endl;
		cout<<"���� : "<<age<<endl;
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
		cout<<"�ּ�: "<<addr<<endl;
		cout<<"��ȭ: "<<phone<<endl<<endl; 
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
		cout<<"����: "<<width*height<<endl;
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
		char * title;	// å�� ���� 
		char * isbn;	// ����ǥ�ص�����ȣ  
		int price;		// å�� ���� 
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
		cout<<endl<<"����: "<<title<<endl;
		cout<<"ISBN: "<<isbn<<endl;
		cout<<"����: "<<price<<endl; 
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
		cout<<"����Ű: "<<DRMKey<<endl;
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
		<����1>
		�ռ� ��Ӱ��迡 �����ִ� Ŭ������ ������ ���� �� ȣ�� ��Ŀ� ���� �����Ͽ���. �� ������ �������� ���� Ŭ������ ������ �����ڸ� �����غ���.
		����� Car Ŭ������ ���ָ����� �����ϴ� �ڵ�����, HybridCar Ŭ������ ���ָ��� ����� �����ϴ� �ڵ�����, HybridWaterCar Ŭ������ ���ָ��� ����Ӹ� �ƴ϶�, ���� ���ÿ� ����� ���� �� �ִ� ������ �ڵ����� ǥ���� ���̴�. 
		�׸��� ���� Ȯ���� ���� ������ Ŭ������ ����ϴ� �ڵ带 ������. 
	*/
	Car normalCar(30);
	HybridCar hybridCar(20, 40);
	HybridWaterCar hybridWaterCar(10, 40, 70);
	
	cout<<"�Ϲ� �� �⸧�� : "<<normalCar.GetGasGauge()<<endl;
	cout<<"���̺긮�� �� �⸧�� : "<<hybridCar.GetGasGauge()<<endl;
	cout<<"���̺긮�� ���ⷮ : "<<hybridCar.GetElecGauge()<<endl; 
	cout<<"���̺긮�� ������ ���ᷮ"<<endl;
	hybridWaterCar.ShowCurrentGauge(); 
	
	/*
		<���� 2>
		���� Ŭ���� MyFriendInfo, MyFriendDetailInfo�� ������ �����ڿ� �Ҹ��ڸ� ������ �� ���� Ȯ���� ���� �ڵ带 �ۼ��غ���. 
	*/
	MyFriendInfo myFriendInfo("�ֱ���", 22);
	MyFriendDetailInfo myFriendDetailInfo("���ۿ�", 22, "����õ", "010-2222-3333");
	
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
	���� 1
	���簢���� �ǹ��ϴ� Square Ŭ������ ���簢���� �ǹ��ϴ� Rectangle Ŭ������ �����ϰ��� �Ѵ�.
	�׷��� ���簢���� ���簢���� �����̹Ƿ� ������ ���·� Ŭ������ ��Ӱ��踦�����ϰ��� �Ѵ�.
	class Rectangle / class Square : public Rectangle
	�̿� ���� �ڵ�� �Բ� ������ �����ϵ��� Ŭ������ �ϼ��غ���. 
	*/
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();
	
	Square sqr(7);
	sqr.ShowAreaInfo();
	/*
	���� 2
	'å'�� �ǹ��ϴ� Book Ŭ������ '���� å'�� �ǹ��ϴ� Ebook Ŭ������ �����ϰ��� �Ѵ�. 
	�׷��� '���� å'�� 'å'�� �����̹Ƿ�, ������ ���·� Ŭ������ ��Ӱ��踦 �����ϰ��� �Ѵ�. (å ����)
	���� �ڵ�� �Բ� ������ �����ϵ��� Ŭ������ �ϼ��غ���. 
	*/
	Book book("���� C++", "555-12345-890-0", 20000);
	book.ShowBookInfo();
	cout<<endl;
	Ebook ebook("���� C++ ebook", "555-12345-890-1", 10000, "fdx9w0i8kiw");
	ebook.ShowEBookInfo();
	
	return;
}

/*
[Chapter07 ���(Inheritance)������]
<7.1. ��ӿ� ���⿡ �ռ�> 
1. ����� ���� �ռ�
 - ����� ������ ��Һ��ٵ� ����� ������ �ִ� ����, ����� �����ؾ� �� ���� �ƴ� ���� �߿��ϴ�.
 - ����, ����� �ʿ��ϰ� �� ������ �����ϸ� �н��� �����Ѵ�.
2. ���� ����Ʈ������ ����
 - ��� ����Ʈ���� ���迡 �־ �߿���ϴ� �� �� �Ϻδ� ������ ����.
	> �䱸���� ���濡 �����ϴ� ���α׷��� ������
	> ����� �߰��� ���� ���α׷��� Ȯ�强
 - ���� ���α׷��� ������� �߰� �䱸�� ��ó�� �����ؾ� �Ѵ�.
 	> �ٽ� ����, �䱸�� ����ֱ� ���� ���α׷��� ��κ��� ��ġ�� ���� ����� �Ѵ�.
	ex) ����� ���� ���α׷����� �����/������/�ӽ��� ���� ���α׷����� Ȯ��� �� ���� ���α׷��� ������/�ӽ��� ���� �߰��� ���� ��κ��� �Լ��� �ǵ�ٸ� ������/Ȯ�强�� ���� ���� �ƴϴ�.
	> �ִ��� ���� �κ��� �������� ���α׷��� ����/Ȯ�� ��ų �� �־�� ���� ���α׷��̶� �� �� �ִ�. 
 - ����, 100% �������� Ȯ�强�� ������ ���� ������, �����̶� �� �����ϰ� ����� ���̴�. 
 - �̷��� �ʿ信 ���� '���(Inheritance)'�� �ʿ伺�� ����Ǿ���. 

<7.2. ����� �������� ����>
1. ����� �ǹ�
 1) ����� �ٸ� Ŭ������ ������� ��ü ���� �����ϰ� �ϴ� ����̴�.
 	> �ܾ��� �ǹ�ó�� �ٸ� Ŭ������ ����� �����޴� ���̴�.
 	> ����� ���� Ŭ������ ����� �� Ŭ������ ��� ����, ��� �Լ��� �����Ѵ�. 
 2) ����� �����ϴ� ����� ������ ����. 
 	class Ŭ�����̸� : public(private/protected) ����� �ִ� Ŭ�����̸�
	ex) class SimpleClass : public otherClass
		{
			...
		};
 3) ����� ���ִ� Ŭ������ ����Ŭ����, ����� �޴� Ŭ������ ����Ŭ������� �Ѵ�.
 	> ������ �ͼ��� ǥ�����δ� ����Ŭ����->�θ�Ŭ����, ����Ŭ����->�ڽ�Ŭ���� �̴�. 
2. ����Ŭ���� ��� ��� �� �ʱ�ȭ
 1) ����Ŭ������ ����� �ʱ�ȭ �Ҷ��� ����Ŭ���� �������� �̴ϼȶ��������� ����Ŭ������ �����ڸ� ȣ���ϴ� ������� �����Ѵ�.
 	ex) class derivedClass : public baseClass
	 	{
		 	...
			derivedClass(int n1, int n2) : baseClass(n1), num(n2)
			...
		};
	> ����, �̴ϼȶ��������� ����Ŭ������ �����ڸ� ȣ������ �ʴ� ��� ���ڰ� ���� �����ڸ� ȣ���Ѵ�.
		>> ��, �� ���ÿ��� baseClass(n1)�� ������ ����Ŭ������ baseClass()�� ȣ���ϴ� ���̴�.
	> �ᱹ, ����Ŭ������ �����ڰ� 2�� ȣ��Ǵ� ���̴�. 
	> �̴� 'Ŭ������ ����� �ش� Ŭ������ �����ڸ� ���ؼ� �ʱ�ȭ�ؾ� �Ѵ�.'�� �⺻ ��Ģ�� ����ȴٴ� ���� �� �� �ִ�. 
 2) ����Ŭ������ ����Ŭ������ ����� �����ϴ��� ����Ŭ������ ����� private�� ����� ���� ���� ������ �� ����.
 	> private�� ���������� Ŭ���� �����̱� ������ �ٸ� Ŭ������ ����Ŭ���������� ���� ������ �� ���� ���̴�. (����� ��ü ���� �������� Ŭ���� ���� ������ �ƴϴ�.) 
 	> �׷��Ƿ�, ����Ŭ������ �Լ��� �̿��ϴ� �� ���������� ������ �ؾ� �Ѵ�.
	> �̴�, ������ ������ ����� �ְ� �޴� ��ü �������� ������ �ȴٴ� ���� �� �� �ִ�. 
 3) �����ڰ� 2�� ȣ��Ǵ� ��ó�� �Ҹ��ڵ� 2�� ȣ��ȴ�.
 	> ���� Ŭ������ �Ҹ��ڰ� ȣ��� �� ���� Ŭ������ �Ҹ��ڰ� ȣ��ȴ�. 
3. ����Ŭ������ ��ü ���� ���� 
 1) ��ü�� ���� �޸𸮰� �Ҵ�ȴ�.
 2) ����Ŭ������ �����ڸ� ȣ���ϸ鼭 �̴ϼȶ������� ���ɴ�.
 3) �̴ϼȶ��������� ����Ŭ������ �����ڸ� ȣ���Ѵ�.
 	> ����Ŭ������ �̴ϼȶ������� ����Ŭ������ ������ ȣ�� �κ��� ���ٸ� ���� Ŭ������ void �����ڸ� ��� ȣ���Ѵ�.
 4) ����Ŭ������ �̴ϼȶ������� ���� �� �����ڸ� �����ϸ鼭 ��ü ������ �Ϸ�ȴ�.
4. ����Ŭ������ ����/�Ҹ� ������ ������
 1) ����Ŭ������ ���� ���������� �׻� ����Ŭ������ ��� �ʱ�ȭ�� ����Ŭ�������� ���� ����ȴ�.
 2) ����Ŭ������ �Ҹ� ���������� �׻� ����Ŭ������ �Ҹ��ڰ� ����Ŭ������ �Ҹ��ں��� ���� ����ȴ�. 
 
<7.3. protected ����� �� ���� ������ ���>
1. protected ������ �ǹ�
 1) protected�� public�� private�� ���� ����° ���������������̴�.
 2) protected �������� �������� �ǹ̴� 'protected�� ����� ��������� �̸� ����ϴ� ���� Ŭ���������� ������ �����ϴ�.'
 	> ��, �ش� Ŭ������ �̸� ����ϴ� ����Ŭ������ ������ �� �ְԵȴ�.
	> private���� ����� ���ܷ� �� ���̴�.
	> private�� public�� �߰��̶�� ����ȴ�.
 3) ������, ����Ŭ������ ����Ŭ���� ���̿����� ���������� �������� ���� ���⿡ �ּ�ȭ�Ϸ��� ����ϴ� ���� ����.
 
2. �� ���� ������ ���
 - ����� �� ���� �� ���� ���·� ����� �����ϴ�.
 1) public ��� : private�� ���ٺҰ��� ����ϰ� �������� �׳� �״�� ����Ѵ�.
  	> ��, ���� Ŭ������ �������������ڰ� ��� �����Ǵ� ���̴�. (��, ����Ŭ������ private ����� ������ �Ұ��� ���·� ����Ѵ�.) 
	> Ư���� ��츦 �����ϰ� ��κ��� ����� public ����̴�.
 2) protected ��� : protected���� ������ ������ ���� ����� protected�� ������Ѽ� ����Ѵ�.
 	> ��, ����Ŭ������ public ��������� protected ��� ������ ��ӹ޴´ٴ� �ǹ��̴�. (��, ����Ŭ������ private ����� ������ �Ұ��� ���·� ����Ѵ�.) 
 3) private ��� : private���� ������ ������ ���� ����� private�� ������Ѽ� ����Ѵ�.
 	> ��, ����Ŭ������ ��� ��������� private ��� ������ ��ӹ޴´ٴ� �ǹ��̴�. (��, ����Ŭ������ private ����� ������ �Ұ��� ���·� ����Ѵ�.) 
 	> private ����� �̷���� Ŭ������ ����� ��� ��� ����� �̹� private�̱⿡ ������ �Ұ��� ���·� ����� �ǰ� ��ǻ� �ǹ� ���� ����� �ȴ�. 

<7.4. ����� ���� ����>
1. ����� �⺻ ���� IS-A ����
 1) ����� �⺻ ������ IS-A ���踦 �������� ���Ѵٸ� ����� ���� �ʴ� �͸� ���ϰ� �ȴ�.
 2) ����Ŭ������ ����Ŭ������ ��� ���� ������ �ڽŸ��� �߰����� Ư���� �������⿡ IS-A���谡 �ʼ����̴�.
 3) IS-A����� '����Ŭ���� IS A ����Ŭ����'������ �����Ѵٴ� �ǹ̷� ����Ŭ������ ������ ����Ŭ���� (����Ŭ������ ����Ŭ������ ����)�̾�� �Ѵ�.
 	ex) ����Ʈ���� ��ȭ���̴�. (����Ʈ�� IS A ��ȭ��) ���⼭�� ����Ʈ���� ����Ŭ����, ��ȭ�Ⱑ ����Ŭ������ �Ǵ� ���̴�.
	ex) ��Ʈ���� ���ڱ���̴�. (��Ʈ�� IS A ���ڱ��) ���⼭�� ��Ʈ���� ����Ŭ����, ���ڱ�Ⱑ ����Ŭ������ �Ǵ� ���̴�.
 4) �̷��� ����� ����� ���̰� �ƹ��� �� ���� ���� �ܰ��� ����Ŭ������ ���� ���� �ܰ��� ����Ŭ���� ���̿����� �����Ǿ�� �Ѵ�.
 	ex) ����Ʈ���� ��ȭ���̴�. / ��ȭ��� ���ڱ���̴�. / ����Ʈ���� ���ڱ���̴�. (��μ���)

2. ����� ������ HAS-A ����
 1) ��� ���� HAS-A ���� ��, ����ϴ� ����� �����ϴ� �͵� ������ ��ó�� ���δ�.
 	ex) ���� HAS A �� ���⼭ ������ ����Ŭ����, ���� ����Ŭ������ �ȴ�. 
 2) ������ �ϰ�����, HAS-A �ܰ�� �ٸ� ������ε� ǥ���� �����ϸ� ����� ����ϸ� ������ �������� �����.
 3) HAS-A ����� �̷���� ��Ӱ���� �������� Ȯ�强 ��� �������� ������ ������ �߻��Ѵ�.
 	> �̴� ������� ���� �� ���� Ŭ������ ���� �������� ��� �����̴�. 
 	ex) ����->�� ��Ӱ��迡�� ���� ���� ���� ������ ǥ���Ϸ��� ū ������ �ʿ��ϱ⿡ �������� ��������.
	ex) ����->�� ��Ӱ��迡�� ���ں��� �� ������ ǥ���Ϸ��� ���߻�ӱ��� ����ϴ� ū ���簡 �ʿ��ϱ⿡ Ȯ�强�� ��������.
 4) �ᱹ ����� IS-A ���迡���� ����ϴ� ���� ����.
 	> �������� �ǰ߿� ������ IS-A / HAS-A ���踦 �����ϰ�� ���� ����� ������� ����� �����Ѵ�. 
*/ 
