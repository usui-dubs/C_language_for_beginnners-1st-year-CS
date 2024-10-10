#include <stdio.h>
#define Max 100

typedef struct stack
{  
    int val ;  
    struct stack *precedent ;
} stack ; 

//to iterative solution:
void init(stack **p)  
{
   // (*p).index = -1 ; 
    *p = NULL ;
}

int pilevide(stack *p)  //empty stack
{
    return (p == NULL) ; 
}

void empiler( stack **p, int x)  
{
 stack *new; 
 new = (stack*)malloc(sizeof(stack)) ;
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

int partition(int V[], int deb, int fin) 
{ 
 int pivot,i,j; 

 pivot=V[(deb+fin)/2]; 
 i=deb; j=fin;  

 while (i<j)  
 { 
     while (pivot > V[i]) 
         i++;  
     while (pivot < V[j]) 
         --j;  
     if (i<j) 
     {
         int temp;
         temp = V[i];
         V[i] = V[j];
         V[j] = temp;
     } 
}  
 return j;  
}

void quicksort(int v[],int i, int j)  
{
 int m; 

 stack* p; 
 init(&p); 
 empiler(&p,i);
 empiler(&p,j); 
 while(!pilevide(p))  
 { 
     depiler(&p,&j);
     depiler(&p,&i); 
     while(i < j)  
     {
         m = partition(v,i,j); 
         empiler(&p,m+1);
         empiler(&p,j); 
         j = m-1; 
     } 
 }  
}
/*
void quickSort(int V[], int deb, int fin) 
{ 
 int ppivot;  
 if (deb<fin) 
 { 
     ppivot=partition(V,deb,fin);  
     quickSort(V,deb,ppivot-1);  
     quickSort(V,ppivot+1,fin);  
 } 
}
*/

int main()
{
    int arr[Max] ;// = {9,7,5,2,1,4,3,6,8} ;
    int i, N;
    
    do
    {
    printf("enter the array size: ");
    scanf("%d", &N);
    } while (N <= 0 || N > Max);
    
    printf("enter the array values: \n");
    for(i = 0; i < N; i++)
    {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    
    quicksort(arr,0,N-1);
    
    printf("\nHere is your sorted array: \n");
    for(i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    
    return 0;
}