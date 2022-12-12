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
		cout<<"이름: "<<name<<endl;
		cout<<"회사: "<<company<<endl;
		cout<<"전화번호: "<<callNum<<endl;
		cout<<"직급: ";
		if(rank == 1)
		{
			cout<<"사원"<<endl; 
		}
		else if(rank == 2)
		{
			cout<<"주임"<<endl; 
		}
		else if(rank == 3)
		{
			cout<<"대리"<<endl; 
		}
		else if(rank == 4)
		{
			cout<<"과장"<<endl; 
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
		cout<<this<<" 복사 생성"<<endl;
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
	/*cout<<"함수 시작 전"<<endl;
	obj.showClassInfo();
	cout<<"함수 시작"<<endl; 
	testFunc(obj).showClassInfo();
	cout<<"함수 종료"<<endl;
	obj.showClassInfo();*/
	
	cin>>num;
	
	return 0;
}

void que5_1()
{
	/*
	문제 : 문제 4-3의 문제 2를 통해 NameCard 클래스를 정의하였다. 그런데 이 클래스도 생성자 내에서 메모리 공간을 동적 할당하기 때문에 복사 생성자가 필요한 클래스이다. 
	이에 복사 생성자를 적절히 정의하고 복사 이후에 문제가 발생하지 않음을 다음 main함수를 통해 확인하자. 
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
[Chapter05 복사 생성자(Copy Constructor)]
<5-1. '복사 생성자'와의 첫 만남>
1. 묵시적 변환 : 객체 생성 및 초기화를 할 때 '='를 사용한 경우 인자가 하나인 생성자가 존재할 때 '()'로 알아서 변환되는 것
	ex) SimpleClass obj = 3 -> SimpleClass obj(3) 묵시적 변환
2. 복사 생성자 : 같은 객체를 인자로 받아 대응하는 멤버 변수끼리 값을 복사하는 생성자
	ex) SimpleClass(const SImpleClass &copy)와 같은 생성자
	- 복사 생성자가 있을 경우 SimpleClass obj = copy와 같은 문장이 성립된다.
	- 복사 생성자에서 인자를 받을 때는 반드시 &를 사용하며, const를 사용하는 것이 좋다.
3. 디폴트 복사 생성자 : 복사 생성자가 따로 정의하지 않은 경우 알아서 맴버 대 맴버 복사를 진행하도록 생기는 생성자
	- 뒤에 설명할 '깊은 복사'가 필요하지 않으면 단순 맴버 대 맴버 복사에서는 문제가 발생하지 않는다.


<5-2. '깊은 복사'와 '얕은 복사'>
1. 얕은 복사 : 맴버 대 맴버로 값만 복사하는 경우
2. 얕은 복사의 문제점 : 포인터 혹은 참조자가 있을 경우 같은 대상을 참조하도록 복사하게 된다. 이는 예상치 못한 결과를 발생시킨다.
	ex) ptr1을 복사한 ptr2에서 값을 변경했더니 ptr1까지 값이 변한다.
3. 따라서, 이러한 문제를 해결하기 위해 참조의 대상까지 고려한 복사가 '깊은 복사'이다. (참조의 대상도 추가하는 복사)

<5-3. 복사 생성자의 호출 시점>
1. Call-by-value(값 전달)방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우 해당 함수가 호출되는 순간 매개변수에 객체를 복사하면서 복사 생성자가 호출된다.
2. 함수의 반환형이 객체인데 참조형이 아닌 경우 함수를 호출한 곳에 반환하는 객체의 복사본을 임시 객체로 전달한다.
3. 임시 객체 : 객체의 정보를 임시로 저장하는 공간으로 다음 행에서 바로 소멸한다.
	- 클래스의 이름을 클래스 외부에서 사용할 경우 임시 객체이다.
		ex) SimpleClass(30);
	- 단, 참조자로 임시객체를 참조하는 경우에는 바로 소멸하지 않는다.
*/

/*
[Chapter05 복사 생성자(Copy Constructor)]
<5-1. '복사 생성자'와의 첫 만남'>
1. 묵시적 변환
 1) C++에서 변수의 선언 및 초기화하는 방법은 다음 두 가지가 있다.
  	- int num = 20; : C언어에서부터 사용한 선언 및 초기화
  	- int num(20); : C++에서 추가로 지원하는 선언 및 초기화 방법
 2) 객체의 경우 '='를 통해 객체 생성 및 초기화를 시도할 때 인자가 하나인 생성자가 존재할 경우  '()'로 변환되는 경우가 있는데 이를 묵시적 변환이라고 한다.
  	ex) SimpleClass obj = 3 -> SimpleClass obj(3)
 3) explict
 	- 묵시적 변환을 원하지 않는 경우 explicit 키워드를 사용하면 묵시적 변환이 이루어지지 않는다.
  	- 자동으로 변환되는 것이 많아질 수록 코드의 결과를 예측하기 어려워진다.
  		> 때문에 코드의 명확함을 더하기 위해 자주 사용되는 키워드이다.
2. 복사 생성자
 1) 같은 객체를 인자로 받아 대응하는 멤버 변수끼리 값을 복사하는 생성자를 '복사 생성자(Copy Constructor)'이라고 한다. 
	ex) SimpleClass(const SimpleClass &copy) : num1(copy.num1), num2(copy.num2) // SimpleClas의 멤버변수는 num1, num2만 존재한다.
	- 복사 생성자가 있으면 SimpleClass obj = copy(Simpleclass 객체) 라는 문장이 성립이 된다.
	 > SimpleClass obj(copy)라는 문장으로 묵시적 변환이 된다. (인자가 하나)
	 > 따라서, copy를 인자로 받는 생성자가 호출이 된다.
 2) 복사 생성자에서 인자를 받을 때는 반드시 &를 사용해야 하며 원본 보존을 위해 const를 사용하는 것이 좋다. 
3. 디폴트 복사 생성자
 1) 복사 생성자를 따로 정의하지 않은 경우에도 위에 나온 예시처럼 객체를 인자로 받아 멤버 대 멤버 복사가 가능하다.
 	ex) SimpleClass obj=copy; // 복사 생성자가 따로 정의되지 않아도 가능
 2) 이 경우 멤버 대 멤버 복사를 위해 복사 
	생성자가 정의되어 있지 않아도 디폴트 복사 생성자라는 것이 삽입되어 멤버 대 멤버 복사를 진행한다.
 	- 디폴트 복사 생성자는 위 예시처럼 SimpleClass(const SimpleClass &copy) : num1(copy.num1), num2(copy.num2)와 같은 형태로 삽입된다.
 3) 멤버 대 멤버 복사를 진행하려 할 때 많은 경우 복사 생성자를 정의하지 않아도 된다. 하지만, 반드시 복사 생성자를 정의해야 하는 경우도 있다. 
 
<5-2. '깊은 복사'와 '얕은 복사'>
1. 얕은 복사
 1) 멤버 대 멤버의 복사 (값만 복사)하는 경우를 얕은 복사라고 한다.
 	- 디폴트 복사 생성자는 얕은 복사에 속한다.
2. 얕은 복사의 문제점
 1) 참조 형태를 복사할 경우 같은 대상을 참조하게 된다.
  	- 얕은 복사는 단순히 값만을 복사한다.
	- 즉, 포인터 변수의 경우 같은 대상을 가리키게 되는 것이다.
	- 결국, 힙의 메모리 공간을 참조하는 경우 문제가 발생한다. 
 2) 같은 대상을 참조하게 되는 경우 예상치 못한 결과가 발생한다.
 	- 개발자는 포인터 변수 ptr1, ptr2이 서로 영향을 주지 않도록 복사하려 했을 테지만, ptr1의 값이 변하면 ptr2의 값도 변하게 된다. 
 3) new, delete 과정에서도 문제가 발생한다.
 	- new로 동적 할당한 포인터 변수를 얕은 복사 할 경우 같은 메모리 공간을 참조하게 된다.
	- delete로 변수를 소멸할 때 다른 복사본도 같은 메모리 공간을 참조하므로 이미 소멸된 변수를 소멸시키는 경우가 발생한다. 
 4) 우리가 원하는 참조의 대상까지 고려한 (대상까지 추가한) 복사를 위해서는 다른 형태의 복사가 필요하다.
  > 이는 '깊은 복사'이다. 
3. 깊은 복사  
 1) 멤버뿐만 아니라, 포인터로 참조하는 대상까지 깊게 복사한다는 의미로 '깊은 복사'이다.
 2) 복사 생성자를 따로 정의하고 참조의 대상도 복사하여 각각 다른 대상을 참조하도록 한다. 
4. 문자열 변수를 통해 비교하는 얕은복사 vs 깊은 복사
	메인 함수의 구문은 다음과 같다. 
	SimpleClass obj1("hello world")
 	SimpleClass obj2 = obj1
 	return;
 1) 얕은 복사
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
  
  obj2가 소멸하는 과정에서 "hello world"가 담긴 문자열 소멸
  obj1이 delete할 때는 소멸 대상이 없으므로 문제 발생
 2) 깊은 복사  
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
  	obj1, obj2가 참조하는 대상이 다르므로 문제 없이 실행  
  	
<5-3. 복사 생성자의 호출 시점>
1. 복사 생성자의 호출 시점
 - 복사 생성자가 호출되는 시점은 크게 세 가지로 구분할 수 있다.
 1) 기존에 생성된 객체를 이용해 새로운 객체를 초기화하는 경우
 	ex) SimpleClass copy(3);
	 	SimpleClass obj = copy;
 2) Call-by-value(값 전달)방식의 함수호출 과정에서 객체를 인자로 전달하는 경우
 	ex) SimpleFunc(SimpleClass obj);
 		...
		int main(void) { ... SimpleFunc(obj); ... } (호출할 때 복사 생성자 호출)
 3) 참조형이 아닌 객체를 반환할 때
 	ex) SimpleFunc() { ... return obj; } (반환할 때 호출한 장소에서 복사생성자 호출
 - 위 세 가지 공통점은 객체를 새로 생성해야 하며 생성과 동시에 동일한 자료형의 객체로 초기화 해야 하는 경우이다.
 - 자세한 내용은 1번 사항을 제외하고 따로 설명하도록 한다. 
2. Call-by-value(값 전달) 방식의 함수 호출 과정에서 객체를 인자로 전달하는 경우
 1) 해당 과정이 객체를 생성해야 하며 생성과 동시에 동일한 자료형의 객체로 초기화 해야 하는 이유 
 	- 매개변수는 함수가 호출되는 순간 메모리가 할당이 된다.
 	- 그리고, 메모리가 할당이 되면서 값을 전달받아 할당과 초기화가 동시에 일어난다.  
 2) 함수를 호출할 때  인자가 객체인 경우 객체의 복사본으로 초기화 해야 하므로 복사 생성자가 호출된다. 
 3) 물론, 이 경우에도 복사 생성자를 따로 정의를 안하면 문제가 되는 경우가 발생하므로 해당 경우에는 복사생성자를 따로 정의해야 한다. (한 번 실험해보고 싶다.) 
 4) 복사 생성자의 호출 주체는 매개변수이다. (함수를 호출하는 곳에서 전달하는 객체가 아니다.) 
3. 객체를 반환하되, 참조형으로 반환하지 않는 경우  
 1) 객체를 반환할 때 함수를 호출한 곳에서 반환값을 사용하는 경우가 있으므로 메모리를 할당하여 반환하는 객체의 정보를 저장해야한다.
 	- 이 경우에 반환 값을 복사해서 함수를 호출한 곳에 전달하게 된다.
	- 따라서, 복사 생성자를 호출하여 객체를 복사한다. 
 	ex) cout<<SimpleFunc(30)<<endl;
 2) 이렇게 반환할 때 임시로 반환 객체의 정보를 저장하는 공간을 '임시 객체'라고 한다. 
4. 임시 객체에 대한 심화 탐구
 1) 임시 객체를 임의로 만드는 방법
 	- 클래스의 이름을 클래스 외부에서 사용하는 경우 임시 객체가 된다.
	 	ex) class SimpleClass { ... };
	 		...
	 		int main(void) { SimpleClass(30); //이 부분이 임시 객체이다. } 
 2) 임시 객체가 소멸되는 시점
 	- 임시 객체는 이름이 없어 다음 행부터는 사용할 수 없으므로 바로 소멸된다.
	- 단, 참조자로 참조한 경우는 다음 행부터도 사용할 수 있어 바로 소멸되지 않는다.
		ex) const SimpleClass &ref = SimpleFunc(30) 
 3) 임시 객체를 이용해 새로운 객체를 초기화 하는 경우에 새로운 객체가 생성되는 것이 아닌 임시 객체에 이름이 붙는다!
 	- SimpleClass tempRef = SimpleFunc(obj) 이 문장에서 tempRef 객체가 생성되고 임시 객체를 사용해 초기화 한다고 생각할 수 있다.
	- 그러나, C++에서는 이러한 경우에 객체의 생성 수를 줄여 효율성을 높이기 위해 객체를 추가로 생성하는 것이 아닌 반환된 임시객체에 이름을 할당한다.
	- 어짜피, 임시 객체도 방금 생성한 객체이기 때문에 가능하다. 
	
<실험결과>
1. 컴파일러의 성능덕분인지 얕은 복사를 해도 참조하는 변수가 알아서 참조 대상까지 복사했다. 
2. 아니그러면 임시객체로 복사생성자가 호출될 때 참조하는 변수가 있으면 따로 복사생성자를 정의해야하는지가 의문이다.
 -> 아마 그래야 할 것으로 보인다. 
*/
