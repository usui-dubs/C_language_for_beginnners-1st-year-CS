package entrepriseSales;

import java.awt.Color;

/*enum Color {
	RED,
	GREEN,
	BLUE;
}*/

public class Decor {
	private String code;
	private double largeur;
	private double longeur;
	private Color couleur;
	private Matiere matiere;
	
	public Decor(String c, double width, double length, Color color, Matiere m)
	{
		code = c;
		largeur = width;
		longeur = length;
		couleur = color;
		matiere = m;
	}
	
	public String getCode()
	{
		return code;
	}
	public double getLargeur()
	{
		return largeur;
	}
	public double getLongeur()
	{
		return longeur;
	}
	public Color getCouleur()
	{
		return couleur;
	}
	public Matiere getMatiere()
	{
		return matiere;
	}
	public void setCode(String c)
	{
		code = c;
	}
	public void setLargeur(double l)
	{
		largeur = l;
	}
	public void setLongeur(double l)
	{
		longeur = l;
	}
	public void setColor(Color c)
	{
		couleur = c;
	}
	public void setMatiere(Matiere m)
	{
		matiere = m;
	}
	public String toString()
	{
		return "Decor[code = " + code + ", largeur = " + largeur + ", longeur = " + longeur + ", couleur = " + couleur + ", matiere = " + matiere + ']';
	}
}
