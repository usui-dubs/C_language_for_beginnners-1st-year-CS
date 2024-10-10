package TP4;

public class voiture extends Vehicule{

    private String logo;
	public voiture(int annee, int prix, String logo) {
		super(annee, prix);
	    this.logo = logo;
	}
	
	public void demarrer() {
		System.out.println("La voiture a démarrer!");
	}
	
	public void accelerer() {
		System.out.println("La voiture a accelerer!");
	}
public String toString() {
		return super.toString() + ", logo:" + logo;
}
}
