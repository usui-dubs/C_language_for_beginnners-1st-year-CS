#include<stdio.h>
typedef struct stack
{  
    int val ;  
    struct stack *precedent ;
} stack ; 

//dec to bin from non terminal recursive fonction
/*void Bin (int n)  
{
 int r ;  
 r = n % 2 ; //ins A
 n = n / 2;
 if ( n != 0) //stop cond
    //ins B
     Bin ( n ); 
    //ins D
 printf("%d", r);   //else ins E
}*/

//to iterative solution:
void init(stack **p)  
{
   // (*p).index = -1 ; 
    *p = NULL ;
}

int pilevide(stack *p)  //empty stack
{
    return (p == NULL) ; 
}

void empiler( stack **p, int x)  
{
 stack *new; 
 new = (stack*)malloc(sizeof(stack)) ;
 new -> val = x; 
 new -> precedent = *p; 
 *p = new; 
} 


void depiler(stack **p, int *v ) 
{ 
    stack *k;
    
    if(*p != NULL) 
    { 
        *v = (*p) -> val; 
        k = *p;
        *p = (*p) -> precedent ; 
        free(k);
    }  
}
void Bin (int n)  
{
    stack *p;
    int r;
    
    init(&p);
    
    r = n % 2; //ins A
    while(n != 0) //stop cond 
    {
        n = n / 2; //ins B
        empiler (&p, r);
        r = n % 2; //ins A
    }
    printf("%d", r); //ins E

/* Or:
while(n != 0) //stop cond 
    {
        r = n % 2; //ins A
        n = n / 2; //ins B
        empiler (&p, r);
    }
    */
    
    while(!pilevide(p))
    {
        depiler (&p, &r);
        printf("%d", r); 
    }
}

int main(void)
{
    long long unsigned i, N, R, base=1, nb ;
    printf("Donner N : ") ;
    do 
    {
        scanf("%llu",&N) ;
    } while (N < 0) ;
    
    printf("N=%llu (en base 10) = ", N) ;
    
   /* do
    {
        R = N % 2 ;
        nb += R * base ;
        base = base * 10 ;
        N = N / 2 ;
    } while (N != 0) ;
    
    printf("%llu (en base 2)", nb) ;*/
    Bin(N);
    
    return 0 ;
}