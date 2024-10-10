#include <stdio.h>
//transforme terminal method to iterative solution:
/*int somme (int v [], int n, int s)
{  
 if (n==0) //condition 
     return s; //ins A
 else 
     //ins B
     somme(v,n-1,s + v[n - 1]) ; //recurcive call with new parameters 
}*/
//iterative:
int somme (int v [], int n, int s)
{  
 while (n!=0) //not condition 
 {
     //inst B
     //new parameters:
     s = s + v[n - 1];
     n = n - 1;
 }
 
 return s; //inst A
}

//non terminal methods
 /*int somme (int v [], int size)
{  
 /*if(size == 1)   
     return v[0];*//*
 if (size==0) 
     return 0; 
 else 
     return v[size - 1] + somme ( v, size-1);
}*/
/*
int somme (int v [], int end)
{  
 /*if (end == -1) 
     return 0; *//*
 if(end == 0)   
     return v[0];
 else 
     return v[end] + somme ( v, end-1);
}   */

//transforme terminal method to iterative solution:
/*int nbr (list *t, int nbr)
{  
 if (t == NULL) //condition 
     return nb; //ins A
 else 
     //ins B
     nbr(t -> suivant, nb++]) ; //recurcive call with new parameters 
}*/
//iterative:
int nbr (list *t, int nb)
{  
 while (t != NULl) //not condition 
 {
     //inst B
     //new parameters:
     nb++;
     t = t -> suivant;
 }
 
 return nb; //inst A
}

//non terminal methods
 /*int nbr (list *t)
{  
 /*if(t == NULL)   
     return 0; 
 else 
     return 1 + nbr(t -> suivant);
}*/


int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]); //sizeof(int) == sizeof (arr[0]) when array is int type
 
    // Function call
    int result;
    
    //somme(arr, N, &result);
    result= somme(arr, N, result);
    
    printf("%d", result);
    
    return 0;
}