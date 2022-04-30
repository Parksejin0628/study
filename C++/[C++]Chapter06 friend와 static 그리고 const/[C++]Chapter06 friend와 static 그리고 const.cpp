#include<iostream>
#include<cstring>

using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	
	
	return 0;
}

/*
[Chapter06 friend와 static 그리고 const]
<6-1. const와 관련해서 아직 못다한 이야기> 
1. const 객체
 1) 객체로 변수처럼 상수화가 가능하다. 이는, 이 객체의 데이터 변경을 허용하지 않는다는 의미이다. 
 	ex) const SimpleClass obj(20);
 2) 상수화된 객체는 멤버함수 중 const 선언이 된 멤버함수만 호출이 가능하다.
 	- 데이터 변경이 이루어지는 경우가 아에 없도록 하기 위해서이다.
	- 이 때문에 우리는 가능하다면 데이터를 변경하지 않는 함수를 const로 선언함으로써 const 객체도 사용할 수 있도록 해야한다. 
2. const선언 함수 오버로딩
 1) const 선언 유무만으로도 함수 오버로딩이 될 수 있다.
 	ex) SimpleFunc(int num) / SimpleFunc(int num) const 가 존재할 때 이 둘은 함수 오버로딩이 된 다른 함수이다.
 2) 인자의 종류와 갯수가 같으나 const 선언만 다른 함수 오버로딩이 호출되는 조건은 다음과 같다.
 	- 호출하는 객체가 일반 객체일 경우 일반 함수를 호출한다.
	- 호출하는 객체가 const 객체일 경우 const 함수를 호출한다. 
	
<6-2. 클래스와 함수에 대한 friend 선언>
1. friend란?
 1) friend는 friend로 선언한 대상(객체나 함수)이 해당 선언이 있는 클래스의 private 멤버 접근을 허용한다는 의미이다.
 	ex) SimpleClass 안에서 'friend 함수' 선언을 할 경우 해당 함수에서 SimpleClass의 private 멤버에 접근할 수 있다.
		Simpleclass 안에서 'firend 객체' 선언을 할 경우 해당 객체에서 SimpleClass의 private 멤버에 접근할 수 있다.
 2) friend 선언은 한 방향이다. 따라서, 양쪽 객체의 private 멤버를 공유하려면 양쪽 다 friend 선언을 해야한다.
 	ex) 클래스 A에서 firend B를 하면 B에서는 A의 private에 접근할 수 있으나 A가 B의 private에 접근할 수 있다는 의미는 아니다.
 3) 하지만, friend 선언은 정보은닉을 무너뜨리기에 가급적 사용하지 않아야 한다.
 	- 나름의 기준이 설 때 까지는 아에 사용하지 않는 것이 좋다.
2.클래스 이름 선언
 1) 함수 선언처럼 클래스 이름만 미리 선언하는 방법이 있다.
 	ex) class SimpleClass;
	- 이 경우 다른 곳에서도 해당 클래스가 있다는 사실을 인지할 수 있다.
 2) 클래스 안에서 friend class Girl 와 같은 문장을 선언할 경우
 	- Girl은 클래스 이름이다.
	- 그리고 friend로 선언한다.
 3) 클래스의 이름을 미리 선언하는 습관을 들이면 좋아 보인다.
 
 <6-3. C++에서의 static>
1. static의 개념
 1) C언어에서 static은 다음과 같은 의미를 가졌다.
  	- 함수 내에 선언된 static : 한 번만 초기화 되며 함수를 빠져나가도 초기화되지 않는다.
	- 전역 변수에 선언된 static : 선언된 파일 내에서만 참조를 허용한다.
 2) C++에서도 클래스내에서 static을 사용할 때 객체가 소멸되도 초기화되지 않는다는 비슷한 특징을 가지고 있다.
2. static 멤버변수
 1) static으로 선언된 멤버변수는 다음과 같은 특징을 가지고 있다.
 	- 객체가 생성되있던 말던 메모리 공간에 딱 하나만 할당되어 공유된다.
	 	> 객체가 생성되기 전에 이미 존재한다는 의미이다.
		> 객체를 아무리 생성해도 static 멤버변수는 오직 하나이며 모든 객체는 이 하나를 공유한다.
		> 객체를 아무리 생성하고 소멸해도 초기화되지 않는다. 
	- 클래스 안에서 선언하지만 객체안에 존재하는 것은 아니다.
		> 그저 객체에게 접근할 수 있는 권한을 줬을 뿐이다. 
		> 그래서, 클래스 이름으로 접근할 수 있다.
 2) static 멤버변수 초기화
 	- static 멤버변수는 생성자로 초기화해서는 안된다.
	 	> 만약, 생성자에서 초기화하는 경우 객체가 생성될 때마다 초기화될 것이고 이는 static의 의미를 퇴색시킨다.
	- 클래스 외부에서 초기화 하도록 정의되어있다.
		ex) int SimpleClass::staticVar = 2;
 3) static 멤버변수 접근
 	- private로 선언된 경우에는 클래스 안에서만 접근이 가능하다.
	- 하지만 public으로 선언된 경우 클래스 이름을 통해 접근이 가능하다!
		ex) cout<<SimpleClass::staticVar<<endl;
		> 객체가 없어도 존재하는 변수이기 때문에 객체가 없어도 클래스명으로 접근할 수 있다.
	- 일반 멤버변수와 구별하기 위해 클래스이름으로 접근하는 것이 좋다.
 4) const static 멤버변수
 	- const와 static의 특징을 모두 가진 멤버변수이다.
	- 즉, 값이 변화하지 않으며 모든 객체가 공유하는 멤버변수이다.
		> 이는 클래스의 모든 객체가 공통적으로 공유하는 상수를 사용할 때 유용하다는 의미이다.
	- const static 멤버변수는 다른 멤버변수와 다르게 클래스 내에서 일반 변수처럼 초기화 한다.
		ex) class SimpleClass
			{
				const static int RUSSIA = 170540;
				const static int CANADA = 998467;
		};
3. static 멤버함수
 1) static 멤버변수와 유사하게 다음과 같은 특징을 가진다.
 	- 선언한 클래스의 모든 객체가 공유하는 함수이다.
	- public으로 선언시 클래스의 이름을 통해 호출이 가능하다.
	- 객체가 생성되었던 말던 메모리 공간에 할당되어있다.
	- 객체의 멤버로 존재하는 것이 아니다.
 2) 여기서 중요한 것은 '객체의 멤버가 아니다'라는 것이다.
 3) 객체의 멤버가 아니므로 객체의 멤버변수나 함수에 접근할 수 없다.
 	> 이게 허용이 되면 객체가 생성되기도 전에 호출할 수 있는 static 멤버함수의 특정상 생성하지도 않은 멤버변수나 함수에 접근할 것이다.
 4) 따라서, static 멤버변수는 static 멤버변수와static 멤버함수만 호출이 가능하다.
4. mutable
 1) mutable로 선언된 멤버변수는 const 함수에서도 값을 변경할 수 있도록 예외를 둔다.
 	> 즉, 값의 변경이 허락되지 않는 const 함수에서 값을 변경할 수 있는 변수가 되는 것이다.
 2) 하지만, 이는 const의 의미를 퇴색시키기에 거의 사용해서는 안되며 의미만 알고 있는 것이 좋다. 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	 
	  


*/
