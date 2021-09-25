//number of question : 2606
//Difficulty : Silver 3
//Time to solve : 35m 27s
//Simple review : 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int main(void)
{
	int n = 0;
	int m = 0;
	int cpt1 = 0;
	int cpt2 = 0;
	int connect[110][110] = {0};
	int rear[110] = {0};
	int quque[1100] = {0};
	int checkBFS[110] = {0};
	int frontIndex = 0;
	int rearIndex = 0;
	int account = -1;
	int temp = 0;
	
	scanf("%d",&n);
	scanf("%d",&m);
	
	for(int i=0; i<m; i++)
	{
		scanf("%d %d",&cpt1, &cpt2);
		connect[cpt1][rear[cpt1]++] = cpt2;
		connect[cpt2][rear[cpt2]++] = cpt1;
	}
	quque[rearIndex++] = 1;
	while(frontIndex<rearIndex)
	{
		temp = quque[frontIndex++];
		if(checkBFS[temp] == 1)	continue;
		checkBFS[temp] = 1;
		account++;
		for(int i=0; i<rear[temp]; i++)
		{
			if(checkBFS[connect[temp][i]] == 0)
			{
				quque[rearIndex++] = connect[temp][i];
			}
		}
	}
	printf("%d\n",account);
	scanf("%d",&n);
	
	return 0;
}
