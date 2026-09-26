#include <stdio.h>
#include <math.h>

int main(){
	int p,n,i,w,s,N;
	int o=5;
	for(n=1;;n++)
	{
		for(i=2;i<n;i++)
		{
			if(n%i==0)
			{
				break;
			}
		}
		if(n==i)
		{
			p = n;
			s=pow(2,p)-1;
			for(i=2;i<s;i++)
			{
				if(s%i==0)
				{
					break;
				}
			} 
			if(s==i)
			{
				w=s*pow(2,p-1);
				printf("ÍêÈ«Êý=%d\n",w);
				N++;
			}
		}
		if(N==o)return 0;
	}
		
}
