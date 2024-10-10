package linked_list;

public class LinkedStack<T>{
private class Node<T>{
    T e;
    Node next;
    public Node(T elem)
    {
        this.e = elem;
        this.next = null;
    }
}
    int size;//ida bghit thsbh
    Node head;
    
    public LinkedStack(){
        this.head = null;
        this.size = 0;
    }
    public boolean isEmpty(){
        return head == null;
    }
    
    public boolean push(T element){
        Node newNode = new Node(element);
        newNode.next = head;
        head = newNode;
        size++;
        return true;
    }
    
    public T pop() throws EmptyStackException{
        if(isEmpty()) throw new EmptyStackException("Empty stack");
        
        T val = (T) head.e;
        Node temp = head;
        head = head.next;
        size--;
        //delete(temp); garbage colloctor
        return val;
    }
    public T peek(){
        return isEmpty() ? null: (T) head.e;
    }
}
