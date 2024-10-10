package TP4suite;

public abstract class Personnel extends Personne {
	private Contrat contrat;
	public Personnel(String nom, String prenom, int age, Contrat contrat) {
		super(nom, prenom, age);
		this.contrat = contrat;
	}
	public Contrat getContrat() {
		return contrat;
	}
	public void setContrat(Contrat contrat) {
		this.contrat = contrat;
	}
	public String afficher() {
		return "Personnel [contrat=" + contrat + ", " + super.afficher() ;
	}


	
}
