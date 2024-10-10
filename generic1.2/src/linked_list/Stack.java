package linked_list;

import java.util.Arrays;

public class Stack <T>{
	protected int size;
	protected T[] tab;//Object[] elements;
	protected int index;

	public Stack() {
		this.index = -1;
		this.tab = (T[]) new Object[size];
	    this.size = 3;
	}
    public Stack(int size) {
		this.size = size;
        this.index = -1;
		this.tab = (T[]) new Object[size];
	}
	
	public boolean isEmpty() {
		if (index == -1)
			return true;
		return false;
	    //return index == -1;
	}
    public boolean isFull(){
        return index == size - 1;
    }
	
	public T peek() throws EmptyStackException {
		if(isEmpty()) throw new EmptyStackException("Stack is empty");
			return tab[index];
	}
	
	public boolean push(T elem) throws fullStackException{
		if(isFull()) {
			throw new fullStackException("Stack is full");
		}
		index++;
		tab[index] = elem;		//tab[++index] = elem;		
	    return true;
	}
	
	public T pop() throws EmptyStackException{
		if(index == -1) {
			throw new EmptyStackException("Stack is empty");
		}
		T val = tab[index];
		index--;
		return val;
	    /*
	    return tab[index--];
	    */
	}
	
	@Override
	public String toString() {
		return "Pile [tab=" + Arrays.toString(tab) + "]";
	}

	public void printStack() {
		for(int i = index; i >= 0; i--)
			System.out.println(tab[i]);
	}

	
}

