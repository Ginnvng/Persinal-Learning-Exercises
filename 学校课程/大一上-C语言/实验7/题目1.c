#include <stdio.h>

void inv(int*a,int n)
{
	int i,j,temp,b[10] = {0};
	for(i=0,j = 9;i<10,j>=0;i++,j--)
	{
		b[i]=a[j];
	}
	for(i=0;i<10;i++)
	{
		a[i] = b[i];
	}
}

main()
{  
int i,arr[10];
for(i=0;i<10;i++)
    scanf("%d",&arr[i]);
   inv(arr,10);
   printf("The array has been reverted:\n");
   for(i=0;i<10;i++)
       printf("%5d",arr[i]);
   printf("\n");
   return 0;
}

