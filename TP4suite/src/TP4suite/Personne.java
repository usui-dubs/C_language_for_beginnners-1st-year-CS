package TP4suite;
//Bellatrache_Mohammed_Amine
//Brahim_Soheib
public abstract class Personne implements Comparable<Personne>  {
	private String nom;
	private String prenom;
	private int age;
	
	public Personne(String nom, String prenom, int age) {
		super();
		this.nom = nom;
		this.prenom = prenom;
		this.age = age;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getPrenom() {
		return prenom;
	}
	public void setPrenom(String prenom) {
		this.prenom = prenom;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public String afficher() {
		return "Personne [nom=" + nom + ", prenom=" + prenom + ", age=" + age + "]";
	}
    public int compareTo(Personne otherPerson) {
        return this.getNom().compareTo(otherPerson.getNom());
    }
}
