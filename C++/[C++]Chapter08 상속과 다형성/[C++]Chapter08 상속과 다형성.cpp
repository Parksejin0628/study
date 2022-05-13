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
	[문제]
	책에 있는 예제 EmployeeManager4.cpp를 확장하여 다음 특성에 해당하는 ForeignSalesWorker클래스를 추가로 정의해보자.
	'영업직 직원 중 일부는 오지산간으로 시장개척을 진행하고 있다. 일부는 아마존에서, 또 일부는 테러의 위험이 있는 지역에서 영업활동을 진행 중에 있다.
	따라서 이러한 직원들을 대상으로 별도의 위험수당을 지급하고자 한다.'
	위험수당의 지급방식은 '위험의 노출도'에 따라서 다음과 같이 나뉘며, 한 번 결정된 직원의 '위험 노출도'는 변경되지 않는다고 가정한다. (const 멤버변수의 선언을 의미한다.)
	 - 리스크 A : 영업직의 기본급여와 인센티브 합계 총액의 30%를 추가로 지급한다.
	 - 리스크 B : 영업직의 기본급여와 인센티브 합계 총액의 20%를 추가로 지급한다.
	 - 리스크 C : 영업직의 기본급여와 인센티브 합계 총액의 10%를 추가로 지급한다.
	다음 코드가 동작하도록 ForeignSalesWorker 클래스를 정의하며, Employee 클래스는 객체 생성이 불가능한 추상 클래스로 정의한다. 
	*/
	// ForeignSalesWorker 클래스 추가부터 시작하면 된다. 
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
[Chapter08 상속과 다형성]
<8.1. 객체 포인터의 참조관계> 
1. 유도클래스도 참조가 가능한 객체 포인터 변수
 1) 클래스를 기반으로도 포인터 변수를 선언할 수 있다.
 	ex) Person * ptr;
	 	ptr = new Person();
 2) 그런데, 이러한 포인터 변수는 해당 객체 뿐만 아니라 그 객체의 클래스를 상속하는 유도 클래스의 객체도 가리킬 수 있다.
 	> 책의 표현을 인용하자면 'C++에서, AAA형 포인터 변수는 AAA 객체 또는 AAA를 직접 혹은 간접적으로 상속하는 모든 객체를 가리킬 수 있다(객체의 주소 값을 저장할 수 있다).'
 	> 이 표현해서 '간접적으로 상속'은 AAA를 상속하는 클래스를 상속한다는 의미이다. 
	ex1) Person * ptr;
		 ptr = new Student(); (Student는 Person을 상속하는 유도클래스이다.)
	ex2) Person * ptr2;
		 ptr2 = new PartTimeStudent(); (PartTimeStudent는 Student를 상속하는 유도클래스이다. Student는 Person을 상속하므로 이 문장이 가능하다.)
 3) 이런 표현이 가능한 이유를 알아보기 위해 위 Person을 예로 들어보자.
   > Student, PartTimeStudent는 모두 Person과 IS-A 관계이다.
   > 즉, Student, PartTimeStudent는 모두 Person이다.
   > 따라서, 논리적으로 Person 포인터 변수가 Student, PartTimeStudent를 가리킬 수 있는 것이다.
 4) 해당 표현을 통해서 우리는 좋은 프로그램의 조건 중 하나인 유연성과 확장성을 확보할 수 있다.
 	> 예를 들어, 위 Person을 사용하는 프로그램에서 Person을 대상으로 한 컨트롤 클래스가 있다고 하자.
	> 만약 Person을 상속하는 Teacher이 추가됐다고 하면 우리는 Teacher을 위해 컨트롤 클래스를 수정할 필요가 있었을 것이다.
	> 하지만, 포인터로 유도클래스도 참조가 가능하게 함으로써, Teacher을 가리키는 변수를 추가할 필요 없이 Person 포인터 변수가 Teacher을 가리키게 하여 수정을 최소화할 수 있다.
	> 결국, Person을 직접 혹은 간접적으로 상속하는 클래스가 추가되었을 때, 컨트롤클래스의 변화가 필요 없어지는 것이다.
	> 이는, 유연성과 확장성의 큰 기여를 한다.
