#include<iostream>
#include<cstring>
#include<ctime>
#include<cstdlib> 

using std::cout;
using std::cin;
using std::endl;

typedef struct __Point
{
	int xpos;
	int ypos;
}Point;

void que2_1();
void que2_2();
void que2_3(); 
void que2_4();
void add(int &num);
void change(int &num); 
void SwapPointer(int *(&ptr1), int *(&ptr2));
Point& PntAdder(const Point &p1, const Point &p2);

int main(void)
{
	int input;
	
	//que2_1();
	//que2_2();
	//que2_3();
	//que2_4();
	
	cin>>input;
	
	return 0;
} 
 
void que2_1()
{
	int num = 10;
	
	// 문제 1 : 참조자를 이용해서 다음 요구사항에 부합하는 함수르르 각각 정의하여라 
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

void que2_2()
{
	const int num = 12;
	//문제 : 포인터 변수를 선어하여 위 변수를 가리키게 한 후 그 포인터 변수를 참조하는 참조자를 선언하자. 마지막으로 선언된 포인터 변수와 참조자를 이용해 num에 저장된 값을 출력하는 예제를 만들자. 
	const int* const ptr = &num;
	const int* const (&ref) = ptr;
	
	cout<<"포인터 형태 : "<<*ptr<<endl;
	cout<<"참조자 형태 : "<<*ref<<endl; 
}

void que2_3()
{
	// 2차원 평면상에서의 좌표를 표현할 수 있는 구조체를 정의한다. 그 뒤  Point& pntAdder(const Point &p1, const Point &p2); 형태의 함수를 정의하여 두 점의 합을 계산하도록 한다.
	// 단, 구조체 Point 관련 변수의 선언은 무조건 new 연산자를 이용해 진행하며 할당된 메모리 공간의 소멸도 철저해야 한다.
	Point *point1 = new Point;
	Point *point2 = new Point;
	point1->xpos = 3;
	point1->ypos = 5;
	point2->xpos = 4;
	point2->ypos = 8;
	 
	Point &result = PntAdder(*point1, *point2);
	cout<<"덧셈 결과 : ("<<result.xpos<<", "<<result.ypos<<")"<<endl;
	
	delete point1;
	delete point2;
	delete &result;
	
	
	return;
}

void que2_4()
{
	// 문제 1 : strlen, strcat, strcpy, strcmp를 호출하는 예제를 만들되 C++헤더를 선언해서 만들어보자. C언어에서는 string.h에 선언되어있다. 
	char *name1 = new char[30];
	char *name2 = new char[30];
	
	strcpy(name1, "dog");
	strcpy(name2, "elephant");
	cout<<"1번과 2번중 더 이름이 긴 것은 : ";
	if(strlen(name1) > strlen(name2))
	{
		cout<<name1<<endl;
	}
	else
	{
		cout<<name2<<endl;
	}
	cout<<"두 이름이 같나요? : ";
	if(strcmp(name1, name2) == 0)
	{
		cout<<"네!"<<endl;
	}
	else
	{
		cout<<"아니요!"<<endl;
	}
	strcat(name1, name2);
	cout<<"이름 융합! : "<<name1<<endl;
	
	// 문제 2 : rnad, srand, time을 이용해서 0이상 100미만의 난수를 총 5개 생성하는 예제를 만들되 C++의 헤더를 선언해서 작성해보자. (time : time.h / rand, srand : stdlib.h)
	int *num = new int[5]; 
	srand(time(NULL));
	cout<<"렌덤 5개 숫자 : ";
	for(int i=0; i<4; i++)
	{
		num[i] = rand() % 100;
		cout<<num[i]<<", ";
	}
	num[4] = rand() % 100;
	cout<<num[4]<<endl;
	
	 
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

Point& PntAdder(const Point &p1, const Point &p2)
{
	Point *result = new Point;
	result->xpos = p1.xpos + p2.xpos;
	result->ypos = p1.ypos + p2.ypos;
	
	return *result;
}

/*
복습 및 정리본
[Chapter02 C언어 기반의 C++ 2]
2.1. Chapter 02의 시작에 앞서
 1) const int num : num을 상수화
 2) const int *ptr = &val : 포인터 ptr으로 val값 수정 불가능
 3) int const *ptr = &val : 포인터 변수 ptr이 상수화

2.2. 새로운 자료형 bool
 1) bool은 true / false를 저장하는 자료형이다.
 2) true : 참 / false : 거짓을 의미한다.
 3) true / false는 각각 1/0이 아닌 참과 거짓을 나타내는 1바이트 크기의 자료형일 뿐이다.

2.3. 참조자(Reference)의 이해
 1) 참조자 : 변수를 선언할 때 변수 명 앞에 &를 붙여 선언한다. 이미 할당된 메모리 영역에 또 다른 이름을 선언하는 것이다.
 2) 참조자는 선언과 동시에 누군가를 참조해야하며 참조의 대상을 바꾸는 것도 불가능하다.
 3) 참조자는 상수를 선언하거나 NULL로 초기화할 수 없다.

2.4. 참조자(Reference)와 함수
 1) 참조자는 C에서 Call-by-reference를 수행할 때 사용하던 포인터를 대체할 수 있다.
 2) const로 참조자를 선언하면 해당 참조자로는 값을 변경할 수 없다.
 3) 매개변수를 const참조자로 선언하면 함수 선언부만 보더라도 해당 함수에서 전달한 인자의 값을 변경하지 않는다는 것을 알릴 수 있으며 상수도 입력받을 수 있다.

2.5. new & delete
 1) new와 delete는 기존 C언어의 malloc, free 역할을 수행한다. new, malloc이 다른 C++ 기능과 상호작용하기 때문에 malloc, free는 사용하지 않는다.
 2) new : 메모리 공간을 할당한다. int *ptr = new int 와 같이 사용한다. 배열은 int *ptr = new int[3]와 같이 사용한다.
 3) delete : 할당된 메모리 공간을 반환한다. delete ptr와 같이 사용한다. 배열은 delete []ptr와 같이 사용한다.

2.6. C++에서 C언어의 표준함수 호출하기
 1) 기존 C언어에서 사용하던 라이브러리는 C언어 라이브러리에서 .h를 빼고 앞에 c를 붙인다.
 2) 예시 : include<stdio.h> -> include<cstdio>
 3) C라이브러리와의 호환성을 위해 이렇게 바꾸었으며 C++ 문법에 맞추어 라이브러리를 변경했기에 위와같은 형태로 라이브러리를 사용해야 한다.
*/

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
 2) 참조자의 단점
  - C언어에서는 변수를 인자로 전달하는 함수가 사용되면 해당 변수의 값은 절대 변하지 않을 것이라는 확신이 있었다.
  	ex) add(a, b) -> a, b의 값이 함수에서는 사용되겠지만, 함수로 인해 a, b의 값이 변하지 않겠구나!
  - 하지만 C++에서는 참조자를 통한 호출도 고려해야 하기 때문에 무조건 함수의 원형을 봐야하며, 만약 매개변수가 참조자인 경우 해당 함수에서 값에 변화를 주는지도 확인해야한다.
  	ex) add(a, b) -> a, b가 참조자로 호출됐으면 값의 변화가 있을 수 있겠네.. 함수의 원형을 찾아봐야겠다. 
	ex) 함수원형 : add(int &num1, int &num2) ->  값이 변할 수도 있겠네.. 함수 몸체도 확인해봐야겠다.
  - 이러한 문제를 어느정도 해결하기 위해 const 선언을 사용하는 것이 좋다.
 3) const로 선언한 참조자
  - const로 선언한 참조자는 참조자를 이용한 값의 변환을 금지한다는 의미이다.
  	ex) const int &ref = num1 / ref++; (X)
  - 이러한 특징을 통해 함수 내에서, 참조자를 사용하지만 값의 변경을 진행하지 않는 경우 참조자를 const로 선언하여 함수의 원형만 보아도 값의 변경이 이루어지지 않음을 알 수 있게 하는 것이 좋다.
  	ex) add(const int &num1, const int &num2) -> 이 함수를 통해 원형 변수의 값이 변화하지 않겠구나!
  - 또한, const로 선언한 참조자는 상수화된 변수는 물론 상수도 선언할 수 있다.
  	ex) 기존 : const int num = 5; / int &ref = num; (X) (num이 상수화되었기 때문에 상수를 참조할 수 없는 참조자는 참조할 수 없다.)
	    const 사용 : const int num = 5; / const int &ref = num; (O)
		상수 : const int &ref = 5; (O)
  - 이것이 가능한 이유는 C++에서 const 참조자를 이용해 상수를 참조할 때 임시 변수를 만들어 상수를 저장한 후 이 변수를 참조하기 때문이다.
  - 이러한 개념을 만든 이유는 const참조자를 매개변수로 하는 함수에서 상수를 전달하기 위해 변수를 선언하는 낭비를 줄이기 위해서이다.
  	ex) int adder(const int &num1, const  int &num2) 함수가 있을 때 이러한 개념이 없으면 adder(20, 30)이 불가능하지만, C++에서는 adder(a, b)뿐만 아니라 adder(20, 30)도 가능하다.
 4) 참조자를 반환형으로 할 경우
  - 참조형으로 반환된 값을 참조자에 저장하면, 참조의 관계가 하나 더 추가되는 것이다.
  - 물론, 함수가 반환하면 매개변수로 선언된 참조자는 소멸되지만, 참조하던 기존 메모리가 소멸하는 것은 아니므로 상관이 없다. 
  - 단, 지역변수 (혹은 일반적인 매개변수)를 참조형으로 반환하고 참조자에 저장하면 참조하던 변수는 함수가 반환된 후 소멸하므로 심각한 오류가 발생할 수 있다.
  	> 게다가, 컴파일러가 에러메시지를 띄워주지도 않으며 아직 채 소멸되지 않은 찌꺼기의 형태로 남아있는 데이터를 참조해서 정상적으로 보이는 출력결과를 보이기도 함으로 더더욱 주의해야한다.
  - 참조자를 반환하는 경우 참조자도, 일반 변수도 반환받을 수 있다. (물론, 그냥 변수를 반환하는 경우에는 참조자로 반환받을 수 없다.) 

