package ex2;

public class Main {
    
    public static void main(String[] args) {
        Etudiant moh = new Etudiant(1111, "Moh", "bel", "etud1@gmail.com", "11-16-2004");
        Etudiant kadour = new Etudiant(2222, "kadour", "bel", "etud2@gmail.com", "11-16-2004");
        Etudiant ja3fer = new Etudiant(3333, "ja3fer", "bel", "etud3@gmail.com", "11-16-2004");

        try{
        	moh.notes.add(new Module("BDD", 4, 10, 10, 10));
	        moh.notes.add(new Module("poo", 4, 10, 10, 10));
	        moh.notes.add(new Module("RI", 4, 10, 10, 10));
	        
	        kadour.notes.add(new Module("BDD", 3, 9, 13, 14));
	        kadour.notes.add(new Module("poo", 5, 14, 13, 15));
	        
	        ja3fer.notes.add(new Module("BDD", 5, 14, 14, 14));
	        ja3fer.notes.add(new Module("poo", 11, 14, 14, 14));
        } catch(InvalidNoteException e){
        	e.printStackTrace();
        }
        
        Group G1 = new Group("G1");
        G1.ajouterEtudiant(moh);
        G1.ajouterEtudiant(ja3fer);
        G1.ajouterEtudiant(kadour);
        
        G1.supprimerEtudiant(kadour);
        
        G1.listerEtudiants();   
    }
    
}


//package ex2;
//
//public class Main {
//    
//    public static void main(String[] args) {
//        Etudiant moh = new Etudiant(1111, "Moh", "bel", "etud1@gmail.com", "11-16-2004");
//        Etudiant kadour = new Etudiant(2222, "kadour", "bel", "etud2@gmail.com", "11-16-2004");
//        Etudiant ja3fer = new Etudiant(3333, "ja3fer", "bel", "etud3@gmail.com", "11-16-2004");
//
//        try{
//        	moh.notes.add(new Module("BDD", 4, 10, 10, 10));
//        } catch(InvalidNoteException e){
//        	e.printStackTrace();
//        }
//        try {
//			moh.notes.add(new Module("poo", 4, 10, 10, 10));
//		} catch (InvalidNoteException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//        try {
//			moh.notes.add(new Module("RI", 4, 10, 10, 10));
//		} catch (InvalidNoteException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//
//        try {
//			kadour.notes.add(new Module("BDD", 3, 9, 13, 14));
//		} catch (InvalidNoteException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//        try {
//			kadour.notes.add(new Module("poo", 5, 14, 13, 15));
//		} catch (InvalidNoteException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//
//        try {
//			ja3fer.notes.add(new Module("BDD", 5, 14, 14, 14));
//		} catch (InvalidNoteException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//        try {
//			ja3fer.notes.add(new Module("poo", 11, 14, 14, 14));
//		} catch (InvalidNoteException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//
//        Group G1 = new Group("G1");
//        G1.ajouterEtudiant(moh);
//        G1.ajouterEtudiant(ja3fer);
//        G1.ajouterEtudiant(kadour);
//        
//        G1.supprimerEtudiant(kadour);
//        
//        G1.listerEtudiants();   
//    }
//    
//}