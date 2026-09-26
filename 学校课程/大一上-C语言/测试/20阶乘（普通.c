#include <stdio.h>
 
//Ð´Ò»¸ö20µÄ½×³Ë 
//0--20£¡ 

int main()
{
	unsigned long long sum = 0,total;
	int i,j,n;
	scanf("%d",&n);
	for(i = n;i>0;i--)
	{
		total = 1;
		for(j = i;j>0;j--)
		{
			total*=j;
		}
		sum+=total;
	}
	printf("%llu\n",sum);
	return 0;
} 
