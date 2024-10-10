#include<stdio.h>
#include<stdlib.h>
int Somme(int n)
{
    if(n==0) return 0;
    else return n+Somme(n-1);
}
int main()
{
    int n;
    printf("Entrez un entier: ");
    scanf("%d",&n);
    printf("La somme des entiers jusqu'a %d est: %d.\n",n,Somme(n));
    system("pause");
    return 0;
}