#include <stdio.h>



int main()
{
	int Stu = 0,FS = 0;
	int i;
	int fun(int FS[Stu]);
	scanf("%d",&Stu);
	for(i = 0;i<Stu;i++)
	{
		scanf("%d",fun(FS[i]));
		
	}
	return 0;
}

int fun(int FS[])
{
	int i;
	for(i = 0;u<Stu;i++)
	{
		int sum = 0;
		sum += FS[i];
		float average = sum / Stu;
		printf("%f",average);
	}
}
