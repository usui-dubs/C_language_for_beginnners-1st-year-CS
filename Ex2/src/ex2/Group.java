package ex2;

import java.util.List;
import java.util.ArrayList;

public class Group {
	private String nomGroup;
	
	private List<Etudiant> etudiants = new ArrayList();

	public Group(String nomGroup) {
		this.nomGroup = nomGroup;
	}

	public List<Etudiant> getEtudiants() {
		return etudiants;
	}

	public void setEtudiants(List<Etudiant> etudiants) {
		this.etudiants = etudiants;
	}
	
	public void ajouterEtudiant(Etudiant e){
		etudiants.add(e);
	}
	public void supprimerEtudiant(Etudiant e){
		if (chercherEtudiant(e) == 1)
			etudiants.remove(e);
		else System.out.println("Dosn't exist");
	}
	public int chercherEtudiant(Etudiant etud) {
		for(Etudiant e : etudiants)
		{
			if(e.getId() == etud.getId())
				return 1;
		}
		return 0;
	}
    public void listerEtudiants()
    {
        for(Etudiant e : etudiants)
        {
            System.out.println(e.toString());
            System.out.println("\nMpyenne: " + e.calculerMoyenne());
        }
    }
}
