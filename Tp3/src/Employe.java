import java.util.Date;

public class Employe extends Personne {
  private double salaire ;

public Employe(String nom, String prenom, Date dateNaissance,double salaire ) {
	super(nom, prenom, dateNaissance);
	this.salaire=salaire;
	
}

public double getSalaire() {
	return salaire;
}

public void setSalaire(double salaire) {
	this.salaire = salaire;
}

@Override	
public String affiche() {
	return super.affiche() + ", Salaire = " + salaire + ']';
}
 
}
