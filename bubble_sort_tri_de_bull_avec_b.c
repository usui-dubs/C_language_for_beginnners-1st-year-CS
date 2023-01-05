#include <stdio.h>
#define MAX 100

bubble_sort( array[], N)
{
    int i,j,b=1,k;
    for(i=0; i<N-1 && b==1; i++) //for(i=N-1; i>0; i--)
    {
        b=0;
        for(j=0; j<N-i-1; j++) //for(j=0; j<i; j++) 
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
                b=1;
            }
        }
        for(k=0; k<N; k++)
            printf("%d ", array[k]);
        printf("\n");
    }
}
    
int main()
{
    int arr[MAX] ;// = { 9,6,5,7,3,1,2,8,4 } ;
    int i, N;
    
    do
    {
    printf("Donner la taille(size) de tableau (dimension) : ");
    scanf("%d", &N);
    } while(N <= 0 || N > MAX);
    
    printf("Donner la tableau(values) : \n");
    for(i = 0; i < N; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    
    bubble_sort(arr, N);
    
    printf("\n\n\n Your sorted array (ton trieé tableau ) :");
    for(i=0; i<N; i++)
        printf("%d ", arr[i]);
}