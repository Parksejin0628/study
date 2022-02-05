#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(void)
{
	FILE *fp;
	
	printf("(1)\n");
	
	scanf("%d");
	return 0;
}


/*
[18장 파일 입출력]
<18.1 파일 개방과 입출력>
18.1.1 파일 개방과 폐쇄
	- 파일을 입출력하기 위해서는 하드디스크에서 원하는 데이터 파일을 찾아야 한다.
	- 이렇게 데이터를 입출력하기 전에 준비하는 과정이 파일 개방이다.
		> 사용이 끝난 파일은 닫는 과정이 필요하다.
	- fopen 함수를 통해 파일을 열 수 있다.
		> 원형 : FILE *fopen(const char *, const char *); (파일 포인터 반환) 
		> 사용법 : (파일 포인터 변수) = fopen("파일명", "개방모드");
			>> 파일을 찾는 기본 위치는 '현재 작업 디렉터리'로 다른 곳에 있는 파일을 개방하려면 경로도 함께 적는다.
		ex) FILE *fp; / fp = fopen("a.txt", "r");
	- fopen에서 개방 모드
		> r : 읽기 위해 개방 (파일이 없을 경우 NULL반환)
		> w : 파일의 내용을 지우고 쓰기 위해 개방 (파일이 없을 경우 새로운 파일 생성)
			>> 해당 파일의 내용을 모두 지우고 개방하므로 주의해야 한다. 
		> a : 파일의 끝에 추가하기 위해 개방 (파일이 없을 경우 새로운 파일 생성)
			>> w와는 다르게 파일의 내용을 지우지 않고 파일의 끝에 데이터를 추가할 수 있다. 
	- fopen 함수는 실제 파일이 있는 장치와 연결되는 스트림 파일을 메모리에 만든다.
	- fopen함수가 파일을 개방하지 못하면 NULL포인터를 반환하므로 항상 반환값을 검사할 필요가 있다. 
	- fclose 함수를 통해 파일을 닫을 수 있다. 
		> 원형 : int fclose(FILE *); 
	- 개방할 파일을 더이상 사용하지 않는 경우 fclose 함수로 닫는다. 
	- 해당 파일을 성공적으로 닫았을 때는 0을 반환하고 아닐 경우 EOF를 반환한다.
18.1.2 스트림 파일과 파일 포인터
	- 스트림 파일은 프로그램과 입출력 장치 사이의 다리 역할을 하는 논리적인 파일이다.
	- 프로그램은 일단 메모리에 있는 스트림 파일로 입출력을 수행한 뒤 그 파일이 키보드(입력), 모니터(출력), 하드디스크(입출력)와 같은 장치와 연결되어 실제적인 입출력을 수행하도록 되어있다.
	- 스트림 파일은 입출력 데이터를 임시로 저장했다가 한번에 입력/출력 장치에서 바로 사용할 수 있도록 하는 '버퍼'를 가지고 있다.
		> 버퍼만 가지고는 저장된 데이터를 관리할 수 없다. (버퍼의 메모리 위치, 버퍼의 크기 등이 필요하다.)
		> 따라서, 스트림 파일은 버퍼 외에 버퍼를 사용하기 위한 정보를 구조체로 묶어 보관하고 있다.
		> 스트림 파일이 사용하는 구조체 이름이 FILE
	- 스트림 파일을 사용하면 입출력 효율을 높이고 장치로부터 독립된 프로그래밍이 가능하다.
		> 하드디스크 동작 속도는 프로그램의 데이터 처리 속도보다 느리기 때문에 버퍼에서 출력 데이터를 한번에 모아 장치로 보낸 후 장치가 데이터를 기록하는 시간 동안 버퍼를 채움으로써 공백시간을 방지한다.
		> 프로그램이 스트림 파일에 임시 저장하게 함으로써 어떤 입출력 장치가 와도 코드를 수정할 필요가 없이 운영체제가 하드웨어 특성에 따라 연결을 하도록 한다. 
18.1.3 문자 입력 함수 fgetc
	- fgetc 함수를 통해 파일에서 하나의 문자를 입력하여 반환한다. (이때 함수 포인터에 있는 파일은 "r"모드로 열어야 한다.) 
		> 원형 : int fgetc(FILE *); 
		ex) ch = fgetc(fp);
	- fgetc는 호출할 때 마다 반환되는 문자가 이전에 반환한 문자 다음에 있는 문자를 반환하기 때문에 파일의 데이터를 모두 읽어올 수 있다.
		> fgetc 함수가 스트림 파일의 버퍼에서 데이터를 가져올 때 버퍼의 크기만큼 데이터를 한꺼번에 가져와 저장한다. (데이터 크기가 버퍼보다 작은 경우 모든 데이터를 가져온다.) 
		> 그 후 fgetc 함수는 첫번째 문자를 반환한다.
		> 스트림 파일에는 문자를 입력할 버퍼의 위치를 알려주는 지시자가 있으며 0부터 시작하여 fgetc 등 입력함수가 데이터를 읽을 때 그 크기만큼 증가한다.  
		> 따라서, fgetc함수를 반복 호출함으로써 모든 데이터를 읽어올 수 있다. 
	- 만약 하드디스크에 더 이상 읽을 데이터가 없으면 fgetc함수는 EOF를 반환한다. (파일을 다읽었음을 판단할 때 사용하면 좋다.) 
		> 버퍼의 데이터를 모두 읽어 위치 지시자의 값과 버퍼에 저장된 데이터 크기와 같아질 경우 데이터가 없을 경우 EOF, 있을 경우 다시 새로운 데이터를 가져온다. 
18.1.4 문자 출력 함수 fputc
	- 한 문자를 파일로 출력할 때는 fputc 함수를 사용한다. (이때 함수 포인터에 있는 파일은 "w"모드로 열어야 한다.)
		> 원형 : int fputc(int, FILE *);
		> 의미 : int fputc(출력할 문자, "w"모드로 열린 파일 포인터);
			- 파일 포인터가 가리키는 파일에 출력할 문자를 출력한다.
		ex) fputc(str[i], fp);
	- fputc 함수 또한 스트림 파일의 버퍼를 사용하여 버퍼에 데이터(문자)를 모은 뒤 한꺼번에 출력한다.
		> 버퍼가 모두 채워지거나 개행문자를 출력하거나 새로운 입력을 수행하는 경우 버퍼의 데이터를 장치로 출력한다.
18.1.5 기본적으로 개방되는 표준 입출력 스트림 파일
	- 운영체제는 프로그램을 실행할 때 기본적으로 3개의 스트림 파일을 만든다. 이들은 키보드와 모니터 등에 연결하여 입출력 함수들이 포인터 없이 사용할 수 있도록 제공한다.
		> stdin : 표준 입력 스트림 / 키보드와 연결된 입력 스트림 파일이다.
		> stdout : 표준 출력 스트림 / 모니터와 연결된 출력 스트림 파일이다.
		> stderr : 표준 에러 스트림 / 모니터와 연결된 에러 스트림 파일이다. 
	- scanf, printf, getchar, putchat, gets, puts 등의 표준 입출력 함수들은 기본적으로 스트림 파일을 사용한다.
	- 파일 포인터를 인수로 받는 함수도 stdin, stdout, stderr를 인수로 사용함으로써 표준 입출력 스트림 파일을 사용할 수 있다.
		ex) fgetc(stdin) - 키보드와 연결된 표준 스트림 파일을 사용함으로써 키보드로 문자를 입력할 수 있다.
		ex) fputc(ch, stdout) - 모니터와 연결된 표준 스트림 파일을 사용함으로써 화면에 문자를 출력할 수 있다.
	- 표준 입력 스트림 파일을 이용하여 입출력 할 경우 버퍼를 통해 입출력하고 버퍼에서 데이터를 입출력하는 방식을 사용한다.
		> getchar을 예시로 들면 getchar은 stdin을 사용함으로 표준 입력 스트림 파일의 버퍼를 통해 입력한다.
		> 키보드에서 입력하는 데이터는 개행 문자와 함께 stdin 스트림 파일의 버퍼에 한꺼번에 저장된다.
		> 그 후 호출되는 getchar함수는 버퍼로부터 차례대로 문자를 반환한다.
		> 그래서 우리는 getchar 함수를 반복문으로 여러번 호출할 때 문자를 여러 번 입력하는 것이 아닌 문장을 한 번만 입력해도 getchar 함수가 전부 실행되게 된다. 
		ex)우리가 키보드로 banana를 입력하면 표준 입출력 스트림 파일의 버퍼에는 banana\n이 저장되고 getchar는 호출될 때 마다 b / a / n / a / n / a / \n 을 반환하게 된다.
	- 만약 버퍼에 저장된 데이터를 작업하던 도중 Ctrl + Z 키를 입력하면 해당 함수가 EOF를 반환하며 종료하게 된다. 이는 Ctrl + Z 가 키보드 입력의 끝을 알리는 용도로 사용되는 아스키 문자이기 때문이다.
		> 유닉스나 리눅스 시스템의 경우 Ctrl + D이다.
18.1.6 텍스트 파일과 바이너리 파일 
	- 파일은 데이터의 기록 방식에 따라 텍스트(text) 파일과 바이너리(binary) 파일로 나뉜다.
		> 텍스트 파일은 데이터를 아스키 코드 값에 따라 저장한 것이다.
		> 바이너라 파일은 그 외의 방식으로 저장된 파일이다.
	- 텍스트 파일은 아스키 코드값에 따라 데이터를 읽고 저장하는 프로그램에서 확인할 수 있고 바이너리 파일은 해당 기록 방식을 적용한 별도의 프로그램을 사용해야 한다.
		> 파일 입출력 함수들도 파일의 형태에 따라 데이터를 읽고 쓰는 방식이 다르므로 파일을 개방할 때 개방 모드에 파일의 형태도 함께 표시해야 한다.
		> rt, wt, at : 텍스트 파일 개방
		> rb, wb, ab : 바이터리 파일 개방
		> 파일의 형태를 별도로 표시하지 않으면 자동으로 텍스트 파일로 개방한다. (즉, "w"로 개방한 파일은 "wt"로 개방한다는 의미이다.)
	- 파일의 형태와 개방 모드가 다를 경우 심각한 문제가 발생한다.
		> 파일의 형태에 따라 프로그램을 읽고 쓰는 저장 방식이 다르기 때문에 문제가 발생한다.
		> 예를 들어 윈도우 운영 체제에서는 화면에서 줄을 바꾸는데 CR + LF 라는 문자를 2개 사용하는데 프로그램 에서는 개행문자 하나만으로 줄을 바꿀 수 있도록 입출력 함수들이 중간에 리턴문자를 추가하거나 제거하는 작업을 수행한다.
		> 그런데, 바이너리 파일로 개방하는 경우 있는 그대로 읽거나 쓰므로 줄을 바꾸는 과정에서 의도한 기능과 다르게 수행될 수 있는 것이다.
18.1.7 + 개방 모드, fseek, rewind, feof 함수
	- 파일 개방 모드는 기본적으로 읽고 쓰고 붙이는 (r / w / a) 세가지 모드가 있다.
	- 하지만, +를 사용하면 읽고 쓰는 작업을 함께할 수 있다.
		> r+ : 텍스트 파일에 읽고 쓰기 위한 개방
		> w+ : 텍스트 파일의 내용을 지우고 읽거나 쓰기 위해 개방
		> a+ : 텍스트 파일을 읽거나 파일의 끝에 추가하기 위해 개방
		> rb+, wb+, ab+ : 위 기능들이 바이너리 파일에서 작동  
	- fseek 함수를 통해 버퍼의 데이터를 전부 하드디스크로 출력한 뒤?(버퍼를 비운 다음으로 해석) 위치 지시자를 옮길 수 있다.
		> 원형 :  
*/ 	
