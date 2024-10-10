package banc;

import java.util.Scanner;

public class Principal {
public static void main(String args[]) {
    int i = 0;
    String c;
    
    Compte[] utilList = new Compte[100];
    
	Compte util1 = new Compte("Bellatreche", "Amine", "1234", 1111, 1000);
    utilList[i] = util1;
	Compte util2 = new Compte("Belhamid", "Ajal", "azerty", 2222, 1000);
    utilList[++i] = util2;
    do{
	System.out.println("Please select the operation : ");
	System.out.println("[W] : withdraw \n[D] : deposit\n[T] : transfer \n[B] : balance \n[E] : exit");
    
        Scanner clavier = new Scanner(System.in);
	
	 c = clavier.nextLine();
    
	switch (c) {
		case "W": {
			try {
				util2.withdraw(util2, -1);
			} catch (InsufficientFundesException | InvalidAmountException e) {
				e.printStackTrace();
				//System.out.println(e.getMessage());
				//System.out.println(e);
			}
		}
		break;
	    case "d":
		case "D": {
			try {
				util1.deposit(-1);
			} catch (InvalidAmountException e) {
				e.printStackTrace();
			}
		}
		break;
		case "T": {
			System.out.println("Your ccp: ");
			long sender_ccp = clavier.nextLong();
			Compte user = Compte.recieversCcp(sender_ccp, utilList);
			
			System.out.println("Password: ");
		    String temp = clavier.nextLine();
			String pwd = clavier.nextLine();
			
			System.out.println("ccp of the reciever: ");
			long rec_cpp = clavier.nextLong();
			 temp = clavier.nextLine();
			user.transferTo(sender_ccp, 500.0, pwd, utilList, rec_cpp);
		}
		break;
		case "B" : {
			System.out.println("Your ccp: ");
			long ccp = clavier.nextLong();
			Compte user = Compte.recieversCcp(ccp, utilList);
			System.out.println("Your info: " + user);
		}
		break;
	    case "E" :
	        break;
	    
		default:
			throw new IllegalArgumentException("Unexpected value: " + c);
	}    
    } while(c != "E");
/*	System.out.println("Comte1: " + util1);
	System.out.println("Comte2: " + util2);
	
	util1.transferTo(util2, 1000.0, "1234");
	System.out.println();
    
    
	util2.transferTo(2222, 500.0, "azerty", utilList, 1111);
	System.out.println();
    
	System.out.println("Comte1: " + util1);
	System.out.println("Comte2: " + util2);
	*/
 }
}