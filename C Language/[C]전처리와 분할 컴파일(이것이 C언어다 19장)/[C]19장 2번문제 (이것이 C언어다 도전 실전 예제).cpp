#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FEMALE
#define LEVEL 5 


int main(void)
{
	double sum;
	#if LEVEL == 3
		double height[3];
	
		printf("�ܰ躰 Ű �Է�(3�ܰ�) : ");
		scanf("%lf %lf %lf", height, height+1, height+2);
		#ifdef MALE
			double standard[3] = {49.4, 74.8, 85.0};
		#endif
	
		#ifdef FEMALE
			double standard[3] = {50.1, 76.0, 86.2};
		#endif
		printf("�ܰ躰 ǥ��Ű�� ���� : ");
		for(int i=0; i<3; i++)
		{
			printf("%.1lf ", height[i] - standard[i]);
			sum += height[i] - standard[i];
		}
		printf("\n");
		printf("���� ��� : %.1lf", sum / 3);
	
	#elif LEVEL == 5
		double height[5];
	
		printf("�ܰ躰 Ű �Է�(5�ܰ�) : ");
		scanf("%lf %lf %lf %lf %lf", height, height+1, height+2, height+3, height+4);
	
		#ifdef MALE
			double standard[5] = {49.4, 66.3, 74.8, 79.9, 85.0};
		#endif
	
		#ifdef FEMALE
			double standard[5] = {50.1, 67.6, 76.0, 81.2, 86.2};
		#endif
		printf("�ܰ躰 ǥ��Ű�� ���� : ");
		for(int i=0; i<5; i++)
		{
			printf("%.1lf ", height[i] - standard[i]);
			sum += height[i] - standard[i];
		}
		printf("\n");
		printf("���� ��� : %.1lf", sum / 5);
	#endif
	
	
	
	scanf("%d");
	
	return 0;
}


/*
���� 2 ��ü ���� �˻� ���α׷�
 - 24�������� ������ Ű�� �ܰ躰�� �Է��Ͽ� ǥ��Ű�� ���� �� �ܰ躰 Ű�� ���̿� ������ ����� ����մϴ�. 
  ǥ��Ű�� ���� ������ ����ϰ� ��ó�� �ܰ迡�� ��ũ�θ��� ���ǿ� ���� ���õǵ��� ���Ǻ� �����Ϸ� �ۼ��մϴ�. 
  > ���� ���� 3�ܰ� ���� ǥ�� Ű : 49.4 74.8 85.0
  > ���� ���� 5�ܰ� ���� ǥ�� Ű : 49.4 66.3 74.8 79.9 85.0
  > ���� ���� 3�ܰ� ���� ǥ�� Ű : 50.1 76.0 86.2 
  > ���� ���� 5�ܰ� ���� ǥ�� Ű : 50.1 67.6 76.0 81.2 86.2 
*/ 
