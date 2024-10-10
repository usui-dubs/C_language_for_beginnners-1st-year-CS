package linked_list;

public class Principal {

	public static void main(String args[]) {
		
		/*Stack<Integer> pile1 = new Stack<>();
		try {
			pile1.push(Integer.valueOf(5));
			pile1.push(Integer.valueOf(55));
			pile1.push(Integer.valueOf(55));
		}
		catch(Exception e) {
			e.getStackTrace();
		}
		
		try {
			pile1.pop();
		}
		catch(Exception e) {
			e.getStackTrace();
		}
		pile1.printStack();*/

		
		Stack<String> pile1 = new Stack<>(3);
		
		try {
			pile1.push("a");
		}
		catch(fullStackException e) {
			e.getStackTrace();
		}
		try {
			pile1.push("b");

		}
		catch(Exception e) {
			e.getStackTrace();
		}
		try {
			pile1.push("c");

		}
		catch(Exception e) {
			e.getStackTrace();
		}
		try {
			pile1.push("d");

		}
		catch(fullStackException e) {
			e.getStackTrace();
		}		
		try {
			pile1.push("e");

		}
		catch(fullStackException e) {
			e.getStackTrace();
		}
		
		pile1.printStack();
	}

}
