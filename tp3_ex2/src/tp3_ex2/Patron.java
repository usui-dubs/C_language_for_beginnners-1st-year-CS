package tp3_ex2;

import java.time.LocalDate;

public class Patron extends Employe {

	private final double CA = 3000000; 
	double precentage;
	public Patron(String Matricule, String Prenom, String Nom, LocalDate DateNaissance, Double precentage) {
		super(Matricule, Prenom, Nom, DateNaissance);
		this.precentage = precentage;
	}

	@Override
	protected double getSalaire() {
		// TODO Auto-generated method stub
		salaire = CA * precentage / 100;
		return salaire / 12;
	}

	@Override
	public String toString() {
		return "Patron [CA=" + CA + ", precentage=" + precentage + ", getSalaire()=" + getSalaire() + ", toString()="
				+ super.toString() + "]";
	}

}
