#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, nbr1, nbr2;
	
	FILE *f1 = fopen("F1.bin", "wb");
	FILE *f2 = fopen("F2.bin", "wb");
  	FILE *g = fopen("G.bin", "wb");
  	
  	if(f1 == NULL || f1 ==  NULL || g == NULL)
	{
    	perror("ERROR IN OPENNING FILES");
    	return -1;
	}
	
  	printf("how many numbers needed:");
  	scanf("%d", &n);
  	
  	printf("Fill the file f1(positive only without repetition):");
  	for(i = 0; i < n; ++i)
	{
		scanf("%d", &nbr1);
		if(nbr1 >= 0)
			fprintf(f1, "%d ", nbr1);
		else
		{
			printf("retry");
			i--;
		}
	}
  	fclose(f1);
  	
  	printf("Fill the file f2(positive only without repetition):");
  	for(i = 0; i < n; ++i)
	{
		scanf("%d", &nbr1);
		if(nbr1 >= 0)
			fprintf(f2, "%d ", nbr1);
		else
		{
			printf("retry");
			i--;
		}
	}
  	fclose(f2);
  	
  	f1 = fopen("F1.bin", "rb");
	f2 = fopen("F2.bin", "rb");
	
	while((fscanf(f1, "%d", &nbr1) != EOF))
	{
		fprintf(g, "%d ", nbr1);
		while((fscanf(f2, "%d", &nbr2) != EOF))
		{
			if(nbr1 % nbr2 == 0)
				fprintf(g, "%d ", nbr2);
		}
		rewind(f2);
	}
	fclose(f1);
  	fclose(f2);
  	fclose(g);

	g = fopen("g.bin", "rb");
	
	printf("Your new file : ");
	while((fscanf(g, "%d", &nbr1) != EOF))
	{
		printf("%d ", nbr1);
	}
	fclose(g);

  	return 0;
}
