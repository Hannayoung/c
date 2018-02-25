#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 13


typedef struct book_search{
	char ch[20],ch1[10],ch2[20];
	int ch3[13];
}BI;

int inspect(int ISBN[] )
{
 int i, s, result=0;
 int result1=0, result2=0;
 for(i=0; i<SIZE; i++)
 {
  if( i % 2 == 1){
   result1  = 3*ISBN[i];
  result += result1;
  }
  else if(i %2 == 0){
   result2 = 1*ISBN[i];
  result += result2;
  }
}
 printf("\n");
 printf("ISBN번호 재확인: ");
 for(i=0;i<SIZE;i++)
  printf("%3d", ISBN[i]);
 printf("\n");

 s= result % 10;

 if(s == 0)
  return 1;
 else if(s != 0)
  return 0;
}

int main()
{
	BI s1;
	int x;
	FILE*fp,*fp1,*fp2= NULL;
	int *p, a;
	int i,count=0;
	char bookname[20],writer[10];
	char fbookname[20],fwriter[10],fpublishment[20];
	char fISBN[13];
	char dISBN[13];
	p=s1.ch3;
	fp=fopen("book_search.txt","w");
	while(1)
	{
		printf("1 : 입력, 2 : 탐색, 3 : 삭제, 4 : 종료\n");
		printf("번호를 입력하십시오: \n");
		scanf("%d", &x);
	    
		if(x==1)
		{

		if(fp== NULL)
		{ 
			fprintf(stderr,"파일을 열 수 없습니다.\n");
			exit(1);
		}
		printf("도서명을 입력하십시오(띄어쓰기x,최대20자): \n");
		scanf("%s", s1.ch);
		printf("저자를 입력하십시오(띄어쓰기x,최대10자): \n");
		scanf("%s",s1.ch1);
		printf("출판사를 입력하십시오(띄어쓰기x,최대20자): \n");
		scanf("%20s",s1.ch2);
		printf("ISBN번호를 입력하십시오(띄어쓰기, 빈칸제외 최대13자): \n");
		for(i = 0; i<SIZE ; i++) 
			scanf("%d", (p + i));
	
		a=inspect(p);

		if(a == 1)
		{
			printf("유효한 ISBN번호입니다.\n");
			printf("\n");
			fprintf(fp,"%s %s %s ",s1.ch,s1.ch1,s1.ch2);
			for(i = 0; i<SIZE ; i++)
				fprintf(fp,"%d", s1.ch3[i]);
			fprintf(fp,"\n");

		}
	
		else if(a == 0 && a!=1)	
			{
				printf("유효하지 않은 ISBN번호입니다.\n");
				printf("\n");
				printf("\n");
				printf("\n");
				
			 }
		
		fclose(fp);
	}

	else if(x == 2)
	{
		fp1=fopen("book_search.txt","r");
		if(fp1== NULL)
		{ 
			fprintf(stderr,"파일을 열 수 없습니다.\n");
			exit(1);
		}
		printf("탐색할 도서명을 입력하세요: ");
		scanf("%s",bookname);
		printf("탐색할 저자명을 입력하세요: ");
		scanf("%s",writer);
		while(!feof(fp1))
		{
		fscanf(fp1,"%s %s %s %s ", fbookname,fwriter,fpublishment,fISBN);
		if(strcmp(bookname,fbookname)==0 && strcmp(writer,fwriter) == 0)
		{
		

			printf("%s %s %s %s ", fbookname,fwriter,fpublishment,fISBN);
			printf("\n");
		}
		
		}
		fclose(fp1);
		}
		else if(x == 3)
		{
			BI book;
		    int size = sizeof(BI);
			int count = 0;   

			fp2=fopen("book_search.txt", "r+");
			if (fp2 == NULL)
			{
				
				printf("출력을 위한 파일을 열수 없습니다.");
				exit(1);
				return;
			}
		 
			printf("삭제할 ISBN을 입력하세요.\n");
		    
			for(i = 0;i<13;i++)
			  scanf("%d", dISBN);
	 	   
		
			fscanf(fp2,"%s %s %s %s ", fbookname,fwriter,fpublishment,dISBN);
			
			 while (feof(fp2)!= NULL)
			 {
   
			  if (strcmp(dISBN,fISBN)==0)
			  {
				printf("삭제할 책을 찾았습니다.(x)\n");
			    fseek(fp2, size * count, SEEK_SET);
			    fwrite(dISBN, size, 1, fp);
				fflush(stdin);
				count += 1;
				return;
			 }
			  else
				  printf("삭제할 책이 존재하지 않습니다.\n");
			 }
		     fflush(stdin);

			 fclose(fp2);
		}
	

		else if(x == 4)
		{
		return 0;
		}
	
	}
}