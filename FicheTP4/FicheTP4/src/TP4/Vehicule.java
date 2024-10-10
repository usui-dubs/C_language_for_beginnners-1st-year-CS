package TP4;

public abstract class Vehicule {
	private static int mat = 0;
    private int matricule;
	private int annee;
	private int prix;
	
	public Vehicule(int annee, int prix) {
		this.annee = annee;
		this.prix = prix;
	//	increment();
	    mat++;
	    this.matricule = mat;
	}
	
	public int getMatricule() {
		return matricule;
	}
	public void setMatricule(int matricule) {
		this.matricule = matricule;
	}
	public int getPrix() {
		return prix;
	}
	public void setPrix(int prix) {
		this.prix = prix;
	}
	public int getAnnee() {
		return annee;
	}
	public void setAnnee(int annee) {
		this.annee = annee;
	}
	
	public void increment() {
		setMatricule(matricule + 1);
	}
	public abstract void demarrer();
	public abstract void accelerer();
	
	public String toString() {
		return getClass().getName() + "(matricule=" + matricule + ", annee=" + annee + ", prix=" + prix + ")";
	}
}
