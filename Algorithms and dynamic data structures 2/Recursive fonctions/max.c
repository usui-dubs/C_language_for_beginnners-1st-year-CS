#include <stdio.h>
 
int maximum (int v [], int size)
{
 int x;
 if (size==0) 
     return v[0]; 
 else 
 {
     x = maximum (v, size - 1);
     if(x > v[size - 1])
     return x;
     return v[size - 1];
 }
}

/*int MAX (int v [], int size, int max)
{  
 if (size==0) 
     return max; 
 if (v[size-1] > max)
     max = v[size-1];
 return MAX(v, size - 1, max);
}*/

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]); //sizeof(int) == sizeof (arr[0]) when array is int type
 
    // Function call
    int result;
    
    result= maximum (arr, N);
    //result= MAX(arr, N, arr[0]);
    
    printf("%d", result);
    
    return 0;
}