import java.util.Date;

public class Chef extends Employe {
	private String service;

	public Chef(String nom, String prenom, Date dateNaissance, double salaire, String service) {
		super(nom, prenom, dateNaissance, salaire);
		this.service=service;
	}

	public String getService() {
		return service;
	}

	public void setService(String service) {
		this.service = service;
	}

	@Override	
	public String affiche() {
		return super.affiche() + ", service = " + service + ']';
	}
	 
}
