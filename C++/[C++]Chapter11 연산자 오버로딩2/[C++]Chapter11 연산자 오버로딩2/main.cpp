#include"Person.h"
#include"Common.h"
#include"Police.h"
#include"Arr.h"
#include"ArrayObject_address.h"
#include"ArrayObject_value.h"
#include"(Example)StablePointPtrArray.h"
#include"BoundCheck2DIntArray.h"

//다음에 공부할 때는 11-2를 풀이하면 된다.

void que1();
void que2();

int main(void)
{
	Person man1("Lee dong woo", 29);
	Person man2("Yoon ji yul", 22);
	man2 = man1;
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	
	Array arr(5);
	arr[2] = 3;
	arr[4] = 5;
	cout << "배열 클래스 값들 : " << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	ArrayObject_value arrObj_val(3);
	arrObj_val[0] = Person("ParkSejin", 22);
	arrObj_val[1] = man1;
	cout << "객체 클래스(값저장)" << endl;
	for (int i = 0; i < 3; i++)
	{
		arrObj_val[i].ShowPersonInfo();
	}

	ArrayObject_address arrObj_add(3);
	arrObj_add[0] = new Person("ParkSejin", 22);
	arrObj_add[1] = new Person(man1);
	arrObj_add[2] = new Person(man2);
	cout << "객체 클래스(주소 저장)" << endl;
	for (int i = 0; i < 3; i++)
	{
		arrObj_add[i]->ShowPersonInfo();
	}

	que1();
	que2();

	return 0;
}

void que1()
{
	/*
	[문제1]
	Chapter 07에서는 예제 HASCComposite.cpp를 통해서 다음의 두 클래스를 정의하였다.
	이 예제에서 Police 클래스를 대상으로 깊은 복사가 이뤄지도록 대입 연산자와 복사 생성자를 동시에 정의하고 
	확인을 위한 함수도 적절히 정의해보자.
	*/
	Police police1(2, 5);
	Police police2 = police1;

	cout << "오리지널 총 정보" << endl;
	police1.ShowPolice();
	cout << "복사생성자 police2 정보 확인" << endl;
	police2.ShowPolice();

	Police police3(5, 22);
	cout << "원래 police3 정보" << endl;
	police3.ShowPolice();
	police3 = police1;
	cout << "대입 후 police3 정보" << endl;
	police3.ShowPolice();

	return;
}

void que2()
{
	/*
	[문제1]
	 - 예제 StablePointPtrArray.cpp의 65행, 66행에서 *(arr[i])가 아닌 arr[i]로 할 수 있도록
	   Point 클래스를 대상으로 연산자 오버로딩을 진행해보자.
	*/
	cout << "문제11-2[1]" << endl;
	BoundCheckPointPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	POINT_PTR address = arr[0];

	for (int i = 0; i < arr.GetArrLen(); i++)
		cout << arr[i];
	delete arr[0];
	delete arr[1];
	delete arr[2];
	/*
	[문제2]
	 - 2차원 배열접근에 대한 연산자 오버로딩을 진행하고자 한다.(실제로 이렇게까지 하지는 않는다.)
	   'class BoundCheck2DIntArray { ... }' 이름으로 클래스를 정의하자.
	   이 클래스는 BoundCheckIntArray(책 예제)클래스의 2차원 배열 버전이다.
	   'BoundCheck2DIntArray arr2d(3, 4); 처럼 객체를 생성하면 세로와 가로의 길이가 각각 3과 4인
	   int형 2차원 배열처럼 동작하는 arr2d 객체가 생성되는 것이다.
	   즉, 'arr2d[n][m] = n + m'와 같은 형태로 데이터를 저장 및 참조할 수 있어야 한다.
	   두 개의 []연산자를 동시에 오버로딩 하는 것은 허용되지 않기 때문에 
	   arr2d[n][m] -> (arr2d.operator[](n))[m] 와 같이 해석되며
	   따라서, ((반환 값).operator[](m); 와 같이 해석되어야 한다.
	[풀이 접근]
	 - 기존 이차원 배열의 원리 처럼 첫 번째 인덱스에서는 주소값을 반환하고 주소값을 받는 함수가
	   값을 반환하도록 해야 할 것 같다.
	   즉, operator[](int)는 주소값을, operator[](...) 주소값에 대한 자료형이 있던가..?
	   자료형은 직접 정의하면 된다! 자료형을 직접 저장한 뒤 클래스의 멤버 변수로 삼으면 그만이다.
	   BoundCheck2dIntArray 클래스에서 Arr클래스를 배열형태로 저장하면 전부 쉬워질 것 같다.
	   operator[](int)에서 Arr을 반환하면 그만이니까
	*/
	BoundCheck2DIntArray arr2d(3, 4);
	
	cout << "문제11-2[2]" << endl;

	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			arr2d[n][m] = n + m;
		}
	}

	for (int n = 0; n < 3; n++)
	{
		for (int m = 0; m < 4; m++)
		{
			cout << arr2d[n][m] << ' ';
		}
		cout << endl;
	}

	return;
}

