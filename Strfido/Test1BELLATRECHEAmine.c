//BELLATRECHE Mohamed Amine

#include<stdio.h>

int main()
{
	FILE *f = fopen("F.bin", "wb");
	
	int n, nbr;
	
	printf("Write Number of Numbers: ");
	scanf("%d", &n);
	
	//F filling:
	printf("\nEnter F.bin content:\n");
	for(int i = 0; i < n; ++i)
	{
		printf("%d : ", i + 1);
		scanf("%d", &nbr);
		fprintf(f, "%d ", nbr);
	}
	fclose(f);

	//Printing F content:
	fopen("F.bin", "rb");
	
	printf("\nF.bin content:\n");
	while((fscanf(f, "%d", &nbr)) != EOF)
	{
		printf("%d ", nbr);	
	}
	
	//sum, multiplication and moy //we can integrate the calculations in the previous loop
	rewind(f);
	
	long sum, mul;
	float moy;
	sum = 0;
	mul = 1;
	
	while((fscanf(f, "%d", &nbr)) != EOF)
	{
		sum += nbr;
		mul *= nbr;
	}
	moy = ((float)sum / (float)n);
	
	printf("\n\nsum = %d, multiplication = %d, moy = %.2f\n", sum, mul, moy);
	
	//coping to G.bin
	rewind(f);
	
	FILE *g = fopen("G.bin", "wb");
	
	while((fscanf(f, "%d", &nbr)) != EOF)
	{
		fprintf(g, "%d ", nbr);
	}
	fclose(g);
	
	//printing G:
	fopen("G.bin", "rb");
	
	printf("\nG.bin content:\n");
	while((fscanf(g, "%d", &nbr)) != EOF)
	{
		printf("%d ", nbr);	
	}
	
	fclose(f);
	fclose(g);

	return 0;
}