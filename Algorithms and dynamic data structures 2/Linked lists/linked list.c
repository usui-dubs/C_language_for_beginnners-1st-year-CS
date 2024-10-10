#include <stdio.h>

typedef struct liste
{  
    int val ;  
    struct liste *suivant;
    //struct linked_list *precedent ;
    
} liste ; 

liste *tete ;

void init(liste **t)  
{
    *t=NULL ; 
}

 void add( liste **t, int x)  
{
 liste *nouv; 
 nouv = malloc(sizeof(liste)) ;
 nouv -> val = x; 
 nouv -> suivant = *t; 
 *t = nouv; 
} 

/*void addlast(liste **t,int x)
{

    liste *last, *p = *t, *prec;
    
    last=malloc(sizeof(liste)) ;
    last->val = x;
    last -> suivant = NULL;

    if(*t == NULL)
        *t = last;
    else
    {    
        while(p != NULL)  
       {   
            prec = p;
            p = p -> suivant; 
       }
    
        //last->suivant = prec -> suivant; 
        prec -> suivant = last; 
    }
}*/

//without precedent pointer
void addlast(liste **t,int x) //**t it's possible the list is empty 
{

    liste *last, *p;
    
    last = (liste*)malloc(sizeof(liste)) ;
    last -> val = x;
    last -> suivant = NULL;
    
    if(*t == NULL)
        *t = last;
    else    
       {
            p = *t ;
            while(p -> suivant != NULL)
            {
                p = p -> suivant;
            }
            p -> suivant = last; 
       }     
}

void supression(liste **t, int x)
{
    liste *p, *precedent;
    
    if(*t != NULL)
    {
        if ((*t) -> val == x ) //**t
        {
            p = *t;
            *t = (*t) -> suivant; // p -> suivant 
            free (p);
        }    
        else
        {
           // precedent = *t;
         //   p = (*t) -> suivant ;//(*prec) -> suivant
            /*liste *prec; */
            p=*t ;
            while(p != NULL && p -> val != x)
            {
                precedent = p ;
                p = p -> suivant;
            }
            
            if(p != NULL) //if(prec -> suivant = NULL)
            {
                precedent -> suivant = p -> suivant ;
                free (p);
            }
        }        
        
    }
    
   
}

void sorted_insertion(liste **t, int x)
{
    liste *p, *precedent;
    liste *new;
    
    new = malloc (sizeof(liste));
    new -> val = x;
    
    //add in head
    if(*t == NULL || *t != NULL && (*t) -> val >= x)
    {
        new -> suivant = *t;
        *t = new; //as in add
    }
    else //add in the middle or end of the list
    {
        /*precedent = *t;
        p = (*t) -> suivant ;*/
        p = *t;
        
        while(p != NULL && p -> val < x)
        {
            precedent = p;
            p = p -> suivant;
        }
        
        new -> suivant = p;
        precedent -> suivant = new;
    }
}

//exercise num 1 :
void reckon(liste *t, int *positive_numbers, int *negatives, int no)
{
    liste* p = t; //you can use directly t

    *positive_numbers = 0;
    negatives= 0; 
    no = 0;
    
    while(p != null)
    {
        if(p -> val > 0)
            (*positive_numbers) ++;
        if(p -> val < 0)
            (*negatives) ++;
        if(p -> val == 0)
            (*null) ++;        
        p = p -> suivant 
    }
}

int research (liste *t, int v)
{
    liste *p = t;
    
    if(p == NULL)
        return NULL;
        
    if(p -> val == v )
        return p;
    
    return research (p -> suivant, v)        
}

int sum (liste *t)
{
    liste *p = t;
    int s = 0;
    
    while(p != null)
    {
        s = s + p -> val;
        p = p -> suivant ;
    }
    return s;
}

//ex2 :
liste *fusion (liste *l1, liste *l2) //liste fusion (liste *l1, liste *l2, liste **l)
{
    liste *new, *p;
    
    if(l1 == NULL)
        new = l2;
    else if(l2 == NULL)
        new = l1;    
    else
    {
        if(l1 -> val < l2 -> val)
        {
            new = l1;
            l1 = l1 -> suivant;
        }
        else
        {
            new = l2;
            l2 = l2 -> suivant;
        }
        p = new;
        while(l1 != NULL && l2 != null)
        {
            if(l1 -> val < l2 -> val)
            {
                p -> suivant = l1;
                p = l1;
                l1 = l1 -> suivant;    
            }
            else
            {
                p -> suivant = l2;
                p = l2;
                l2 = l2 -> suivant;    
            }
           // p = p -> suivant; 
        }
    }    
     
    if(l1 == NULL)
            p -> suivant = l2;
    else   
            p -> suivant= l1       
    
    return new; //*l = new;
}
//ex 4:
void inverse (liste **t)
{
    liste *tet = NULL;
    liste *new = *t;
    
    while(new != null)
    {
        liste *prec = new -> suivant;
        new -> suivant = tet;
        tet = new;
        new = prec;
    }
    *t = tet;
}

void afficheliste( liste*t)  // we don't want to change the address in tete
{
 liste *p=t;

 while(p != NULL)  
 { 
    printf(" %d \n", p->val);  
    p=p->suivant; 
 }
}

void circular_list_transformation(liste *t)
{
    liste *p = t;
    
    if(p != NULL) //if list is not empty 
    {
        while(p -> suivant != NULL)
            p = p -> suivant ;
        
        p -> suivant = t;    
    }
}


 int main() 
{
    int num, del;
 //liste *tete ; 
 init(&tete) ;

 do
 {
 printf("enter another element :");
 scanf("%d", &num);
 sorted_insertion(&tete,num) ; 
 } while(num);
 
/* printf("last :");
 scanf("%d", &num);

 addlast(&tete, num);*/

 printf("your list : ");
 afficheliste(tete) ; 
 
 printf("what do you want to delete: ");
 scanf("%d", &del);
 
 supression (&tete, del);

 printf("your list after deletion : ");
 afficheliste(tete) ; 

 circular_list_transformation(tete);
printf("your list after deletion : ");
 afficheliste(tete) ; 
}