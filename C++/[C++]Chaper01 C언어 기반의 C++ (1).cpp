#include<iostream>

void que1_1();
void que1_2();
void que1_3(); 
void swap(int* num1, int* num2);
void swap(char* ch1, char* ch2);
void swap(double* dbl1, double* dbl2);
void func1(void);
void func1(int num1 = 3, int num2 = 5);
int BoxVolume();
int BoxVolume(int length);
int BoxVolume(int length, int width);
int BoxVolume(int length, int width, int height);


int main(void)
{
	int n;
	//que1_1();
	//que1_2();
	que1_3();
	//func1();
	// 디폴트 값을 설정해놓은 경우 매개변수 개수 차이를 통한 함수 오버로딩은 불가능하다. 
	
	std::cin>>n;
	
	return 0;
}

void que1_1()
{
	//문제1 사용자로부터 총 5개의 정수를 입력 받아서, 그 합을 출력하는 프로그램을 작성해 보자.
	/*
	int num = 0;
	int result = 0;
	
	for(int i=1; i<=5; i++)
	{
		std::cout<<i<<"번째 정수 입력: ";
		std::cin>>num;
		result+=num;
	} 
	std::cout<<"합계: "<<result<<std::endl;
	*/
	
	//문제2 프로그램 사용자로부터 이름과 전화번호를 문자열의 형태로 입력 받아서, 입력 받은 데이터를 그대로 출력하는 프로그램을 작성해보자.
	/*
	char name[20];
	char number[20];
	
	std::cout<<"이름 : ";
	std::cin>>name;
	std::cout<<"전화번호 : ";
	std::cin>>number;
	std::cout<<"[사용자정보]"<<std::endl;
	std::cout<<"이름 : "<<name<<std::endl;
	std::cout<<"전화번호 : "<<number<<std::endl; 
	*/
	
	//문제3 숫자를 하나 입력받아서 그 숫자에 해당하는 구구단을 출력하는 프로그램을 작성해 보자.
	/*
	int num = 0;
	std::cout<<"숫자를 입력해주세요 : ";
	std::cin>>num;
	for(int i=1; i<=9; i++)
	{
		std::cout<<num<<" * "<<i<<" = "<<num*i<<std::endl;
	} 
	*/
	
	/*문제4 판매원들의 급여 계산 프로그램을 작성해 보자. 이 회사는 모든 판매원들에게 매달 50만원의 기본 급여와 물품 판매 가격의 12%에 해당하는 돈을 지급한다. 
	 예를 들어서 민수라는 친구의 이번 달 물품 판매 금액이 100만원이라면, 50 + 100 * 0.12 = 62, 따라서, 62만원을 급여로 지급 받는다. 단 급여의 계산은 -1이 입력될 때까지 계속 되어야 한다.*/
	/*
	int num = 0;
	int basicSalary = 50; 
	double percent = 0.12;
	while(1)
	{
		std::cout<<"판매 금액을 만원 단위로 입력(-1 to end): ";
		std::cin>>num;
		if(num < 0)
		{
			std::cout<<"프로그램을 종료합니다.";
			break;
		}
		std::cout<<"이번 달 급여: "<<basicSalary + num*percent<<"만원"<<std::endl;
	} 
	*/
	
	return;
}

void que1_2()
{
	//다음 구문이 필요로 하는 swap 함수를 오버로딩해서 구현해보자. 
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	std::cout<<num1<<' '<<num2<<std::endl;
	
	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	std::cout<<ch1<<' '<<ch2<<std::endl;
	
	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	std::cout<<dbl1<<' '<<dbl2<<std::endl;
	
	return;
} 

void que1_3()
{
	//문제1 : 예제 DefalutValue3.cpp에 정의된 함수 BoxVolume를 '매개변수의 디폴트 값 지정' 형태가 아닌, '함수 오버로딩'의 형태로 재 구현해보자.
	/*
	예제 DefalutValue3.cpp에 정의된 함수 Boxvolume
	int BoxVolume(int length, int width, int height)
	{
		return length*width*height;
	}
	*/
	std::cout<<"[3, 3, 3] : "<<BoxVolume(3, 3, 3)<<std::endl; 
	std::cout<<"[5, 5, D] : "<<BoxVolume(5, 5)<<std::endl;
	std::cout<<"[7, D, D] : "<<BoxVolume(7)<<std::endl;
	
	return; 
}

void swap(int* num1, int* num2)
{
	int temp = 0;
	int number1 = 0;
	int number2 = 0;
	
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	
	return;
}

void swap(char* ch1, char* ch2)
{
	char temp = '\0';
	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
	
	return;
}


void swap(double* dbl1, double* dbl2)
{
	double temp = 0;
	temp = *dbl1;
	*dbl1 = *dbl2;
	*dbl2 = temp;
	
	return;
}

void func1(void)
{
	
	return;
}

void func1(int num1, int num2)
{
	return;
}

