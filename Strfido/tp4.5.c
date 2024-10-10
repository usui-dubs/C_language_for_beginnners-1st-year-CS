#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Etudiant {
    char nom[50];
    char prenom[50];
    int age;
    float moyenne;
};


void ajouterEtudiant() {
    FILE *fichier = fopen("FichierEtudiant.txt", "a");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    struct Etudiant etudiant;

    printf("Nom de l'etudiant : ");
    scanf("%s", etudiant.nom);

    printf("Prenom de l'etudiant : ");
    scanf("%s", etudiant.prenom);

    printf("Age de l'etudiant : ");
    scanf("%d", &etudiant.age);

    printf("Moyenne de l'etudiant : ");
    scanf("%f", &etudiant.moyenne);

    fprintf(fichier, "%s %s %d %f\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.moyenne);

    fclose(fichier);
}
void ajouterEtudiant_arrivant() {
    FILE *fichier = fopen("FichierArrivant.txt", "a");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    struct Etudiant etudiant;

    printf("Nom de l'etudiant : ");
    scanf("%s", etudiant.nom);

    printf("Prenom de l'etudiant : ");
    scanf("%s", etudiant.prenom);

    printf("Age de l'etudiant : ");
    scanf("%d", &etudiant.age);

    printf("Moyenne de l'etudiant : ");
    scanf("%f", &etudiant.moyenne);

    fprintf(fichier, "%s %s %d %f\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.moyenne);

    fclose(fichier);
}
void ajouterEtudiant_deparrant() {
    FILE *fichier = fopen("FichierDepart.txt", "a");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    struct Etudiant etudiant;

    printf("Nom de l'etudiant : ");
    scanf("%s", etudiant.nom);

    printf("Prenom de l'etudiant : ");
    scanf("%s", etudiant.prenom);

    printf("Age de l'etudiant : ");
    scanf("%d", &etudiant.age);

    printf("Moyenne de l'etudiant : ");
    scanf("%f", &etudiant.moyenne);

    fprintf(fichier, "%s %s %d %f\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.moyenne);

    fclose(fichier);
}
void afficherEtudiants() {
    FILE *fichier = fopen("FichierEtudiant.txt", "r");

    struct Etudiant etudiant;

    printf("\nListe des etudiants :\n");

    while (fscanf(fichier, "%s %s %d %f", etudiant.nom, etudiant.prenom, &etudiant.age, &etudiant.moyenne) != EOF) {
        printf("Nom: %s\n", etudiant.nom);
        printf("Prenom: %s\n", etudiant.prenom);
        printf("Age: %d\n", etudiant.age);
        printf("Moyenne: %.2f\n", etudiant.moyenne);
        printf("------------------------\n");
    }

    fclose(fichier);
}


void supprimerEtudiant() {
    FILE *fichier = fopen("FichierEtudiant.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char nom[50];
    char prenom[50];
    printf("Entrez le nom de l'etudiant a supprimer : ");
    scanf("%s", nom);
    printf("Entrez le prenom de l'etudiant a supprimer : ");
    scanf("%s", prenom);

    FILE *tempFichier = fopen("tempFichier.txt", "w");
    if (tempFichier == NULL) {
        perror("Erreur lors de la cr ation du fichier temporaire");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    struct Etudiant etudiant;

    while (fscanf(fichier, "%s %s %d %f", etudiant.nom, etudiant.prenom, &etudiant.age, &etudiant.moyenne) != EOF) {
        if (strcmp(etudiant.nom, nom) != 0 || strcmp(etudiant.prenom, prenom) != 0) {
            fprintf(tempFichier, "%s %s %d %f\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.moyenne);
        }
    }

    fclose(fichier);
    fclose(tempFichier);

    remove("FichierEtudiant.txt");
    rename("tempFichier.txt", "FichierEtudiant.txt");
}


void rechercherEtudiant() {
    FILE *fichier = fopen("FichierEtudiant.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char nom[50];
    char prenom[50];
    printf("Entrez le nom de l'etudiant a rechercher : ");
    scanf("%s", nom);
    printf("Entrez le prenom de l'etudiant a rechercher : ");
    scanf("%s", prenom);

    struct Etudiant etudiant;
    int found = 0;

    while (fscanf(fichier, "%s %s %d %f", etudiant.nom, etudiant.prenom, &etudiant.age, &etudiant.moyenne) != EOF) {
        if (strcmp(etudiant.nom, nom) == 0 && strcmp(etudiant.prenom, prenom) == 0) {
            printf("Etudiant trouve :\n");
            printf("Nom: %s\n", etudiant.nom);
            printf("Prenom: %s\n", etudiant.prenom);
            printf("Age: %d\n", etudiant.age);
            printf("Moyenne: %.2f\n", etudiant.moyenne);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Etudiant non trouve.\n");
    }

    fclose(fichier);
}


void modifierEtudiant() {
    FILE *fichier = fopen("FichierEtudiant.txt", "r");
    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    char nom[50];
    char prenom[50];

    printf("Entrez le nom de l'etudiant a modifier : ");
    scanf("%s", nom);
    printf("Entrez le prenom de l'etudiant a modifier : ");
    scanf("%s", prenom);

    FILE *tempFichier = fopen("tempFichier.txt", "w");
    if (tempFichier == NULL) {
        perror("Erreur lors de la cr ation du fichier temporaire");
        fclose(fichier);
        exit(EXIT_FAILURE);
    }

    struct Etudiant etudiant;
    int found = 0;

    while (fscanf(fichier, "%s %s %d %f", etudiant.nom, etudiant.prenom, &etudiant.age, &etudiant.moyenne) != EOF) {
        if (strcmp(etudiant.nom, nom) == 0 && strcmp(etudiant.prenom, prenom) == 0) {
            printf("Entrez le nouvel age de l'etudiant : ");
            scanf("%d", &etudiant.age);

            printf("Entrez la nouvelle moyenne de l'etudiant : ");
            scanf("%f", &etudiant.moyenne);

            found = 1;
        }

        fprintf(tempFichier, "%s %s %d %.2f\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.moyenne);
    }

    if (!found) {
        printf("Etudiant non trouve.\n");
    }

    fclose(fichier);
    fclose(tempFichier);

    remove("FichierEtudiant.txt");
    rename("tempFichier.txt", "FichierEtudiant.txt");
}
void MaJ() {
    FILE *fichierEtudiant = fopen("FichierEtudiant.txt", "r");
    FILE *fichierArrivant = fopen("FichierArrivant.txt", "r");
    FILE *fichierDepart = fopen("FichierDepart.txt", "r+");

    if (fichierEtudiant == NULL || fichierArrivant == NULL || fichierDepart == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    FILE *fichierEtudiantMaj = fopen("FichierEtudiantMaJ.txt", "w+");

    if (fichierEtudiantMaj == NULL) {
        perror("Erreur lors de la création des fichiers de mise à jour");
        fclose(fichierEtudiant);
        fclose(fichierArrivant);
        fclose(fichierDepart);
        exit(EXIT_FAILURE);
    }

    struct Etudiant etudiant;
    int found,depart_age;
    char depart_nom[50],depart_prenom[50];
    float depart_moyenne;


    while (fscanf(fichierArrivant, "%s %s %d %f", etudiant.nom, etudiant.prenom, &etudiant.age, &etudiant.moyenne) != EOF) {
        fprintf(fichierEtudiantMaj, "%s %s %d %.2f\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.moyenne);
    }


    while (fscanf(fichierEtudiant, "%s %s %d %f", etudiant.nom, etudiant.prenom, &etudiant.age, &etudiant.moyenne) != EOF) {
        found = 0;
        while ((fscanf(fichierDepart,"%s %s %d %f", depart_nom, depart_prenom, &depart_age, &depart_moyenne) )!= EOF) {
            if ((strcmp(etudiant.nom, depart_nom) == 0 )&&( strcmp(etudiant.prenom, depart_prenom) == 0)) {
                found=1;
                break;
            }
        }


        if (found==0) {
            fprintf(fichierEtudiantMaj, "%s %s %d %f\n", etudiant.nom, etudiant.prenom, etudiant.age, etudiant.moyenne);
        }
      rewind(fichierDepart);
    }

    printf("\nListe des etudiants mis a jour :\n");
    rewind(fichierEtudiantMaj);
    while (fscanf(fichierEtudiantMaj, "%s %s %d %f", etudiant.nom, etudiant.prenom, &etudiant.age, &etudiant.moyenne) != EOF) {
        printf("Nom: %s\n", etudiant.nom);
        printf("Prenom: %s\n", etudiant.prenom);
        printf("Age: %d\n", etudiant.age);
        printf("Moyenne: %.2f\n", etudiant.moyenne);
        printf("------------------------\n");
    }




    fclose(fichierEtudiant);
    fclose(fichierArrivant);
    fclose(fichierDepart);
    fclose(fichierEtudiantMaj);

    printf("Mise a jour terminee.\n");
}
int main() {
    int choix;
    FILE *fichier = fopen("FichierEtudiant.txt", "a");
    FILE *fichier_arrivant = fopen("FichierArrivant.txt", "a");
    FILE *fichier_depart = fopen("FichierDepart.txt", "a");
    if (fichier == NULL) {
        perror("Erreur lors de la cr ation du fichier");
        exit(EXIT_FAILURE);
    }
    fclose(fichier);

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un etudiant\n");
        printf("2. Afficher les etudiants\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Rechercher un etudiant\n");
        printf("5. Modifier un etudiant\n");
        printf("6. Ajouter un etudiant arrivant\n");
        printf("7. Ajouter un etudiant departant\n");
        printf("8. Mis a jour la list des etudient\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterEtudiant();
                break;
            case 2:
                afficherEtudiants();
                break;
            case 3:
                supprimerEtudiant();
                break;
            case 4:
                rechercherEtudiant();
                break;
            case 5:
                modifierEtudiant();
                break;
            case 6:
                ajouterEtudiant_arrivant();
                break;
            case 7:
                ajouterEtudiant_deparrant();
                break;
            case 8:
                MaJ();
                break;
            case 0:
                printf("Au revoir!\n");
                break;
            default:
                printf("Choix invalide\n");
        }

    } while (choix != 0);

}
