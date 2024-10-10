package ex2;

public class Module {
	private String nom;
	private double coef;
	private double test;
	private double exam;
	private double tp;
	
	public Module(String nom, double coef, double test, double exam, double tp) throws InvalidNoteException {
		if(coef < 0 || coef > 10 || test > 20 || test < 0 || exam > 20 || exam < 0 || tp > 20 || tp < 0) {
			throw new InvalidNoteException("uncorrect Note");	
		}
		this.nom = nom;
		this.coef = coef;
		this.test = test;
		this.exam = exam;
		this.tp = tp;
	}
	public String getNom() {
		return nom;
	}
	public void setNom(String nom) {
		this.nom = nom;
	}
	public double getCoef() {
		return coef;
	}
	public void setCoef(double coef) {
		this.coef = coef;
	}
	public double getTest() {
		return test;
	}
	public void setTest(double test) {
		this.test = test;
	}
	public double getExam() {
		return exam;
	}
	public void setExam(double exam) {
		this.exam = exam;
	}
	public double getTp() {
		return tp;
	}
	public void setTp(double tp) {
		this.tp = tp;
	}
	
	public double calculerCC()
	{
		return (test + tp) / 2;
	}
	
	public double calculerMoyenneModule(){
		double cc = calculerCC();
		return (cc * 0.4 + exam * 0.6) * coef;
	}
	@Override
	public String toString() {
		return "\n\tModule [nom=" + nom + ", coef=" + coef + ", test=" + test + ", exam=" + exam + ", tp=" + tp + "]";
	}
	
	
}
