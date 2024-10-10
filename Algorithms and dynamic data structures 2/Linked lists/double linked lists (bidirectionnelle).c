#include <stdio.h>

typedef struct double_linked_list
{  
    int val ;  
    struct double_linked_list *next, *precedent ;
    //struct linked_list *precedent ;
    
} linked_list ; 

linked_list *head ;

void init(list **t)  
{
    *t=NULL ; 
}

 void addFirstElm( linked_list **t, int x)//first element has no precedent nor next
{
 linke_list *nouv; 
 nouv = (linked_list*)malloc(sizeof(linked_list)) ;
 nouv -> val = x; 
 nouv -> suivant = *t; 
 nouv -> precedent = NULL;
 *t = nouv; 
} 

void add( linked_list **t, int x)//LIFO
{
 linked_list *nouv; 
 nouv = (linked_list*)malloc(sizeof(linked_list)) ;
 nouv -> val = x; 
 nouv -> suivant = *t; 
 nouv -> precedent = NULL; 
 //if(*t != NULL) //if we didn't have the addFirstElm fonction 
 (*t) -> precedent = nouv;    
 *t = nouv; 
} 

void addlast(linked_list **t,int x) //**t it's possible the list is empty 
{

    liste *last, *p = *t;
    
    last = (liste*)malloc(sizeof(liste)) ;
    last -> val = x;
    last -> suivant = NULL;
    
    if(*t == NULL)
    {
        *t = last;
        last -> precedent = NULL
    }
    else    
       {
            p = *t ;
            while(p -> suivant != NULL)
            {
                p = p -> suivant;
            }
            p -> suivant = last;
            last -> precedent = p;
       }     
}

void supression(linked_list **t, int x)
{
    liste *p, *precedent;
    
    if(*t != NULL)
    {
        if ((*t) -> val == x ) //**t
        {
            p = *t;
            *t == (*t) -> suivant; // p -> suivant 
            if(*t != NULL)
            (*t) -> precedent = NULL;
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
               // precedent = p ; we don't need precedent in dll
                p = p -> suivant;
            }
            
            if(p != NULL) //if(prec -> suivant = NULL)
            {
                (p -> precedent) -> suivant = p -> suivant;
            
                if( p -> suivant != NULL)
                (p -> suivant) -> precedent = p -> precedent;
   
                free (p);
            }
        }        
        
    }
    
   
}

void sorted_insertion(linked_list **t, int x)
{
    liste *p;
    liste *new;
    
    new = malloc (sizeof(liste));
    new -> val = x;
    
    //add in head
    if(*t == NULL || *t != NULL && (*t) -> val >= x)
    {
        new -> suivant = *t;
        new -> precedent = NULL;
        if(*t != NULL)
            (*t) -> precedent = new;
        *t = new; //as in add // we change the head that's why the parameter is **t 
    }
    else //add in the middle or end of the list
    {
        p = *t;
        
        while(p != NULL && p -> val < x)
        {
            p = p -> suivant;
        }
        
        new -> suivant = p;
        new -> precedent = p -> precedent
        (p -> precedent) -> suivant = new;
         p -> precedent = new;
        
        /*
        *prec = p -> precedent ; 
         new -> precedent = prec ; 
         new -> suivant = p; 
         p -> precedent = new; 
         prec -> suivant = new; */
    }
}

int insert (linke_list **t, int x, int pos) // cette fonction retourne 0 si insertion réussi -1 sinon 
{ 
 bidlist *new,*p; 
 int erreur = 0; 

 new = (linked_list*)malloc(sizeof(linked_list)) 
 new -> val = x; 

 if(pos == 0) // si on insère en position 0, on doit modifier la tete  
     if(*t != NULL) 
     { 
         new -> suivant = *t; 
         new -> precedent = Null; 
         (*t) -> precedent = new;  
         *t = new; //as in add
     }  
     else  
     { 
         new -> suivant = NULL; 
         new -> precedent = NULL; 
         *t = new;
     }  
    /* {
    //or we can
    new -> suivant = *t; 
     new -> precedent = Null; 
     if(*t != NULL)
            (*t) -> precedent = new;
     *t = new; //as in add
    }*/
 else  
 { 
     int i=0 ; 
     p=*t; 
    
     While(p != NULL && i < pos)  
     {
         i++; 
         p = p ->suivant; 
     } 
     if (i == pos)
     { // si la position existe  bidlist 
         *prec = p -> precedent ; 
         new -> precedent = prec ; 
         new -> suivant = p; 
         p -> precedent = new; 
         prec -> suivant = new; 
     } 
     else // sinon une erreur de position qui ne peut être assurée  
     { 
         erreur = -1  
     }  
 }
 return erreur;  
}

void afficheliste( linked_list *t)  // we don't want to change the address in tete
{
 linked_list *p=t;

 while(p != NULL)  
 { 
    printf(" %d \n", p->val);  
    p=p->suivant; 
 }
}

void circular_list_transformation(linked_list **t)
{
    lonked_list *p = *t;
    
    if(p != NULL) //if list is not empty 
    {
        while(p -> suivant != NULL)
            p = p -> suivant ;
        
        p -> suivant = *t;    
        
        (*t) -> precedent = p;
    }
}

void negative_nums_suppression (linked_list **t)
{
    linked_list *p;

    while(*t != NULL && (*t) -> val < 0) // while bc there could be more than one
    {
        p = *t;
        *t = (*t) -> suivant;
        if(*t != NULL)
            (*t) -> precedent = NULL;
       /* if ((*t)->suivant !=NULL) 
             ((*t)->suivant)->precedent=NULL;
         *t=(*t)->suivant ;*/
        free(p);
    }
    
    p = *t;
    linked_list k;
    
    while(p != null)
    {
        if(p -> val < 0)
        {
            k = p;
            (p -> precedent) -> suivant = p -> suivant;
            
            if( p -> suivant != NULL)
                (p -> suivant) -> precedent = p -> precedent;
        
            p = p -> suivant;
            free(k);
        }
        else
            p = p -> suivant ;
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
}