2. 함수 오버라이딩
 1) 함수 오버라이딩(function overriding)
 	> 기초클래스에서 상속받는 함수를 유도클래스에서 동일한 이름과 형태로 '재정의'하는 것이다. (오버라이딩은 무시하다는 의미로 기존 함수를 무시하고 새로 정의한다는 의미를 담고있다.) 
	> 유도클래스에서 유도클래스만 가지는 기능을 다시 정의할 때 사용된다.
	> 해당 유도클래스에서 해당 이름의 함수를 호출할 경우 기존 기초클래스에 있던 함수가 아닌 유도클래스에서 재정의된 함수가 호출된다. 
	> 기초클래스에 오버라이딩한 함수를 호출하는 함수가 있을 경우 이 함수는 기초클래스의 함수를 호출하게되므로 유도클래스에있는 함수를 호출하게 하기 위해서는 역시 유도클래스에서 오버라이딩 해야한다. 
	
<8.2. 가상함수>
1. 포인터 연산에 대한 컴파일러의 판단
 1) 앞에서 확인했듯 클래스형 포인터 변수는 유도클래스까지 가리킬 수 있다.
 	ex) Person *ptr / ptr = new Student();
 2) 하지만 컴파일러는 포인터 연산의 가능성을 판단할 때 자료형을 기준으로 한다. 즉, 기초클래스 포인터로 유도클래스를 가리키는 것은 가능하지만 유도클래스의 멤버는 사용할 수 없는 것이다. 
 	> Base * bptr 포인터 변수가 있다고 하면 bptr은 Base외에도 유도클래스인 Derived를 가리킬 수 있다.
	> 하지만, bptr의 자료형은 Base이므로 Base의 멤버만 호출할 수 있다.
	> 다시말해, Derived의 멤버함수인 DerivedFunc()는 호출할 수 없다.
 3) 이러한 특징때문에 유도클래스에 기초클래스를 대입하는 것도 제한이 된다.
 	> 즉, Base 포인터 변수가 Derived를 가리키더라도 Derived 포인터 변수에 대입연산은 불가능하다. Base 포인터 변수가 Base를 가리킬지 Derived를 가리킬지는 모르기 때문이다. 
	 	ex) Base *bptr = new Derived(); / Derived *dptr = bptr (x)
	> 또한, 기초클래스 포인터 변수에 유도클래스를 대입하는 것은 가능하다. 이는 기초클래스가 유도클래스를 가리키는 것까지 허용하기 때문이다. 
		ex) Derived *dptr = new Derived(); / Base *bptr = dptr (o)
2. 자료형을 따르는 함수 호출
 1) 앞에서 살펴본 컴파일러 판단의 특징때문에 클래스 포인터 변수의 멤버 호출은 자료형을 따라간다.
 2) 이는, 오버라이딩도 해당이 된다.
 	> 아무리 유도클래스를 가리키고, 오버라이딩이 존재한다고 해도 자료형의 함수를 호출하게 되는 것이다.
	 	ex) First * fptr = new Third / MyFunc()  결과 : FristFunc (함수 오버라이딩이 존재하지만 자료형을 따라 First에 있는 멤버함수 호출) 
			Third * tptr = new Third / MyFunc() 결과 : ThirdFunc (함수 오버라이딩으로 Third에 있는 멤버함수 호출) 
 3) 이러한 특징은 상속의 목적인 확장성과 유연성을 해칠 수 있게 된다.
 	> 가리키는 객체에 따라 원하는 다른 함수를 호출해야 유연성과 확장성이 확보되지만, 자료형만 따르기 때문이다.
	> 이는 가상함수 개념의 등장배경이 되었다. 
