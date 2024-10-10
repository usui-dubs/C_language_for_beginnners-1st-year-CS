package TP4;

public class camion extends Vehicule{

    private String logo;
	public camion(int annee, int prix, String logo) {
		super(annee, prix);
	    this.logo = logo;
	}
	
	public void demarrer() {
		System.out.println("Le camion a démarrer!");
	}
	
	public void accelerer() {
		System.out.println("Le camion a accelerer!");
	}
	public String toString() {
		return super.toString() + ", logo:" + logo;
	}
}
