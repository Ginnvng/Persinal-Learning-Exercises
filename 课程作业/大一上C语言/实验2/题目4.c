#include <stdio.h>

int main()
{
	int y,year,month,day,sum=0,Y=0;
	scanf("%d %d %d",&year,&month,&day);
	if(year<2010)
	{
		printf("»’∆⁄¥ÌŒÛ");
		return 0; 
	}
	int ysum=0;
	y = year-1; 
	while(y>=2010)
	{
		ysum+=365;
		if(y%4 ==0)
		{
			ysum++;
		}
		y--;
	}
	int msum=0;
	
	for(month-=1;month>0;month--)
	{
		if(month==1||month==3||month==5||month==7||month==8||month==10||month==12)
		{
			msum+=31;
		}
		else if(month == 2)
		{
			if(year%4 == 0)
			{
				msum+=29;
			}
			else
			{
				msum+=28;
			}
		}
		else
		{
			msum+=30;
		}
	}
	sum = ysum + msum + day;
	Y = sum%5;
	if(Y==4||Y==0)
	{
		printf("…πÕ¯\n");
	}
	else printf("¥Ú”„\n");
	printf("%d\n",sum);
	return 0;
	
}
