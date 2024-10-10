#include <stdio.h>
#include <stdlib.h>

int main() {
  
  	int nbr, nbr1 , nbr2, n1, n2, i;
  	
  	FILE *f = fopen("F.txt", "w");
	FILE *g = fopen("G.txt", "w");
  	FILE *h = fopen("H.txt", "w");
  	
  	if(f == NULL || g ==  NULL || h == NULL)
	{
    	perror("ERROR IN F.TEXT AND G");
    	return -1;
	}
	
  	printf("how many numbers in f:");
  	scanf("%d", &n1);
  	printf("how many numbers in g:");
  	scanf("%d", &n2);
  	
  	printf("Fill the file f(must enter numbers in order):");
  	for(i = 0; i < n1; ++i)
	{
		scanf("%d", &nbr);
		fprintf(f, "%d ", nbr);
	}
	
	printf("Fill g(must enter numbers in order):");
  	for(i = 0; i < n2; ++i)
	{
		scanf("%d", &nbr);
		fprintf(g, "%d ", nbr);
	}
  	
  	fclose(f);
	fclose(g);
	
    f = fopen("F.txt", "r");
	g = fopen("G.txt", "r");
  	h = fopen("H.txt", "w");
	
	int stat1, stat2;
	
	stat1 = fscanf(f, "%d", &nbr1);	
	stat2 = fscanf(g, "%d", &nbr2);	
	
	while((stat1 != EOF) && (stat2 != EOF))
	{
		if(nbr1 < nbr2)
		{
			fprintf(h, "%d ", nbr1);
			stat1 = fscanf(f, "%d", &nbr1);	
		}
		else
		{
			fprintf(h, "%d ", nbr2);
			stat2 = fscanf(g, "%d", &nbr2);	
		}	
	}
	
	while(stat1 != -1)
	{
		fprintf(h, "%d ", nbr1);
		stat1 = fscanf(f, "%d", &nbr1);	
	}
	
	while(stat2 != -1)
	{
		fprintf(h, "%d ", nbr2);
		stat2 = fscanf(g, "%d", &nbr2);		
	}
	
	fclose(h);
	
	h = fopen("H.txt", "r");
	while((fscanf(h, "%d", &nbr) != EOF))
	{
		printf("%d ", nbr);	
	}
	
	fclose(f);
	fclose(g);
	fclose(h);

    return 0;
}
