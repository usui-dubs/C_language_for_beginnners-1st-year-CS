// C Code to explain why not
// clearing the input buffer
// causes undesired outputs
#include<stdio.h>
int main()
{
	char str[80], ch; //string of carracteres
	
	// Scan input from user -
	// GeeksforGeeks for example
	scanf("%s", str);
	
	// flushes the standard input
    // (clears the input buffer)
    while ((getchar()) != '\n');
    
	// Scan character from user-
	// 'a' for example
	ch = getchar();
	
	// Printing character array,
	// prints “GeeksforGeeks”)
	printf("%s\n", str);
	
	// This does not print
	// character 'a'
	// Printing character a: It
    // will print 'a' this time
	printf("%c", ch);
	
	return 0;
}