2.5. new & delete
 1) new & delete는 기존 C언어의 malloc & free의 역할을 수행한다.
  - new : 기존의 malloc 처럼 메모리 공간을 할당하는 역할을 한다. 
  - delete : 기존의 free 처럼 할당된 메모리 공간을 반환한다.
  - 게다가, new와 delete는 후에 클래스에서 다루겠지만 C++의 클래스와 객체 개념에서 또 다른 기능을 수행하기 때문에 C++에서는 malloc & free를 사용하지 않는다. (오히려 문제가 될 수 있다.)
 2) 사용방법
  - new : '포인터변수 = new 자료형;' 형식으로 사용한다. 배열의 형태를 사용할 대는 자료형에 '[배열크기]'를 붙인다. 
  	ex) int * ptr1 = new int;
	  	int * arr1 = new int[3];  
  - delete : 'delete 변수명;' 형식으로 사용한다. 배열의 형태를 할당한 변수는 변수명 앞에 []를 붙인다.
  	ex) delete ptr1;
	  	delete []arr1;
 3) 힙에 할당된 변수를 포인터를사용하지 않고도 접근하기
  - C++에서는 new 연산자를 이용해 할당된 메모리 공간도 변수로 간주하여 참조자의 선언이 가능하도록 한다.
  	ex) int *ptr = new int; / int &ref = *ptr; / ref = 20; (O) (이처럼 포인터를 사용하지 않고도 힙 영역에 접근했다는 사실이 중요하다.) 
  	
2.6. C++에서 C언어의 표준함수 호출하기 
 1) C++에서 기존 C언어에서 사용하던 라이브러리는 C언어에서 사용하던 헤더파일 이름에서 확장자인 .h를 빼고 앞에 c를 붙이면 C++에서 호환하는 헤더파일 이름이 된다.
 	ex) stdio.h -> cstdio / string.h -> cstring
	ex) #include<cmath>
 2) C++의 헤더를 선언해야 하는 이유
  - C++에서 C 라이브러리를 지원해주는 이유는 하위 버전과의 호환성을 위해서이다.
  - C라이브러리를 C++ 문법에 맞추어 바꿨기 때문에 C++의 표준헤더를 사용하는 것이 좋다. 
*/ 
