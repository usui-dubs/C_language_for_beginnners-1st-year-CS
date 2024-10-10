#include <stdio.h> 
int p=0; /* variable globale*/ //permanent ,allocated memory in data segment

void prod(int a, int n); //a and n are temporary var in memory 
        //we pass to the arguments by value
    //allocated memory in stack segment(segment de pile)
// auxiliary space 0(1)
// recursive stack space: O(n)
main() 
{
int x=3; //permanent , allocated memory in data segment

    printf("p= %d\n",p);
    prod(x,2); 
    printf("p= %d\n" , p);
    prod(x,3); 
    printf("p= %d" , p);
} 

void prod( int a, int n ) 
{ 
    static int k; /*variable locale mais statique */ 
    //permanent but only the prod fonction can access 
    // Static variables (like global variables) are initialized as 0 if not initialized explicitly
    // Static variables are allocated memory in data segment, 
    //not stack segment. 
    // Static variables should not be declared inside structure
   // https://www.geeksforgeeks.org/static-variables-in-c/amp/
    printf("k = %d ", k); k++; 
    p=a*n;
}