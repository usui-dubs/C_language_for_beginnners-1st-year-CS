#include <stdio.h>
int main()
{
    int i, n ;
    printf("Enter the number :");
    scanf("%d", &n);
    for (i=1; i<=n; i++)
    {
// number divisible by 3 and 5 will always be divisible by 15, print 'FizzBuzz' in place of the number
        if (i%15 == 0)
            printf ("FizzBuzz\t");

// number divisible by 3, print 'Fizz' in place of the number
        else if ((i%3) == 0)
            printf("Fizz\t");

// number divisible by 5, print 'Buzz' in place of the number
        else if ((i%5) == 0)
            printf("Buzz\t");

        else // print the number
            printf("%d\t", i);
    }
    return 0;
}
/*
#include <stdio.h>

int main(void)
{
    int i;
    for(i=1; i<=100; ++i)
    {
        if (i % 3 == 0)
            printf("Fizz");
        if (i % 5 == 0)
            printf("Buzz");
        if (i % 3 != 0 && i % 5 != 0)
            printf("number=%d", i);
        printf("\n"); //puts("");
    }

    return 0;
}
*/


/*
#include <stdio.h>

int main(void)
{
   int i = 1;
   for (; i<=100; ++i) {
      printf("number= %d %s%s\n", i, i%3?"":"Fizz", i%5?"":"Buzz");
   }
   return 0;
} */
