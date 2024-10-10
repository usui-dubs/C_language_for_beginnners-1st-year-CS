#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct livre{
	int isbn;
	char auteur[100];
	char titre[50];
	char filiere [50];
} livre;

/* void trier ( FILE *f) {
        livre l1 ;
        char Max[20] ;

        while (!feof(f)){
            fscanf (f," %s ", l1.titre);




        }


}*/

int chercher( int isbn ){
	int k;
	struct livre l;
	FILE *f=fopen("Bibo.txt","r");
	char b=fgetc(f);
	rewind(f);
		while(fscanf(f,"%d %s %s %s",&l.isbn,l.auteur,l.titre,l.filiere)!=EOF){


            	if(l.isbn==isbn){
            	fclose(f);
				return 1;
				}


			}
			fclose(f);
			return 0;




}

void ajouter (){
	int k;
	struct livre l1;
	FILE *f=fopen("Bibo.txt","a+");
	printf("donner moi le isbn:\n");
	scanf("%d",&l1.isbn);

if(chercher(l1.isbn)==1){

    do{
		FILE *f=fopen("Bibo.txt","a+");
	printf("donner moi autre isbn:\n");
	scanf("%d",&l1.isbn);
	rewind(f);
}while(chercher(l1.isbn)==1);
}
	printf("donner moi le nom de l auteur:\n");
	scanf("%s",l1.auteur);
	printf("donner moi le titre de livre:\n");
	scanf("%s",l1.titre);
	printf("donner moi la filiere:\n");
	scanf("%s",l1.filiere);
	  fprintf(f,"%d\n",l1.isbn);
	  fprintf(f,"%s\n",l1.auteur);
	  fprintf(f,"%s\n",l1.titre);
	  fprintf(f,"%s\n\n",l1.filiere);

	fclose(f);

}

void supp(int isbn){

   struct	livre l1;

	FILE *f=fopen("Bibo.txt","r");
	FILE *temp=fopen("temp.txt","w+");
	if (chercher(isbn)==1) {

		while(fscanf(f,"%d %s %s %s",&l1.isbn,l1.auteur,l1.titre,l1.filiere)!=EOF){
		/*fscanf(f,"%d",&l1.isbn);
		printf("L1 %d\n",l1.isbn);
		fscanf(f,"%s",l1.auteur);
		fscanf(f,"%s",l1.titre);
		fscanf(f,"%s",l1.filiere);*/


		if(l1.isbn==isbn){

		printf("we found it %d %d \n",l1.isbn,isbn);
		//if(feof(f))break;
            fscanf(f,"%d",&l1.isbn);

			fscanf(f,"%s",l1.auteur);

			fscanf(f,"%s",l1.titre);

			fscanf(f,"%s",l1.filiere);


		    //printf("L1: %d ",l1.isbn);

		}

		else {
			fprintf(temp,"%d \n",l1.isbn);

			fprintf(temp,"%s \n",l1.auteur);

			fprintf(temp,"%s \n",l1.titre);

			fprintf(temp,"%s \n",l1.filiere);
		}
			//b=fgetc(f);
	}

	} else {
		printf("le isbn %d n exist pas:",isbn);
		return ;

	}
    /*while(fscanf(f,"%d %s %s %s",&l1.isbn,l1.auteur,l1.titre,l1.filiere)!=EOF)
    {
        if(l1.isbn != isbn)
            fprintf(temp, "%d %s %s %s\n",l1.isbn,l1.auteur,l1.titre,l1.filiere);
    }
*/
	fclose(f);
	fclose(temp);
remove("Bibo.txt");
rename("temp.txt","Bibo.txt");
}
	void modifier(int isbn,int nvisbn,char auteur[20],char titre[20],char filier[20]) {

   struct	livre l1;

	FILE *f=fopen("Bibo.txt","r");
	FILE *temp=fopen("temp.txt","w+");
	if (chercher(isbn)==1) {

		while(fscanf(f,"%d %s %s %s",&l1.isbn,l1.auteur,l1.titre,l1.filiere)!=EOF){



		/*fscanf(f,"%d",&l1.isbn);
		printf("L1 %d\n",l1.isbn);
		fscanf(f,"%s",l1.auteur);
		fscanf(f,"%s",l1.titre);
		fscanf(f,"%s",l1.filiere);*/

		if(l1.isbn==isbn){

		printf("we found it %d %d \n",l1.isbn,isbn);
        l1.isbn=nvisbn;
        strcpy(l1.auteur,auteur);
        strcpy(l1.titre,titre);
        strcpy(l1.filiere,filier);
		}

			fprintf(temp,"%d \n",l1.isbn);

			fprintf(temp,"%s \n",l1.auteur);

			fprintf(temp,"%s \n",l1.titre);

			fprintf(temp,"%s \n",l1.filiere)

	}

	} else {
		printf("le isbn %d n exist pas:",isbn);
		return ;

	}
    /*while(fscanf(f,"%d %s %s %s",&l1.isbn,l1.auteur,l1.titre,l1.filiere)!=EOF)
    {
        if(l1.isbn != isbn)
            fprintf(temp, "%d %s %s %s\n",l1.isbn,l1.auteur,l1.titre,l1.filiere);
        else
            l1.isbn=nvisbn;
            strcpy(l1.auteur,auteur);
            strcpy(l1.titre,titre);
            strcpy(l1.filiere,filier);
            fprintf(temp, "%d %s %s %s\n",l1.isbn,l1.auteur,l1.titre,l1.filiere);
    }
*/
/*
or:
    while(fscanf(f,"%d %s %s %s",&l1.isbn,l1.auteur,l1.titre,l1.filiere)!=EOF)
    {
        if(l1.isbn == isbn)
        {  l1.isbn=nvisbn;
            strcpy(l1.auteur,auteur);
            strcpy(l1.titre,titre);
            strcpy(l1.filiere,filier);
         }   
            fprintf(temp, "%d %s %s %s\n",l1.isbn,l1.auteur,l1.titre,l1.filiere);
    }
*/
	fclose(f);
	fclose(temp);
remove("Bibo.txt");
rename("temp.txt","Bibo.txt");
}

