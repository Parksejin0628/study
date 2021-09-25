//number of question : 2667
//Difficulty : Silver 1
//Time to solve : 40m 51s
//Simple review : 

#include<stdio.h>

void searchMap(int row, int column, int complex);
void mergeSort(int start, int end);
void inputMap(int row, int column);

int map[30][30] = {0};
int checkDFS[30][30] = {0};
int house[650] = {0};
int sortedHouse[650] = {0};

int main(void)
{
	int n = 0;
	int complex = 0;
	
	scanf("%d", &n);
	
	
	for(int r=1; r<=n; r++)
	{
		inputMap(r, n);
	}
	for(int r=1; r<=n; r++)
	{
		for(int c=1; c<=n; c++)
		{
			//printf("check3 - r : %d, c : %d, map : %d, check : %d\n", r, c, map[r][c], checkDFS[r][c]);
			if(map[r][c] == 1 && checkDFS[r][c] != 1)
			{
			//	printf("check1\n");
				searchMap(r, c, complex++);
			}
		}
	}
	mergeSort(0, complex-1);
	printf("%d\n", complex);
	for(int i=0; i<complex; i++)
	{
		printf("%d\n", house[i]);
	}
	scanf("%d",&n);
	
	return 0;
}

void searchMap(int row, int column, int complex)
{
	int R = 0;
	int C = 0;
	
	if(checkDFS[row][column] == 1)	return;
	house[complex]++;
	checkDFS[row][column] = 1;
	
	R = row + 1;
	C = column;
	if(map[R][C] == 1 && checkDFS[R][C] != 1)
	{
		searchMap(R, C, complex);
	}
	R = row - 1;
	C = column;
	if(map[R][C] == 1 && checkDFS[R][C] != 1)
	{
		searchMap(R, C, complex);
	}
	R = row;
	C = column + 1;
	if(map[R][C] == 1 && checkDFS[R][C] != 1)
	{
		searchMap(R, C, complex);
	}
	R = row;
	C = column - 1;
	if(map[R][C] == 1 && checkDFS[R][C] != 1)
	{
		searchMap(R, C, complex);
	}
	return;
}

void mergeSort(int start, int end)
{
	if(start>=end)	return;
	
	int mid = (start + end) / 2;
	int i = start;
	int j = mid + 1;
	int k = start;
	
	mergeSort(start, mid);
	mergeSort(mid + 1, end);
	
	for(; k<=end; k++)
	{
		if(i>mid || j>end)
		{
			break;
		}
		if(house[i] < house[j])
		{
			sortedHouse[k] = house[i++];
		}
		else
		{
			sortedHouse[k] = house[j++];
		}
	}
	if(i>mid)
	{
		for(; k<=end; k++)
		{
			sortedHouse[k] = house[j++];
		}
	}
	else
	{
		for(; k<=end; k++)
		{
			sortedHouse[k] = house[i++];
		}
	}
	for(k=start; k<=end; k++)
	{
		house[k] = sortedHouse[k];
	}
	
	return;
}

void inputMap(int row, int column)
{
	char input[40] = {'\0'};
	
	scanf("%s", input);
	for(int i=1; i<=column; i++)
	{
		map[row][i] = (int)(input[i-1] - '0');
		//printf("check2 - map[%d][%d] : %c\n", row, i, map[row][i]);
	}
}
