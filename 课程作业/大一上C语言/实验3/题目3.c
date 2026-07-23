#include <stdio.h>

int main(){
	int n,m,i,a=0;
	scanf("%d %d",&m,&n); 
	for(m+=1;;m++)
	{
		for(i=2;i<m;i++)
		{
			if(m%i==0)
			{
				break;
			}
		}
		if(m==i)
		{
			printf("%5d ",m);
			a++;
		}
		
		if(a==n)
		{
			break;
		}
	}
	return 0;
}
