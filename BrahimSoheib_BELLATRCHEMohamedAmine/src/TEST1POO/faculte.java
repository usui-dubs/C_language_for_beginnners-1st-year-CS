package TEST1POO;

import java.util.ArrayList;

public class faculte {
	private String specialite;
	private biblio b;
    private ArrayList<departement> dep = new ArrayList<>(10);

	public String getSpecialite() {
		return specialite;
	}
	public void setSpecialite(String specialite) {
		this.specialite = specialite;
	}
	public biblio getB() {
		return b;
	}
	public void setB(biblio b) {
		this.b = b;
	}
	public ArrayList<departement> getDep() {
		return dep;
	}
	public void setDep(ArrayList<departement> dep) {
		this.dep = dep;
	}
		public faculte(String specialite,String nom) {
		this.specialite = specialite;
		b = new biblio(nom);
	}
	public departement addDepartement(String nom) {
		departement d = new departement(nom);
		dep.add(d);
	    return d;
	}
	@Override
	public String toString() {
		return "faculte [specialite=" + specialite + ", b=" + b + ", dep=" + dep.toString() + "]";
	}
	
    public departement getDep(int n)
    {
        return dep.get(n);
    }
}
