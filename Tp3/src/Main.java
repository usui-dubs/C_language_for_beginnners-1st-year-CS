import java.util.Date;
import java.util.List;
import java.util.ArrayList;
public class Main {

	public static void main(String[] args) {
	    /*Personne p= new Personne("amine","bel",new Date(2004-1900,3,1));
	    System.out.println(p.affiche());
	    
	    Employe moh = new Employe("moh", "Djilali", new Date(2004-1900, 3, 1), 50000.0);
	    System.out.println(moh.affiche());
	    
	    p = new Chef("dd","dddd",new Date(2004-1900,3,1),500, "service A");
	    System.out.println(p.affiche());
	    
	    Chef f = new Directeur("aaaaaa","aaaaaaaaaa",new Date(2004-1900,3,1), 500, "service b", "education");
	    System.out.println(f.affiche());*/
	    List <Personne> persons = new ArrayList<Personne>(8);
	    Personne Emp1 = new Employe("moh", "Djilali", new Date(2004-1900, 3, 1), 50000.0);
	    persons.add(Emp1);
	    Personne Emp2 = new Employe("moh", "Djilali", new Date(2004-1900, 3, 1), 50000.0);
	    persons.add(Emp2);
	    Personne Emp3 = new Employe("moh", "Djilali", new Date(2004-1900, 3, 1), 50000.0);
	    persons.add(Emp3);
	    Personne Emp4 = new Employe("moh", "Djilali", new Date(2004-1900, 3, 1), 50000.0);
	    persons.add(Emp4);
	    Personne Emp5 = new Employe("moh", "Djilali", new Date(2004-1900, 3, 1), 50000.0);
	    persons.add(Emp5);
	    Personne Chef1 = new Chef("dd","dddd",new Date(2004-1900,3,1),500, "service A");
	    persons.add(Chef1);
	    Personne Chef2 = new Chef("dd","dddd",new Date(2004-1900,3,1),500, "service A");
	    persons.add(Chef2);
	    Personne Director = new Directeur("aaaaaa","aaaaaaaaaa",new Date(2004-1900,3,1), 500, "service b", "education");
	    persons.add(Director);
	    
	    for(Personne p : persons)
	    {
	        System.out.println(p.affiche());
	    }
	    //System.out.println(persons.toString());
	    for(int i = 0; i < persons.size(); ++i)
	    {
	        if((persons.get(i) instanceof Chef) && !(persons.get(i) instanceof Directeur)) //!instanceof
	            System.out.println(persons.get(i).affiche());
	    }
	    
	        //for-each loop
	    for(Personne p : persons)
	    {
	        if((p instanceof Chef) && !(p instanceof Directeur)) //!instanceof
	            System.out.println(p.affiche());
	    }
	    
	    
	}
    
}
