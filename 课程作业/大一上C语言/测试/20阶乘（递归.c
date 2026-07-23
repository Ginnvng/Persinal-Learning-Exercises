#include <stdio.h>

//1--20�׳˵ĵݹ�
unsigned long long fun(int n);
unsigned long long total(int n);

int main()
{
	int n;
	scanf("%d",&n);
	unsigned long long sum = total(n);
	/*
	for(n;n>0;n--)
	{
		sum += fun(n);
	}
	*/
	printf("%llu\n",sum);
	return 0;
} 

unsigned long long fun(int n)
{
	if(n<=1)
	{
		return 1;
	}
	else
	{
		return n * fun(n-1);
	}
}

unsigned long long total(int n)
{
	unsigned long long sum = 0;
	for(n;n>0;n--)
	{
		sum+=fun(n);
	}
	return sum;
}
