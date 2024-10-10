package tp3_ex2;

import java.time.LocalDate;

public class Cadre extends Employe {

	int indice;
	public Cadre(String Matricule, String Prenom, String Nom, LocalDate DateNaissance, int indice) {
		super(Matricule, Prenom, Nom, DateNaissance);
		this.indice = indice;
	}

	@Override
	protected double getSalaire() {
		switch(indice)
		{
			case 1:
				salaire = 33000.0;
		    break;
			case 2:
				salaire = 45000.0;
		    break;
			case 3:
				salaire = 67000.0;
		    break;
			case 4:
				salaire = 80000.0;
		    break;
			default:
				System.out.println("Cette indice n'est exist pas!");
		}
		return salaire;
	}

	@Override
	public String toString() {
		return "Cadre [indice=" + indice + ", getSalaire()=" + getSalaire() + ", toString()=" + super.toString() + "]";
	}
	
	
}
