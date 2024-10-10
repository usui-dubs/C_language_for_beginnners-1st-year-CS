#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Noeud  
         {  int val; 
            struct Noeud *FG, *FD; 
         }  Noeud; 
         
         
Noeud  * cree_noeud (int x)
{	Noeud *nouv; 

	nouv= malloc(sizeof(Noeud));
	nouv->val =x;
	nouv->FD=NULL;
	nouv->FG=NULL; 
	return nouv ; 
} 
int valeur (Noeud *N)
{
	if (N != NULL) return N -> val; 
}
 
int taille (Noeud *N)
{
	if (N == NULL) return 0; 
	return 1+ taille( N->FG)+ taille ( N->FD);
}

int max (int x,int y)
{ if(x>y)return x;
   return y;
}

int hauteur (Noeud *N)
{
	if (N == NULL) return 0;
    return 1+ max(hauteur( N->FG), hauteur ( N->FD));
}
int height(Noeud *root) 
 { 
     if(root == NULL) 
         return 0; 
     int left_height = height(root->FG); 
     int right_height = height(root->FD); 
     return max(left_height,right_height) + 1;
 }
 
int nbfeuille (Noeud *N)
{
	if (N == NULL) return 0;
	if( N->FG==NULL &&  N->FD==NULL) return 1;
    return nbfeuille( N->FG)+ nbfeuille ( N->FD);
}

void prefixe (Noeud *a)
{ 	if  (a != NULL) 	{ printf(" %d ",a->val);
 	                      prefixe ( a->FG) ;
	                      prefixe ( a->FD) ;
	                      
	                   }
}

 void miroir(Noeud *a)
 {if  (a != NULL) 	{miroir( a->FG) ;
                     miroir( a->FD) ;
                     Noeud *N=  a->FG ;
                     a->FG = a->FD ;
                     a->FD = N ;
                     }
      
 }
      
 int research(Noeud *a, int v)
 {
    if(a == NULL)
        return 0;
    if(a -> val == v)
        return 1;
    return research (a -> FG, v);
    return research (a -> FD, v);
 }
 
 int find_max(Noeud *root) 
 { 
     if(root == NULL) 
         return INT_MIN; 
     int max = root->val; 
     int left_max = find_max(root->FG); 
     int right_max = find_max(root->FD); 
     if(left_max > max) 
         max = left_max; 
     if(right_max > max) 
         max = right_max; 
     return max; 
  
 }
main()
{ Noeud *racine=NULL;
     racine= cree_noeud (1);
     racine->FG = cree_noeud (2);
     racine->FD = cree_noeud (3);
     racine->FG->FG = cree_noeud (4);
     racine->FG->FD = cree_noeud (5);
     racine->FD->FG = cree_noeud (6);
     racine->FD->FD = cree_noeud (7);
   prefixe (racine);
   printf(" \ntaille %d \n",taille(racine));
   printf(" hauteur %d \n",hauteur(racine));
   printf(" nbfeuille %d \n",nbfeuille(racine));
   miroir(racine); 
   prefixe (racine);
   
   getchar(); 
   
}  