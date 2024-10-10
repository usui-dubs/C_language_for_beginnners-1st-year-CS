#include <stdio.h>
#include <stdlib.h>

void enterArray(int *ptr, int size)
{
	int index;
	
	for(index=0; index < size; ++index)
	{
		printf("%d element : ", index + 1);
		scanf("%d", (ptr + index) ); // &ptr[i]
	}
}

int evenOrNot(int Num)
{
	if ((Num % 2) == 0 )
		return 1;
	else return 0;	
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
		
		int nb;
		
		for(i=0; i < N - 1; ++i)
		{
			if( (evenOrNot( (*(T + i)) ) == 0 ) && ( evenOrNot( (*(T + i+1)) ) == 1 ) )
				nb++;
		}		
		
  printf("the array elements : ");
		for(i=0; i < N; ++i)
		{
			printf("%d ", *(T + i));
		}
		
		printf("\nnumber of occurrences :%d", nb);

  free(T);
	}	
	
}