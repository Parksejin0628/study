#include<iostream>
#include<cstring>
using std::cin;
using std::cout;
using std::endl;

void que8_1();

namespace Employee_h
{
	namespace RISK_LEVEL
	{
		enum RiskLevel {RISK_A = 3, RISK_B = 2, RISK_C = 1};
	}
	
	//Employee.h
	class EmployeeHandler;
	class Employee;
	class PermanentWorker;
	
	class EmployeeHandler
	{
	private:
		Employee* empList[50];
		int empNum;
	public:	
		EmployeeHandler();
		void AddEmployee(Employee* emp);
		void ShowAllSalaryInfo() const;
		void ShowTotalSalary() const;
		~EmployeeHandler();
	}; 
	
	class Employee
	{
	private:
		char name[100];
	public:	
		Employee(char * name);
		void ShowYourName() const;
		virtual int GetPay() const = 0;
		virtual void ShowSalaryInfo() const = 0;
	};
	
	class PermanentWorker : public Employee
	{
	private:
		int salary;
	public:	
		PermanentWorker(char * name, int money);
		virtual int GetPay() const;
		virtual void ShowSalaryInfo() const;
	};
	
	class SalesWorker : public PermanentWorker
	{
	private:
		int salesResult;
		double bonusRatio;
	public:
		SalesWorker(char * name, int money, double ratio);
		void AddSalesResult(int value);
		virtual int GetPay() const;
		virtual void ShowSalaryInfo() const;
		int GetBonus() const;
	};
	
	class ForeignSalesWorker : public SalesWorker
	{
	private:
		const RISK_LEVEL::RiskLevel risk;
	public:
		ForeignSalesWorker(char *name, int money, double ratio, RISK_LEVEL::RiskLevel risk);
		virtual int GetPay() const;
		virtual void ShowSalaryInfo() const;
	};
	
	//Employee.cpp
	//EmployeeHandler
	EmployeeHandler::EmployeeHandler() : empNum(0)
	{
		
	}
	void EmployeeHandler::AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void EmployeeHandler::ShowAllSalaryInfo() const
	{
		for(int i=0; i<empNum; i++)
		{
			empList[i]->ShowSalaryInfo();
		}
	}
	void EmployeeHandler::ShowTotalSalary() const
	{
		int sum = 0;
		for(int i=0; i<empNum; i++)
		{
			sum += empList[i]->GetPay();
		}
		cout<<"salary sum: "<<sum<<endl;
	}
	EmployeeHandler::~EmployeeHandler()
	{
		for(int i=0; i<empNum; i++)
		{
			delete empList[i];
		}
	}
	
	//Employee
	Employee::Employee(char * name)
	{
		strcpy(this->name, name);
	}
	void Employee::ShowYourName() const
	{
		cout<<"name : "<<name<<endl;
	}
	
	//PermanentWorker
	PermanentWorker::PermanentWorker(char * name, int money) : Employee(name), salary(money)
	{
		
	}
	int PermanentWorker::GetPay() const
	{
		return salary;
	}
	void PermanentWorker::ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
	//SalesWorker
	SalesWorker::SalesWorker(char * name, int money, double ratio) : PermanentWorker(name, money), salesResult(0), bonusRatio(ratio)
	{
		
	}
	void SalesWorker::AddSalesResult(int value)
	{
		salesResult += value;
	}
	int SalesWorker::GetPay() const
	{
		return PermanentWorker::GetPay() + GetBonus();
	}
	void SalesWorker::ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<GetPay()<<endl<<endl;
	}
	int SalesWorker::GetBonus() const
	{
		return (int)(salesResult * bonusRatio);
	}
	//ForeignSalesWorker
	ForeignSalesWorker::ForeignSalesWorker(char * name, int money, double ratio, RISK_LEVEL::RiskLevel risk) : SalesWorker(name, money, ratio), risk(risk)
	{
		
	}
	int ForeignSalesWorker::GetPay() const
	{
		return SalesWorker::GetPay() + SalesWorker::GetPay() * (risk * 0.1);
	}
	void ForeignSalesWorker::ShowSalaryInfo() const
	{
		ShowYourName();
		cout<<"salary: "<<SalesWorker::GetPay()<<endl;
		cout<<"risk pay: "<<SalesWorker::GetPay() * (risk*0.1)<<endl;
		cout<<"sum: "<<GetPay()<<endl<<endl;
	}
}

