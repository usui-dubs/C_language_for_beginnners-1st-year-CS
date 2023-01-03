#include<stdio.h>
main(){
	float ve,vs;
	int s;
	char u;
	printf("\n\t\t\t\t\tBonjour et bienvenu a ce convertisseur d'unite!\n");
	printf("Veuillez choisir l'unite en tapant:\n ==> 'D' pour Devise\n ==> 'T' pour Température\n ==> 'M' pour Masse\n ==> 'L' pour Longueur\n ==> 'V' pour Vitesse.\n");
	scanf("%c",&u);
	if (u == 'D'){
		printf("Veuillez choisir le sens de la converion en tapant:\n ==> 1 pour DA => USD\n ==> 2 pour USD => DA\n");
		scanf("%d",&s);
		if (s == 1){
			printf("Tapez la valeur en DA\n ");
			scanf("%f",&ve);
			vs = ve * 0.0071;
			printf("%.3f DA = %.3f USD",ve,vs);
		}
		else if (s == 2){
			printf("Tapez la valeur en USD\n ");
			scanf("%f",&ve);
			vs = ve * 140.58;
			printf("%.3f USD = %.3f DA",ve,vs);
		}
		else{
		printf("Nombre non compatible avec les choix ci-dessus");
		}
	}
	else if (u == 'T'){
		printf("Veuillez choisir le sens de la converion en tapant:\n ==> 1 pour Celsius => Fahrenheit\n ==> 2 pour Fahrenheit => Celsius\n");
		scanf("%d",&s);
		if (s == 1){
			printf("Tapez la valeur en degre Celsius\n ");
			scanf("%f",&ve);
			vs =  (ve * 2)+30 ;
			printf("%.3f degre Celsius = %.3f degre Fahrenheit",ve,vs);
			
		}
		else if (s == 2){
			printf("Tapez la valeur en degre Fahrenheit\n ");
			scanf("%f",&ve);
			vs = (ve-30)/2;
			printf("%.3f degre Fahrenheit = %.3f degre Celsius",ve,vs);
		}
		else{
		printf("Nombre non compatible avec les choix ci-dessus");
		}
	}
	else if (u == 'M'){
		printf("Veuillez choisir le sens de la converion en tapant:\n ==> 1 pour Gramme => Pound\n ==> 2 pour Pound => Gramme\n");
		scanf("%d",&s);
		if (s == 1){
			printf("Tapez la valeur en Gramme \n");
			scanf("%f",&ve);
			vs = ve / 453.592 ;
			printf("%.3f Gramme = %.3f Pound",ve,vs);
		}
		else if (s == 2){
			printf("Tapez la valeur en Pound\n ");
			scanf("%f",&ve);
			vs = ve * 453.592;
			printf("%.3f Pound = %.3f Gramme",ve,vs);
		}
		else{
		printf("Nombre non compatible avec les choix ci-dessus");
		}
	}
	else if (u == 'L'){
		printf("Veuillez choisir le sens de la converion en tapant:\n ==> 1 pour Kilometre => Metre\n ==> 2 pour Metre => Kilometre\n");
		scanf("%d",&s);
		if (s == 1){
			printf("Tapez la valeur en Kilometre\n ");
			scanf("%f",&ve);
			vs = ve * 1000 ;
			printf("%.3f Kilometre = %.3f Metre",ve,vs);
		}
		else if (s == 2){
			printf("Tapez la valeur en Metre\n ");
			scanf("%f",&ve);
			vs = ve / 1000 ;
			printf("%.3f Metre = %.3f Kilometre",ve,vs);
		}
		else{
		printf("Nombre non compatible avec les choix ci-dessus");
		}
	}
	else if (u == 'V'){
		printf("Veuillez choisir le sens de la converion en tapant:\n ==> 1 pour Metre par seconde => Noeud\n ==> 2 pour Noeud => Metre par seconde\n");
		scanf("%d",&s);
		if (s == 1){
			printf("Tapez la valeur en Metre par seconde \n");
			scanf("%f",&ve);
			vs = ve * 1.944;
			printf("%.3f Metre par seconde = %.3f Noeud",ve,vs);
		}
		else if (s == 2){
			printf("Tapez la valeur en Noeud\n ");
			scanf("%f",&ve);
			vs = ve / 1.944;
			printf("%.3f Noeud = %.3f Metre par seconde",ve,vs);
		}
		else{
		printf("Nombre non compatible avec les choix ci-dessus");
		}
	}
	else if (u == 'd' || u == 't' || u == 'm' || u == 'l' || u == 'v'){
		printf("Les lettres minuscules sont refusees");
	}
	else{
		printf("Lettre non compatible avec les choix ci-dessus");
	}
}

