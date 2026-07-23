#include <stdio.h>
#define N 2
struct student
{
	int num;
	char name[8];
	float score[4];
};

struct student stu[N];

int main()
{	
	input();
	print();
	
	return 0;
}
void input()
{
	int i,j;
	for(i=0;i<N;i++)
	{
		printf("\n please input %d of %d\n",i+1,N);
		
		printf("num: ");
		/**********ERROR**********/
		scanf("%d",&stu[i].num);//¼ÓÈ¡µØÖ··ûºÅ 
		
		printf("name: ");
		scanf("%s",stu[i].name);
		
		for(j=0;j<3;j++)
		{
			printf("score %d:",j+1);
			/**********ERROR**********/
			scanf("%f",&stu[i].score[j]);
		}
		printf("\n");
	}
}
void print()
{
	int i,j;
	printf("\nNo. Name Sco1 Sco2 Sco3\n");
	/**********ERROR**********/
	for(i=0;i<N;i++)
	{
		printf("%-6d%-10s",stu[i].num,stu[i].name);
		for(j=0;j<3;j++)
			printf("%-8.1f",stu[i].score[j]);
		printf("\n");
	}
}