using namespace Employee_h; //include"Employee.h"

int main(void)
{
	int num = 0;
	
	que8_1();
	
	cin>>num;
	
	return 0;
}

void que8_1()
{
	/*
	[����]
	å�� �ִ� ���� EmployeeManager4.cpp�� Ȯ���Ͽ� ���� Ư���� �ش��ϴ� ForeignSalesWorkerŬ������ �߰��� �����غ���.
	'������ ���� �� �Ϻδ� �����갣���� ���尳ô�� �����ϰ� �ִ�. �Ϻδ� �Ƹ�������, �� �Ϻδ� �׷��� ������ �ִ� �������� ����Ȱ���� ���� �߿� �ִ�.
	���� �̷��� �������� ������� ������ ��������� �����ϰ��� �Ѵ�.'
	��������� ���޹���� '������ ���⵵'�� ���� ������ ���� ������, �� �� ������ ������ '���� ���⵵'�� ������� �ʴ´ٰ� �����Ѵ�. (const ��������� ������ �ǹ��Ѵ�.)
	 - ����ũ A : �������� �⺻�޿��� �μ�Ƽ�� �հ� �Ѿ��� 30%�� �߰��� �����Ѵ�.
	 - ����ũ B : �������� �⺻�޿��� �μ�Ƽ�� �հ� �Ѿ��� 20%�� �߰��� �����Ѵ�.
	 - ����ũ C : �������� �⺻�޿��� �μ�Ƽ�� �հ� �Ѿ��� 10%�� �߰��� �����Ѵ�.
	���� �ڵ尡 �����ϵ��� ForeignSalesWorker Ŭ������ �����ϸ�, Employee Ŭ������ ��ü ������ �Ұ����� �߻� Ŭ������ �����Ѵ�. 
	*/
	// ForeignSalesWorker Ŭ���� �߰����� �����ϸ� �ȴ�. 
	EmployeeHandler handler;
	
	ForeignSalesWorker * fseller1 = new ForeignSalesWorker("Hong", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1); 
	
	ForeignSalesWorker * fseller2 = new ForeignSalesWorker("Yoon", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2); 
	
	ForeignSalesWorker * fseller3 = new ForeignSalesWorker("Lee", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3); 
	
	handler.ShowAllSalaryInfo();
	
	return;
}

