#include <stdio.h>

typedef struct stack
{  
    int val ;  
    struct stack *precedent ;
} stack ; 

stack *p = NULL;

void init(stack **p)  
{
   // (*p).index = -1 ; 
    *p = NULL ;
}

int pilevide(stack *p)  //empty stack
{
    return (p == NULL) ; 
}

int pilepleine(stack *p)  //full stack
{
    return 0; 
}

int sommetpile(stack *p) 
{ 
    if(p != NULL) 
        return (p -> val) ; 
}

void empiler( stack **p, int x)  
{
 stack *new; 
 new = (stack*)malloc(sizeof(stack)) ;
 /*if (new_node == NULL) {
        printf("Stack overflow \n");
        exit(0);
    }*/
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

/*int subStacks(stack *p, stack *sp)
{
    int v;
    =
    while (!pilevide(p)) 
    {
        depiler (&sp, &v);
        while ( !pilevide(p) )
        {
            
                
        }
    }
    
    return 0;
}*/

int substackS(pile *sp,pile *p)
{
 stack *p1;
 int  v, bO=0;

 init (&p1);
 
  while ((pilevide (sp)==0 && pilevide (p)==0) &&  sommetpile(p)==sommetpile(sp)) 
  { 
    depiler (&p, &v);
    depiler (&sp, &v);
    empiler (&p1, v);
  }  
  
  if (pilevide (sp)==1) 
      bO=1 ;
                                                                                                          
  while (pilevide (p1)==0) 
  {
     depiler (&p1, &v);
     empiler (&sp, v);
     empiler (&p, v);                          
  }
  return bO; 
  }
  
int substack(pile *sp,pile *p)
{
  stack* p1;

  int  v,b=0;

  init (&p1);
  while (pilevide (p)==0&& b==0) 
  { 
    if (souspileS(sp,p)==1) 
        b=1;
    else
    {
        depiler(&p,&v);
        empiler (&p1, v);
    }
  }
  
  while (pilevide (p1)==0) 
  {
     depiler (&p1, &v);
     empiler (&p, v);                          
  }
  return b; 
}

void negativesupression (stack **p)
{
    stack *p1;
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

int rechinsert (stack **p , int val)  //stack elements must be ordered
{ 
 stack *p1; 
 int v,bool=1; 

 init (&p1); 

 while (pilevide (*p)==0 && sommetpile(*p) > val ) //if the stack isn't sorted: sommetpile(*p) != val
 {  
     depiler (p, &v); 
     empiler (&p1, v); 
 }  

 if (pilevide (*p) || sommetpile(*p) < val)  //if (pilevide (*p) || sommetpile(*p) != val
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

//orders stack ex2
holds (stack *s, int val)
{
    int v, b = 1;
    stack *s1;
    init(&s1);
    
    while(! pilevide(s) || sommepile(s) < val)
    {
       depiler (&s, &v); 
       empiler (&p1, v); 
    }
   /* if(sommepile(s) == val)
        b = 1;*/
    if(pilevide(s) || sommepile(s) > val)//sommepile(s) != val
    b = 0;
    
    while (!pilevide (p1))  
    {  
     depiler (&p1, &v); 
     empiler (&s, v); 
    }  
 return b;
}

 create (stack *s, stack *s2, stack **s3)
 {
     int v;
     stack *s1;
     init(&s1);
     init(s3);
    
     while(! pilevide (s))
     {
         depiler (&s, &v);
         if(!holdes(s2, v))
         {
             empiler (s3, v);
             empiler (&p1, v);
         }
             
     }
    
     while (!pilevide (p1))  
    {  
     depiler (&p1, &v); 
     empiler (&s, v); 
    }  
 }

void insertAtBottom(struct sNode** top_ref, int item)
{
    if (isEmpty(*top_ref))
        push(top_ref, item);
    else {
 
        // Hold all items in Function Call
        // Stack until we reach end of the
        // stack. When the stack becomes
        // empty, the isEmpty(*top_ref)becomes
        // true, the above if part is executed
        // and the item is inserted at the bottom
        int temp = pop(top_ref);
        insertAtBottom(top_ref, item);
 
        // Once the item is inserted
        // at the bottom, push all
        // the items held in Function
        // Call Stack
        push(top_ref, temp);
    }
}
 
// Below is the function that
// reverses the given stack using
// insertAtBottom()
void reverse(struct sNode** top_ref)
{
    /*if (*head == NULL)
    {
        printf("Stack does not exist\n");
    }
    else if ((*head)->next == NULL)
    {
        printf("Single node stack reversal brings no difference\n");
    }*/

    if (!isEmpty(*top_ref)) {
        // Hold all items in Function
        // Call Stack until we
        // reach end of the stack
        int temp = pop(top_ref);
        reverse(top_ref);
 
        // Insert all the items (held in
        // Function Call Stack)
        // one by one from the bottom
        // to top. Every item is
        // inserted at the bottom
        insertAtBottom(top_ref, temp);
    }
}
 

/*void affichepile(stack *p)  // we don't want to change the address in tete
{
 stack* p1 = p;

 while(p1 != NULL) //while ( !pilevide(p1) )
 { 
    printf(" %d \n", p1 -> val);  
    p1 = p1 -> precedent; 
 }
}*/

void affichepile(stack *p)
{
 stack* p1 = p;
 int v;

 while(p1 != NULL) 
 { 
    depiler (&p1, &v);
    printf(" %d \n", v);
 }
}

 int main() 
{
    int num, val, N, i;
 //stack *p ; 
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