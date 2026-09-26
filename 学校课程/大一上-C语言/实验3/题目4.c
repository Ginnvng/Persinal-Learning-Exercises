#include <stdio.h>

int main(){
	int n,m,i;
	m=0;
	float s = 0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		m+=i;
		s+=(double)1/m;
	}
	printf("%f\n",s);
	return 0;
} 
