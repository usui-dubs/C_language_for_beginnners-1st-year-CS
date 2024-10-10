#include <stdio.h>
void hanoi(int n,int dbt,int fin,int intr)
    {
    if (n == 1)
       {
       	printf("%d--->%d \n",dbt,fin) ;
	   }
	   else
	   {
	   	hanoi(n-1,dbt,intr,fin);
	   	printf("%d--->%d \n",dbt,fin);
	   	hanoi(n-1,intr,fin,dbt) ;
	   }
}

int main()
 { int n;
        printf("donnes n : \n") ;
        scanf("%d",&n);

  		hanoi( n , 1 , 3 ,2 ) ;


}