#include <stdio.h>

void inv(int *a, int n)
{  
   int temp;
   int *start = a; 
   int *end = a+n-1;
   while(start<end)
   {
		temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
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
}

