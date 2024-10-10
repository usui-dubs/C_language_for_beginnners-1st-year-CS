#include <stdio.h>

/*void somme (int v [], int n, int *s)
{  
 if (n==0) 
     *s=0; 
 else 
 {
     somme(v,n-1,s) ; 
     *s=*s+v[n-1] ; 
 }
}

 /*if (n==0) 
     *s+=0; 
 else 
 {
     
     *s=*s+v[n-1] ; 
    somme(v,n-1,s) ; 
 }
}

/ Explain to me this fonction 
// This function is a recursive function that calculates the sum of the elements of an array. 
// It takes the array, the size of the array, and a pointer to a variable where the sum will be stored as parameters. 
// If the size of the array is 0, then the sum is set to 0. If the size of the array is not 0, the function calls itself with size - 1, 
// and then adds the last element of the array to the sum stored in the pointer.

//can u trace the execution of the of the fonction 
// for an array of size 3
// Trace: 
// somme([1,2,3], 3, s) 
// somme([1,2], 2, s) 
// somme([1], 1, s) 
// somme([], 0, s) 
// s = 0 
// s = s + 1 = 1 
// s = s + 2 = 3 
// s = s + 3 = 6

*/



//another method 
 /*int somme (int v [], int size)
{  
 if (size==0) 
     return 0; 
 else 
     return v[size - 1] + somme ( v, size-1);
}*/

int somme (int v [], int end)
{  
 /*if (end == -1) 
     return 0; */
 if(end == 0)   
     return v[0];
 else 
     return v[end] + somme ( v, end-1);
}   

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]); //sizeof(int) == sizeof (arr[0]) when array is int type
 
    // Function call
    int result;
    
    //somme(arr, N, &result);
    result= somme(arr, N);
    
    printf("%d", result);
    
    return 0;
}