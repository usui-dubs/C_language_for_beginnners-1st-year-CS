#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct employee {
    int mat;
    char nom[50];
    char prenom[50];
    char fonc[50];
    float salaire;
} employee;

int main() {
    int nbr, i;
    employee employees[100];
    
    FILE *f = fopen("Fi_employés.dat", "wb");
	
    printf("Number of employees: ");
    scanf("%d", &nbr);
    
	for(i = 0 ; i < nbr ; ++i)
	{
		printf("\nFamily Name of the employee %d: ", i + 1 );
		scanf("%s", &employees[i].nom);
		printf("First Name: ");
		scanf("%s", &employees[i].prenom);
		printf("Matricule: ");
		scanf("%d", &employees[i].mat);
		printf("Fonction: ");
		scanf("%s", &employees[i].fonc);
		printf("Salery: ");
		scanf("%f", &employees[i].salaire);
	}
	fwrite(employees, sizeof(employee), nbr, f);
    fclose(f);
    
    f = fopen("Fi_employés.dat", "rb");
	employee p;
	
	while(fread(&p, sizeof(employee), 1, f))
	{
		
		printf("\n---Mr.%s:", p.nom);
		printf("\n%s", p.prenom);
		printf("\n%d", p.mat);
		printf("\n%s", p.fonc);
		printf("\n%.2f", p.salaire);
	}
	
	fclose(f);
	
    return 0;
}
