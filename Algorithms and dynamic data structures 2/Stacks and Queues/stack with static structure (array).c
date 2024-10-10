#include <stdio.h>
#define maxSize 100

typedef struct stack
{  
    int index ;  
    int arr[maxSize] ;
} stack ; 

stack p ;

void init(stack *p)  
{
   // (*p).index = -1 ; 
    p -> index = -1 ;
}

int pilevide(stack p)  //empty stack
{
    return (p.index == -1) ; 
}

int pilepleine(stack p)  //full stack
{
    return (p.index == maxSize - 1) ; 
}

int sommetpile(stack p) 
{ 
    if(p.index >= 0) 
        return p.arr[p.index]; 
}

void empiler(stack *p, int v )  
{ 
    if(p->index < maxSize-1) 
    { 
         p->index = p->index+1; //(p->index)++;
         p->arr[p->index] = v ; 
     }  
}

void depiler(stack *p, int *v ) 
{ 
    if(p->index > -1) 
    { 
        *v = p->arr[p->index] ; 
        p->index = p->index-1; 
    }  
}

void negativesupression (stack *p)
{
    stack p1;
    int v;
    
    init(&p1);
    
    /*while(pilevide(*p) == 0)*/ while(!pilevide(*p))
    {
        depiler(p, &v);
        if(v >= 0)
            empiler (&p1, v);
    }
    
    while(pilevide(p1) == 0)
    {
        depiler (&p1, &v);
        empiler (p, v);
    }
}

int rechinsert (stack *p , int val)  //stack elements must be ordered
{ 
 stack p1; 
 int v,bool=1; 

 init (&p1); 

 while (pilevide (*p)==0 && sommetpile(*p) > val ) 
 {  
     depiler (p, &v); 
     empiler (&p1, v); 
 }  

 if (pilevide (*p) || sommetpile(*p) < val)  
 {
     empiler (p, val); 
     bool=0; 
 }   

 while (pilevide (p1)==0)  
 {  
     depiler (&p1, &v); 
     empiler (p, v); 
 }  
 return bool; 
}

 void  suppneg (pile *p )
          {     pile p1;
                 int  v;
                     init (&p1);
                     while (pilevide (*p)==0  ) 
                                                      {
                                                                 depiler (p, &v);
                                                               if (v>=0)  empiler (&p1, v);
                                                      }
                      
                                                                                           
                      while (pilevide (p1)==0) 
                                                     {
                                                                 depiler (&p1,&v);
                                                                 empiler (p, v);
                                                     }
           }
 
  int souspileS(pile sp,pile p)
 {pile p1;
 int  v,bO=0;
 init (&p1);init(&p1);
 
 
  while ((pilevide (sp)==0 && pilevide (p)==0) &&  sommetpile(p)==sommetpile(sp)) 
  { 
    depiler (&p, &v);depiler (&sp, &v);
    empiler (&p1, v);
  }  
  
  if (pilevide (sp)==1) bO=1 ;
                                                                                                          
  while (pilevide (p1)==0) 
  {
     depiler (&p1, &v);empiler (&sp, v);
     empiler (&p, v);                          
     }
  return bO; 
  }
  
  int souspile(pile sp,pile p)
 {pile p1;
  int  v,b=0;
  init (&p1);init(&p1);   
  while (pilevide (p)==0&& b==0) 
  { 
    if (souspileS(sp,p)==1) b=1;
    else depiler(&p,&v);empiler (&p1, v);
  }
  
  while (pilevide (p1)==0) 
  {
     depiler (&p1, &v);
     empiler (&p, v);                          
     }
  return b; 
  }   

void affichepile(stack p)  // we don't want to change the address in tete
{
 int i = p.index;

 while(i != -1)  
 { 
    printf(" %d \n", p.arr[i]);  
    i--; 
 }
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