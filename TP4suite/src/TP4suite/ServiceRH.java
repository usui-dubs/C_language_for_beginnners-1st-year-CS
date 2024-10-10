package TP4suite;

import java.util.ArrayList;
import java.util.Collections;
public class ServiceRH {
	private String nom_univ;
	private ArrayList<Personne> personnes = new ArrayList<Personne>();
	
	public ServiceRH(String nom_univ) {
		this.nom_univ = nom_univ;
	}
	public void ajouter(Personne p) {
		personnes.add(p);
	}
	public void supprimer(Personne p) {
		personnes.remove(p);
	}
	public void typePersonne(Personne p) {
		if(p instanceof Enseignant) System.out.println("Enseignant");
		else if(p instanceof Administratif) System.out.println("Administratif");
		else if(p instanceof ContactExt) System.out.println("ContactExt");
	}
	public void afficher() {
	   // StringBuilder result = new StringBuilder("ServiceRH [nom_univ=" + nom_univ + ", personnes=\n");

	    for (Personne personne : personnes) {
	       // result.append("   ").append(personne.afficher()).append("\n");
	    	System.out.println(personne.afficher());
	    }

	    //result.append("]");

	    //return result.toString();
	    /*PS: tu peux tester les deux methods,les deux fcontionne*/
	}
	public Personne recherche(String nom, String prenom) {
		for(Personne p : personnes) {
			if(p.getNom().equals(nom) && p.getPrenom().equals(prenom)) return p;
		}
		return null;
	}
	
	public void trier() {
		Collections.sort(personnes);
	}

}
