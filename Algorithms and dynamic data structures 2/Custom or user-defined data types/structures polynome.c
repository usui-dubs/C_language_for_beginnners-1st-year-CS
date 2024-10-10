#include <stdio.h>
#include <math.h>

typedef struct term
{
    int coef;
    int degree;
} term ;
    
int main()
{
    int i, N, x;
    int S = 0;
    term poly[50];
    
    printf("Enter the number of terms: ");
    scanf("%d", &N);
    
    printf("Enter X : ");
    scanf("%d", &x);
    
    for(i = 0; i < N; ++i)
    {
        printf("Enter the %d term coefficient : ", i+1);
        scanf("%d", &poly[i].coef);
        
        printf("Enter the %d term degree : ", i+1);
        scanf("%d", &poly[i].degree);
        
        S += ((poly[i].coef) * pow(x, poly[i].degree));
    }
    
    printf("The sum of the polynome is %d", S);
    
    return 0;
}