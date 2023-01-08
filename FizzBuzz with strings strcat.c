#include <stdio.h>
#include <string.h>

int main(void)
{	
	int i;
	
	for (i = 1; i <= 100; i++)
	{
		char output[10] = "" ; 
	/*	
		another better way to initialize a string in c to an empty string :
		char output[10] ;
		
		output[0] = "\0";  //or output[0] = 0;	*/
		
		if (i % 5 == 0) { strcat(output, "Fizz" ) ; }
		if (i % 3 == 0) { strcat(output, "Buzz" ) ; }
		
		//We DONT want to repreat the same test twice so that if we decide to change the condition from multiple of 3 to 8 for instanse, we will only change 3 to 8 in the second if flow statment
		//That WILL have an impact in bigger codes
		/*if ( output == "" ) { printf("%d", i) ; }
		else printf ("%s", output);*/
		
		if ( strcmp(output, "") == 0 ) { printf("%d\n", i) ;} // you can write "\0" in place of the empty string ""
		
		else printf("%s\n", output);
	}

	return 0;
}
