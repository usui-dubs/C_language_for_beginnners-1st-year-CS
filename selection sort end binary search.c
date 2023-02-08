#include <stdio.h>
#define Max 100

void selection_sort(int array[], int N )
{
    int i, j, temp;
    
    for(i = 0; i < N - 1; i++)
    {
        for(j = i + 1; j < N; j++)
        {
            if(array[j] < array[i])
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

binary_search(int N, int arr[N], int x)
{
    int i;
    int start, end, mid;
    
    start = 0;
    end = N - 1;
    
    while(start <= end)
    {
        mid = (start + end) / 2;
        
        if(arr[mid] == x)
            return mid;
        else if(arr[mid] < x)
            start = mid + 1;
        else end = mid - 1;       
    }
    
    return -1;
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
    
    selection_sort(arr, N);
    
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
    
    pos = binary_search(N, arr, x);
    
    if(pos != -1)
        printf("The number you are searching for %d = arr[%d] is at the position %d in the array", arr[pos], pos, pos+1);
    else printf("the number doesn't exist, pleas try again");
    } while(pos == -1);
    
    return 0;
}