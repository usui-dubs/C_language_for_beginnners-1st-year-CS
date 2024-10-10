package entrepriseSales;

import java.util.*;
import java.awt.Color;
import java.time.LocalDate;
import java.util.Scanner;
//import java.ColorUtil.*;
/*
import java.time.LocalDateTime; // Import the LocalDateTime class
import java.time.format.DateTimeFormatter; // Import the DateTimeFormatter class
*/
public class Main_entreprise {
	public static void main(String[] args )
	{
		//Date dateOfConst = new Date();//date constructors are deprecated
	 /*   Calendar cal = Calendar.getInstance();
cal.set(Calendar.YEAR, 2010);
cal.set(Calendar.MONTH, Calendar.JANUARY);
cal.set(Calendar.DAY_OF_MONTH, 1);
Date dateOfConst = cal.getTime();*/
	    //LocalDate dateOfConst = LocalDate.of(2010, 11, 16);
	    /*
	    // Example 1  
        String dInStr = "2011-09-01";  
        LocalDate d1 = LocalDate.parse(dInStr);  
        System.out.println("String to LocalDate : " + d1); 
	    */
	    
	    	/*String input = clavier.nextLine();
		SimpleDateFormat Format = new SimpleDateFormat("yyyy-MM-dd");
		try {
			Date date = Format.parse(input);
		} catch (ParseException e) {	
			e.printStackTrace();
		}
		Date date = Format.parse(input);*/
	    /*
	    LocalDateTime myDateObj = LocalDateTime.now();
    System.out.println("Before formatting: " + myDateObj);
    DateTimeFormatter myFormatObj = DateTimeFormatter.ofPattern("dd-MM-yyyy HH:mm:ss");

    String formattedDate = myDateObj.format(myFormatObj);
    System.out.println("After formatting: " + formattedDate);
	    */
	    
	    Scanner clavier = new Scanner(System.in);
	    
		System.out.println("Donnez le nom de la salle: ");
		String nom = clavier.nextLine();
	    
		System.out.println("Donnez l adresse: ");
		String adresse = clavier.nextLine();
	    
		System.out.println("Donnez la superficie: ");
		double superficie = clavier.nextDouble();
	    
		System.out.println("Donnez le nombre de porte: ");
		int nbrPort = clavier.nextInt();
	clavier.nextLine(); 
	    
		System.out.println("Donnez la date(dans la format yyyy-MM-dd): ");
		String input = clavier.nextLine();
	    LocalDate dateOfConst = LocalDate.parse(input);
	    
		Salle s1 = new Salle(nom, adresse, superficie, nbrPort, dateOfConst);
	    
	    System.out.println("Donnez le code: ");
		String code = clavier.nextLine();
	    
		System.out.println("Donnez le largeur: ");
		double largeur  = clavier.nextDouble();
	    
		System.out.println("Donnez le longeur: ");
		double longeur  = clavier.nextDouble();
		clavier.nextLine(); 
	    
	    System.out.println("Donnez la couleur: ");
		String input1 = clavier.nextLine();
		//Color couleur = ColorUtil.getColorFromString(input1);
		//System.out.println("Donnez la couleur: ");
		Color couleur = Color.RED;
	    System.out.println("Choisir une matiere: ");
	    /*for(Matiere m : Matiere.values())
		{
			System.out.println(m.ordinal() + 1 + ". " + m);
		}
	    
		System.out.println("Donnez un nombre: ");
		int nbr = clavier.nextInt();
		if(nbr >= 1 && nbr <= Matiere.values().length)
		{
			Matiere matiere = Matiere.values()[nbr - 1];
		}
	    else
		{
			System.out.println("Choix Invalide, sil vous plait ecrire le matriel:");
		    String input2 = clavier.nextLine();
		    Matiere matiere = Matiere.valueOf(input2);
		}*/
		Matiere matiere = Matiere.PLASTIQUE;
	    
		s1.AjoutDecor(code, largeur, longeur, couleur, matiere);
	    
		System.out.println(s1);

	}
}
