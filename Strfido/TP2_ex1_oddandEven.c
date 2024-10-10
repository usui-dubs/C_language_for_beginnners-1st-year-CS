#include <stdio.h>
#include <stdlib.h>

int main() {
  
  	int nbr, n, i;
  	
  	FILE *f = fopen("nums.bin", "wb");
	FILE *g = fopen("pair.bin", "wb");
  	FILE *h = fopen("impair.bin", "wb");
  	
  	if(f == NULL || g ==  NULL || h == NULL)
	{
    	perror("ERROR IN OPENNING FILES");
    	return -1;
	}
	
  	printf("how many numbers needed:");
  	scanf("%d", &n);
  	
  	printf("Fill the file f:");
  	for(i = 0; i < n; ++i)
	{
		scanf("%d", &nbr);
		fprintf(f, "%d ", nbr);
	}
  	fclose(f);
	  	
    f = fopen("nums.bin", "rb");

	while(fscanf(f, "%d", &nbr) != EOF)
	{
		if(nbr % 2 == 0)
		{
			fprintf(g, "%d ", nbr);
		}
		else
		{
			fprintf(h, "%d ", nbr);
		}	
	}
	fclose(f);
	fclose(g);
	fclose(h);
	
	g = fopen("pair.bin", "r");
	h = fopen("impair.bin", "r");
	
	
	if(fscanf(g, "%d", &nbr) == EOF)
	{
		printf("no even numbers ");
	}
	else
	{
		printf("The even numbers are: ");
		printf("%d ", nbr);	
		while((fscanf(g, "%d", &nbr) != EOF))
		{
			printf("%d ", nbr);	
		}
	}

	if((fscanf(h, "%d", &nbr) == EOF))
	{
		printf("and no odd numbers");
	}
	else
	{
		printf("and the odd numbers arr: ");		
		printf("%d ", nbr);	
		while((fscanf(h, "%d", &nbr) != EOF))
		{
			printf("%d ", nbr);	
		}
	}
	
	fclose(g);
	fclose(h);
	
	return 0;
}