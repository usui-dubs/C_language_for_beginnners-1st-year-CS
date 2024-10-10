package tpArrayList;
import java.util.*;

public class Main_Etudiant {
	
	public static void main(String[] args)
	{
		ArrayList<Etudiant> Etuds = new ArrayList<>(1); //2 etud
		
	    Scanner clavier = new Scanner(System.in);
	    
	    Etudiant Amine = new Etudiant();
	    Etuds.add(Amine);
	    
	    Etudiant popo = new Etudiant();
	    Etuds.add(popo);
	    
	    for(Etudiant e : Etuds)
	    {
	        System.out.println("ajout les notes de cette etudiant : ");
	        for(int i = 1; i < 5; i++)
	        {
	            double note = clavier.nextDouble();
	            e.ajoutModule(note);
	        }
	    }
		
		for(Etudiant e : Etuds)
		{
	    System.out.println(e);
		    if(e.Passage())
		        System.out.println("PASS");
		    else 
		        System.out.println("NE PASS PAS");
		}
		
		/*for(int i = 0; i < Etuds.size(); ++i)
		{
		    Etuds.get(i).ajoutModule(10.0);
		    Etuds.get(i).ajoutModule(8.0);
		}
		for(int i = 0; i < Etuds.size(); ++i)
		{
	 System.out.println(Etuds.get(i));   
			if(Etuds.get(i).Passage())
				System.out.println("PASS");
			System.out.println("NE PASS PAS");
		}*/
	    /*Etudiant Amine = new Etudiant();
	    
	    Amine.ajoutModule(10.0);
	    Amine.ajoutModule(5);
	    Amine.ajoutModule(7);
	    Amine.ajoutModule(8);
	    Amine.ajoutModule(15);
	    Amine.ajoutModule(12);
	    Amine.ajoutModule(10);
	    Amine.ajoutModule(17);
	    
	    System.out.println(Amine);
	    
	    if(Amine.Passage())
	        System.out.println("PASS");
	    else 
	        System.out.println("NE PASS PAS");
	    */
		
	}
}
