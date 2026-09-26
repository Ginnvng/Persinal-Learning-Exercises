#include <stdio.h>
#include <string.h>

main()
{
	char s1[80],s2[80];
	void scat(char s1[],char s2[]);
	
	gets(s1);
	gets(s2);
	
	scat(s1,s2);
	
	puts(s1);
}

void scat(char s1[],char s2[])
{
 	int i=0,j=0;
 	
	/**********ERROR**********/
 	while(s1[i] != '\0') 
		i++;
		
	/**********ERROR**********/
 	while(s2[j] != '\0')
    {
	/**********ERROR**********/
	    s1[i] = s2[j];
	    i++;
	    j++;
    }
    
	/**********ERROR**********/
  	s1[i]='\0';
}

