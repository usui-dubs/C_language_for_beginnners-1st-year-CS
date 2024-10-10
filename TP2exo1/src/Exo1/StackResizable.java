package Exo1;

public class StackResizable<T> extends Stack<T> {
	protected T[] ts;
	public StackResizable(int capacite_max) {
		super(capacite_max);
	}
	
	public void addElement(T element) {
		if(isFull() == true) {
			setCapacite_max(capacite_max++);
			ts = (T[]) new Object[capacite_max];
			for(int i = 0;i<capacite_max-1;i++) {
				ts[i] = t[i];
			}
			index++;
			ts[index] = element;
		}
			index++;
			ts[index] = element;
		
	}
}
