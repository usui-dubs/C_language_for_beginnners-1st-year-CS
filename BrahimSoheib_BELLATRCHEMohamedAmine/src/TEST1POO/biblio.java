package TEST1POO;

public class biblio {
	private String nom;
	public biblio(String nom) {
		this.nom = nom;
	}
	@Override
	public String toString() {
		return "biblio [nom=" + nom + "]";
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	
}
