#include <stdio.h>
#include <stdlib.h>

void enterArray(int *ptr, int size)
{
	int index;
	
	for(index=0; index < size; ++index)
	{
	/*	do
  {
      //printf("element %d : ", index + 1);
      printf("%02d: ", index); 
	     	scanf("%d", (ptr + index) ); // &ptr[i]
   } while( *(ptr + index) < 0);*/

    printf("%02d: ", index); 
	   	scanf("%d", (ptr + index) );
    if(*(ptr + index) < 0)
        --index;    
	}
}

int almostPerfect(int Num)
{
 int i, divisors_sum = 0;

 for(i = 1; i < (Num / 2) + 1; ++i)
 {
	    if ((Num % i) == 0 )
     {     
         divisors_sum += i;
     }  
 }

  if(divisors_sum == Num - 1)
     return 1;
  else 
     return 0;    
}


int main()
{
	int i;
	int *T = NULL, N;
	
do
{
	printf("Enter number of the array elements : ");
	scanf("%d", &N);
} while(N <= 0);
	
	T = (int*)malloc(N * sizeof(int));
	
	if(T == NULL)
  {
		    printf("Memory was not allocated succsesfully");
      exit(0);
  }
	else
	{
		printf("enter the elements : \n");
		enterArray (T, N); 
		
		int nb = 0;
		
  printf("the array elements : ");
		for(i=0; i < N; ++i)
		{
			printf("%d ", *(T + i));

   if( almostPerfect ( *(T + i)) )
			    nb++;
		}
		
		printf("\nnumber of almost perfect elements is :%d", nb);

  free(T);
	}	
	
}