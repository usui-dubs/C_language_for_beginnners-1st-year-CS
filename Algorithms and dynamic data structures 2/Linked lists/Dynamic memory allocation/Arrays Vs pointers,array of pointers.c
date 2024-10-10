// C program to illustrate Pointer Arithmetic

 

#include <stdio.h>

 

int main() 

{

 

    // Declare an array 

    int v[3] = { 10, 100, 200 }; 

 

    // Declare pointer variable 

    int* ptr; 

 

    // Assign the address of v[0] to ptr 

    ptr = v; 

 

    /*for (int i = 0; i < 3; i++) 
    { 

       

          // print value at address which is stored in ptr 

        printf("Value of *ptr = %d\n", *ptr); 

       

          // print value of ptr 

        printf("Value of ptr = %p\n\n", ptr); 

 

        // Increment pointer ptr by 1 

        ptr++; //yrouh lladress li ba3dha b +4 li hiya sizeof(int) 
                //ywli fih &v[1]
            //and if we add 2 (ptr += 2) we get &v[2]
            
    When we add a value x to a pointer p, 
the value of the resultant expression is p + x*sizeof(*p) 
where sizeof(*p) means size of data type pointed by p.

//but Size of a pointer is fixed for a compiler. 
All pointer types take same number of bytes for a compiler. 
That is why we get 4 for both ptri and ptrc.

prt2-ptr1=(5*4)/(4) =5;

(char*)ptr2 - (char*)ptr1=(5*4)/size0f(char) = (5*4)/1 =20
When we do '(char *)ptr2', ptr2 is type-casted to char pointer and size of character is one byte, 
pointer arithmetic happens considering character pointers. 
So we get 5*sizeof(int)/sizeof(char) as a difference of two pointers.

/*d 

Question 9CORRECT
#include<stdio.h>
void fun(int arr[])
{
  int i;
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  for (i = 0; i < arr_size; i++)
      printf("%d ", arr[i]);
}
 
int main()
{
  int i;
  int arr[4] = {10, 20 ,30, 40};
  fun(arr);
  return 0;
} 
Run on IDE
A
10 20 30 40
Machine Dependent
C
10 20
D
Northing
C Pointer Basics    
Discuss it


Question 9 Explanation: 
In C, array parameters are always treated as pointers. So following two statements have the same meaning.
void fun(int arr[])
void fun(int *arr)
[] is used to make it clear that the function expects an array,
 it doesn’t change anything though.
 People use it only for readability so that the reader is clear about the intended parameter type. 
The bottom line is, sizeof should never be used for array parameters, 
a separate parameter for array size (or length) should be passed to fun(). 
So, in the given program, arr_size contains ration of pointer size and integer size,
 this ration= is compiler dependent.
void fun(int arr[], size_t arr_size) 
{ int i; 
for (i = 0; i < arr_size; i++) 
    printf("%d ", arr[i]); 
} 
int main() 
{ int i; int arr[] = {10, 20 ,30, 40}; 
// Use of sizeof is fine here 
size_t n = sizeof(arr)/sizeof(arr[0]);
 fun(arr, n); 
return 0; } 
    } */

    for(int i = 0; i < 3; i++)
    {
        printf("v[%d] = *(v+%d) = %d ", i, i, *(v+i) );
        printf("= ptr[%d] = *(ptr+%d) = %d\n\n", i, i, *(ptr+i) );
    } //while in scanf("%d", v + i); equivalent to &v[i]
    
    //and so on nums[i][j] is equivalent to *(*(nums+i)+j)
    //check: https://www-geeksforgeeks-org.cdn.ampproject.org/v/s/www.geeksforgeeks.org/c-pointers/amp/?amp_gsa=1&amp_js_v=a9&usqp=mq331AQKKAFQArABIIACAw%3D%3D#amp_tf=From%20%251%24s&aoh=16680418373415&referrer=https%3A%2F%2Fwww.google.com&ampshare=https%3A%2F%2Fwww.geeksforgeeks.org%2Fc-pointers%2F
    
    
    return 0; 

}

/*The reason for using pointers in a C program is


Pointers allow different functions to share and modify their local variables.


To pass large structures so that complete copy of the structure can be avoided.


Pointers enable complex “linked" data structures like linked lists and binary trees.*/
    
    /*The operator * is used for dereferencing and the operator & is used to get the address. 
    These operators cancel out effect of each other when used one after another.
     We can apply them alternatively any no. of times. 
    In the above code, ptr is a pointer to first character of string g. 
    *ptr gives us g, &*ptr gives address of g, 
    *&*ptr again g, &*&*ptr address of g, 
    and finally *&*&*ptr gives ‘g’ 
    Now try below
int main()
{
 char *ptr = "GeeksQuiz"; 
 printf("%s\n", *&*&ptr);
 return 0;
}



Void Pointers 
void* ptr = NULL;
 

NULL Pointers
int* ptr = NULL;


Wild Pointers 
Wild Pointers are pointers that have not been initialized with something yet.
 These types of C-pointers can cause problems in our programs and can eventually cause them to crash. While working with Wild Pointers Programmer must be very careful.

int* ptr;

Dangling Pointer
free(ptr);



*/


/* 
another method:
array of pointers:
#include <stdio.h>

int main ()

{

int a[3] = {10, 100, 200},n=3;

int i, *ptr[3];

for ( i = 0; i < 3; i++)

{

  ptr[i] = &a[i];

}

for ( i = 0; i < n; i++)

{

  printf("Value of a[%d] = %d\n", i, *ptr[i] );
                           or **(ptr + i)
}

return 0;

}

*/