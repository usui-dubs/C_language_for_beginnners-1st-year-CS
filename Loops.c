#include <stdio.h>
#include <string.h>

int main(void)
{
	char S[4];
	int i, len;
	
	do
	{
		printf("Write a word less than 4 characters: : ");
		gets(S);
	} while ( strlen(S) >= 4) ;
		
	for (i=0; S[i] != '\0'; i++)
	//{
	    printf("\ni = %d", i);
	//}
 
 printf("\nwe exit the loop and");
 printf("\nthe string(mot) length is %d", i);

	return 0;
} 