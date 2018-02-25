#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define SIZE 500

int x=0,y=0,z=0,c;
int counter1=0,counter2[SIZE]={0};

int counter3()
{
	printf(" %d : %d회\n", z, counter2[z]);
	
}

int main()
{
	srand((unsigned int)time(NULL));
	printf("숫자를 입력하십시오: ");
	scanf("%d", &x);
	while(x>=25)
	{	
		y= rand() % (x+1);
		counter2[y]= counter2[y] +1; 
		counter1++;
		
		if( counter2[x] == 100 )
		{
			printf("\n%d이 100회 발생하기 위해 숫자 발생 시킨 회수는 %d회 입니다.\n\n", x, counter1);
			for (z=0; z<=x; z++)
			{
				c= counter3();

				
			}
			return 0;
			
		}
	
	}
	
}