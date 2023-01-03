
#include <stdio.h> //tkhdm m3aha getchar();
#include <conio.h> //lazem m3a/t3 getch();
#define NFOIS -3 
 main() 
{
 float x= 10 ; 
 float y ; 
printf ("Bonjour\n") ; //const est entier %d //u positive // hd,d sahih
printf ("Je vais vous afficher la valeur de %f , %u fois \n ",x , NFOIS) ; 
printf ("%.0f et %.0f et %.0f\n ", x, x, x) ; 
y=x*x ;  // %.2f 2 values after the point
printf ("Le nombre %100f au carrée est : %.0f\n", x, y) ;
//getch();         // %2f zooj horouf
system("pause");
return 0;
main(); //recursion tb9a ghir tt3wd
}
