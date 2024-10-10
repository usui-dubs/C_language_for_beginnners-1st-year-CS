package linked_list;

public class StackResizable<T> extends Stack<T> {

	public StackResizable(int size) {
		super(size);
	}
    public boolean push(T e)
    {
        if(isFull()){
            resize();
        }
        tab[++index] = e;
        return true;
    }
    
private void resize(){
    //id dertha Object dirh hna tani
    T[] newElements = (T[]) new Object[size * 2];
    size *= 2;
    for(int i = 0; i < tab.length; i++)
    {
        newElements[i] = tab[i];
    }
    tab = newElements;
}
//System.arraycopy()
//Arrays.copy..
}