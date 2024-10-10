package TP4suite;

public class Enseignant extends Personnel {
	private Grade grade;
	public Enseignant(String nom, String prenom, int age, Contrat contrat, Grade grade) {
		super(nom, prenom, age, contrat);
		this.grade = grade;
	}
	public Grade getGrade() {
		return grade;
	}
	public void setGrade(Grade grade) {
		this.grade = grade;
	}
	public String afficher() {
		return "Enseignant [grade=" + grade + ", " + super.afficher() + "]";
	}
	
}
