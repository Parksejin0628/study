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
		cout<<"���� ���: "<<numOfApples<<endl;
		cout<<"�Ǹ� ����: "<<myMoney<<endl<<endl;
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
			cout<<"�߸��� �Է��Դϴ�."<<endl;
			return false;
		}
		numOfApples += seller.SaleApples(money);
		myMoney -= money;
		
		return true;
	}
	void FruitBuyer::ShowBuyResult() const
	{
		cout<<"���� �ܾ�: "<<myMoney<<endl;
		cout<<"��� ����: "<<numOfApples<<endl<<endl; 
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
	 ���� : Chapter03���� ������ ������� �ùķ��̼� ���� FruitSaleSim1.cpp���� ������ �� Ŭ������ ��������� 0���� ���� ���� ������ �� ���� ������ �߰�����.
	        �׸��� ������ �������� ���� �� �ֵ��� �Ϻ� �Լ��� const�� �����غ���. 
	*/	 
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);
	FruitBuyer buyer;
	buyer.InitMembers(5000);
	buyer.BuyApples(seller, 2000);
	
	cout<<"���� �Ǹ����� ��Ȳ"<<endl;
	seller.ShowSalesResult();
	cout<<"���� �������� ��Ȳ"<<endl;
	buyer.ShowBuyResult(); 
		
	return;
}

void que4_2()
{
	/*
	���� : Point Ŭ������ ������� �Ͽ� (�������� �����ϴ� Ŭ����) ���� �ǹ��ϴ� Circle Ŭ������ ��������.
	 	   Circle ��ü���� ��ǥ���� ��ġ ����(���� �߽���ǥ)�� �������� ���� ������ ���� �� ����� �� �־�� �Ѵ�.
		   �׸��� ������ Circle Ŭ������ ������� Ring Ŭ������ ��������. ���� �� ���� ������ ǥ�� �����ϹǷ�(�ٱ��� ���� ���� ��), �� ���� Circle ��ü�� ������� ���ǰ� �����ϴ�.
		   ����� ���� ���� �ٱ��� ���� �߽���ǥ�� �����ϴٸ� �β��� ������ ���� ǥ���ϴ� ���� �Ǹ�, �߽���ǥ�� �������� �ʴٸ� �β��� �������� ���� ���� ǥ���ϴ� ���� �ȴ�.
		   ���� ���忡�� Init�� �Լ�ȣ���� ���� ���޵� 1, 1, 4�� ���� ���� ������ �ش��ϸ� (X, Y, ������), �̾ ���޵� 2, 2, 9�� �ٱ��� ���� ������ �ش��Ѵ�.
		   �������� å�� ���ÿ� ���ų� �����ؾ� �Ѵ�. ĸ��ȭ�� ���� ���� �޶����� Ŭ������ ������ �� ĸ��ȭ�� ����غ���. �׸��� ���� �ڵ�� ���� ���غ���. 
	�޸�
	 - ������ Ring Ŭ������ �����ϴ� ���̴�. 
	 - ������ ���� ���� ���� �ٱ��� ���� �����ϱ⿡ Circle ��ü 2���� �ʿ��� ���̴�. 
	 - Circle�ȿ� ������, ��ġ ������ ����ϴ� ����� �ִ� ���� ���� ���̸� �̴� PointŬ�������� �ؼ��� �� �ִ�. 
	*/
	//���� Circle, Ring ����ü ���� �� ������ �ؾ� �ϴ� �� 
	Ring ring;
	ring.init(1, 1, 4, 2, 2, 9);
	ring.ShowRingInfo();
	
	return;
}


