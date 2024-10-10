#include <stdio.h>
#define Max 100

/*void quicksort(int number[],int first,int last)
{
   int i, j, pivot, temp;

   if(first<last)
   {
      pivot=(first + last)/2; //= last or = first
      i=first;
      j=last;
    
      while(i<j)
     {
         while(number[i]<=number[pivot]&&i<last)
             i++;
         while(number[j]>number[pivot])
             j--;
         if(i<j)
        {
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }
      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
    
      quicksort(number,first,j-1);
      quicksort(number,j+1,last);
   }
}
*/

// A utility function to swap two elements
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places the pivot element at its correct position in sorted 
	array, and places all smaller (smaller than pivot) to left of pivot and all greater elements to right 
    of pivot 
*/
int partition(int arr[], int low, int high)
{
	int pivot = arr[high]; // pivot
	int i = (low - 1);	   // Index of smaller element

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than the pivot
		if (arr[j] < pivot)
		{
			i++; // increment index of smaller element
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quicksort(int arr[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now 
		at right place */
		int pi = partition(arr, low, high);

		// Separately sort elements before
		// partition and after partition
		quicksort(arr, low, pi - 1);
		quicksort(arr, pi + 1, high);
	}
}

int sorted_check(int arr[Max], int size)
{
    int i;
    
    /*for(i = 0; i < size - 1; i++)
    {
        if(arr[i] > arr[i+1])
            return 0; //*p = i ;
    }
    return 1;*/
    
    if(size == 1)
            return 1;
            
    if(arr[size - 2] > arr[size - 1])    
        return 0;
        
    return sorted_check(arr, size - 1)  ;  
}

int binary_search(int start, int end, int array [], int target)
{
    int mid;
    
    if(start > end)
        return -1; //return end( position )
    
    mid = (start + end) / 2;
        
    if(array[mid] == target)
        return mid;
    else if(array [mid] < target)
        return binary_search(mid + 1, end, array, target);
    else return binary_search(start, mid - 1, array, target);
    
}

int main()
{
    int arr[Max] ;// = {9,7,5,2,1,4,3,6,8} ;
    int i, N;
    
    do
    {
    printf("enter the array size: ");
    scanf("%d", &N);
    } while (N <= 0 || N > 100);
    
    printf("enter the array values: \n");
    for(i = 0; i < N; i++)
    {
        printf("arr[%d]= ", i);
        scanf("%d", &arr[i]);
    }
    
    if(sorted_check(arr, N))
        printf("\nsorted");
    else 
    {
        printf("\nnot sorted");   
         
        quicksort(arr,0,N-1);
    }
    
    printf("\nHere is your sorted array: \n");
    for(i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    
    int x, pos;
    
    do
    {
    printf("\nWhat are you searching for ?");
    scanf("%d",&x);
    
    pos = binary_search(0, N-1, arr, x);
    
    if(pos != -1)
        printf("The number you are searching for %d = arr[%d] is at the position %d in the array", arr[pos], pos, pos+1);
    else printf("the number doesn't exist, pleas try again");
    } while(pos == -1);
    
    return 0;
}