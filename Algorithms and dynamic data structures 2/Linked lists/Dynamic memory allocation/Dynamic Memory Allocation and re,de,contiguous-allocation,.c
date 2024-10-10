#include <stdio.h> 
#include <stdlib.h> 

  

int main() 
{ 

  

    // This pointer will hold the 

    // base address of the block created 

    int *ptr = NULL, *ptr1 = NULL; 

    int n, i; 

  

    // Get the number of elements for the array 

    printf("Enter number of elements: \n"); 

    scanf("%d",&n);

    // Dynamically allocate memory using malloc() 
if(n>0)
{
    ptr = (int*)malloc(n * sizeof(int)); 
//initialize each block with 
//the default garbage value initially.     
  

    // Dynamically allocate memory using calloc() 

    ptr1 = (int*)calloc(n, sizeof(int)); 
    /*
    different points and these are:
It initializes each block with a default value ‘0’.
It has two parameters or arguments as compare to malloc().
    ptr = (int*)calloc(n, sizeof(int)); 
*/

    // Check if the memory has been successfully 

    // allocated by malloc or not 

    if (ptr == NULL || ptr1 == NULL) { 

        printf("Memory not allocated.\n"); 

        exit(0); 

    } 

    else { 

  

        // Memory has been successfully allocated 

        printf("Memory successfully allocated using malloc.\n"); 

        // Get the elements of the array 

        for (i = 0; i < n; ++i)
        { 
            printf("element %d = ", i + 1); 
           // scanf("%d", &ptr[i]);
            scanf("%d", (ptr + i) );
        } 

  

        // Print the elements of the array 

        printf("The elements of the array are: "); 

        for (i = 0; i < n; ++i) 

          //  printf("%d, ", ptr[i]); 
            printf("%d", *(ptr + i) );
printf("\n%p",ptr);

        // Get the new size for the array 
        int new_num;
        
        printf("\n\nEnter the new size of the array: \n", n); 
        scanf("%d",&new_num);
  

        // Dynamically re-allocate memory using realloc() 

        ptr = realloc(ptr, n * sizeof(int)); 
/*re-allocation of memory
 maintains the already present value
 and new blocks will be initialized
 with the default garbage value.*/
  

        // Memory has been successfully allocated 

        printf("Memory successfully re-allocated using realloc.\n"); 

  

        // Get the new elements of the array 

        for (i = n; i < new_num; ++i) 
        { 
            printf("element %d = ", i + 1); 
           // scanf("%d", &ptr[i]);
            scanf("%d", (ptr + i) );

        } 

  

        // Print the elements of the array 

        printf("The elements of the new array are: "); 

        for (i = 0; i < new_num; ++i) { 

            printf("%d, ", ptr[i]); 

        } 

        // Free the memory 

        free(ptr); 


        printf("Malloc Memory successfully freed.\n"); 

for (i = 0; i < new_num; ++i) 

 printf("%d, ", ptr[i]); 
 printf("\n%p",ptr);

  

        // Memory has been successfully allocated 

        printf("\nMemory successfully allocated using calloc.\n"); 

  

        // Free the memory 

        free(ptr1); 

        printf("Calloc Memory successfully freed.\n"); 

    } 
}
  

    return 0; 
} 