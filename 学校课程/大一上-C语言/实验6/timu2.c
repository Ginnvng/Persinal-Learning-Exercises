#include <stdio.h>
#include <math.h>

int main()
{
	int P,i,n,x=0;
	for(P = 2;;P++)
	{
		
		for(i = 2;i<P/2;i++)
		{
			if(P%i != 0)
			{
				n = pow(2,P)-1;
				printf("%d\n",n);
				x++;
				if(x == 5)
				{
					break;
				}
			}
		}
	}
	return 0;
}
