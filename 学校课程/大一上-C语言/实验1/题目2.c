#include <stdio.h>
#include <math.h>

int main(){
	int n,s,i=0;
	for(n=1;n<=999;n++)
	{
		i=0;
		s=1;
		int a = n;
		while(a>0)
		{
			a/=10.0;
			i++;
			s *=10;
		}
		if((n*n)%s==n)
		{
			printf("%d\n",n);
		}	
	}
	return 0;
}