int BoxVolume(int length)
{
	return length;
}

int BoxVolume(int length, int width)
{
	return length*width;
}

int BoxVolume(int length, int width, int height)
{
	return length*width*height;
}


/*
[Chapter 01 C언어 기반의 C++ 1]
1-1. printf와 scanf를 대신하는 입출력방식
 1) C와 비교되는 C++의 특징 
  - C++에서는 입출력 함수를 사용하기 위해 #include<iostream>을 선언해야한다.
  - C++ 표준 헤더파일의 선언에서는 확장자인 .h를 생략한다.
   > 이는 과거의 표준 라이브러리와 구분하기 위해서이다.
  - C++은 어디서나 지역변수 선언이 가능하다. (기존 C언어는 함수의 가장 앞부분에 위치했어야 했다.)
 2) 출력
  - 'std::cout<<출력대상' 형태로 출력을 사용할 수 있다.
  - '출력대상' 위치에는 정수, 실수, 문자열, 변수 등 어떠한 것이 오든 상관이 없다.
  - C언어와 달리 %d, %lf와 같은 서식문자를 사용하지 않아도 변수의 형태에 따라 알아서 출력이 이루어진다.
  - <<연산자를 계속 사용하여 여러 대상을 출력할 수 있다.
   ex) std::cout<<13<<"+"<<num1<<'='<<result;
  - <<연산자 이후 std::endl을 통해 줄넘김(개행)을 할 수 있다.
 3) 입력
  - 'std::cin>>변수' 와 같은 형태로 입력을 할 수 있다. 
  - 출력과 마찬가지로 서식문자를 사용하지 않아도 변수의 형태에 따라 알아서 입력이 이루어진다. 심지어, 문자열도 마찬가지이다.
   > 개인적인 생각으로는 이러한 변수의 형태를 찾는 과정으로 인해 C언어보다는 쉬울 수 있어도 더 느리게 작동할 것 같다.
   
1-2. 함수 오버로딩(Function Overloading)
 1) 함수 오버로딩 : 매개 변수의 선언 형태가 다르다면 동일한 이름의 함수 정의를 허용하는 것이다.
  > c++은 호출할 함수를 찾을 때 이름 뿐만 아니라 매개변수의 선언방식도 활용하기 때문이다.
  > 궁금한 것은 C에서는 함수명이 주소를 가리키기 때문에 함수의 정보가 담긴 주소로 찾아가기만 하면 그만이었다. 
   그런데, 매개 변수의 형태까지 파악하려면 어떻게 하는 것일까? 이름에 주소값을 여러개 저장하고 하나하나 찾아가며 매개변수를 비교하는 것일까? 
 2) 함수 오버로딩이 가능한 조건  
  - 매개변수의 자료형이 다른 경우 
  	ex) int MyFunc(char c)
  		int MyFunc(int n)
  - 매개변수의 개수가 다른 경우
    ex) int myFunc(int n)
		int myFunc(int n1, int n2)
  - 즉, 매개변수의 자료형 또는 개수가 다른 경우 함수의 오버로딩이 가능하다. 
  
1-3. 매개변수의 디폴트 값(Defalut Value)
 1) C++에서는 함수의 매개변수에 디폴트 값을 설정할 수 있다.
  > 함수를 호출할 때 인자를 전달하지 않는 경우 매개변수의 값이 설정한 디폴트 값으로 된다.
  > 따라서, 디폴트 값을 설정한다면 일부 혹은 전부 다 인자를 전달하지 않아도 된다.
  	ex) int cal(int num1 = 5, int num2 = 7)로 선언된 함수가 있으면 cal(), cal(2), cal(2, 5)모두 문법적으로 문제가 없다.
 2) 단, 디폴트 값은 반드시 맨 오른쪽에 있는 매개변수부터 채워 넣어야 한다.
  	ex) 3개의 매개변수를 가진 함수가 있다고 가정했을 때 3번만 디폴트 값을 설정하는 것은 가능하지만 1번, 2번만 디폴트 값을 설정하는 것은 불가능하다.
  > 이유는, 함수를 호출할 때 인자를 맨 왼쪽 매개변수부터 채워 넣기 때문이다.
  	ex) 3번만 디폴트 값이 없는 함수가 있다 가정해보자. 1, 2번은 디폴트 값으로 하고 3번만 인자를 넣고 싶어도 함수를 호출할 때 인자를 왼쪽부터 채워넣기 때문에 불가능하다.
 3) 함수의 원형을 별도로 선언할 때는 함수 원형 선언 부분에만 디폴트 값을 설정한다. 
 4) 이러한 기능은 게임을 제작할 때 게임의 기본 값으로 프로그램을 돌리다가 사용자가 설정을 통해 특정 변수의 수치를 조절할 경우 유용하게 사용될 것 같다. 
 
1-4. 인라인(inline) 함수
 1) 인라인 : 인라인은 함수를 호출하는 대신 함수의 몸체 부분이 함수호출 문장을 대체하는 것이다. 매크로 함수의 실행방식을 생각하면 편하다.
 2) 인라인 함수 : 매크로 함수의 단점인 정의의 복잡함을 해소한 C++의 기능이다.
  > 사용법 : 함수를 선언할 때 앞에 inline을 붙이고 기존 매크로 함수 처럼 사용하면 된다.
  	ex) inline int SQUARE(int x)... / std::cout<<SQUARE(5)<<std::endl
 3) 인라인 함수의 장단점
  > 장점 : 인라인 함수는 컴파일러에 의해 처리되기 때문에 인하인 과정이 오히려 성능에 해가 되면 키워드를 무시하는 등 최적화가 한 층 더 잘된다. 
		   매크로 함수에 비해 정의가 훨씬 쉽다.
  > 단점 : 매크로 함수와는 다르게 자료형을 사전에 정의해야 하기 때문에 자료형에 의존해야한다.
   - 이는 나중에 나오는 템플릿을 이용하면 개선이 가능하다. 
   
1-5. 이름공간(namespace)
 1) 이름공간 : 이름공간은 협업을 하거나 라이브러리 간에 함수이름이 겹쳐 오류가 발생하는 것을 사전에 방지하기 위하여 공간에 이름을 붙여놓은 것을 의미한다.
  > 특정한 이름공간을 만들고 그 안에 함수를 정의하거나 변수를 정의하면 다른 이름공간에 함수나 변수와 이름이 겹치더라도 충돌이 발생하지 않는다.
  > 이름공간 안에 있는 함수나 변수에 접근하기 위해서는 :: 연산자를 이용하며 '이름공간::함수나변수' 방식으로 사용한다. 
  	ex) std::cout (그렇다, cout, cin같은 C++표준 라이브러리의 함수도 std라는 이름공간에 선언되어 있는 것이다!)
  > ::연산자를 범위지정 연산자라 하며 이름공간을 지정할 때 사용한다.
 2) 이름공간만의 특징  
  > 이름 공간 안에 원형이 선언된 함수는 이름 공간 밖에서 저장할 때 ::연산자를 이용해 지정한 후 함수를 정의한다.
  	ex) BestComImpl안에 void SimpleFunc(void); 처럼 선언된 경우 이름공간 밖에서는 'void BeskComImpl::SimpleFunc(void){ 함수 정의 }' 와 같은 형식으로 정의한다. 
  > 동일한 이름공간에 정의된 함수를 호출할 때는 이름 공간을 명시할 필요가 없다. (같은 함수안에서 지역변수를 사용하는 것과 비슷하게 생각하면 된다. 
  > 이름공간은 마치 구조체 처럼 이름공간 안에 이름공간이 중첩될 수 있다.
   - 이는 구조체에서 .로 접근했던 것 처럼 ::로 이름공간 안에 이름공간으로 접근하면 된다.
   	ex) abc이름공간 안에 efg이름공간에 접근할 때 'abc::efg::함수나변수'와 같은 형식으로 접근한다. 
 3) using
  > 이름공간의 명시가 필요없다고 생각되는 경우 using을 통해 이름공간 명시를 생략할 수 있다.
  > 특정 이름공간의 함수나 변수를 using할 때는 'using 이름공간::함수나 변수' 처럼 선언하면 된다. 그러면 해당 함수나 변수가 무조건 해당 이름공간 안에 있는 함수나 변수를 가리키는 것으로 해석한다. 
  	ex) using std::cin; 처럼 명시하면 다음부터 std안에 cin을 사용할 때 std::cin이 아닌 cin만 사용해도 된다. 
  > 특정 이름공간의 함수나 변수 모두를 using 할 때는 'using namespace 이름공간' 처럼 선언하면 된다.
  	ex) using namespace std; 처럼 명시하면 다음부터 cout, cin을 사용할 때 std::cin, std::cout이 아닌 cin, cout만 사용하면 된다.
  > 이렇게 using을 쓰면 프로그래밍을 할 때 편해지지만 이름충돌이 발생할 확률이 높아진다.
  > using 선언을 함수 안에 한 경우 해당 함수 안에서만 적용된다. 파일 자체에 적용하려면 함수 밖에 선언해야한다.
  > 'namespace 이름 = 이름공간경로' 형태를 통해 별칭을 지어줄 수 있다.
  	ex) namespace ABC = AAA::BBB::CCC / 다음부터 ABC는 AAA::BBB::CCC에 접근한다는 의미가 된다.
  > 함수 안에서 지역변수와 이름이 같은 전역변수를 사용하려면 변수이름 앞에 ::를 붙이면 된다.
  	ex) val이라는 변수가 지역변수, 전역변수 모두 선언된 상태에서 ::val += 7을 사용하면 지역 변수가 아닌 전역변수 val의 값을 7 증가시킨다. 
*/

 