/*
[Chapter 04 Ŭ������ �ϼ�]
<4-1. ��������>
 1. ���������� ���� ���  
  - ���� Ŭ������ �Ǳ� ���� �ּ����� ������ �Ŵ´ٸ� '��������'�� 'ĸ��ȭ'�̴�.
  - �����ϴ� ���������� ó�� �������� �ǵ��� �ٸ��� ������ �����ϴ� �Ǽ��� ���� �߻��Ѵ�.
  	ex) xPos �������� 0~100�� ���� �ֱ�� ������ ���� ���� �Ǽ��� -5�� �־���.
  - �̷��� �Ǽ��� ���� �߻����� ���α׷����� �Ǽ��� ���� ��å�� �ʿ伺�� ��Ÿ����.
  - �̷��� ��å �� �ϳ��� '���ѵ� ������θ� ��������� ������ ����Ͽ� �߸��� ���� ������� �ʵ��� ���� �Ǽ��� ���� �߰ߵǵ��� �ϴ� ��'�̶�� ������ �����ߴµ� �̰��� �ٷ� ���������̴�.
 2. ��������
  - ���������� ��������� private�� ������ �� �ش� ������ �����ϴ� �Լ��� ������ �����Ͽ� ������ ���·� ��� ������ ������ �����ϴ� ���̴�.
   > Ư�� �Լ���� ���ѵ� ����� �����ϰ�� ��� ������ ������ �� ������ �Ѵ�.
   > �ܺ� ħ���κ��� ������ �����ϰ� ��ȣ�Ѵ�. 
  - ��������� �����ϴ� �Լ����� ���� ������ �����Ѵ�.
   > ���α׷����� �Ǽ��� �����Ѵ�.
  - ��� ������ �����ϴ� �Լ��� ��ȯ���� bool�� �����Ѵ�.
   > ���� ���� ���ǿ� ��߳��� ���� ���� ��� false�� ��ȯ�ϰ� ���� �޽����� �������ν� �Ǽ��� ���� �߰ߵǵ��� �Ѵ�.
 3. ������ �Լ�
  - ��������� private�� �����ϸ鼭 Ŭ���� �ܺο����� ������� ������ �������� ���ǵ� �Լ����̴�.
  	ex) GetX : X���� �������� �Լ� / SetX : X���� �����ϴ� �Լ� 
  - ������ �Լ��� ȣ������ �ʾƵ� ���Ǹ� �صд�.
   > Ŭ������ ���� �������� ������ �ʿ����� �ʾƵ� ���߿� �ʿ��� �� �ִٰ� �ǴܵǴ� �Լ����� ����� ���Խ��� �����س��� ��찡 ����.
   > ������ �Լ��� �̷��� ���� �� �ϳ��̴�.
 4. const �Լ�(const�� �Լ� �� �ڿ�)
  - �Լ� �ڿ� const�� �ٴ� ��찡 �ִ�.
  	ex) int GetX() const;
  - ��const�� �� �Լ� �������� '�������'�� ����� ���� �������� �ʴ´ٴ� �ǹ��̴�. 
   > �ٸ� ������ �ƴ� Ŭ������ '�������'�̴�. 
  - const�� ����� �Լ� ������ ��������� ���� �����ϴ� ������ ���� ��� ������ ������ �߻��Ѵ�.
   > �̸� ���� �Ǽ��� ��������� ���� �����Ű�� �� ��� ������ ������ ���� �ٷ� �� �� �ִ�.
  - ����, const�� ����� �Լ� �������� const�� ����� �Լ��� ȣ���� �� �ִ�.
   > ��������� ���� ����� ���ɼ��� �ִ� ��츦 ��� �����ϴ� ���̴�.
   > �̷��� ����� ��ŷ �� �ܺ� �������� ���� ����� ȿ���� ���� ���̴�.
  - ������, �ٸ� Ŭ�������� const �����ڸ� ���� ��ü�� ���� ���� �ش� ��ü�� ����Լ��� const ������ �ƴ϶�� ȣ���� �� ����.
   > ȿ���� ���� ����.
  - ����, �ϳ��� const�� ����ϸ� ���� �κп� const�� �߰��ؾ� ������ �׸�ŭ �ڵ��� �������� ��������.
  - ������ ���� �ذ��� ���������� const�� �� ���� �ƴ϶� �ڵ��� �������� ���� ���� ��ȭ�� ���� ��� �Լ����� const�� �߰��ϴ� ������ ������. 
 
*/
