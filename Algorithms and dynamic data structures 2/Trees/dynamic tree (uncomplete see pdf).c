#include <stdio.h>
#define MaxNodes 100

typedef struct sode
{  
    int val ;  
    node *Lson, *Rson ;
} node ; 

node *root = NULL ; //double linked lists are linear whereas trees are struct

node *creat_node(int x) 
{
    node *new;
    new = (node*)malloc(sizeof(node));
    
    
}

int value(node N) 
{ 
    if(N != NULL) 
        return N -> val; 
}

node Rson(stack *p, int v )  
{ 
    if(p->index < maxSize-1) 
    { 
         p->index = p->index+1; //(p->index)++;
         p->arr[p->index] = v ; 
     }  
}

node Lson(stack *p, int *v ) 
{ 
    if(p->index > -1) 
    { 
        *v = p->arr[p->index] ; 
        p->index = p->index-1; 
    }  
}

int empty node(node* N)  // we don't want to change the address in tete
{
 
}

int leaf(node *N)
{

}



 int main() 
{
    int num, val, N, i;
 //stack p ; 
 init(&p) ;
 
 printf("enter size : ");
 scanf("%d",&N);
 i = 0;

 while(i<N)
 {
     printf("enter element %d: ", i);
     scanf("%d", &num);
     empiler(&p, num) ; 
     i++;
 }

 printf("your stack : "); 
 affichepile(p) ; 

 negativesupression (&p);

 printf("search for an element and add it if not present:  :");
 scanf("%d", &val);
 rechinsert(&p, val);
 /*printf("what do you want to delete: ");
 scanf("%d", &del);
 
 supression (&tete, del);*/

 printf("your list after deletion : ");
 affichepile(p) ; 
}