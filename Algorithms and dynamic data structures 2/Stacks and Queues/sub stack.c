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
     
 main() 
{ 
  pile p ,sp;
  int n,i; 
  int val;
  init(&p) ; init(&sp);
   printf("entrer le nombre n \n");
   scanf("%d",&n);
   for(i=1;i<=n;i++)
   { printf("\n entrez la %d ime  valeur ",i);
     scanf("%d",&val);
     empiler(&p,val);
   }  
   puts("\n les valeurs de la pile sont :");
affichepile( p) ;
 getchar();
 for(i=1;i<=n/2;i++)
   { printf("\n entrez la %d ime  valeur ",i);
     scanf("%d",&val);
     empiler(&sp,val);
   }

affichepile(sp);
getchar();
if(souspile(sp, p)==1) printf("\n OUI ");
else printf("\n NON ");

getchar();
}