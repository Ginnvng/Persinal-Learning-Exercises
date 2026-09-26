#include <stdio.h>

int runnian(int year)
{
	return ((year%400 == 0) || (year%4 == 0 && year%100 != 0));
}
int main()
{
	int year,month,day,totaldays=0;
	scanf("%d %d %d",&year,&month,&day);
	if(year<2010)
	{
		printf("ÈÕÆÚ´íÎó");
		return 0; 
	}
	int y ;
	for(y=2010;y<year;y++)
	{
		totaldays+= runnian(y)? 366:365;
		 
	}
	int monthDays[]={31,28,31,30,31,30,31,31,30,31,30,31};
	int m;
	for(m=0;m<month-1;m++)
	{
		if(runnian(year))
		{
			monthDays[1]=29;
		}
		totaldays+=monthDays[m];
	}
	totaldays+=day;
	
	int Y = totaldays%5;
	if(Y==4||Y==0)
	{
		printf("É¹Íø\n");
	}
	else printf("´òÓã\n");
	printf("%d\n",totaldays);
	return 0;
}
