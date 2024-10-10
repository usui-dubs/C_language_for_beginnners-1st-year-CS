package entrepriseSales;

import java.awt.Color;
import java.util.*;
import java.time.LocalDate;

public class Salle {
	private String nom;
	private String adresse;
	private double superficie;
	private int nbrPort;
	private LocalDate dateConstruction;
	private ArrayList<Decor> d =  new ArrayList<>();
	
	public Salle(String n, String a, double s, int p, LocalDate d)
	{
		nom = n;
		adresse = a;
		superficie = s;
		nbrPort = p;
		dateConstruction = d;
	}
	public String toString()
	{
		return "Salle[nom : " + nom + ", adresse : " + adresse + ", superficie : " + superficie + ", nbr fe ports : " + nbrPort
	    											+ ", en la date: " + dateConstruction + ",\nles decors : " + d.toString() + ']';
	}
	public void AjoutDecor(String c, double width, double length, Color color, Matiere m)
	{
		Decor temp = new Decor(c, width, length, color, m);
		d.add(temp);
	}
    public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public String getadresse() {
		return adresse;
	}
	public void setadresse(String adresse) {
		this.adresse = adresse;
	}
	public double getSuperficie() {
		return superficie;
	}
	public void setSuperficie(double superficie) {
		this.superficie = superficie;
	}
	public int getNbrPort() {
		return nbrPort;
	}
	public void setNbrPorte(int nbrPort) {
		this.nbrPort = nbrPort;
	}
	public LocalDate getDateConstruction() {
		return dateConstruction;
	}
	public void setDateConstruction(LocalDate dateConstruction) {
		this.dateConstruction = dateConstruction;
	}
}
