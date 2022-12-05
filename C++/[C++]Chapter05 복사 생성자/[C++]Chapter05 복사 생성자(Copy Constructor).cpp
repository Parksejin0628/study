#include<iostream>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;

namespace NameCard_h
{
	//NameCard.h
	namespace COMP_POS
	{
		enum {CLERK = 1, SENIOR, ASSIST, MANAGER};
	}
	
	class NameCard
	{
	private:
		char *name;
		char *company;
		char *callNum;
		int rank;
	public:
		NameCard(char *inputName, char *inputCompany, char *inputCallNUm, int inputRank);
		NameCard(const NameCard &copy);
		void ShowNameCardInfo() const;
		~NameCard();
	};
	
	//NameCard.cpp
	NameCard::NameCard(char *inputName, char *inputCompany, char *inputCallNum, int inputRank) : rank(inputRank)
	{
		int len;
		len = strlen(inputName) + 1;
		name = new char[len];
		strcpy(name, inputName);
		
		len = strlen(inputCompany) + 1;
		company = new char[len];
		strcpy(company, inputCompany);
		
		len = strlen(inputCallNum) + 1;
		callNum = new char[len];
		strcpy(callNum, inputCallNum);
	}
	
	NameCard::NameCard(const NameCard &copy) : rank(copy.rank)
	{
		name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
		
		company = new char[strlen(copy.company) + 1];
		strcpy(company, copy.company);
		
		callNum = new char[strlen(copy.callNum) + 1];
		strcpy(callNum, copy.callNum);
	}
	
	void NameCard::ShowNameCardInfo() const
	{
		cout<<"�̸�: "<<name<<endl;
		cout<<"ȸ��: "<<company<<endl;
		cout<<"��ȭ��ȣ: "<<callNum<<endl;
		cout<<"����: ";
		if(rank == 1)
		{
			cout<<"���"<<endl; 
		}
		else if(rank == 2)
		{
			cout<<"����"<<endl; 
		}
		else if(rank == 3)
		{
			cout<<"�븮"<<endl; 
		}
		else if(rank == 4)
		{
			cout<<"����"<<endl; 
		}
		cout<<endl;
	}
	
	NameCard::~NameCard()
	{
		delete []name;
		delete []company;
		delete []callNum;
	}
}

namespace testClass_h
{
	//testClass.h
	class testClass
	{
	private:
		int num;
		char *name;
	public:
		testClass(int num, char *name);
		//testClass(const testClass &copy);
		void showClassInfo() const;
		~testClass();
	};
	