3. 가상함수(virtual Function)
 1) 항상 자료형을 따라가는 클래스 포인터 변수의 멤버 호출의 단점을 보완하기 위해 탄생한 개념이다.
 2) 함수를 가상함수로 선언하면 포인터의 자료형을 기반으로 호출 대상을 선정하는 것이 아닌 가리키는 대상을 기반으로 호출 대상을 선정하게 된다.
	ex) First *fptr = new Third()이고, MyFunc()가 가상함수인 경우 Third의 MyFunc를 호출하게 된다.
 3) 이러한 가상함수의 선언은 virtual 키워드의 선언을 통해서 이루어진다.
 	> 멤버함수 앞에 virtual 키워드를 추가한다.
 	> 함수의 선언부에만 virtual 키워드를 추가한다. 
	ex) virtual void MyFunc() { ... }
 4) 가상함수가 선언된 뒤 해당 함수를 오버라이딩하는 함수도 자동으로 가상함수가 된다.
 	> 하지만, 가상함수라는 것을 명시하기 위해 유도클래스에서 virtual을 추가하도록 하자. 
4. 순수 가상함수, 추상 클래스(Pure Virtual Function, Abstract Class)
 1) 기초 클래스 중에서는 기초 클래스로서의 의미만 가질 뿐 객체의 생성을 위한 클래스가 아닌 것이 있다.
 	> 이런 클래스를 대상으로 객체를 선언하는 실수가 발생할 수 있다.
 2) 이런 클래스에서는 실수를 막기 위해 가상함수를 '순수 가상함수(Pure Virtual Function)'으로 선언하는 것이 좋다.
 	> 순수 가상함수는 함수의 몸체가 정의되지 않은 함수를 의미한다.
	> 함수 선언 끝에 = 0을 붙여 표현한다.
		ex) virtual int GetPay() const = 0;
 3) 하나 이상의 순수 가상함수를 가지는 클래스를 추상 클래스(abstract class)라고 한다.
 	> 추상 클래스는 문법적으로 객체생성을 불가능하게 하기에 실수를 방지할 수 있다.
	> 호출을 돕는 의미만을 가지는 함수를 좀 더 명확히 명시할 수 있게 된다. 
5. 다형성(Polymorphism)
 1) 여태까지 다룬 가상함수의 호출 관계에서 보인 특성을 가리켜 '다형성(polymorphism)'이라고 한다.
 2) 다형성은 동질이상을 의미한다.
 	> 모습은 같은데 형태는 다르다는 의미를 가진다.
	> C++의 관점으로 말하면 문장은 같은데 결과는 다르다는 것을 의미한다.
	> virtual로 가리키는 대상에 따라 같은 문장도 다른 결과를 도출해내기에 다형성이라고 한다.
		ex) First *fptr = new First() 혹은 new Third() / fptr->MyFunc() 여기서 처음에 포인터변수가 무엇을 가리키냐에 따라 같은 문장이지만 다른 결과를 도출해내기에 다형성의 예시가 된다. 
6. 상속의 이유 
 1) 상속을 통해 연관된 일련의 클래스에 대해 공통적인 규약을 정의할 수 있다.
 	> 쉽게 말해 IS-A관계로 표현 가능한 클래스들에 공통적인 규약, 특징들을 정의할 수 있게 해준다.
 2) 이러한 상속을 통해 모든 클래스의 객체를 하나의 기초 클래스로 묶어 바라봄으로써 유연성과 확장성을 늘려준다.
 	ex) 책 예시에서 사용하는 PermanentWorker, TemporaryWorker, SalesWorker 모두 Employee로 바라보고 프로그램을 만듦으로써 유연성과 확장성을 확보하였다. 

<8.3. 가상 소멸자와 참조자의 참조 가능성>
1. 가상 소멸자
 1) 소멸자 또한 포인터 변수의 자료형을 따라가므로 유도 클래스의 소멸자는 제대로 호출이 안될 수 있다.
 2) 따라서, virtual 키워드를 통해 소멸자를 가상함수로 정의함으로써 유도 클래스의 소멸자도 제대로 호출될 수 있도록 한다. 
2. 참조자의 참조 가능성  
 1) 참조자도 포인터 변수처럼 멤버함수를 접근한다.
 	> 기초클래스로 참조자를 선언할 경우 유도클래스도 참조할 수 있게 된다.
	> 기본적으로 멤버호출은 선언한 자료형을 따른다.
	> 단, virtual로 가상함수화 시켰을 경우 가리키는 대상의 멤버를 호출한다. 


*/
