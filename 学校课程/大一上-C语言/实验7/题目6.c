#include<stdio.h>
#define N 80
int delete(int a[], int n)
{
	/**********Begin**********/
	int i,j=1;
	for(i = 1;i<20;i++)
	{
		if(a[i]!=a[j-1])
		{
			a[j] = a[i];
			j++;
		}
	}
  return j;
  
    /**********  End  **********/  
}
void main()
{ 
	int a[N]={2,2,2,3,4,4,5,6,6,6,6,7,7,8,9,9,10,10,10,10}, i, n=20;
  
	printf("The original data :\n");
	for(i=0; i<n; i++)  
		printf("%3d",a[i]);
		
  	n = delete(a,n);
  	
	printf("\n\nThe data after deleted :\n");
  	for(i=0; i<n; i++)  
		printf("%3d",a[i]);  
  	printf("\n");
}
