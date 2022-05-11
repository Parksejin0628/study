#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main(void)
{
	
	
	return 0;
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


*/
