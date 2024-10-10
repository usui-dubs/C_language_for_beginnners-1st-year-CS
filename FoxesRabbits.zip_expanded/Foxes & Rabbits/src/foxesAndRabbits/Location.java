package foxesAndRabbits;

/**
 * Représente une position dans une grille rectangulaire.
 * 
 * @author David J. Barnes et Michael Kolling
 * @version 2008.03.30
 */
public class Location
{
    // Ligne (Row) et colonne (column) de la position
    private int row;
    private int col;

    /**
     * Représente une ligne et une colonne.
     * @param row La ligne.
     * @param col La colonne.
     */
    public Location(int row, int col)
    {
        this.row = row;
        this.col = col;
    }
    
    /**
     * Implante l'égalité de contenu.
     */
    public boolean equals(Object obj)
    {
        if(obj instanceof Location) {
            Location other = (Location) obj;
            return row == other.getRow() && col == other.getCol();
        }
        else {
            return false;
        }
    }
    
    /**
     * Renvoie une chaîne ligne,colonne
     * @return Une représentation chaîne de la position.
     */
    public String toString()
    {
        return row + "," + col;
    }
    
    /**
     * Utilise les 16 bits forts pour la valeur de la ligne et les 16 bits faibles
     * pour la colonne. Fournit une clé de hachage unique pour chaque paire
     * (ligne,colonne) sauf pour de très grandes grilles.
     * @return Un code de hachage pour la position.
     */
    public int hashCode()
    {
        return (row << 16) + col;
    }
    
    /**
     * @return La ligne.
     */
    public int getRow()
    {
        return row;
    }
    
    /**
     * @return La colonne.
     */
    public int getCol()
    {
        return col;
    }
}
