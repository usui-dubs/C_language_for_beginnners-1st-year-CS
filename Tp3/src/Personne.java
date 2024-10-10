import java.util.Date;

public class Personne {
	private String nom ,prenom;
	private Date dateNaissance;

	public Personne(String nom, String prenom, Date dateNaissance) {
		this.nom = nom;
		this.prenom = prenom;
		this.dateNaissance = dateNaissance;
	}

	public String getNom() {
		return nom;
	}

	public void setNom(String nom) {
		this.nom = nom;
	}

	public String getPrenom() {
		return prenom;
	}

	public void setPrenom(String prenom) {
		this.prenom = prenom;
	}

	public Date getDateNaissance() {
		return dateNaissance;
	}

	public void setDateNaissance(Date dateNaissance) {
		this.dateNaissance = dateNaissance;
	}


	public String affiche() {
		return getClass().getName() + " (nom=" + nom + ", prenom=" + prenom + ", dateNaissance=" + dateNaissance + ')';
	}
}
