package TEST1POO;

import java.util.ArrayList;

public class University {
	private String nom;
	private String adress;
	private String site;
	private String date;
	private biblio centrale;
	private ArrayList<faculte> f = new ArrayList<>();
	public University(String nom, String adress, String site, String date,String nom1) {
		this.nom = nom;
		this.adress = adress;
		this.site = site;
		this.date = date;
		centrale = new biblio(nom);
	}
	public faculte addFaculte(String specialite,String nom) {
		faculte f1 = new faculte(specialite,nom);
		f.add(f1);
		return f1;
	}
	@Override
	public String toString() {
		return "University [nom=" + nom + ", adress=" + adress + ", site=" + site + ", date=" + date + ", centrale="
				+ centrale + ", f=" + f.toString() + "]";
	}
/*	public String afficherEnseignants() {
	    for(faculte fac : f)
	    {
	        for(int i = 0; i < 0; i++){
	            return fac.getDep(0).e.toString();
	        }
	    }
	}*/
    /*public faculte getFac(int n)
    {
        return f.get(n);
    }*/
    
}
