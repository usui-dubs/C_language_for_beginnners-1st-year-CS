#include<stdio.h>

 int PGCD(int a, int b)
{
	int r;
	do{
	r=a%b;
	a=b;
	b=r;
	}while(r!=0);
	return a; ////not b because  r=b and a=b instructions executed
}

//the smaller and bigger idea :
/*int PGCD(int a, int b)
{
	int rem, smaller, bigger;
 
 if (b<a)
 {
     smaller = b;
     bigger = a;
 }
 else 
 {
     smaller = a;
     bigger = b;
 }
	do
 {
	    rem=bigger%smaller;
	    bigger=smaller;
	    smaller=rem;
	}while(rem!=0);

	return bigger; 
}*/

/*int GCD(int a, int b) //Or HCF
{
    int i, smaller;
    if(b<a)
        smaller = b;
    else smaller = a;
    
    for(i=0; i<=smaller; i++)
        if((a%i == 0) && (b%i == 0))
            return i;
}*/

int main(void)
{
	int x,y,r,p;
retry:	printf("enter x : "); //do{} while(x<0 || y<0);
	scanf("%d",&x);
	printf("enter y : ");
	scanf("%d",&y);
	if(x>0 && y>0 && x>y) p=PGCD(x,y);
	else if (x>0 && y>0 && x<y)  p=PGCD(y,x); 
/*or we can apply the smaller idea 
 if (x>0 && y>0) p=PGCD(x,y);*/
 /*if (x>0 && y>0) p=GCD(x,y);*/
	else goto retry; 

	printf("the pgcd of %d and %d is %d.\n",x,y,p);

 if (p==1) printf("les Deux nombres sont premier entre eux ");
 else printf("les Deux nombres ne sont pas premier entre eux ");
}
