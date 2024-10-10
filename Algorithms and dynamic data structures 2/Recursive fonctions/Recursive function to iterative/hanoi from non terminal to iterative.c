#include <stdio.h>
//transforme non terminal method to iterative solution:

typedef struct stack
{  
    int val ;  
    struct stack *precedent ;
} stack ; 

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

//non terminal:

/*void hanoi (int n, int start, int inter, int end)
{  
 if (n > 1) 
     {
         hanoi(n - 1, start, end, inter);
         printf("%d -> %d, start, end");
         hanoi(n - 1, inter, start, end);
     }
}*/

//iterative:
void hanoi (int n, int start, int inter, int fin)
{  
 stack s;
 init(&p);

 empiler (&p, n);
 empiler (&p, start);
 empiler (&p, inter);
 empiler (&p, end);
 
 while(! pilevide)
 {
     depile(&p, &end);
     depile(&p, &inter);
     depile(&p, &start);
     depile(&p, &n);
 }
  
 while(n > 1)
 {
     empiler (&p, n - 1);
     empiler (&p, inter);
     empiler (&p, start);
     empiler (&p, end);
     int c = end;
     end = inter;
     inter = c;
 }
 printf("%d -> %d, start, end");
}

int main(void)
{
    
    return 0;
}