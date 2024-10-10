import java.util.Date;

public class Directeur extends Chef {
    private String societe;

	public Directeur(String nom, String prenom, Date dateNaissance, double salaire, String service, String societe) {
		super(nom, prenom, dateNaissance, salaire, service);
		this.societe=societe;
	}

	public String getSociete() {
		return societe;
	}

	public void setSociete(String societe) {
		this.societe = societe;
	}

@Override	
public String affiche() {
	return super.affiche() + ", societe = " + societe + ']';
}
 
}
