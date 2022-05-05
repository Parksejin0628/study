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

using namespace Car_h; //#include"Car.h"
using namespace MyFriend_h; //#include"MyFriend.h" 

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

*/ 
