#include <stdio.h>
#include <string.h>

void creer(FILE *f, int nbr)
{
	f = fopen("pres.dat", "w");
    char nom[50];
	for(int i = 0; i < nbr; ++i)
	{
		printf("%d: ", i + 1);
		printf("\n");
		fflush(stdin);
		gets(nom);
        fprintf (f, "%s ", nom);
	}
    fclose(f);
}

void afficher(FILE* f)
{
	char nom[50];
	
	while(fscanf(f, "%s", nom) != EOF)
	{
		printf("%s\n", nom);
	}
	
}

int verification(FILE *f, char nom[50])
{
	char t[50];
	rewind(f); //rewined the curcer to the beginning
	while((fscanf(f, "%s", t)) != EOF)
	{
		if (strcmp(nom, t) == 0)
			return 1;
	}
    return 0;
}
void copie(FILE *f, FILE *g, char nom[50])
{
	char t[50];
    rewind (f);
	while(fscanf(f, "%s", t) != EOF)
	{
		if (strcmp(nom, t) != 0)
		{
			fprintf(g, "%s ", t);
		}
	}
}

int main()
{
	FILE *f, *g;
	char nom[50];
	
	g = fopen("pres_c.dat", "wb");
	
	creer(f, 2);
    f = fopen("pres.dat", "rb");
	afficher(f);
	
	printf("donner le nom: ");
	scanf("%s", &nom);
	
	if (verification(f, nom))
	{
		printf("le nom exist\n");
	}
	else 
		printf("n'exist pas\n");
	
	copie(f, g, nom);
	fclose(g);
    fclose(f);
    
    g = fopen("pres_c.dat", "rb");
    
    afficher(g);
    
	
	fclose(g);
	
	return 0;	
}