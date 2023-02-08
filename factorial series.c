//how to find a factorial series of numbers in a range.
// recursive function to calculate the factorial of n number 
//Factorial Program using recursion in C
//we used loop before but recursion is better

/*Why to use recursion. 
Recursion adds clarity and (sometimes) reduces the time needed to write and debug code
(but doesn't necessarily reduce space requirements or speed of execution). 
Reduces time complexity. Performs better in solving 
problems based on tree structures.*/

/*Disadvantage:
It can throw a StackOverflowException 
since it consumes a lot of memory*/

#include<stdio.h>

long int factorial(int N)
{
   if(N == 0) return 1; //our base case
   else return N*factorial (N-1); //recursive case
//recursive call

    // another method Using ternary operator
   // return (N == 1 || N == 0) ? 1 : N * factorial (N - 1);
}

int main()
{
    int i;
    int s_range, e_range;
    
    do
    {
    printf("Enter the start of fhe range: ");
    scanf("%d",&s_range);
    printf("enter the end : ");
    scanf("%d",&e_range);
    } while(s_range < 0 || e_range < 0 || e_range < s_range);
    
    printf("Factorial series of the given range is: \n\n");
    for(i=s_range; i <= e_range; i++)
        printf("The factorial of %d is : %ld\n",i, factorial (i));
    
    return 0;
    
    //Time Complexity: O(n)
    //Auxiliary Space: O(n) of the program that finds a factorial of a number with recursive solution 

    // and for the iterative solution:
    //Time Complexity: O(n)
    //Auxiliary Space: O(1)
}