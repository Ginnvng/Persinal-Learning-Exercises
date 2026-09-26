#include <stdio.h>

int main()
{
	int n;
	for(n=0;;n++)
	{//暴力枚举了，有更好的方法吗？？ 
		if(n%3==2&&n%4==3&&n%5==4&&n%6==5&&n%7==0)
		{
			printf("%d\n",n); 
			break;
		}
	}
	return 0;
}
