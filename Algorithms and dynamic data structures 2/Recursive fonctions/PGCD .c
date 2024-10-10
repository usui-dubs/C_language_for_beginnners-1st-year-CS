#include<stdio.h>

int PGCD(int a, int b)
{
	//int rem, smaller, bigger;
 
 /*if (b<a)
 {
     smaller = b;
     bigger = a;
 }
 else 
 {
     smaller = a;
     bigger = b;
 }*/

	/*do
 {
	    rem=bigger%smaller;
	    bigger=smaller;
	    smaller=rem;
	}while(rem!=0);

	return bigger; */

/* rem = bigger%smaller;
	bigger = smaller;
	smaller = rem;

 if (rem == 0) return bigger;

 return PGCD (bigger, smaller); 
//or without assignments: return PGCD (smaller, bigger%smaller); 
*/
 
 /*if ( a % b == 0) 
     return b;*/
 if(b == 0)
     return a; 
 else   
     return PGCD (b, a%b);
}

int main(void)
{
	int x,y,r,p;
 do
{
	printf("enter x : ");
	scanf("%d",&x);
	printf("enter y : ");
	scanf("%d",&y);

 if (x>0 && y>0) 
 {
      int smaller, bigger;
    
      if (y<x)
      {
         smaller = y;
         bigger = x;
      }
      else 
      {
         smaller = x;
         bigger = y;
      }
      p=PGCD(bigger,smaller);
 }
 else printf("please try again\n");
 } while(x<0 || y<0);

	printf("the pgcd of %d and %d is %d.\n",x,y,p);

 }
