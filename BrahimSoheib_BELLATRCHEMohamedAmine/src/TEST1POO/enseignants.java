package TEST1POO;

import java.util.ArrayList;

public class enseignants {
	private String nom;
	private String grade;
	private departement d;
	private ArrayList<String> modules = new ArrayList<>();
	public enseignants(String nom,String grade) {
	this.nom = nom;
	this.grade = grade;
	}
	public void affecterModule(String mod) {
		modules.add(mod);
	}
	public void setDepartement(departement dep) {
		d = dep;
	}
	@Override
	public String toString() {
		return "enseignants [nom=" + nom + ", grade=" + grade + ", d=" + d + ", modules=" + modules.toString() + "]";
	}
	
}
