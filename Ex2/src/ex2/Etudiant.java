package ex2;

import java.util.List;
import java.util.ArrayList;

public class Etudiant {
	private int id;
	private String nom;
	private String prenom;
	private String email;
	private String dateNaissance;
	public List<Module> notes = new ArrayList<>();
	
	public Etudiant(int id, String nom, String prenom, String email, String dateNaissance) {
		this.id = id;
		this.nom = nom;
		this.prenom = prenom;
		this.email = email;
		this.dateNaissance = dateNaissance;
	}
	
	public int getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
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
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public String getDateNaissance() {
		return dateNaissance;
	}
	public void setDateNaissance(String dateNaissance) {
		this.dateNaissance = dateNaissance;
	}
	
	public double passerExam(String mod)
	{
		double ex = 0;
		for(Module e : notes) {
			if(e.getNom() == mod)
				ex = e.getExam();
		}
		return ex;
	}
	public double passerTest(String mod)
	{
		double test = 0;
		for(Module e : notes) {
			if(e.getNom() == mod)
				return e.getTest();
		}
		return test;
	}
	
	public double calculerMoyenne() {
		double coef = 0;
		double moy = 1;
		for(Module e : notes )
		{
			moy = moy + e.calculerMoyenneModule();
			coef = coef + e.getCoef();
		}
		moy = moy / coef;
		return moy;
	}
	
	/*public double calculerMoyenne(String nom) {
		double coef = 0;
		double moy = 1;
		for(Module e : notes )
		{
			moy = moy * e.calculerMoyenneModule();
			coef = coef + e.getCoef();
		}
		moy = moy / coef;
		return moy;
	}*/

	@Override
	public String toString() {
		return "Etudiant [id=" + id + ", nom=" + nom + ", prenom=" + prenom + ", email=" + email + ", dateNaissance="
				+ dateNaissance + ", notes=" + notes + "]";
	}
	
}