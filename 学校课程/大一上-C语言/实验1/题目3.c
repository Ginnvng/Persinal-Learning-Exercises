#include <stdio.h>
#include <math.h>
int main()
{
	int n,a,m,b,i = 0,sum;
	scanf("%d",&n);
	if(n<100||n>1000000000)
	{
		printf("Data error");
		return 0;
	}
	a = n;
	while(a>0)
	{
		a/=10;
		i++;
	}
	b = n;
	sum = 0;
	while(b>0)
	{
		m = b%10;
		b/=10;
		sum+=pow(m,i);
	}
	if(sum==n)
	{
		printf("%d",n);
	}
	else printf("No");
	return 0;
}
