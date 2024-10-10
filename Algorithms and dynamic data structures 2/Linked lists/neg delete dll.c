#include <stdio.h>
#include <stdlib.h>

typedef struct bidliste 
   { int val ; 
      struct bidliste *precedent; 
      struct bidliste *suivant; 
    } bidliste;
bidliste *tete;

void init(bidliste **t)
          {*t=NULL ;
          }
           
void  ajoutpremier( bidliste **t, int x) // le traitement du premier �l�ment qui n'a ni suivant ni pr�c�dent
{bidliste *nouv;
  nouv=( bidliste *)malloc(sizeof(bidliste));
  nouv -> val=x;
  nouv -> suivant=*t;
  nouv -> precedent=NULL;
  *t= nouv;
}
          

void  ajout( bidliste **t, int x)   // ajout en tete de la liste ce sera une liste LIFO
{bidliste *nouv;
  nouv=( bidliste *)malloc(sizeof(bidliste));
  nouv -> val=x;
  nouv -> suivant=*t;
  nouv -> precedent=NULL;
  (*t) -> precedent = nouv;    
  *t= nouv;
}

void  afficheliste( bidliste*t)
 { bidliste *p=t;
   while(p !=NULL)
   { printf(" %d  ", p->val); 
    p=p->suivant;
   }
 }
void  suppneg( bidliste **t)
 { bidliste *p;
     // on commence � regarder les valeurs au debut de la liste sont negative
      while(*t !=NULL && (*t)->val < 0 ) // suppression en tete de la bidliste
       {
          p=*t ;
         if ((*t)->suivant !=NULL) ((*t)->suivant)->precedent=NULL;
         *t=(*t)->suivant ;
         free(p) ;
       }
       // on va regarder dans les elements du milieu et fin de la liste si on trouve des valeurs negatives
  p =*t ; bidliste *d;
   while(p !=NULL) 
    { if (p->val <0)  // suppression dans le milieu ou fin de la bidliste
        { ( p->precedent) -> suivant = p->suivant;
          if ( p->suivant != NULL )( p->suivant) -> precedent= p->precedent; // ce test � la supression de l'avant dernier �l�ment
          d=p;
          p= p->suivant;
          free(d);
        }
        else  p = p->suivant;
    }
}
main()
{  int n,i; 
   int v;
   init(&tete) ; 
   printf("entrer le nombre n \n");
   scanf("%d",&n);
  if(n>0)
  {  printf("\n entrez la premli�re  valeur ");
     scanf("%d",&v);
     ajoutpremier(&tete,v);
     
     for(i=2;i<=n;i++)
     { printf("\n entrez la %d ime  valeur ",i);
       scanf("%d",&v);
      ajout(&tete,v);
     }  
     puts(" les valeurs de la listes sont :");
     afficheliste( tete) ;
     getchar();     
   
    suppneg(&tete);   
    puts(" \n les valeurs de la listes apres suppression sont :");
    if (tete != NULL) afficheliste( tete) ;
        else puts(" \n liste vide");
  
  }
  getchar();
}