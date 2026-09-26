#include <stdio.h>
#include <math.h>

int main()
{	
	int n,i,lineCount = 0;
	int perline = 5;
	for(n=200;n<=500;n++)
	{
		for(i=2;i<=n/i;i++)	
		{
			if(n%i==0)
			{
				break;
			}
		}
		if(i>n/i)
		{
			printf("%5d",n);
			lineCount++;
			
			if(lineCount==perline)
			{
				printf("\n");
				lineCount = 0;
			}
			else
			{
				printf(" ");
			}
		}
		
	}
	return 0;
}
