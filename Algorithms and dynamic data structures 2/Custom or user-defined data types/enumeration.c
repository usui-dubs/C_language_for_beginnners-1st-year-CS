#include <stdio.h>

// define enum flags.

enum color { red, blue, green };         // set is {0, 1, 2}.

enum fruit { mango = 10, apple, grapes }; // set is {10, 11, 12}. 

int main()

{

    enum color c1;

    enum fruit f1;

    c1 = blue;  // default value i.e. 1 will be assigned.

    f1 = apple; // 11 will be assigned. 

    printf("The second value in enum set is: %d\n",c1);

    printf("The second value in enum set is: %d\n",f1); 

    return 0;

}