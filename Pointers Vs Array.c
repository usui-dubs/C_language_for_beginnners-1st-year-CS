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
    } */

    for(int i = 0; i < 3; i++)
    {
        printf("v[%d] = *(v+%d) = %d ", i, i, *(v+i) );
        printf("= ptr[%d] = *(ptr+%d) = %d\n\n", i, i, *(ptr+i) );
    }
    
    //and so on nums[i][j] is equivalent to *(*(nums+i)+j)
    //check: https://www-geeksforgeeks-org.cdn.ampproject.org/v/s/www.geeksforgeeks.org/c-pointers/amp/?amp_gsa=1&amp_js_v=a9&usqp=mq331AQKKAFQArABIIACAw%3D%3D#amp_tf=From%20%251%24s&aoh=16680418373415&referrer=https%3A%2F%2Fwww.google.com&ampshare=https%3A%2F%2Fwww.geeksforgeeks.org%2Fc-pointers%2F
    
    
    return 0; 

}

