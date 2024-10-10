package Exo1;

import java.util.Arrays;

public class Stack<T> {
	protected T[] t;
	protected int  capacite_max;
	protected int index = -1;
	
	
	
	public Stack(int capacite_max) {
		this.capacite_max = capacite_max;
		this.t = (T[]) new Object[capacite_max];
	}

	public void addElement(T element) throws FullStack{
		if(isFull() == true) {
			throw new FullStack("La Pile est Full!");
		}else {
		index++;
		t[index] = element;
		}
	}
	
	public void removeElement() throws EmptyStack{
		if(isEmpty() == true) {
			throw new EmptyStack("La Pile est vide!");
		}else {
		t[index] = null;
		index--;
		}
	}
	
	public boolean isEmpty() {
		if(index == -1) {
			return true;
		}
		return false;
	}
	
	public boolean isFull() {
		if(index >= capacite_max) {
			return true;
		}else {
			return false;
		}
	}
	public T[] getT() {
		return t;
	}
	public void setT(T[] t) {
		this.t = t;
	}
	public int getCapacite_max() {
		return capacite_max;
	}
	public void setCapacite_max(int capacite_max) {
		this.capacite_max = capacite_max;
	}
	public int getIndex() {
		return index;
	}
	public void setIndex(int index) {
		this.index = index;
	}
	
	public void afficherPile() {
		for(int i = index;i>=0;i--) {
			System.out.println(t[i]);
		}
	}
	public String toString() {
		return "Pile [t=" + Arrays.toString(t) + ", capacite_max=" + capacite_max + ", index=" + index + "]";
	}
}
