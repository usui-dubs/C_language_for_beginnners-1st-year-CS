#include<stdio.h>
int addmul(int a,int b,int* p){
	*p = a*b;
	return a+b;
}
main(){
	int somme,x,y,M;
	printf("entrez x:\n");
	scanf("%d",&x);
	printf("entrez y:\n");
	scanf("%d",&y);
	somme = addmul( x , y ,&M);
	printf("add= %d\n",somme);
 printf("mul= %d\n",M);
	
	
}

















