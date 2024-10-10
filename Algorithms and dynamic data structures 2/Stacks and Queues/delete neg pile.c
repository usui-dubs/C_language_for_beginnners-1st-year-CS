#include <stdio.h>
#include <stdlib.h>
#define taillemax 50

    typedef  struct pile
                { int ind; 
                   int tab[taillemax]; 
                } pile;        
   
void init(pile *p)
 { p->ind=-1 ;
 }

int  pilevide(pile p)
 {return (p.ind== -1) ;
  }

int  pilepleine(pile p)
 {return (p.ind== taillemax-1) ;
  }

int sommetpile(pile p)
{ if(p.ind>=0) return p.tab[p.ind];
} 

void empiler(pile *p, int v )
 { if(p->ind<taillemax-1) { p->ind=p->ind+1;
                                          p->tab[p->ind]=v ;
                                              }
       }

void depiler(pile *p, int *v )
 { if(p->ind> -1) { *v= p->tab[p->ind] ;
                             p->ind=p->ind-1;
                                }
       }
 
  void  affichepile( pile p) //je rajoute une primitive � la liste des primitives de la pile pour faire un parcours sans depiler
{int  inds= p.ind;
  while(inds!=-1)
  { printf(" %d  ", p.tab[inds]); 
    inds--;
  }
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
 
 main() 
{ 
  pile p ;
  int n,i; 
  int val;
  init(&p) ; 
   printf("entrer le nombre n \n");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   { printf("\n entrez la %d ime  valeur ",i);
     scanf("%d",&val);
     empiler(&p,val);
   }  
   puts("\n les valeurs de la pile sont :");
affichepile( p) ;
suppneg(&p); 

puts("\n les valeurs de la pile apr�s suppression des n�gatifs sont :");

affichepile(p);
getchar();
getchar();
}