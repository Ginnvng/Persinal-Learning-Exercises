#include <stdio.h>

#include<stdio.h>
#define max 50
int main()
{
	int i,k,m,n,num[max],*p;
	printf("please input the total of numbers:");
	scanf("%d",&n);
	/**********ERROR**********/
	p /* = */=num;
	for(i=0;i<n;i++)
		*(p+i)=i+1;
	i=0;
	k=0;
	m=0;
	/**********ERROR**********/
	while(m<n-1)//> ¸Ä³É <= 
	{
		if(*(p+i)!=0) 
			k++;
		/**********ERROR**********/
		if(k==3)//È¥µô £¡ 
		{
			*(p+i)=0;
			k=0;
			m++;
		}
		i++;
		if(i==n) 
			i=0;
	}
	while(*p==0) 
		p++;
	printf("%d is left\n",*p);
	return 0;
}