ostream& operator<<(ostream& os, const Point& pos)
{
	os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
	return os;
}

ostream& operator<<(ostream& os, const Point* pos)
{
	os << '[' << pos->xpos << ", " << pos->ypos << ']' << endl;
	return os;
}



/*
[Chapter11 연산자 오버로딩2]
<11.1. 반드시 해야 하는 대입 연산자의 오버로딩>
1. 대입 연산자의 대표적인 특성 및 오버로딩
 1) 대입 연산자의 특성은 복사 생성자와 매우 유사하다.
	- 정의하지 않으면 디폴트 대입 연산자가 삽입된다.
	- 디폴트 대입 연산자는 멤버 대 멤버의 복사를 진행한다. (얕은 복사)
	- 깊은 복사가 필요한 경우 직접 정의해야 한다.
 2) 복사 생성자 호출과 다른 점은 이미 생성 및 초기화를 끝낸 객체들을 대상으로 진행한다.
	ex) obj2 = obj1 이 문장의 경우
		> obj1만 초기화가 끝난 객체인 경우 : 복사 생성자 호출
		> obj1, obj2 모두 초기화가 끝난 객체인 경우 : 대입 연산자 호출(오버로딩)
 3) 디폴트 대입 연산자는 멤버 대 멤버의 복사를 진행하며 호출한 객체를 참조형으로 반환한다.
	- 다른 연산자 오버로딩처럼 obj1 = obj2 는 obj1.operator=(obj2) 로 해석된다.
2. 디폴트 대입 연산자의 문제점 및 해결법
 1) 복사 생성자의 유사한 문제점이 존재한다.
	- 유사하게 얕은 복사가 진행되기에 참조형 변수를 복사할 때 서로 다른 객체가 같은 주소를 가리키게 되는 문제가 있다.
		> 즉, 동적할당을 하는 변수가 있을 경우 객체가 소멸할 때 같은 공간을 두 번 소멸하게 된다.
	- 이미 정의된 객체를 대상으로 복사가 이루어지기 때문에 기존에 가리키던 공간의 주소값을 잃게 된다.
		> 주소값을 잃은 공간은 다시 접근이 불가능하기에 소멸도 불가능하게 된다. 이는 메모리 누수로 이어진다.
 2) 복사 생성자의 문제를 해결하기 위해서는 복사 생성자의 문제를 해결할 때와 유사하게 접근해야 한다.
	- 따로 정의하여 깊은 복사를 진행하도록 해야 한다.
	- 복사를 진행하기 전 메모리 누수를 방지하기 위해 기존에 가리키던 공간의 메모리를 해제시켜야 한다.
3. 상속 구조에서의 대입 연산자 호출
 1) 대입 연산자는 복사 생성자와 다르게 유도 클래스에서 대입 연산자가 호출되어도 기초 클래스의 대입 연산자가 호출되지 않는다.
	- 이는 유도 클래스의 대입 연산자 부분에서 기초 클래스의 대입 연산자 호출을 따로 명시해야 한다는 의미이다.
	- 따로 명시하지 않을 경우 기초 클래스의 대입 연산자는 호출되지 않아 유도 클래스의 멤버만 복사되는 경우가 발생하낟.
4. 이니셜라이저가 성능 향상에 도움을 주는 이유
 1) 이니셜라이저는 생성과 동시에 초기화가 이루어진다.
	> 따라서, 초기화 과정에서 생성자만 호출된다.
 2) 단순한 대입 연산자를 통한 초기화는 생성과 초기화가 따로 이루어진다.
	- 즉, 선언과 초기화를 별도의 문장에서 진행하는 형태로 이루어진다.
	- 이는 선언을 할 때 생성자가, 초기화를 할 때 대입 연산자가 호출되어 함수를 2번 이상 호출하게 한다.
 3) 위 같은 이유 때문에 이니셜라이저를 이용하면 함수의 호출 횟수가 줄어들어 성능향상이 된다.

<11.2. 배열의 인덱스 연산자 오버로딩>
1. 배열의 인덱스 연산자 오버로딩 및 배열 클래스
 1) []연산자도 다른 연산자와 비슷하게 연산자 오버로딩이 된다.
	ex) obj[2] -> obj.operator[](2)로 해석이 된다.
	- []연산자는 멤버함수 기반으로만 오버로딩 할 수 있다.
 2) C, C++의 기본 배열은 경계검사를 실시하지 않는다는 단점을 가지고 있다.
	- 즉, arr[3]으로 정의한 변수에 arr[-1], arr[4]등 범위를 넘게 접근해도 이상 없이 컴파일 된다.
 3) 기본 배열의 단점을 보완하는 멤버 함수를 지닌 배열 클래스가 필요한 이유이다.
	- 배열 클래스의 기본적인 형태는 코드부분 arr 클래스에서 다룬다.
 4) []연산자 오버로딩에서 반환형태를 참조형으로 함으로써 배열 값의 변경을 허용한다.
	ex) 'int& operator[](int idx)' 형식처럼 하여 'obj[2] = 3'과 같은 문장이 허용되도록 한다.(기존 배열처럼 사용을 위해)
 5) 객체를 대상으로 하는 복사 생성자와 대입 연산자를 private 멤버로 두어 복사와 대입을 원천적으로 막는것이 좋다.
	- 배열은 유일성이 보장될 필요가 있기 때문이다.
2. const 오버로딩 활용하기
 1) const함수에서도 객체 클래스 값에 접근해야 하는 경우가 있다.
	- 그러나, 연산자 오버로딩이 const가 아니기에 접근할 수 없다.
 2) 기존 연산자 오버로딩 함수를 const로 선언하면 값의 변화가 불가능해진다.
	ex) 'obj[2] = 3'과 같은 문장은 멤버의 값을 변화시키기에 const 선언과 맞지 않는다.
 3) 따라서, const함수를 위한 const 오버로딩을 해둘 필요가 있다.
	- 이미 앞에서 const의 유무 만으로 오버로딩이 가능함을 익혔다.
	- 이때 'int operator[](int idx) const'와 같이 참조형이 아닌 값을 반환한다.
		> 값의 변화는 어차피 허용되지 않기 때문이다.
	- 이와 관련된 코드는 코드부분의 arr부분에서 다루고 있다.
3. 객체를 저장하는 배열 클래스
 1) 객체를 저장하는 배열 기반의 클래스
	- 객체 자체를 멤버 변수에 저장하는 방법이다.
	- 배열을 초기화 할 때 대입연산을 사용해야 하기 때문에 복사 생성자와 대입 연산자의 얕은 복사를 신경써야 하는 단점이 있다.
 2) 주소값을 저장하는 배열 기반의 클래스
	- 객체의 주소값을 멤버 변수에 저장하는 방법이다.
	- new, delete를 신경써야 하지만 복사 생성자와 대입 연산자의 얕은 복사를 신경쓸 필요가 없다.
	- 위와 같은 장점으로 객체를 저장하는 방법보다 많이 쓰인다.
 3) 형태 : 코드 부분의 objArr부분에서 다룬다.
*/