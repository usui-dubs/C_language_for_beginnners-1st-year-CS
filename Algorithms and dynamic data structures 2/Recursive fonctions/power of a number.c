#include<stdio.h>

long int power(int n, int p)
{
    if(p == 0) return 1;
    
    else return n*power(n, p - 1);
}

/*iterative solution:
long long nt power(int n, int p)
{
    int i;
    long int res = 1;
    
    for(i = 1; i <= p; i++)
        res *= n;
        
    return res;     
}*/

int main()
{
    int num, pow;
    
    printf("Enter a number(base): ");
    scanf("%d",&num);
    printf("Power of ?(exponent)");
    scanf("%d",&pow);
    
    long int result= power(num, pow);
    
    printf("%d^%d = %.2ld",num, pow, result);

    return 0;
}