/*
[Chapter08 ��Ӱ� ������]
<8.1. ��ü �������� ��������> 
1. ����Ŭ������ ������ ������ ��ü ������ ����
 1) Ŭ������ ������ε� ������ ������ ������ �� �ִ�.
 	ex) Person * ptr;
	 	ptr = new Person();
 2) �׷���, �̷��� ������ ������ �ش� ��ü �Ӹ� �ƴ϶� �� ��ü�� Ŭ������ ����ϴ� ���� Ŭ������ ��ü�� ����ų �� �ִ�.
 	> å�� ǥ���� �ο����ڸ� 'C++����, AAA�� ������ ������ AAA ��ü �Ǵ� AAA�� ���� Ȥ�� ���������� ����ϴ� ��� ��ü�� ����ų �� �ִ�(��ü�� �ּ� ���� ������ �� �ִ�).'
 	> �� ǥ���ؼ� '���������� ���'�� AAA�� ����ϴ� Ŭ������ ����Ѵٴ� �ǹ��̴�. 
	ex1) Person * ptr;
		 ptr = new Student(); (Student�� Person�� ����ϴ� ����Ŭ�����̴�.)
	ex2) Person * ptr2;
		 ptr2 = new PartTimeStudent(); (PartTimeStudent�� Student�� ����ϴ� ����Ŭ�����̴�. Student�� Person�� ����ϹǷ� �� ������ �����ϴ�.)
 3) �̷� ǥ���� ������ ������ �˾ƺ��� ���� �� Person�� ���� ����.
   > Student, PartTimeStudent�� ��� Person�� IS-A �����̴�.
   > ��, Student, PartTimeStudent�� ��� Person�̴�.
   > ����, �������� Person ������ ������ Student, PartTimeStudent�� ����ų �� �ִ� ���̴�.
 4) �ش� ǥ���� ���ؼ� �츮�� ���� ���α׷��� ���� �� �ϳ��� �������� Ȯ�强�� Ȯ���� �� �ִ�.
 	> ���� ���, �� Person�� ����ϴ� ���α׷����� Person�� ������� �� ��Ʈ�� Ŭ������ �ִٰ� ����.
	> ���� Person�� ����ϴ� Teacher�� �߰��ƴٰ� �ϸ� �츮�� Teacher�� ���� ��Ʈ�� Ŭ������ ������ �ʿ䰡 �־��� ���̴�.
	> ������, �����ͷ� ����Ŭ������ ������ �����ϰ� �����ν�, Teacher�� ����Ű�� ������ �߰��� �ʿ� ���� Person ������ ������ Teacher�� ����Ű�� �Ͽ� ������ �ּ�ȭ�� �� �ִ�.
	> �ᱹ, Person�� ���� Ȥ�� ���������� ����ϴ� Ŭ������ �߰��Ǿ��� ��, ��Ʈ��Ŭ������ ��ȭ�� �ʿ� �������� ���̴�.
	> �̴�, �������� Ȯ�强�� ū �⿩�� �Ѵ�.
2. �Լ� �������̵�
 1) �Լ� �������̵�(function overriding)
 	> ����Ŭ�������� ��ӹ޴� �Լ��� ����Ŭ�������� ������ �̸��� ���·� '������'�ϴ� ���̴�. (�������̵��� �����ϴٴ� �ǹ̷� ���� �Լ��� �����ϰ� ���� �����Ѵٴ� �ǹ̸� ����ִ�.) 
	> ����Ŭ�������� ����Ŭ������ ������ ����� �ٽ� ������ �� ���ȴ�.
	> �ش� ����Ŭ�������� �ش� �̸��� �Լ��� ȣ���� ��� ���� ����Ŭ������ �ִ� �Լ��� �ƴ� ����Ŭ�������� �����ǵ� �Լ��� ȣ��ȴ�. 
	> ����Ŭ������ �������̵��� �Լ��� ȣ���ϴ� �Լ��� ���� ��� �� �Լ��� ����Ŭ������ �Լ��� ȣ���ϰԵǹǷ� ����Ŭ�������ִ� �Լ��� ȣ���ϰ� �ϱ� ���ؼ��� ���� ����Ŭ�������� �������̵� �ؾ��Ѵ�. 
	
<8.2. �����Լ�>
1. ������ ���꿡 ���� �����Ϸ��� �Ǵ�
 1) �տ��� Ȯ���ߵ� Ŭ������ ������ ������ ����Ŭ�������� ����ų �� �ִ�.
 	ex) Person *ptr / ptr = new Student();
 2) ������ �����Ϸ��� ������ ������ ���ɼ��� �Ǵ��� �� �ڷ����� �������� �Ѵ�. ��, ����Ŭ���� �����ͷ� ����Ŭ������ ����Ű�� ���� ���������� ����Ŭ������ ����� ����� �� ���� ���̴�. 
 	> Base * bptr ������ ������ �ִٰ� �ϸ� bptr�� Base�ܿ��� ����Ŭ������ Derived�� ����ų �� �ִ�.
	> ������, bptr�� �ڷ����� Base�̹Ƿ� Base�� ����� ȣ���� �� �ִ�.
	> �ٽø���, Derived�� ����Լ��� DerivedFunc()�� ȣ���� �� ����.
 3) �̷��� Ư¡������ ����Ŭ������ ����Ŭ������ �����ϴ� �͵� ������ �ȴ�.
 	> ��, Base ������ ������ Derived�� ����Ű���� Derived ������ ������ ���Կ����� �Ұ����ϴ�. Base ������ ������ Base�� ����ų�� Derived�� ����ų���� �𸣱� �����̴�. 
	 	ex) Base *bptr = new Derived(); / Derived *dptr = bptr (x)
	> ����, ����Ŭ���� ������ ������ ����Ŭ������ �����ϴ� ���� �����ϴ�. �̴� ����Ŭ������ ����Ŭ������ ����Ű�� �ͱ��� ����ϱ� �����̴�. 
		ex) Derived *dptr = new Derived(); / Base *bptr = dptr (o)
2. �ڷ����� ������ �Լ� ȣ��
 1) �տ��� ���캻 �����Ϸ� �Ǵ��� Ư¡������ Ŭ���� ������ ������ ��� ȣ���� �ڷ����� ���󰣴�.
 2) �̴�, �������̵��� �ش��� �ȴ�.
 	> �ƹ��� ����Ŭ������ ����Ű��, �������̵��� �����Ѵٰ� �ص� �ڷ����� �Լ��� ȣ���ϰ� �Ǵ� ���̴�.
	 	ex) First * fptr = new Third / MyFunc()  ��� : FristFunc (�Լ� �������̵��� ���������� �ڷ����� ���� First�� �ִ� ����Լ� ȣ��) 
			Third * tptr = new Third / MyFunc() ��� : ThirdFunc (�Լ� �������̵����� Third�� �ִ� ����Լ� ȣ��) 
 3) �̷��� Ư¡�� ����� ������ Ȯ�强�� �������� ��ĥ �� �ְ� �ȴ�.
 	> ����Ű�� ��ü�� ���� ���ϴ� �ٸ� �Լ��� ȣ���ؾ� �������� Ȯ�强�� Ȯ��������, �ڷ����� ������ �����̴�.
	> �̴� �����Լ� ������ �������� �Ǿ���. 
3. �����Լ�(virtual Function)
 1) �׻� �ڷ����� ���󰡴� Ŭ���� ������ ������ ��� ȣ���� ������ �����ϱ� ���� ź���� �����̴�.
 2) �Լ��� �����Լ��� �����ϸ� �������� �ڷ����� ������� ȣ�� ����� �����ϴ� ���� �ƴ� ����Ű�� ����� ������� ȣ�� ����� �����ϰ� �ȴ�.
	ex) First *fptr = new Third()�̰�, MyFunc()�� �����Լ��� ��� Third�� MyFunc�� ȣ���ϰ� �ȴ�.
 3) �̷��� �����Լ��� ������ virtual Ű������ ������ ���ؼ� �̷������.
 	> ����Լ� �տ� virtual Ű���带 �߰��Ѵ�.
 	> �Լ��� ����ο��� virtual Ű���带 �߰��Ѵ�. 
	ex) virtual void MyFunc() { ... }
 4) �����Լ��� ����� �� �ش� �Լ��� �������̵��ϴ� �Լ��� �ڵ����� �����Լ��� �ȴ�.
 	> ������, �����Լ���� ���� ����ϱ� ���� ����Ŭ�������� virtual�� �߰��ϵ��� ����. 
4. ���� �����Լ�, �߻� Ŭ����(Pure Virtual Function, Abstract Class)
 1) ���� Ŭ���� �߿����� ���� Ŭ�����μ��� �ǹ̸� ���� �� ��ü�� ������ ���� Ŭ������ �ƴ� ���� �ִ�.
 	> �̷� Ŭ������ ������� ��ü�� �����ϴ� �Ǽ��� �߻��� �� �ִ�.
 2) �̷� Ŭ���������� �Ǽ��� ���� ���� �����Լ��� '���� �����Լ�(Pure Virtual Function)'���� �����ϴ� ���� ����.
 	> ���� �����Լ��� �Լ��� ��ü�� ���ǵ��� ���� �Լ��� �ǹ��Ѵ�.
	> �Լ� ���� ���� = 0�� �ٿ� ǥ���Ѵ�.
		ex) virtual int GetPay() const = 0;
 3) �ϳ� �̻��� ���� �����Լ��� ������ Ŭ������ �߻� Ŭ����(abstract class)��� �Ѵ�.
 	> �߻� Ŭ������ ���������� ��ü������ �Ұ����ϰ� �ϱ⿡ �Ǽ��� ������ �� �ִ�.
	> ȣ���� ���� �ǹ̸��� ������ �Լ��� �� �� ��Ȯ�� ����� �� �ְ� �ȴ�. 
5. ������(Polymorphism)
 1) ���±��� �ٷ� �����Լ��� ȣ�� ���迡�� ���� Ư���� ������ '������(polymorphism)'�̶�� �Ѵ�.
 2) �������� �����̻��� �ǹ��Ѵ�.
 	> ����� ������ ���´� �ٸ��ٴ� �ǹ̸� ������.
	> C++�� �������� ���ϸ� ������ ������ ����� �ٸ��ٴ� ���� �ǹ��Ѵ�.
	> virtual�� ����Ű�� ��� ���� ���� ���嵵 �ٸ� ����� �����س��⿡ �������̶�� �Ѵ�.
		ex) First *fptr = new First() Ȥ�� new Third() / fptr->MyFunc() ���⼭ ó���� �����ͺ����� ������ ����Ű�Ŀ� ���� ���� ���������� �ٸ� ����� �����س��⿡ �������� ���ð� �ȴ�. 
6. ����� ���� 
 1) ����� ���� ������ �Ϸ��� Ŭ������ ���� �������� �Ծ��� ������ �� �ִ�.
 	> ���� ���� IS-A����� ǥ�� ������ Ŭ�����鿡 �������� �Ծ�, Ư¡���� ������ �� �ְ� ���ش�.
 2) �̷��� ����� ���� ��� Ŭ������ ��ü�� �ϳ��� ���� Ŭ������ ���� �ٶ����ν� �������� Ȯ�强�� �÷��ش�.
 	ex) å ���ÿ��� ����ϴ� PermanentWorker, TemporaryWorker, SalesWorker ��� Employee�� �ٶ󺸰� ���α׷��� �������ν� �������� Ȯ�强�� Ȯ���Ͽ���. 

<8.3. ���� �Ҹ��ڿ� �������� ���� ���ɼ�>
1. ���� �Ҹ���
 1) �Ҹ��� ���� ������ ������ �ڷ����� ���󰡹Ƿ� ���� Ŭ������ �Ҹ��ڴ� ����� ȣ���� �ȵ� �� �ִ�.
 2) ����, virtual Ű���带 ���� �Ҹ��ڸ� �����Լ��� ���������ν� ���� Ŭ������ �Ҹ��ڵ� ����� ȣ��� �� �ֵ��� �Ѵ�. 
2. �������� ���� ���ɼ�  
 1) �����ڵ� ������ ����ó�� ����Լ��� �����Ѵ�.
 	> ����Ŭ������ �����ڸ� ������ ��� ����Ŭ������ ������ �� �ְ� �ȴ�.
	> �⺻������ ���ȣ���� ������ �ڷ����� ������.
	> ��, virtual�� �����Լ�ȭ ������ ��� ����Ű�� ����� ����� ȣ���Ѵ�. 


*/
