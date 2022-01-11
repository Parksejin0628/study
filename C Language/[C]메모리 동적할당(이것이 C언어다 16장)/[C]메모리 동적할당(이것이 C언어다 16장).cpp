#include<stdio.h>
#include<stdlib.h>


int main(void)
{
	int i = 0;
	int *pi;
	double *pd;
	char *pc;
	
	printf("(1)\n");
	pi = (int*)malloc(sizeof(int));
	if(pi == NULL)	printf("error\n"); 
	*pi = 7;
	printf("동적 할당한 메모리로 정수 저장 : %d\n", *pi);
	free(pi);
	// malloc함수로 동적할당이 가능하고 free함수로 반환한다. 
	printf("\n(2)\n");
	pi = (int*)malloc(5*sizeof(int));
	for(i=0; i<5; i++)
	{
		pi[i] = i*5; 
	}
	printf("malloc함수로 배열생성 결과\n");
	for(i=0; i<5; i++)
	{
		printf("%d\n", pi[i]);
	}
	free(pi);
	//malloc함수 사이즈에 정수를 곱함으로써 배열선언 가능 
	printf("\n(3)\n");
	pi = (int*)calloc(5, sizeof(int));
	pi[0] = 1;
	pi[1] = 2;
	pi[2] = 3;
	printf("calloc을 통한 배열 생성 결과\n");
	for(i=0; i<5; i++)
	{
		printf("%d\n", pi[i]);
	}
	pi = (int*)realloc(pi, 10*sizeof(int));
	printf("realloc을 통해 저장공간을 늘린 결과\n");
	for(i=0; i<10; i++)
	{
		printf("%d\n", pi[i]);
	}
	//calloc함수로 0으로 초기화된 메모리를 얻을 수 있고 realloc을 통해 사이즈롤 재할당 가능 
	
	scanf("%d");
	return 0;
}

/*
[16장 메모리 동적할당]
<16.1 동적 할당 함수>
16.1.1 malloc, free 함수 
	- 프로그램을 작성할 때 처리할 데이터 종류나 수를 장담할 수 없다면 필요한 변수나 배열의 공간을 실행 도중에 동적으로 확보하는 것이 좋다.
	- 프로그램 실행 중에 할당한 저장 공간은 사용 후 재활용을 위해 반납해야한다.
	- malloc함수 : 메모리를 동적 할당할 때 사용한다. (stdlib.h 헤더파일을 포함시켜야한다.) 
		> 사용법 : 사용하고자 하는 자료형의 포인터 변수를 준비한 뒤 '포인터변수 = (포인터변수의 자료형*) malloc(sizeof(자료형))' 으로 메모리를 동적 할당한다. 
		> 원형 : void *malloc(unsigned int size);
		> 의미 : size 바이트 수만큼 할당하고 시작 위치(주소)를 반환한다. 
		> 예시 : double* pd; / pd = (double *)malloc(sizeof(double))
		> malloc함수는 void*형을 반환하므로 사용하고자 하는 포인터형으로 형변환해야한다. 
		> 프로그램 실행시 메모리 부족 등의 문제로 원하는 크기의 공간을 할당하지 못하면 malloc함수는 NULL포인터를 반환한다. 따라서, malloc함수를 사용할 때는 반환값이 널포인터가 아닌지 '반드시' 확인하고 사용해야한다.
			ex) pi = (int*)malloc(sizeof(int)) / if(pi==NULL)	exit(1);
		> 사용이 끝난 저장 공간은 재활용할 수 있도록 반환해야 한다.
		> 동적 할당된 저장공간은 저장공간 힙(heap)영역을 사용하고 이는 프로그램이 종료될 때 까지 메모리에 존재하므로 어느 함수에서나 사용할 수 있다. 단, 쓰레기값이 존재한다. 
	- free함수 : 할당한 메모리를 반환할 때 사용한다. (stdlib.h 헤더파일을 포함시켜야 한다.) 
		> 사용법 : free(동적할당된 메모리를 가리키는 포인터)를 통해 동적할당된 메모리를 반환시킨다. 
		> 원형 : void free(void *p);
		> 의미 : p에 연결된 영역을 반환한다.
		> 예시 : free(pd);
16.1.2 동적 할당 영역을 배열처럼 쓰기
	- 형태가 같은 변수가 많이 필요할 경우 많은 저장 공간을 한꺼번에 동적 할당하여 배열처럼 사용할 수 있다.
	- malloc함수를 사용할 때 매개변수에 sizeof(자료형) * (할당하려는 저장 공간의 갯수)처럼 사용하여 배열처럼 사용할 수 있다.
		ex) int *pi; / pi = (int*)malloc(5 * sizeof(int)); / printf("%d",pi[2]);
16.1.3 기타 동적 할당 함수
	- 메모리를 동적 할당할 때 malloc을 가장 보편적으로 사용한다. 그러나, 경우에 따라 더 잘 들어맞게 사용할 수 있는 함수들이 있다.
	- calloc함수 : 할당한 저장공간을 0으로 초기화한다. (0으로 초기화된 메모리 공간을 얻고자 할 때 사용) 
		> 사용법 : 포인터변수 = (자료형*)calloc(공간의 개수, sizeof(자료형)) / 공간의 개수에는 배열로 사용할 때 배열 요소의 개수를 적으면 된다. 
		> 원형 : void *calloc(unsigned int cnt, unsigned int size);
		> 의미 : size크기의 공간을 cnt개만큼 할당하고, 할당한 저장 공간을 모두 0으로 초기화한다.
		> 예시 : int* pi; / pi = (int*)calloc(5, sizeof(int)) : int형 저장공간을 5개만큼 할당 
	- realloc함수 : 할당한 저장 공간의 크기를 조절할 수 있다. (할당할 때 예측한 크기보다 필요한 크기가 너무 크거나 작은 경우 사용) 
	`	>사용법 : 포인터변수 = (자료형*)realloc(이미 할당한 포인터, 재할당 후 전체 저장공간의 크기) 
		> 원형 : void *realloc(void *p, unsigned int size); 
		> 의미 : p에 연결된 저장공간을 size크기만큼 재할당한다.
		> 예시 : pi = (int*)realloc(pi, 10 * sizeof(int)) : pi에 연결된 저장공간을 10칸으로 확장
		> 이미 사용하던 저장 공간의 위치를 포인터가 기억하고 있더라도 재할당 과정에서 메모리의 위치가 바뀔 수 있으므로 realloc 함수가 반환하는 주소를 다시 포인터에 저장하는 것이 좋다. 
		> 초기화를 안할 경우 새로 할당한 저장공간의 쓰레기값이 나올 수 있음 
*/ 	
