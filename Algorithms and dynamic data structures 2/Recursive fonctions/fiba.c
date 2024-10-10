#include<stdio.h>

long int fib(int N)
{
   if(N < 2)
       return N; //our base case
   else return
       fib (N - 1) + fib (N - 2); //recursive case
//recursive call
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
    
    printf("Fibanaucci series of the given range is: \n\n");
    for(i=s_range; i <= e_range; i++)
        printf("%ld ",fib (i));
    
    return 0;
    
    //Time Complexity: Exponential, as every function calls two other functions.

//If the original recursion tree were to be implemented 
//then this would have been the tree 
//but now for n times the recursion function is called

    //Extra Space: O(n) 
    //if we consider the function call stack size, 
    //otherwise O(1).
    
   /*  #include<stdio.h>    
void printFibonacci(int n){    
    static int n1=0,n2=1,n3;    
    if(n>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
         printf("%d ",n3);    
         printFibonacci(n-1);    
    }    
}    
int main(){    
    int n;    
    printf("Enter the number of elements: ");    
    scanf("%d",&n);    
    printf("Fibonacci Series: ");    
    printf("%d %d ",0,1);    
    printFibonacci(n-2);//n-2 because 2 numbers are already printed    
  return 0;  
 }    */
}