package banc;

public class Compte {
	private String Nom;
	private String Prenom;
	private String MotPass;
	private long ccp;
	private double Balance;
	
	public Compte(String Nom, String Prenom, String MotPass, long ccp, double Balance)
	{
		this.Nom = Nom;
		this.Prenom = Prenom;
		this.MotPass = MotPass;
		this.ccp = ccp;		
		this.Balance = Balance;
	}
	public String getNom(){
		return Nom;
	}
	public String getPrenom(){
		return Prenom;
	}
	public long getCcp(){
		return ccp;
	}
	public double getBalance(){
		return Balance;
	}
	public void deposit(double tran) throws InvalidAmountException
	{
		if(tran <= 0) {
			throw new InvalidAmountException(tran + " is a negative number ,you can't add a negative number into your account!!!!!!!");
		} else {
			this.Balance += tran;	
		}
	}
	public void withdraw(Compte util, double tran) throws InsufficientFundesException, InvalidAmountException //withdraw
	{ 
		if(tran > Balance) {
			throw new InsufficientFundesException(Balance + " you dont have enough money!!!!!!!");
		} 
	    else if(tran <= 0) {
			throw new InvalidAmountException(tran + " is a negative number ,you can't add a negative number into your account!!!!!!!");
		}
	    else {
			util.Balance -= tran;
		}
	}
	public void transferTo(Compte util, double tran, String Mot)
	{
		if(this.MotPass == Mot)
		{
		    if(Balance - tran >= 0)
		    {
		        this.Balance -= tran;
		        util.Balance += tran;
		        //	util.add(tran);
		    }
		    else
		        System.out.println("insufissent balance");
		}
	    else
	        System.out.println("incorrect password...");
	}
    public static Compte recieversCcp(long acc_nbr, Compte[] List)
    {
        for(int i = 0; i < 2; i++)
	    {
	        if (List[i].ccp == acc_nbr)
	            return List[i];
	    }
        return null;
    }
    
    public void transferTo(long acc_nbr, double tran, String Mot, Compte[] utilList, long reciever)
	{
		if(this.ccp == acc_nbr && this.MotPass == Mot)
		{
		    if(Balance - tran >= 0 )
		    {
		        Compte rec = recieversCcp(reciever, utilList);
		        if (rec != null)
		        {
		            this.Balance -= tran;
		            rec.Balance += tran;
		        //	rec.add(tran);
		        }
		    }
		    else
		        System.out.println("insufissent balance");
		}
	    else
	        System.out.println("incorrect password...");
	}
	public String toString()
	{
		return "{Nom: " + Nom + ", Prenom: " + Prenom + ", ccp: "  + ccp + ", Balance: " + Balance + '}';
	}
	
}
