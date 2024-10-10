#include <stdio.h>
#include <string.h>

// Structure pour repr�senter une personne
struct Person {
    char nom[50];
};
char NOM[50];
// Proc�dure pour cr�er le fichier avec les noms des personnes
void creerFichierPersonnes(n) {
    FILE *fichier = fopen("pers.dat", "wb");

    if (fichier == NULL) {
        perror("Erreur lors de la cr�ation du fichier");
        return;
    }

    /*struct Person personnes[] = {
        {"Amine"},
        {"Bachir"},
        {"Chahid"},
        {"Dani"},
        // Ajoutez d'autres noms ici
    };*/
    
  /*  struct Person personnes[n];
    
    int i;
    for(i = 0; i < n; i++){
		printf("Donnez les noms: ");
        //fgets(personnes[i].nom, 50, stdin);
		//scanf("%s", personnes[i].nom);
        gets(personnes[i].nom);
        //scanf("%s", &personnes[i]);
	}
	
    fwrite(personnes, sizeof(struct Person), sizeof(personnes) / sizeof(struct Person), fichier); //n
    */
    
   /* struct Person personne;
    int i;
    for(i = 0; i < n; i++) {
        gets(personne.nom);
        fwrite(&personne, sizeof(struct Person), 1, fichier);
         // fprintf(fichier, "%s ", personne.nom); //must add fscanf too
     }
  */     
  int i;
  for(i = 0; i < n; i++) {
       gets(NOM);
       fwrite(NOM, sizeof(char), 50, fichier);
       }
    fclose(fichier);
}

// Proc�dure pour afficher les noms des personnes
void afficherNomsPersonnes(n) {
    FILE *fichier = fopen("pers.dat", "rb");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

   /* struct Person personne[n];

    int i;
    fread(personne , sizeof(struct Person), n, fichier);

    for(i = 0; i < n; i++){
        printf("%s\n", personne[i].nom);
    }*/

//	struct Person personne;
//    while (fread(&personne, sizeof(struct Person), 1, fichier)) {
//        printf("%s\n", personne.nom);
//    }

    while (fread(NOM, sizeof(char), 50, fichier)) {
        printf("%s\n", NOM);
      }
    fclose(fichier);
}

// Proc�dure pour afficher les noms des personnes copie
void afficherNomsPersonnesCOPIE() {
    FILE *fichier = fopen("pers_copie.dat", "rb");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }

	/*struct Person personne;
    while (fread(&personne, sizeof(struct Person), 1, fichier)) {
        printf("%s\n", personne.nom);
    }*/
    
    while (fread(NOM, sizeof(char), 50, fichier)) {
        printf("%s\n", NOM);
      }

    fclose(fichier);
}

// Fonction pour chercher un nom dans le fichier
int chercherNom(char nomRecherche[50]) {
    FILE *fichier = fopen("pers.dat", "rb");

    if (fichier == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        return 0; // Faux, car le fichier n'existe pas
    }

    /*struct Person personne;

    while (fread(&personne, sizeof(struct Person), 1, fichier)) {
        if (strcmp(personne.nom, nomRecherche) == 0) {
            fclose(fichier);
            return 1; // Vrai, le nom existe
        }
    }*/
    
    while (fread(NOM, sizeof(char), 50, fichier)) {
        if (strcmp(NOM, nomRecherche) == 0) {
            fclose(fichier);
            return 1; // Vrai, le nom existe
        }
    }
    fclose(fichier);
    return 0; // Faux, le nom n'existe pas
}

// Proc�dure pour copier les noms sans compter un nom sp�cifique
void copierNomsSansNom(char nomAExclure[50]) {
    FILE *fichierLecture = fopen("pers.dat", "rb");
    FILE *fichierCopie = fopen("pers_copie.dat", "wb");

    if (fichierLecture == NULL || fichierCopie == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        return;
    }

    /*struct Person personne;

    while (fread(&personne, sizeof(struct Person), 1, fichierLecture)) {
        if (strcmp(personne.nom, nomAExclure) != 0) {
            fwrite(&personne, sizeof(struct Person), 1, fichierCopie);
        }
    }*/
    
    while (fread(NOM, sizeof(char), 50, fichierLecture)) {
        if (strcmp(NOM, nomAExclure) != 0) {
            fwrite(NOM, sizeof(char), 50, fichierCopie);
        }
      }
      
    fclose(fichierLecture);
    fclose(fichierCopie);
}

int main() {
    int n;
    char temp;
    
    printf("Donner le nombre des nomes: ");
    scanf("%d", &n);
    scanf("%d", &temp);
    creerFichierPersonnes(n);

    printf("Noms des personnes :\n");
    afficherNomsPersonnes(n);

    //const char *nomRecherche = "Bachir";
    //char nomRecherche[50] = "Bachir";
    char nomRecherche[50];
    printf("Research an nom:");
    //scanf("%s", nomRecherche);
    gets(nomRecherche);
    if (chercherNom(nomRecherche)) {
        printf("Le nom '%s' existe dans le fichier.\n", nomRecherche);
    } else {
        printf("Le nom '%s' n'existe pas dans le fichier.\n", nomRecherche);
    }

  //  const char *nomAExclure = "Chahid";
    char nomAExclure[50];
    printf("Exclure an nom:");
    //scanf("%s", nomAExclure);
    gets(nomAExclure);
    copierNomsSansNom(nomAExclure);

    printf("Noms des personnes sans %s apr�s copie :\n", nomAExclure);
    afficherNomsPersonnesCOPIE();

    return 0;
}
