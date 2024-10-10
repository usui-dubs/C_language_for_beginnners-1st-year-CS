package Exo1;

public class Main {
	public static void main(String args[]) {
		StackResizable<String> p1 = new StackResizable<>(5);
		p1.addElement("0");
		p1.addElement("1");
		p1.addElement("2");
		p1.addElement("3");
		p1.addElement("4");
		p1.addElement("5");
		p1.addElement("6");
		p1.addElement("7");
		p1.afficherPile();
		System.out.println(p1.toString());
	}
}
