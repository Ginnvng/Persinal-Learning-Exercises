#include <stdio.h>
#include <math.h>

int main()
{
	int n,a,b,i,j,c=0;
	scanf("%d",&n);
	a = pow(n,2);
	b = a;
	while(b>0)
	{
		c=c*10+b%10;
		b/=10;
	}
	if(c==a)
	{
		printf("%d\n",n);
	}
	else
	{
		printf("No\n");
	}
	return 0;
	
}
