#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fichierF = fopen("F.txt", "r");
    FILE *fichierG = fopen("G.txt", "w");

    if (fichierF == NULL || fichierG == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        return 1;
    }

    /*int caracterePrecedent = EOF;
    int caractereCourant;

    while ((caractereCourant = fgetc(fichierF)) != EOF) {
        if (caractereCourant != ' ' || caracterePrecedent != ' ') {
            fputc(caractereCourant, fichierG);
        }
        caracterePrecedent = caractereCourant;
    }*/
    char current, prec = ' ';
    //current = fgetc(fichierF);
    /*if(current = ' ')
    {
        prec = current;
    }*/
    while ((current = fgetc(fichierF)) != EOF)
    {
        if(!(current == ' ' && prec == ' '))
            fputc(current, fichierG);
        prec = current;
    }

    fclose(fichierF);
    fclose(fichierG);

    printf("Le fichier G a été créé avec les séquences de blancs supprimées.\n");

    return 0;
}
