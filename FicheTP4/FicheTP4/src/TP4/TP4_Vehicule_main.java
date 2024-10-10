package TP4;

public class TP4_Vehicule_main {
	public static void main(String[] args) {
		Vehicule v = new voiture(2022, 300000, "logan");
		Vehicule c = new camion(1990, 150000, "pigaux");
		Vehicule c2 = new camion(2004, 150000, "camio");
	    Vehicule v2 = new voiture(2022, 300000, "loto");
		v.demarrer();
		c.accelerer();
	    System.out.println(c2);
	    Parking park = new Parking(3);
	    park.addVehicule(v);
	    park.addVehicule(c);
	    park.addVehicule(c2);
	    park.addVehicule(v2);
	    System.out.println(park.affiche());
	}
}
