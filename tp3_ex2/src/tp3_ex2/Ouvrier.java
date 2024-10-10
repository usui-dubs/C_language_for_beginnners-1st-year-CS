package tp3_ex2;

import java.time.LocalDate;

public class Ouvrier extends Employe {

	private LocalDate AnneedEntre;
	private final double SMIG = 20000.0; 
	
	public Ouvrier(String Matricule, String Prenom, String Nom, LocalDate DateNaissance, LocalDate AnneedEntre) {
		super(Matricule, Prenom, Nom, DateNaissance);
		this.AnneedEntre = AnneedEntre;
	}

	@Override
	protected double getSalaire() {
		salaire = SMIG + (Ancienite(AnneedEntre) * 3000.0);
		if(salaire < SMIG*3)
			return salaire ;
		return 60000.0;
	}
	
	public double Ancienite(LocalDate annee)
	{
	    double a = (double) (annee.getYear());
	        double anciente = 2023 - a;
		return anciente;
	}

	@Override
	public String toString() {
		return "Ouvrier [AnneedEntre=" + AnneedEntre + ", SMIG=" + SMIG + ", getSalaire()=" + getSalaire()
				+ ", toString()=" + super.toString() + "]";
	}
	
}
