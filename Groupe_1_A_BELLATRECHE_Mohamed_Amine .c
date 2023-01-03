//ce programme permet de calculer des Conversions d�unit�s basiques
#include<stdio.h>
main()
{
	float c1,c2; //les �l�ment de la conversion
	int conversion_type;//le sens de la conversion
	char unit;//L'unite
	printf("\n\t\t\t\t\t*******Bonjour !********\n\t\t\t\t**�a est TON convertisseur d'unite!**\n");
	printf("Veuillez choisir l'unite en tapant:\n--> 'D' pour Devise(DA-USA)\n--> 'T' pour Temp�rature(Fahrenheit-Celsius)\n--> 'M' pour Masse(Gramme-Pound)\n--> 'L' pour Longueur(Kilom�tre-M�tre)\n--> 'V' pour Vitesse(M�tre par seconde-Noeud)\n");
	scanf("%c",&unit);
  	switch (unit)
	  		{
  		case 'D' :// le chois d'unite
  			printf("Veuillez choisir le sens de la conversion en tapant:\n--> 1 pour (DA==>USA)\n==> 2 pour (USA-->DA)\n");
  			scanf ("%d",&conversion_type);//le sens de la conversion
  			if(conversion_type == 1) {//SOIT 1
  				printf("Tapez la valeur en DA:\n");
  				scanf("%f",&c1);
  				c2=c1*140.23;
  				printf("%.2f DA = %.2f USA",c1, c2);	
				  }
			else if(conversion_type == 2){	//soit 2			
				printf("Tapez la valeur en USA:\n");
  				scanf("%f",&c1);
  				c2=c1/140.23;
  				printf("%.2f USA = %.2f DA",c1, c2);
				}
			else printf("�a sens n'exist pas!!");//soit u,e qutre chose
						
			break;
		case 'T' :
			printf("Veuillez choisir le sens de la conversion en tapant:\n --> 1 pour (Celsius => Fahrenheit)\n --> 2 pour (Fahrenheit => Celsius)\n");
  			scanf ("%d",&conversion_type);
  			if(conversion_type == 1) {
  				printf("Tapez la valeur en degre Celsius:\n");
  				scanf("%f",&c1);
  				c2=(c1*9/5) + 32 ;
  				printf("%.2f degre Celsius = %.2f degre Fahrenheit",c1, c2);	
				  }
			else if(conversion_type == 2){				
				printf("Tapez la valeur en degre Fahrenheit:\n");
  				scanf("%f",&c1);
  				c2=(c1-32)*5/9;
  				printf("%.2f Fahrenheit = %.2f Celsuis",c1, c2);
				}
			else printf("�a sens n'exist pas!!");		
			break;
		case 'M' :
			printf("Veuillez choisir le sens de la conversion en tapant:\n --> 1 pour (Gramme => Pound)\n --> 2 pour (Pound => Gramme)\n");
  			scanf ("%d",&conversion_type);
  			if(conversion_type == 1) {
  				printf("Tapez la valeur en Gramme:\n");
  				scanf("%f",&c1);
  				c2=c1/453.6;
  				printf("%.2f Gramme = %.2f Pound",c1, c2);	
				  }
			else if(conversion_type == 2) {				
				printf("Tapez la valeur en Pound:\n");
  				scanf("%f",&c1);
  				c2=c1*453.6;
  				printf("%.2f Pound = %.2f Gramme",c1, c2);
				}
			else printf("�a sens n'exist pas!!");		
			break;
		case 'L' :
			printf("Veuillez choisir le sens de la conversion en tapant:\n --> 1 pour (Kilom�tre => M�tre)\n --> 2 pour (M�tre => Kilom�tre)\n");
  			scanf ("%d",&conversion_type);
  			if(conversion_type == 1) {
  				printf("Tapez la valeur en Kilom�tre\n");
  				scanf("%f",&c1);
  				c2=c1*1000;
  				printf("%.2f Kelom�tre = %.2f M�tre",c1, c2);	
				  }
			else if(conversion_type == 2) {				
				printf("Tapez la valeur en M�tre:\n");
  				scanf("%f",&c1);
  				c2=c1/1000;
  				printf("%.2f M�ter = %.2f Kilom�tre)",c1, c2);
				}
			else printf("�a sens n'exist pas!!");		
			break;
		case 'V' :
			printf("Veuillez choisir le sens de la conversion en tapant:\n --> 1 pour (M�tre par seconde => Noeud)\n --> 2 pour (Noeud => M�tre par seconde-Noeud)\n");
  			scanf ("%d",&conversion_type);
  			if(conversion_type == 1) {
  				printf("Tapez la valeur en M�tre par seconde\n");
  				scanf("%f",&c1);
  				c2=c1*1.944;
  				printf("%.2f M�tre par seconde = %.2f Noeud",c1, c2);	
				  }
			else if(conversion_type == 2) {				
				printf("Tapez la valeur en Noeud:\n");
  				scanf("%f",&c1);
  				c2=c1/1.944;
  				printf("%.2f Noeud = %.2f M�tre par seconde)",c1, c2);
				}
			else printf("�a sens n'exist pas!!");		
			break;
  		case 'd' :
  		case 't' :
  		case 'm' :
  		case 'l' :
  		case 'v' :printf("la lettre est minuscule!! la lettre doivent etre MAJUSCULE");break;
  		//quand l'utilisateur saisi un (unite) que ne correspond � aucun cas(case); ni 'D' ni 'G'...ect, on qffiche :
  		default  :printf("n'exist pas");
		  	
			}
  		main(); //�a est reccursion que r�p�te le programme chaque fois on fini l'ex�cution,je l'ai ajout� pour les cas que ne complete pas le programme.
//on peut aussi ajoute un infinit loop (while(1))

}
    