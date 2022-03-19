#include<iostream>

void que1_1();
void que1_2();
void swap(int* num1, int* num2);
void swap(char* ch1, char* ch2);
void swap(double* dbl1, double* dbl2);


int main(void)
{
	int n;
	que1_1();
	que1_2();
	
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
// swap 함수 버그수정이 필요하다. 
void swap(int* num1, int* num2)
{
	int temp = 0;
	int number1 = 0;
	int number2 = 0;
	
	temp = *num1
	*num1 = *num2;
	*num2 = temp;
	
	return;
}

void swap(char* ch1, char* ch2)
{
	char temp = '\0';
	temp = *ch1
	*ch1 = *ch2;
	*ch2 = temp;
	
	return;
}


void swap(double* dbl1, double* dbl2)
{
	double temp = 0;
	temp = *dbl1
	*dbl1 = *dbl2;
	*dbl2 = temp;
	
	return;
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
   
*/

 
