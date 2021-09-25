//number of question : 1620
//Difficulty : Silver 4
//Time to solve : 1h 43m 10s
//Simple review : 

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

char pokemon[100100][40] = {'\0'};
char sortingPokemon[100100][40] = {'\0'};
char sortedPokemon[100100][40] = {'\0'};
int sortingPokemonNumber[100100] = {0};
int sortedPokemonNumber[100100] = {0};

int square(int num)
{
	int temp = 1;
	for(int i=0; i<num; i++)
	{
		temp*=10;
	}
	return temp;
}

void mergeSort(int start, int end)
{
	if(start >= end)	return;
	
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	//printf("check1 start : %d, end : %d\n", start, end);
	
	for(; k<=end; k++)
	{
		if(strcmp(sortingPokemon[i], sortingPokemon[j]) < 0)
		{
			strcpy(sortedPokemon[k], sortingPokemon[i]);
			sortedPokemonNumber[k] = sortingPokemonNumber[i++];
			//printf("%d번째 자리에 %s 이동\n",k, sortedPokemon[k]);
		}
		else
		{
			strcpy(sortedPokemon[k], sortingPokemon[j]);
			sortedPokemonNumber[k] = sortingPokemonNumber[j++];
			//printf("%d번째 자리에 %s 이동\n",k, sortedPokemon[k]);
		}
		if(i>mid || j>end)	
		{
			k++;
			break;
		}
	}
	if(j>end)
	{
		for(; k<=end; k++)
		{
			strcpy(sortedPokemon[k], sortingPokemon[i]);
			sortedPokemonNumber[k] = sortingPokemonNumber[i++];
			//printf("%d번째 자리에 %s 이동\n",k, sortedPokemon[k]);
		}
	}
	else if(i > mid)
	{
		for(; k<=end; k++)
		{
			strcpy(sortedPokemon[k], sortingPokemon[j]);
			sortedPokemonNumber[k] = sortingPokemonNumber[j++];
			//printf("%d번째 자리에 %s 이동\n",k, sortedPokemon[k]);
		}
	}
	for(k = start; k<=end; k++)
	{
		strcpy(sortingPokemon[k], sortedPokemon[k]);
		sortingPokemonNumber[k] = sortedPokemonNumber[k];
		//printf("%d번째 숫자 저장중..\n", k);
	}
}

int main(void)
{
	int n = 0;
	int m = 0;
	int size = 0;
	int number = 0;
	int start = 0;
	int mid = 0;
	int end = 0;
	int temp = 0;
	char input[40] = {'\0'};
	
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++)
	{
		scanf("%s",pokemon[i]);
		strcpy(sortingPokemon[i], pokemon[i]);
		sortingPokemonNumber[i] = i;
	}
	mergeSort(1, n);
	for(int i=0; i<m; i++)
	{
		scanf("%s",input);
		if((int)(input[0] - '0') <= 9) 
		{
			size = strlen(input) - 1;
			for(int j=size; j>=0; j--)
			{
				number += (int)(input[j] - '0') * (int)(square(size-j));
			}
			//printf("check1 - number : %d, size : %d, input : %s\n",number, size, input);
			printf("%s\n",pokemon[number]);
			number = 0;
			continue;
		}
		else
		{
			start = 1;
			end = n;
			mid = (start + end) / 2;
			while(start <= end)
			{
				temp = strcmp(input, sortedPokemon[mid]);
				//printf("input : %s, sortedPokemon[%d] : %s 비교\n", input, mid, sortedPokemon[mid]);
				if(temp == 0)
				{
					printf("%d\n", sortedPokemonNumber[mid]);
					break;
				}
				else if(temp < 0)
				{
					end = mid - 1;
				}
				else
				{
					start = mid + 1;
				}
				mid = (start + end)/2;
			}
		}
	}
	//scanf("%d",&n);
	
	return 0;
}
