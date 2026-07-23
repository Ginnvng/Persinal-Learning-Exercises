#include<stdio.h>
#define N 100
void fun(char str[])
{  
	int i = 0,j;
	while(str[i]!='\0')
	{
		i++;
	}
	i--;
	for(j = 0;j<i;j++,i--)
	{

		int temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}
main()
{
	char str[N];
	gets(str);
	fun(str);
	puts(str);
	return 0;
}
//How to wori in zhizhen??
