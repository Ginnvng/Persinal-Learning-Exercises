#include <stdio.h>

int main()
{
	int n,m=1,i;
	scanf("%d",&n);
	for(i=n-1;i>0;i--)
	{
		m=(m+1)*2;
		printf("天数 = %d 苞米数 = %d\n",i,m);
	}
	return 0;
}
