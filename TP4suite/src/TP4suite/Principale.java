package TP4suite;

import java.util.Scanner;

public class Principale {
	public static void main(String[] args) {
		ServiceRH USTORH = new ServiceRH("USTO");
		Personne e1 = new Enseignant("MOUSSA", "Karim", 30, Contrat.CDI, Grade.PR);
		Personne e2 = new Enseignant("OUALI", "Majda", 37, Contrat.INTERIM, Grade.MCA);
		Personne a1 = new Administratif("BADJI", "Ahmed", 28, Contrat.CDD, Poste.SECURITE);
		Personne a2 = new Administratif("SAAD", "Khalil", 40, Contrat.CDI, Poste.LOGISTIQUE);
		Personne a3 = new Administratif("MOUAD", "Ibrahim", 50, Contrat.CDI, Poste.MAINTENANCE);
		Personne c1 = new ContactExt("OUASTI", "Halima", 30, TypeContact.CHEF);
		Personne c2 = new ContactExt("MOUSSA", "Imad", 28, TypeContact.SALARIE);
		
		USTORH.ajouter(e1);
		USTORH.ajouter(e2);
		USTORH.ajouter(a1);
		USTORH.ajouter(a2);
		USTORH.ajouter(a3);
		USTORH.ajouter(c1);
		USTORH.ajouter(c2);
		
		//System.out.println(USTORH.afficher());
		USTORH.afficher();
		Scanner clavier = new Scanner(System.in);
		
		System.out.println("donnez la personne a rechercher pour supprimer: ");
	
		String nom = clavier.nextLine();
		String prenom = clavier.nextLine();
		
		if(USTORH.recherche(nom, prenom) != null) {
			System.out.println("la personne exist dans le service");
			USTORH.supprimer(USTORH.recherche(nom, prenom));
			USTORH.afficher();
		}
		else {
			System.out.println("la personne n existe pas dans le service");
		}
		
		USTORH.trier();
		//System.out.println(USTORH.afficher());
		USTORH.afficher();
	}
}
