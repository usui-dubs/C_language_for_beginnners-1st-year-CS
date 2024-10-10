#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Livre {
    char title[50];
    char nAuteur[50];
    char specialite[50];
    int annee;
    int code;
} Livre;


void initialiserFichier (FILE**f, char *name) {
    *f = fopen(name, "a");

    if (*f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
}

void ajouter (FILE*f, Livre *newLivre) { //newLivre

    //fseek(f, SEEK END)
    fwrite(newLivre, sizeof(Livre), 1, f); //&newLivre
}

void chercher (FILE*f, int code) {
    //rewind(f);
    Livre livre;
    while(fread(&livre, sizeof(Livre), 1, f))
    {
        if(livre.code == code)
        {
            printf("title: %s\n", livre. title);
            printf("nAuteur: %s\n", livre. nAuteur);
            printf("specialite: %s\n", livre. specialite);
            printf("annee: %d\n", livre. annee);
        }
    }
    printf("The book dosn't exist!");
}
void afficher(File *f, char* motcle)
{
    Livre livre;
    frewind(f);
    while(fread(&livre, sizeof(Livre), 1, f))
    {
        if(strcmp(livre.title, motcle) == NULL)
        {
            printf("title: %s\n", livre. title);
            printf("nAuteur: %s\n", livre. nAuteur);
            printf("specialite: %s\n", livre. specialite);
            printf("annee: %d\n", livre. annee);
        }
}

void supprimer(FILE *f, int code)
{
    FILE *temp;

}
int main()
{
    File *file;
    char[50] name;
    Livre jombo;
    int code;

    printf("Name of the file");
    scanf("%s", name);
    initialiserFichier (file, name)

    ajouter(file, &jombo);

    printf("The code?");
    scanf("%d", &code);
    chercher(file, code);
}
