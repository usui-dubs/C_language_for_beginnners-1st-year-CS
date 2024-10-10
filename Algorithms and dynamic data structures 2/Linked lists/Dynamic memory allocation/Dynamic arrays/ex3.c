#include <stdio.h>
#include <stdlib.h>

void enterArray(int *ptr, int size)
{
	int index = 0;
	
	//printf("%d ", index); 
	printf("%02d: ", index);
	scanf("%d", (ptr) );
	  
	for(index = 1; index < size; ++index)
	{
	/*	do
  		{
      		//printf("element %d : ", index + 1);
      		printf("%02d: ", index); 
	     	scanf("%d", (ptr + index) ); // &ptr[i]
   		} while(*(ptr + index) < *(ptr + index - 1));*/

    	printf("%02d: ", index);
		scanf("%d", (ptr + index) );
	    if ( *(ptr + index) < *(ptr + index - 1))
	    	index--;
	}
}

int main()
{
	int i;
	int *V = NULL, N;
	int *A = NULL;
	
	do
	{
		printf("Enter number of the array elements : ");
		scanf("%d", &N);
	} while(N <= 0);
	
	V = (int*)malloc(N * sizeof(int));

	if(V == NULL)
	{
		printf("Memory was not allocated succsesfully");
      	exit(0);
  	}
	else
	{
		printf("enter the elements : \n");
		enterArray (V, N); 
		
		int nb = 1;
		
 		printf("the array elements : ");
 		for(i=0; i < N ; ++i)
		{
			printf("%d ", *(V + i));
		}
		
		for(i=0; i < N - 1; ++i)
		{
   			if(*(V + i) != *(V + i + 1 ))
			    nb++;
		}
		
		A = (int*)malloc((nb*2) * sizeof(int)); 
		if(A == NULL)
		{
			printf("Memory was not allocated succsesfully");
      		exit(0);
  		}
  		/*
		int k,j;
		for(i=0, k=0; i < N - 1; ++i)
		{
			*(A + k) = *(V + i);
			int nbb = 1;             
			k++;
			for(j = i; j < N-1 && *(V + j) == *(V + j + 1 ); ++j)
			{
      if(*(V + j) == *(V + j + 1 ) )
      {
   				    nbb++;
          i++;
   				}
			}
			*(A + k) = nbb;
			k++;
		}
 if(*(V + N - 2) != *(V + N - 1))
 {
     *(A + k) = *(V + N - 1);
     *(A + k + 1) = 1 ;
 } 
*/
int k;
int nbb = 1;
*A = *V;
for(i = 0, k = 0; i < N - 1; ++i)
{
    if(*(V + i) == *(V + i + 1 ) )
    {
   				    nbb++;
   		}
    else if(*(V + i) != *(V + i + 1 ) )
    {
        k++;
        *(A + k) = nbb;
        k++;
        *(A + k) = *(V + i + 1);
        nbb = 1;
    }
}
if(*(V + N - 2) == *(V + N - 1))
 {
     *(A + k + 1) = nb;
 } 

if(*(V + N - 2) != *(V + N - 1))
 {
    // *(A + k) = *(V + N - 1);
     *(A + k + 1) = 1 ;
 } 

		printf("the second array : ");
 		for(i=0; i < nb*2 ; ++i)
		{
			printf("%d ", *(A + i));
		}
		
  		free(V);
  		free(A);
	}	
	
}