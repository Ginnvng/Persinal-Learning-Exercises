#include <stdio.h>
#include <math.h>
 
int main(){
	int n,ab,cd;
	for(n=1000;n<=9999;n++)
	{
		ab=n/100;
		cd=n%100;
		if(n==pow((ab+cd),2))
		{
			printf("%d\n",n); 
		}
		
	}
	return 0;
}
