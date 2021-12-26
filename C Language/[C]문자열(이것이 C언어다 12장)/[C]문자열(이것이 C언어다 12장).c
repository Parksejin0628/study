#include<stdio.h>
#include<string.h>

int main(void)
{
	char *fruit; 
	char *pa;
	char *pb; 
	
	char word[20];
	char str1[20];
	char str2[20];
	char str3[20];
	
	int i = 0; 
	
	printf("(1)\n");
	printf("문자열 study의 주소값 : %p\n", "study");
	printf("첫 번째 문자 : %c\n", *"study");
	printf("두 번째 문자 : %c\n", *("study" + 1));
	printf("세 번째 문자 : %c\n", "study"[2]);
	//문자열은 컴파일 과정에서 char 배열로 바뀌기 때문에 포인터 연산이 가능하다.
	printf("\n(2)\n");
	fruit = "apple";
	printf("첫 번째 과일은 : %s이다.\n", fruit);
	fruit = "banana";
	printf("두 번째 과일은 : %s이다.\n", fruit);
	//char포인터에 문자열을 대입하여 포인터를 문자열처럼 사용할 수 있으며 문자열을 쉽게 바꿀 수 있다. 
	printf("\n(3)\n");
	pa = "pointer";
	pb = "pointer";
	printf("pointer의 주소값 : %p / %p\n", pa, pb);
	//같은 문자열이 여러번 사용하는 경우 하나의 메모리 공간에서 문자열을 가져온다. 즉, 주소값이 같다. 
	printf("\n(4)\n");
	scanf("%s", word);
	for(i=0; i<=20; i++)
	{
		if(i>0 && word[i-1] == '\0')
		{
			break;
		}
		printf("scanf함수의 경우 %d번째 단어의 아스키코드 : %d\n", i, word[i]);
	}
	fgetc(stdin); 
	//scanf을 통해 입력한 문자열 끝에는 널문자인 '\0'를 추가하고 저장한다. 
	printf("\n(5)\n");
	gets(word); 
	for(i=0; i<=20; i++)
	{
		if(i>0 && word[i-1] == '\0')
		{
			break;
		}
		printf("gets 함수의 경우 %d번째 단어의 아스키코드 : %d\n", i, word[i]);
	}
	//scanf와 마찬가지로 문자열 끝에는 '\0'이 추가되며 공백또한 입력할 수 있다. 
	printf("\n(6)\n");
	fgets(word, 20, stdin); 
	for(i=0; i<=20; i++)
	{
		if(i>0 && word[i-1] == '\0')
		{
			break;
		}
		printf("gets 함수의 경우 %d번째 단어의 아스키코드 : %d\n", i, word[i]);
	}
	//fgets함수는 '\n'을 변환하지 않고 보존한다. 
	printf("\n(7)\n");
	printf("scanf를 통한 입력 : ");
	scanf("%s", str1);
	fgetc(stdin);
	printf("gets를 통한 입력 : ");
	gets(str2);
	printf("fgetc를 통한 입력 : ");
	fgets(str3, 20, stdin);
	printf("scanf로 입력했을 때 문자열의 길이 : %d / gets로 입력했을 때 문자열의 길이 : %d / fgets로 입력했을 때 문자열의 길이 : %d\n", strlen(str1), strlen(str2), strlen(str3));
	//개행문자를 널문자로 변환하는 scanf와 gets는 문자열의 길이가 같지만, 개행문자를 보존한채로 널문자를 추가하는 fgets는 문자열의 길이가 1 더 길다. 
	printf("gets를 통한 출력 : ");
	puts(str3);
	printf("fgets를 통한 출력 : ");
	fputs(str3, stdout);
	//puts, fputs모두 공백을 포함하여 출력한다. puts는 자동으로 줄을 넘기고 fgets는 넘기지 않는다. (개행문자가 살아있는 str3를 출력하므로 gets는 2번, fgets는 1번 개행이 된다.) 
	
	
	
	scanf("%d");
	
	return 0;
}
/*
[12장 문자열]
<12.1 문자열과 포인터>
	12.1.1 문자열 상수 구현 방법 
		- 문자열은 컴파일 과정에서 첫 번째 문자의 주소로 바뀐다.
		- 컴파일러는 문자열을 char 배열에 따로 보관하고 문자열 상수가 있던 곳에는 배열의 위치값을 사용한다.
		- 따라서, char 변수의 주소로 바뀌는 문자열은 포인터 연산을 수행할 수 있다. 단, 주소로 접근하여 문자열을 바꿔서는 안된다. 
	12.1.2 char 포인터로 문자열 사용
		- 문자열은 주소이므로 char포인터에 대입하여 포인터를 문자열처럼 사용할 수 있다.
			ex) char *fruit = "apple" : fruit를 "apple"처럼 사용 가능
		- 또한, 포인터를 다른 문자열로 바꾸는 것도 가능하다.
			ex) fruit = "banana" : "apple" -> "banana"
		- 이를 응용하여 printf함수의 %s 변환문자는 포인터 연산으로 문자열을 출력한다.
			> 즉, printf함수 안에서는 %s 변환문자를 사용할 때 해당 문자가 널문자가 나올 때 까지 한 글자씩 출력하는 과정을 수행한다.
		- 컴파일러는 최적화를 위해 같은 문자열이면 여러번 사용해도 하나의 메모리 공간에 저장한 문자열을 사용한다.
			> 즉, 내가 "apple"을 여러번 사용할 경우 처음 "apple"을 사용했을 때 메모리공간에 있는 "apple"만을 사용한다.
	12.1.3 scanf 함수를 사용한 문자열 입력 
		- scanf는 %s를 사용하여 공백이 없는 연속된 문자들을 입력받는다. 
		- scanf로 저장한 문자열의 끝에는 널문자를 붙여서 문자열을 완성한다.
		- 이렇게 공백문자를 추가하는 성질 때문에 scanf에 사용할 문자열은 예상 문자길이보다 +1을 해서 배열을 선언해야 한다. 
		- scanf는 버퍼에서 문자를 가져올 때 공백문자, 탭문자, 개행문자가 있으면 그 전까지만 저장된다.
		- 또한, 공백문자, 탭문자, 개행문자가 있으면 모두 걸러낸다. 이는 문자열 끝에 개행문자인 \n이 있어도 저장되지 않는다는 의미이다.
			ex) "hello"를 엔터를 사용하여 입력하면 "hello\n"이 입력된 것이지만 문자열에 저장할 때는 "hello\0"으로 저장된다.
	12.1.4 gets 함수를 사용한 문자열 입력
		- scanf는 공백을 포함할 수 없으므로 공백이 포함된 문자열을 한 번에 입력하기 위해 gets를 사용한다.
		- gets함수는 엔터가 입력될 때까지 모든 문자를 입력한다. (공백문자를 포함)
		- gets함수도 scanf함수와 마찬가지로 개행문자인 \n을 널문자인 \0으로 변환시킨다.
			ex) 입력 : "apple\n" -> 저장 : "apple\0" 
		- scanf는 공백을 인식하지 않으므로 엔터만 칠 경우 입력이 되지 않지만 gets는 엔터만 입력해도 저장된다. 즉, 널문자인 \0이 저장된다. 
	12.1.5 fgets함수를 사용한 문자열 입력
		- scanf함수와 gets 함수는 문자열을 입력할 때 배열 크기를 넘어 설 위험이 존재하고 이는 프로그램 오류를 발생시킬 수 있다.
		- 따라서, 안전하게 문자열을 입력하려면 배열 크기를 확인하는 fgets 함수가 유용하다.
			> fgets함수 원형 : char *fgets(char *str, int n, FILE *stream)
			> str은 문자열, n은 배열의 크기, stream에는 표준 입력버퍼를 의미하는 stdin을 입력한다.
		- fgets함수도 scanf, gets와 마찬가지로 문자열 마지막에 '\0'을 추가한다.
		- 하지만 두 함수와 다르게 '\n'을 '\0'으로 변환시키지 않고 문자열 마지막에 '\0'을 추가하기만 한다. 따라서, 문자열의 길이는 배열 - 2가 된다.
			ex) 입력 : : "apple\n" -> 저장 : "apple\n\0"
	12.1.6 표준 입력 함수의 버퍼 공유 문제
		- 표준 입력 함수들은 입력 버퍼를 공유한다.
		- 따라서, 앞서 입력한 함수가 버퍼에 개행문자를 남겨 놓는 경우 이어서 호풀되는 함수에서 개행문자를 입력했다고 인식하여 입력을 바로 끝내는 문제가 생긴다.
			ex) scanf함수의 경우 공백문자를 걸러내므로 버퍼에 \n이 남는다.
		- 따라서, 버퍼에 남아있는 개행문자를 지울 필요가 있다. 다음 방법을 통해 지울 수 있다.
			>getchar();
			>scanf("%*c");
			>fgetc(stdin);
			>fflush(stdin);	 - 나머지 세 함수와 다르게 버퍼에 남아있는 모든 내용을 지운다. 백준 문제풀이에서는 사용할 수 없다.
	12.1.7 문자열을 출력하는 puts, fputs 함수 
		- 문자열만을 출력하는 경우 다음과 같은 전용 출력 함수가 있다.
			>puts(str);				: str배열에 저장된 문자열을 출력하고 줄을 자동으로 바꾼다. 
			>fputs(str, stdout); 	: str배열에 저장된 문자열을 출력하고 줄을 자동으로 바꾸지 않는다.
		- 두 함수 모두 문자열의 시작 위치부터 널문자가 나올 때 까지 모든 문자를 출력한다.(공백 가능) 
		- 두 함수 모두 정상 출력된 경우 0을 반환, 실패한 경우 -1(EOF)를 반환한다. 
<12.2 문자열 연산 함수>
	12.2.1 문자열을 대입하는 strcpy함수
	 	- strcpy함수는 char 배열에 문자열을 복사하는 대입 연산 기능을 수행한다.
		 	>함수 원형 : char *strcpy(char *dest, const char *src)
		 	>ex) strcpy(str1, str2)
		- 두 번째 인수에는 char배열, 문자열을 저장한 포인터, 문자열 등 문자의 시작 위치가 담긴 어떤 것이든 사용할 수 있다.
		- 하지만, 첫 번째 인수에는 char배열, 배열명을 저장한 포인터만 가능하다.
	12.2.2 strcpy함수 구현 방법
		- 실습 칸 참고
	12.2.3 원하는 개수의 문자만을 복사하는 strncpy함수
		- strncpy함수는 char 배열에 지정한 개수만큼 문자를 복사하는 대입 연산 기능을 수행한다.
			>함수 원형 : char *strncpy(char *dest, const char *scr, size_t n)
			>ex) strncpy(str1, str2, 8)
		- 즉, strcpy함수와 비슷하지만 세 번째 인수에 복사를 원하는 문자의 개수를 입력하면 된다.
	12.2.4 문자열 길이를 계산하는 strlen 함수
		- 배열의 크기가 아닌 배열에 저장된 문자열의 실제 길이를 알고 싶을 때 strlen함수를 사용한다. (sizeof함수는 배열의 크기를 반환한다.) 
			> 함수 원형 : size_t strlen(const cahr *str)
			> ex)strlen(str) 
		- strlen 함수는 널문자가 나올 때까지의 문자 수를 세어 반환한다.
	12.2.5 문자열을 붙이는 strcat, strncat 함수
		- 배열에 있는 문자열의 뒤에 문자열을 이어 붙일 때는 strcat 또는 strncat 함수를 사용한다. (strncat는 지정된 개수만큼 두 번째 인수를 이어붙인다.) 
			> 함수 원형 : char *strcat(char *dest, const char *str) / char *strncat(char *dest, const char *src, size_t n)
			> ex) strcat(str1, str2) / strncat(str1, str2, 5)
		- str1에 있는 문자열 뒤에 str2 문자열을 이어 붙인다.
		- 문자열을 이어 붙이기 전에 널문자를 탐색하므로 반드시 첫 번째 문자열을 초기화 해야한다.
	12.2.6 문자열을 비교하는 strcmp, strncmp 함수
		- 두 문자열의 사전 순서를 판단하고 싶은 경우 strcmp / strncmp 함수를 사용한다. (strncmp는 지정된 개수만큼 두 문자열을 비교한다.)
			> 함수 원형 : char *strcmp(const char *str1, const char *str2) / char *strncmp(const char *str1, const char *str2, size_t n)
			> ex) strcmp(str1, str2) / strncmp(str1, str2, 11)
		- strcmp / strncmp 함수는 두 문자열을 비교하여 다음과 같은 값을 반환한다.
			>str1이 str2보다 사전에 나중에 나오면 1 반환
			>str1이 str2보다 사전에 먼저 나오면 -1 반환
			>str1과 str2가 같은 문자열이면 0반환 (strncmp의 경우 지정된 개수까지의 문자열이 같은 경우)
				ex)str1 : apple, str2 : banana인 경우 -1 반환
				ex)str1 : year, str2 : month인 경우 1반환
				ex)str1 : dance, str2 : dance인 경우 0 반환
				ex)str1 : apple, str2 : applepie인 경우 strcmp는 -1 반환 (apple뒤에는 널문자인 '\0'이므로 아스키코드가 0이다. 따라서, 무조건 먼저 나오는 것으로 판단된다.)
				   strncmp의 경우 세 번째 인수가 5인경우 0을 반환, 6이상인 경우 -1 반환
		- strcmp / strncmp 함수는 정확히는 아스키 코드값을 비교하므로 항상 사전 순서를 의미하지는 않는다. 
*/
