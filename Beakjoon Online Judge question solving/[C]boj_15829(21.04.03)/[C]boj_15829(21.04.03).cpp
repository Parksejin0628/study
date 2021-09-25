//number of question : 15829
//Difficulty : Bronze 2
//Time to solve : 19m 56s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define M 1234567891

long long square(int base, int sqe)
{
	long long sum = 1;
	for(int i=0; i<sqe; i++)
	{
		sum *= base;
		sum %= M;
	}
	return sum;
}

int main(void)
{
	int l = 0;
	char input[60] = {'\0'};
	long long sum = 0;
	
	scanf("%d",&l);
	scanf("%s",input);
	for(int i=0; i<l; i++)
	{
		//printf("%lld\n",((int)input[i] - (int)'a' + 1) * square(31, i));
		sum += ((int)input[i] - (int)'a' + 1) * square(31, i);
		sum %= M;
	}
	printf("%lld\n",sum);
	
	return 0;
}
