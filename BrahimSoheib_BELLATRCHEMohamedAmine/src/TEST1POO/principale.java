package TEST1POO;

public class principale {
	public static void main(String[] args) {
		/*University USTO = new University("usto","usto","usto.com","1999-1-12","bib centrale"); 
		faculte MI = new faculte("math info","bib math info");
		departement info = new departement("info");
		info.recruterEnseignant("djabar", "chef");
		info.recruterEnseignant("amine", "dowyen");
		USTO.addFaculte(MI.getSpecialite(),MI.getB().getNom());
		MI.addDepartement(info.getNom());
		System.out.println(USTO);
		System.out.println(MI);
		System.out.println(info);
	}*/
	    University USTO = new University("usto","usto","usto.com","1999-1-12","bib centrale");
	    faculte MI = USTO.addFaculte("math info","bib math info");//the point?
	    departement info = MI.addDepartement("info");
	    
	    enseignants amine = new enseignants("amine", "dowyen");
	    
	    info.recruterEnseignant(amine);
	    amine.setDepartement(info);
	    
	    System.out.println(amine);
	   // System.out.println("les enseignants: " + USTO.afficherEnseignants());

	   /* University USTO = new University("usto","usto","usto.com","1999-1-12","bib centrale");
	    faculte MI = USTO.addFaculte("math info","bib math info");//the point?
	    departement info = USTO.getFac(0).addDepartement("info");
	    
	    enseignants amine = new enseignants("amine", "dowyen");
	    
	    USTO.getFac(0).getDep(0).recruterEnseignant(amine);
	    amine.setDepartement(info);
	    
	    System.out.println(USTO);
	    System.out.println("les enseignants: " + USTO.afficherEnseignants());
*/
	    }
}    