	//testClass.cpp
	testClass::testClass(int num, char *name) : num(num)
	{
		cout<<"nameAddress : "<<&name<<endl;
		cout<<this<<" construct testClass"<<endl;
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	/*testClass::testClass(const testClass &copy) : num(copy.num), name(copy.name)
	{
		cout<<"nameAddress : "<<&name<<endl;
		cout<<this<<" ���� ����"<<endl;
		/*name = new char[strlen(copy.name) + 1];
		strcpy(name, copy.name);
	}*/
	void testClass::showClassInfo() const
	{
		cout<<"thisClass : "<<this<<endl;
		cout<<"num : "<<num<<" name : "<<name<<endl;
		
		return; 
	}
	testClass::~testClass()
	{
		cout<<"nameAddress : "<<&name<<endl;
		cout<<this<<" destruct testClass"<<endl;
		delete []name;
	}
}

using namespace NameCard_h;
using namespace testClass_h; //include"testClass.h"

testClass testFunc(testClass copy)
{
	testClass newObj = copy;
	copy.showClassInfo();
	
	return newObj;
}

void que5_1();

int main(void)
{
	int num = 0;
	testClass obj(20, "parksejin");
	testClass copy1 = obj;
	testClass copy2 = obj;
	
	obj.showClassInfo();
	copy1.showClassInfo();
	copy2.showClassInfo();
	 
	//que5_1();
	/*cout<<"�Լ� ���� ��"<<endl;
	obj.showClassInfo();
	cout<<"�Լ� ����"<<endl; 
	testFunc(obj).showClassInfo();
	cout<<"�Լ� ����"<<endl;
	obj.showClassInfo();*/
	
	cin>>num;
	
	return 0;
}

void que5_1()
{
	/*
	���� : ���� 4-3�� ���� 2�� ���� NameCard Ŭ������ �����Ͽ���. �׷��� �� Ŭ������ ������ ������ �޸� ������ ���� �Ҵ��ϱ� ������ ���� �����ڰ� �ʿ��� Ŭ�����̴�. 
	�̿� ���� �����ڸ� ������ �����ϰ� ���� ���Ŀ� ������ �߻����� ������ ���� main�Լ��� ���� Ȯ������. 
	*/
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
	NameCard copy1 = manClerk;
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
	NameCard copy2 = manSENIOR;
	copy1.ShowNameCardInfo();
	copy2.ShowNameCardInfo();
	
	return;
}

/*
[Chapter05 ���� ������(Copy Constructor)]
<5-1. '���� ������'���� ù ����>
1. ������ ��ȯ : ��ü ���� �� �ʱ�ȭ�� �� �� '='�� ����� ��� ���ڰ� �ϳ��� �����ڰ� ������ �� '()'�� �˾Ƽ� ��ȯ�Ǵ� ��
	ex) SimpleClass obj = 3 -> SimpleClass obj(3) ������ ��ȯ
2. ���� ������ : ���� ��ü�� ���ڷ� �޾� �����ϴ� ��� �������� ���� �����ϴ� ������
	ex) SimpleClass(const SImpleClass &copy)�� ���� ������
	- ���� �����ڰ� ���� ��� SimpleClass obj = copy�� ���� ������ �����ȴ�.
	- ���� �����ڿ��� ���ڸ� ���� ���� �ݵ�� &�� ����ϸ�, const�� ����ϴ� ���� ����.
3. ����Ʈ ���� ������ : ���� �����ڰ� ���� �������� ���� ��� �˾Ƽ� �ɹ� �� �ɹ� ���縦 �����ϵ��� ����� ������
	- �ڿ� ������ '���� ����'�� �ʿ����� ������ �ܼ� �ɹ� �� �ɹ� ���翡���� ������ �߻����� �ʴ´�.


<5-2. '���� ����'�� '���� ����'>
1. ���� ���� : �ɹ� �� �ɹ��� ���� �����ϴ� ���
2. ���� ������ ������ : ������ Ȥ�� �����ڰ� ���� ��� ���� ����� �����ϵ��� �����ϰ� �ȴ�. �̴� ����ġ ���� ����� �߻���Ų��.
	ex) ptr1�� ������ ptr2���� ���� �����ߴ��� ptr1���� ���� ���Ѵ�.
3. ����, �̷��� ������ �ذ��ϱ� ���� ������ ������ ����� ���簡 '���� ����'�̴�. (������ ��� �߰��ϴ� ����)

<5-3. ���� �������� ȣ�� ����>
1. Call-by-value(�� ����)����� �Լ� ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ��� �ش� �Լ��� ȣ��Ǵ� ���� �Ű������� ��ü�� �����ϸ鼭 ���� �����ڰ� ȣ��ȴ�.
2. �Լ��� ��ȯ���� ��ü�ε� �������� �ƴ� ��� �Լ��� ȣ���� ���� ��ȯ�ϴ� ��ü�� ���纻�� �ӽ� ��ü�� �����Ѵ�.
3. �ӽ� ��ü : ��ü�� ������ �ӽ÷� �����ϴ� �������� ���� �࿡�� �ٷ� �Ҹ��Ѵ�.
	- Ŭ������ �̸��� Ŭ���� �ܺο��� ����� ��� �ӽ� ��ü�̴�.
		ex) SimpleClass(30);
	- ��, �����ڷ� �ӽð�ü�� �����ϴ� ��쿡�� �ٷ� �Ҹ����� �ʴ´�.
*/

/*
[Chapter05 ���� ������(Copy Constructor)]
<5-1. '���� ������'���� ù ����'>
1. ������ ��ȯ
 1) C++���� ������ ���� �� �ʱ�ȭ�ϴ� ����� ���� �� ������ �ִ�.
  	- int num = 20; : C�������� ����� ���� �� �ʱ�ȭ
  	- int num(20); : C++���� �߰��� �����ϴ� ���� �� �ʱ�ȭ ���
 2) ��ü�� ��� '='�� ���� ��ü ���� �� �ʱ�ȭ�� �õ��� �� ���ڰ� �ϳ��� �����ڰ� ������ ���  '()'�� ��ȯ�Ǵ� ��찡 �ִµ� �̸� ������ ��ȯ�̶�� �Ѵ�.
  	ex) SimpleClass obj = 3 -> SimpleClass obj(3)
 3) explict
 	- ������ ��ȯ�� ������ �ʴ� ��� explicit Ű���带 ����ϸ� ������ ��ȯ�� �̷������ �ʴ´�.
  	- �ڵ����� ��ȯ�Ǵ� ���� ������ ���� �ڵ��� ����� �����ϱ� ���������.
  		> ������ �ڵ��� ��Ȯ���� ���ϱ� ���� ���� ���Ǵ� Ű�����̴�.
2. ���� ������
 1) ���� ��ü�� ���ڷ� �޾� �����ϴ� ��� �������� ���� �����ϴ� �����ڸ� '���� ������(Copy Constructor)'�̶�� �Ѵ�. 
	ex) SimpleClass(const SimpleClass &copy) : num1(copy.num1), num2(copy.num2) // SimpleClas�� ��������� num1, num2�� �����Ѵ�.
	- ���� �����ڰ� ������ SimpleClass obj = copy(Simpleclass ��ü) ��� ������ ������ �ȴ�.
	 > SimpleClass obj(copy)��� �������� ������ ��ȯ�� �ȴ�. (���ڰ� �ϳ�)
	 > ����, copy�� ���ڷ� �޴� �����ڰ� ȣ���� �ȴ�.
 2) ���� �����ڿ��� ���ڸ� ���� ���� �ݵ�� &�� ����ؾ� �ϸ� ���� ������ ���� const�� ����ϴ� ���� ����. 
3. ����Ʈ ���� ������
 1) ���� �����ڸ� ���� �������� ���� ��쿡�� ���� ���� ����ó�� ��ü�� ���ڷ� �޾� ��� �� ��� ���簡 �����ϴ�.
 	ex) SimpleClass obj=copy; // ���� �����ڰ� ���� ���ǵ��� �ʾƵ� ����
 2) �� ��� ��� �� ��� ���縦 ���� ���� 
	�����ڰ� ���ǵǾ� ���� �ʾƵ� ����Ʈ ���� �����ڶ�� ���� ���ԵǾ� ��� �� ��� ���縦 �����Ѵ�.
 	- ����Ʈ ���� �����ڴ� �� ����ó�� SimpleClass(const SimpleClass &copy) : num1(copy.num1), num2(copy.num2)�� ���� ���·� ���Եȴ�.
 3) ��� �� ��� ���縦 �����Ϸ� �� �� ���� ��� ���� �����ڸ� �������� �ʾƵ� �ȴ�. ������, �ݵ�� ���� �����ڸ� �����ؾ� �ϴ� ��쵵 �ִ�. 
 
<5-2. '���� ����'�� '���� ����'>
1. ���� ����
 1) ��� �� ����� ���� (���� ����)�ϴ� ��츦 ���� ������ �Ѵ�.
 	- ����Ʈ ���� �����ڴ� ���� ���翡 ���Ѵ�.
2. ���� ������ ������
 1) ���� ���¸� ������ ��� ���� ����� �����ϰ� �ȴ�.
  	- ���� ����� �ܼ��� ������ �����Ѵ�.
	- ��, ������ ������ ��� ���� ����� ����Ű�� �Ǵ� ���̴�.
	- �ᱹ, ���� �޸� ������ �����ϴ� ��� ������ �߻��Ѵ�. 
 2) ���� ����� �����ϰ� �Ǵ� ��� ����ġ ���� ����� �߻��Ѵ�.
 	- �����ڴ� ������ ���� ptr1, ptr2�� ���� ������ ���� �ʵ��� �����Ϸ� ���� ������, ptr1�� ���� ���ϸ� ptr2�� ���� ���ϰ� �ȴ�. 
 3) new, delete ���������� ������ �߻��Ѵ�.
 	- new�� ���� �Ҵ��� ������ ������ ���� ���� �� ��� ���� �޸� ������ �����ϰ� �ȴ�.
	- delete�� ������ �Ҹ��� �� �ٸ� ���纻�� ���� �޸� ������ �����ϹǷ� �̹� �Ҹ�� ������ �Ҹ��Ű�� ��찡 �߻��Ѵ�. 
 4) �츮�� ���ϴ� ������ ������ ����� (������ �߰���) ���縦 ���ؼ��� �ٸ� ������ ���簡 �ʿ��ϴ�.
  > �̴� '���� ����'�̴�. 
3. ���� ����  
 1) ����Ӹ� �ƴ϶�, �����ͷ� �����ϴ� ������ ��� �����Ѵٴ� �ǹ̷� '���� ����'�̴�.
 2) ���� �����ڸ� ���� �����ϰ� ������ ��� �����Ͽ� ���� �ٸ� ����� �����ϵ��� �Ѵ�. 
4. ���ڿ� ������ ���� ���ϴ� �������� vs ���� ����
	���� �Լ��� ������ ������ ����. 
	SimpleClass obj1("hello world")
 	SimpleClass obj2 = obj1
 	return;
 1) ���� ����
  	class SimpleClass
  	{
  	private:
  		char *str;
  	public:
  		SimpleClass(char *sen)
  		{
  			int len = strlen(sen) + 1;
  			str = new char(len);
  			strcpy(str, sen);
  		}
  		~SimpleClass()
  		{
  			delete []str;
  		}
  	}
  
  obj2�� �Ҹ��ϴ� �������� "hello world"�� ��� ���ڿ� �Ҹ�
  obj1�� delete�� ���� �Ҹ� ����� �����Ƿ� ���� �߻�
 2) ���� ����  
 	class SimpleClass
  	{
  	private:
  		char *str;
  	public:
  		SimpleClass(char *sen)
  		{
  			int len = strlen(sen) + 1;
  			str = new char(len);
  			strcpy(str, sen);
  		}
  		SimpleClass(SimpleClass &copy)
  		{
  			int len = strlen(copy.str) + 1;
  			str = new char(len);
  			strcpy(str, copy.str);
  		~SimpleClass()
  		{
  			delete []str;
  		}
  	}
  	obj1, obj2�� �����ϴ� ����� �ٸ��Ƿ� ���� ���� ����  
  	
<5-3. ���� �������� ȣ�� ����>
1. ���� �������� ȣ�� ����
 - ���� �����ڰ� ȣ��Ǵ� ������ ũ�� �� ������ ������ �� �ִ�.
 1) ������ ������ ��ü�� �̿��� ���ο� ��ü�� �ʱ�ȭ�ϴ� ���
 	ex) SimpleClass copy(3);
	 	SimpleClass obj = copy;
 2) Call-by-value(�� ����)����� �Լ�ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
 	ex) SimpleFunc(SimpleClass obj);
 		...
		int main(void) { ... SimpleFunc(obj); ... } (ȣ���� �� ���� ������ ȣ��)
 3) �������� �ƴ� ��ü�� ��ȯ�� ��
 	ex) SimpleFunc() { ... return obj; } (��ȯ�� �� ȣ���� ��ҿ��� ��������� ȣ��
 - �� �� ���� �������� ��ü�� ���� �����ؾ� �ϸ� ������ ���ÿ� ������ �ڷ����� ��ü�� �ʱ�ȭ �ؾ� �ϴ� ����̴�.
 - �ڼ��� ������ 1�� ������ �����ϰ� ���� �����ϵ��� �Ѵ�. 
2. Call-by-value(�� ����) ����� �Լ� ȣ�� �������� ��ü�� ���ڷ� �����ϴ� ���
 1) �ش� ������ ��ü�� �����ؾ� �ϸ� ������ ���ÿ� ������ �ڷ����� ��ü�� �ʱ�ȭ �ؾ� �ϴ� ���� 
 	- �Ű������� �Լ��� ȣ��Ǵ� ���� �޸𸮰� �Ҵ��� �ȴ�.
 	- �׸���, �޸𸮰� �Ҵ��� �Ǹ鼭 ���� ���޹޾� �Ҵ�� �ʱ�ȭ�� ���ÿ� �Ͼ��.  
 2) �Լ��� ȣ���� ��  ���ڰ� ��ü�� ��� ��ü�� ���纻���� �ʱ�ȭ �ؾ� �ϹǷ� ���� �����ڰ� ȣ��ȴ�. 
 3) ����, �� ��쿡�� ���� �����ڸ� ���� ���Ǹ� ���ϸ� ������ �Ǵ� ��찡 �߻��ϹǷ� �ش� ��쿡�� ��������ڸ� ���� �����ؾ� �Ѵ�. (�� �� �����غ��� �ʹ�.) 
 4) ���� �������� ȣ�� ��ü�� �Ű������̴�. (�Լ��� ȣ���ϴ� ������ �����ϴ� ��ü�� �ƴϴ�.) 
3. ��ü�� ��ȯ�ϵ�, ���������� ��ȯ���� �ʴ� ���  
 1) ��ü�� ��ȯ�� �� �Լ��� ȣ���� ������ ��ȯ���� ����ϴ� ��찡 �����Ƿ� �޸𸮸� �Ҵ��Ͽ� ��ȯ�ϴ� ��ü�� ������ �����ؾ��Ѵ�.
 	- �� ��쿡 ��ȯ ���� �����ؼ� �Լ��� ȣ���� ���� �����ϰ� �ȴ�.
	- ����, ���� �����ڸ� ȣ���Ͽ� ��ü�� �����Ѵ�. 
 	ex) cout<<SimpleFunc(30)<<endl;
 2) �̷��� ��ȯ�� �� �ӽ÷� ��ȯ ��ü�� ������ �����ϴ� ������ '�ӽ� ��ü'��� �Ѵ�. 
4. �ӽ� ��ü�� ���� ��ȭ Ž��
 1) �ӽ� ��ü�� ���Ƿ� ����� ���
 	- Ŭ������ �̸��� Ŭ���� �ܺο��� ����ϴ� ��� �ӽ� ��ü�� �ȴ�.
	 	ex) class SimpleClass { ... };
	 		...
	 		int main(void) { SimpleClass(30); //�� �κ��� �ӽ� ��ü�̴�. } 
 2) �ӽ� ��ü�� �Ҹ�Ǵ� ����
 	- �ӽ� ��ü�� �̸��� ���� ���� ����ʹ� ����� �� �����Ƿ� �ٷ� �Ҹ�ȴ�.
	- ��, �����ڷ� ������ ���� ���� ����͵� ����� �� �־� �ٷ� �Ҹ���� �ʴ´�.
		ex) const SimpleClass &ref = SimpleFunc(30) 
 3) �ӽ� ��ü�� �̿��� ���ο� ��ü�� �ʱ�ȭ �ϴ� ��쿡 ���ο� ��ü�� �����Ǵ� ���� �ƴ� �ӽ� ��ü�� �̸��� �ٴ´�!
 	- SimpleClass tempRef = SimpleFunc(obj) �� ���忡�� tempRef ��ü�� �����ǰ� �ӽ� ��ü�� ����� �ʱ�ȭ �Ѵٰ� ������ �� �ִ�.
	- �׷���, C++������ �̷��� ��쿡 ��ü�� ���� ���� �ٿ� ȿ������ ���̱� ���� ��ü�� �߰��� �����ϴ� ���� �ƴ� ��ȯ�� �ӽð�ü�� �̸��� �Ҵ��Ѵ�.
	- ��¥��, �ӽ� ��ü�� ��� ������ ��ü�̱� ������ �����ϴ�. 
	
<������>
1. �����Ϸ��� ���ɴ������� ���� ���縦 �ص� �����ϴ� ������ �˾Ƽ� ���� ������ �����ߴ�. 
2. �ƴϱ׷��� �ӽð�ü�� ��������ڰ� ȣ��� �� �����ϴ� ������ ������ ���� ��������ڸ� �����ؾ��ϴ����� �ǹ��̴�.
 -> �Ƹ� �׷��� �� ������ ���δ�. 
*/
