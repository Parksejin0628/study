#include<iostream>

int main(void)
{
	//문제 5-1부터 진 행 
	
	return 0;
}

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
 2) 이 경우 멤버 대 멤버 복사를 위해 복사 생성자가 정의되어 있지 않아도 디폴트 복사 생성자라는 것이 삽입되어 멤버 대 멤버 복사를 진행한다.
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
  
*/
