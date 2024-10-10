package TEST1POO;

import java.util.ArrayList;

public class departement {
	private String nom;
	public ArrayList<enseignants> e = new ArrayList<>();
	public departement(String nom) {
		this.nom = nom;
	}
/*	public enseignants recruterEnseignant(String nom,String grade) {
		enseignants e1 = new enseignants(nom, grade);
		e.add(e1);
		return e1;
	}*/
    public void recruterEnseignant(enseignants ens) {
        e.add(ens);
    }
	@Override
	public String toString() {
		return "departement [nom=" + nom + ", e=" + e.toString() + "]";
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public ArrayList<enseignants> getE() {
		return e;
	}
	public void setE(ArrayList<enseignants> e) {
		this.e = e;
	}
	public ArrayList<enseignants> getEns()
    {
        return e;
    }
}
