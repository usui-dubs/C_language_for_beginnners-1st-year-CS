package TP4suite;

public class ContactExt extends Personne {
	private TypeContact type;
	public ContactExt(String nom, String prenom, int age, TypeContact type) {
		super(nom, prenom, age);
		this.type = type;
	}
	public TypeContact getType() {
		return type;
	}
	public void setType(TypeContact type) {
		this.type = type;
	}
	public String afficher() {
		return "ContactExt [type=" + type + ", " + super.afficher() + "]";
	}
	
}
