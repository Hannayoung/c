#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 500

int x=0,y=0,z=0,c;
int counter1=0,counter2[SIZE]={0};

int counter3()
{
	printf(" %d : %dȸ\n", z, counter2[z]);
	
}

int main()
{
	srand((unsigned int)time(NULL));
	printf("���ڸ� �Է��Ͻʽÿ�: ");
	scanf("%d", &x);
	while(x>=25)
	{	
		y= rand() % (x+1);
		counter2[y]= counter2[y] +1; 
		counter1++;
		
		if( counter2[x] == 100 )
		{
			printf("\n%d�� 100ȸ �߻��ϱ� ���� ���� �߻� ��Ų ȸ���� %dȸ �Դϴ�.\n\n", x, counter1);
			for (z=0; z<=x; z++)
			{
				c= counter3();

				
			}
			return 0;
			
		}
	
	}
	
}