package TP4suite;

public class Administratif extends Personnel {
	private Poste poste;
	public Administratif(String nom, String prenom, int age, Contrat contrat, Poste poste) {
		super(nom, prenom, age, contrat);
		this.poste = poste;
	}
	public Poste getPoste() {
		return poste;
	}
	public void setPoste(Poste poste) {
		this.poste = poste;
	}
	public String afficher() {
		return "Administratif [poste=" + poste + ", " + super.afficher() + "]";
	}
	
}
