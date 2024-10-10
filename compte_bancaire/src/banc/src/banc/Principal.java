package banc;
import java.util.Scanner;import java.util.ArrayList;

public class Principal {
public static void main(String args[]) {
    int i = 0;
    int key;
    Compte[] utilList = new Compte[100];
	Compte util1 = new Compte("Bellatreche", "Amine", "1234", 1111, 1000);
    utilList[i] = util1;
	Compte util2 = new Compte("Belhamid", "Ajal", "azerty", 2222, 1000);
    utilList[++i] = util2;
    do {
    System.out.println("what do you want to do:\n 1 --> deposit in your account.\n 2 --> withdraw from your account.\n 3 --> exit.");
    Scanner clavier = new Scanner(System.in);
    key = clavier.nextInt();
    switch (key) {
	case 1: { 
		System.out.println("how much you want to deposit into your account?: ");
		int tran = clavier.nextInt();
		try {
		util1.deposit(tran);
	} catch (InvalidAmountException e) {
		e.printStackTrace();
	}
		break;
	}
	case 2:{
		System.out.println("how much you want to withdraw from your account?: ");
		int tran = clavier.nextInt();
		try {
			util2.withdraw(util2,tran);
		} catch (InsufficientFundesException e) {
			e.printStackTrace();
			//System.out.println(e.getMessage());
			//System.out.println(e);
		} catch (InvalidAmountException e) {
			e.printStackTrace();
		}
		break;
	}
	case 3:{
		break;
	}
	default:
		throw new IllegalArgumentException("Unexpected value: " + key);
	}
    }while(key != 3);
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
