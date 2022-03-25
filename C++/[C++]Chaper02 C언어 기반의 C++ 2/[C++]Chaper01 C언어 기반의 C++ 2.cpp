#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void que2_1();
void add(int &num);
void change(int &num); 
void SwapPointer(int *(&ptr1), int *(&ptr2));

int main(void)
{
	int input;
	
	que2_1();
	
	cin>>input;
	
	return 0;
} 
 
void que2_1()
{
	int num = 10;
	
	// 문제 1 : 참조자를 이용ㅇ해서 다음 요구사항에 부합하는 함수르르 각각 정의하여라 
	/*
	add(num);
	cout<<"1을 증가시킨 후 num값 : "<<num<<endl;
	change(num);
	cout<<"부호를 바꾼 뒤 num값 : "<<num<<endl;
	*/
	
	// 문제 2 : 포인터 변수 ptr1, ptr2가 있다고 했을 때 SwapPointer(ptr1, ptr2); 를 호출하면 ptr1과 ptr2가 가리키는 대상이 서로 바뀌도록 함수를 정의해보자.
	/*
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;
	
	cout<<"현재 ptr1 주소값 : "<<ptr1<<endl;
	cout<<"현재 ptr2 주소값 : "<<ptr2<<endl;
	SwapPointer(ptr1, ptr2);
	cout<<"변환 후 ptr1 주소값 : "<<ptr1<<endl;
	cout<<"변환 후 ptr2 주소값 : "<<ptr2<<endl; 
	*/
	
	
	return;
} 

void add(int &num)
{
	num++;
	
	return;
}

void change(int &num)
{
	num *= -1;
	
	return; 
}

void SwapPointer(int *(&ptr1), int *(&ptr2))
{
	int *temp;
	temp = ptr1;
	ptr1 = ptr2;
	ptr2 = temp;
	
	return;
}


/*
[C언어 기반의 C++ 2]
2.1. Chapter 02의 시작에 앞서
 1) const의 의미
  - const int num : num을 상수화
  - const int *ptr1 = &val1 : 포인터변수 ptr1으로 val1의 값을 수정할 수 없다.
  - int * const ptr2 = &val2 : 포인터변수 ptr2가 상수화되었다.
  - const int * const ptr3 = &val3 : 포인터 변수 ptr3가 상수화 되었으며 ptr3로 val3의 값을 수정할 수 없다.
 2) 메모리 영역
  - 데이터 : 전역변수가 저장되는 영역
  - 스택 : 지역변수 및 매개변수가 저장되는 영역
  - 힙 : malloc 함수호출에 의해 프로그램이 실행되느느 과정에서 동적으로 할당이 이루어지는 영역
 3) 호출방법
  - Call-by-value : 변수 값으로 호출
  - Call-by-reference : 주소를 통해 호출
  
2.2. 새로운 자료형 bool
 1) bool 자료형의 의미 : true와 false를 저장하는 자료형이다.
  - true : 참
  - false : 거짓
  - 단, true와 false는 각각 1, 0이 아닌 참과 거짓을 나타내는 1바이트 크기의 자료형이다. 단지, 정수의 형태로 형변환하거나 출력할 때 1, 0으로 변환되도록 정의되었을 뿐이다.
 2) bool 또한 기본 자료형이기 때문에 다른 기본 자료형처럼 선언도, 함수의 반환으로도 선언이 가능하다. 
 
2.3. 참조자(Reference)의 이해
 1) 참조자 : 참조자는 이미 할당된 메모리 영역에 또 다른 이름을 선언하는 것이다. 즉, 변수에 별명(별칭)을 붙여주는 것이다.
  - 사용 방법 : 변수를 선언할 때 변수 명 앞에 &를 붙여준다.
  	ex) int num1 = 0; int &num2 = num1;
  - 단, 변수에 대해서만 선언이 가능하고 선언과 동시에 누군가를 참조해야 한다.
  - 또한, 참조의 대상을 바꾸는 것도 불가능하다. 
 2) 참조자의 특징
  - 참조자의 수에는 제한이 없다. 같은 메모리 영역(변수)에 많은 참조자를 선언할 수 있다. (단, 필요 이상으로 참조자를 선언하는 것은 바람직하지 않다.) 
  - 참조자를 대상으로 참조자를 선언할 수 있다. 
  	ex) int num1 = 10; int &num2 = num1; int &num3 = num2; int &num4 = num3; (가능하다)
  - 참조자를 상수로 선언하는 것은 불가능하다.
  	ex) int &ref = 20; (X)
  - 참조자를 미리 선언한 후 후에 참조하거나 NULL로 초기화하는 것도 불가능하다.
  	ex) int &ref = NULL; (X)
  - 배열요소는 변수로 간주되기 때문에 참조가 가능하다.
  	ex) int arr[3] = {1, 3, 5}; int &ref = arr[1]; (O) 
  - 이러한 특징이 포인터와의 큰 차이점 중 하나이다. 
  
2.4. 참조자(Reference)와 함수
 1) 참조자의 활용은 함수가 큰 위치를 차지한다.
  - 기존 C언어에서 포인터로 수행하던 Call-by-reference 즉, 주소에 의한 호출을 참조자에 의해서도 가능하기 때문이다.
  	ex) void swap(int &ref1, int &ref2) { 스왑... } 함수는 실제로 함수를 호출한 곳의 데이터를 스왑시켜준다.
	  > 매개변수는 함수 호출과 동시에 초기화가 되기 때문에 선언과 동시에 초기화해야하는 참조자가 사용이 가능하다. 
*/ 
