#include <stdio.h>

int main()
{
	int user,password,i=0;
	do{
		
		printf("%s\n","请输入用户名：");
		scanf("%s",&user);
		printf("%s\n","请输入密码：");
		scanf("%d",&password);
		if(user=='a'&&password==1)
		{
			printf("Welcome");
			return 0;
		}
		else if(i<2)
		{
			printf("用户名或密码错误，请重新输入\n");
		}
		else 
		{
			printf("Game Over");
		}
			i++;
	}while(i<3);
	
	return 0; 
	
	
} 
