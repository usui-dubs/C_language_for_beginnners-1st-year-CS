package tp3_ex2;

import java.time.LocalDate;

public abstract class Employe {
	private String Matricule;
	private String Nom;
	private String Prenom;
	private LocalDate DateNaissance;
	protected double salaire;
	
	public Employe(String Matricule, String Prenom, String Nom, LocalDate DateNaissance)
	{
		this.Matricule = Matricule;
		this.Nom = Nom;
		this.Prenom = Prenom;
		this.DateNaissance = DateNaissance;
	}
	
	protected abstract double getSalaire();

	@Override
	public String toString() {
		return ", Matricule=" + Matricule + ", Nom=" + Nom + ", Prenom=" + Prenom + ", DateNaissance="
				+ DateNaissance + "]";
	}
}
