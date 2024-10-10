package tp3_ex2;
import java.time.LocalDate;
public class Main {

	public static void main(String[] args) {
	    Employe Ali = new Ouvrier("0001", "Ali", "Omar", LocalDate.of(2001, 03, 11), LocalDate.of(2019, 05, 04));
	    Ouvrier Taleb = new Ouvrier("0002", "Taleb", "Yacin", LocalDate.of(2001, 03, 11), LocalDate.of(2021, 03, 11));
	    Ouvrier Charef = new Ouvrier("0003", "Charif", "Nadia", LocalDate.of(2001, 03, 11), LocalDate.of(2000, 03, 11));
	    Cadre Kameli = new Cadre("0004", "Kamli", "Omar", LocalDate.of(2001, 03, 11), 3);
	    Patron Benali = new Patron("0005", "Benali", "Omar", LocalDate.of(2001, 03, 11), 20.0);
	    
	    System.out.println(Ali);
	    System.out.println(Taleb);
	    System.out.println(Charef);
	    System.out.println(Kameli);
	    System.out.println(Benali);
	}

}
