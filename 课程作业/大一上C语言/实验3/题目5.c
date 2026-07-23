#include <stdio.h>
#include <math.h>

int main(){
	int n,i;
	double z = 0;
	double s = 0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		z+=sqrt(i);
		s+=z;
	}
	printf("s=%f\n",s);
	return 0;
} 
