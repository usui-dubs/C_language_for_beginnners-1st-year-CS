package tpArrayList;
import java.util.ArrayList;

public class Etudiant {
	public ArrayList<Double> notes = new ArrayList<>();
	
	public void ajoutModule( double N)
	{
		if(N >=0 && N <= 20)
			notes.add(N);
	}
	
	public boolean cherecheModule(double mod)
	{
		for(double note : notes)
		{
			if(note == mod)
				return true;
		}
			return false;
	}

	public double CalculeMoy()
	{
		double moy = 0; 
		for(double note : notes)
		{
			moy += note / notes.size(); 
		}
		return moy;
	}

	/*public double CalculeMoy()
	{
		double moy = 0;
		
		for(int i = 0; i <  notes.size(); ++i)
		{
			moy += notes.get(i) / notes.size(); 
		}
	    return moy;
	}*/
    public boolean Passage ()
    {
        return CalculeMoy() >= 10;
    }
	    public String toString()
	    {
	        return notes.toString();
	    }
	}