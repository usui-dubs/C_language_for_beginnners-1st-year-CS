#include <stdio.h>
#include <stdlib.h>

int searchMAX(FILE *f)
{
	f = fopen("notsorted.bin", "rb");
	int temp;
	int MAX;
	fscanf(f, "%d", &MAX);
	while((fscanf(f, "%d", &temp) != EOF))
	{
		if(temp > MAX)
			MAX  = temp;
	}
	fclose(f);
	return MAX;
}
	void deleatMAX(FILE *f,FILE *h, int max)
	{
		int num;
		f = fopen("notsorted.bin", "rb");
		h = fopen("copy.bin", "wb");

		while((fscanf(f, "%d", &num) != EOF))
		{
			if(num != max)
				fprintf(h, "%d ", num);
		}
		fclose(f);
		fclose(h);

		f = fopen("notsorted.bin", "wb");
		h = fopen("copy.bin", "rb");
		while((fscanf(h, "%d", &num) != EOF))
		{
			fprintf(f, "%d ", num);
		}
		fclose(f);
		fclose(h);
	}


int main() {
  
  	int nbr, n, i;
  	
  	FILE *f = fopen("notsorted.bin", "wb");
	FILE *g = fopen("sorted.bin", "wb");
	FILE *h;
  	if(f == NULL || g ==  NULL)
	{
    	perror("ERROR in openning file");
    	return -1;
	}
	
  	printf("how many numbers: ");
  	scanf("%d", &n);
  	
  	printf("Fill the file notsorted.dat:");
  	for(i = 0; i < n; ++i)
	{
		scanf("%d", &nbr);
		fprintf(f, "%d ", nbr);
	}
	fclose(f);

	for(i = 0; i < n; ++i)
	{
		int max = searchMAX(f);
		fprintf(g, "%d ", max);
		deleatMAX(f, h, max);
	}
	
	fclose(g);
	
	g = fopen("sorted.bin", "rb");
	
	printf("yOUR SORTED file sorted.dat:\n");
	while((fscanf(g, "%d", &nbr) != EOF))
	{
		printf("%d ", nbr);	
	}
	
	fclose(g);

    return 0;
}
