// C code to linearly search x in arr[]. If x
// is present then return its location, otherwise
// return -1

#include <stdio.h>

int linear_search(int arr[], int size,int key)
{
   if(size == 0) return -1; //our base case
   
    if(arr[size - 1] == key) 
        return size - 1; 
    else return linear_search(arr, size - 1, key);
     //recursive case
//recursive call

    
}
/*iterative solution 
int search(int arr[], int N, int x)
{
    int i;
    for (i = 0; i < N; i++)
        if (arr[i] == x)
            return i;
    return -1;
}*/
 
// Driver's code
int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int N = sizeof(arr) / sizeof(arr[0]); //sizeof(int) == sizeof (arr[0]) when array is int type
 
    // Function call
    int result = linear_search(arr, N, x);
    (result == -1)
        ? printf("Element is not present in array")
        : printf("Element is present at index %d", result);
    return 0;
}
    
    //Time Complexity: O(n)
    //Auxiliary Space: O(n), for using recursive stack space. 

    // and for the iterative solution:
    //Time Complexity: O(n)
    //Auxiliary Space: O(1)
//Space Complexity:Space complexity includes both Auxiliary space and space used by input. 
//Space complexity for linear search is O (n) as it does not use any extra space where 
//is the number of elements in an array.