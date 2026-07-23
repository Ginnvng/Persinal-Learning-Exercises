#include <stdio.h>


/**********ERROR**********/
int fun(int m, int *ptr)
{
	int i,k=1;
	
  	if(m<=1)
		k=0;
		
	/**********ERROR**********/
  	for(i=2; i<m; i++)
	/**********ERROR**********/
  	if(m%i==0) 
		k=0;
	if(k!=0)
		(*ptr)++;
	/**********ERROR**********/
  	return k;
}

int main()
{
 	int n,k=0,*p=&k;
 	for(n=1; n<100; n++)
   		if(fun(n,p)==1)
    	{
     		printf("%5d",n);			
     		if(k%5==0)
				printf("\n");
    	}
    return 0;
}