void titree(char t[]){
	struct livre l;
	FILE *f=fopen("Bibo.txt","r");
	while(fscanf(f,"%d %s %s %s",&l.isbn,l.auteur,l.titre,l.filiere)!=EOF){
			if(strcmp(l.titre,t)==0){
			printf("%d %s %s %s\n",l.isbn,l.auteur,l.titre,l.filiere);
			fclose(f);
			return;
		}
	}
	printf("Livre n'existe pas");
}

void Supprimer(int isbn,struct livre l){
	struct livre l1;
	FILE *f,*g;
	f=fopen("Bibo.txt","r");
	g=fopen("temp.txt","w");
	while(fscanf(f,"%d %s %s %s",&l1.isbn,l1.auteur,l1.titre,l1.filiere)!=EOF){
		if(l1.isbn!=isbn){
			fprintf(g,"%d %s %s %s\n",l1.isbn,l1.auteur,l1.titre,l1.filiere);
		}
	//	else if(l.auteur!="") fprintf(g,"%d %s %s %s\n",l.isbn,l.auteur,l.titre,l.filiere);
	}
	fclose(f);
	fclose(g);
	remove("Bibo.txt");
	rename("temp.txt","Bibo.txt");
}
void trifichier(){
	struct livre l,l1;
	FILE *temp=fopen("temp.txt","w+");
	fclose(temp);
	FILE *f=fopen("Bibo.txt","r");
	while(!feof(f)){
		fscanf(f,"%d %s %s %s",&l.isbn,l.auteur,l.titre,l.filiere);
		while(fscanf(f,"%d %s %s %s",&l1.isbn,l1.auteur,l1.titre,l1.filiere)!=EOF){
			if(strcmp(l.titre,l1.titre)>0)l=l1;

		}
		fclose(f);
		FILE *temp=fopen("temp.txt","a");
		fprintf(temp,"%d %s %s %s",&l.isbn,l.auteur,l.titre,l.filiere);
		fclose(temp);
		Supprimer(l.isbn,l);
		f=fopen("Bibo.txt","r");
	}
	fclose(f);
	remove("Bibo.txt");
	rename("temp.txt","Bibo.txt");
}

int main(){
	int ind,isbn;
   //FILE *Bibo = fopen("Bibo.txt","w+");
   do{
   	   printf("*******Bienvenu dans notre Bibliotheque******* \n");
	   printf("pour ajouter un  livre appuyer sur   ---> 1: \n");
   	   printf("pour chercher un livre appuyer sur   ---> 2: \n");
   	   printf("pour modifier un livre appuyer sur   ---> 3: \n");
   	   printf("pour supprimer une livre appuyer sur ---> 4: \n ");
   	   printf("pour chercher le tite si exist appuyer sur ---> 5: \n ");
   	   printf("pour trier appuyer sur ---> 6: \n ");
   	   scanf("%d",&ind);
   	   switch(ind) {
   	   	case 1:
   	   		ajouter();
   	        break ;
		case 2:
		  printf("donner moi le isbn de livre que vous cherchez: ");
		  scanf("%d",&isbn);
		  if(chercher(isbn)==1) printf("Le Livre existe !!!!");
		  else printf("Le Livre n'existe pas !!!!");
		break ;
		case 3:
			int isbn,nvisbn;
			char auteur[20],titre[20],filier[20];
			printf("donner moi le isbn de livre a modifier:");
			scanf("%d",&isbn);
				printf("donner moi le nvisbn de livre :");
			scanf("%d",&nvisbn);
				printf("donner moi le titre de livre a modifier:");
			scanf("%s",titre);
				printf("donner moi l auteur de livre a modifier:");
			scanf("%s",auteur);
				printf("donner moi la filier  de livre a modifier:");
			scanf("%s",filier);
			modifier(isbn,nvisbn,auteur,titre,filier);

            break ;
   	   	case 4:
   	   	int	isbnn;
   	   		//fclose(Bibo);
   	   			printf("donner moi le isbn de livre a supprimer:\n");
	scanf("%d",&isbnn);
   	   	    supp(isbnn);


   	   	//Bibo=fopen("Bibo.txt","w+");


   	   		break;
   	   	 case 5:
   	   	 	char titr[20];
   	   	 	printf("donner moi le titre:");
   	   	 	scanf("%s",titr);
   	   	 	titree(titr);


   	   	 	break;
   	   	 case 6:
			   trifichier();
   	   	 	default:
   	   	 		break;
   	   }

   	   	printf("pour faire  autre modification appuyer sur ---> 1: \n ");
   	   	printf("pour arreter appuyer sur ---> 0: \n ");
   	   	scanf("%d",&ind);
   	   		while(ind!=0 && ind!=1){
				  printf("donner moi autre valeur entre 1 et 0:\n");
				  scanf("%d",&ind);
				  }



   }while(ind!=0);

}