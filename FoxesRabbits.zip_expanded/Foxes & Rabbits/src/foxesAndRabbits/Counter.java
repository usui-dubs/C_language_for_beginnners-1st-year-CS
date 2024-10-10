package foxesAndRabbits;

import java.awt.Color;

/**
 * Compteur pour un participant à la simulation.
 * Comporte une chaîne d'identification et un compteur
 * du nombre de particpants de ce type actuellement
 * dans la simulation.
 * 
 * @author David J. Barnes et Michael Kolling
 * @version 2008.03.30
 */
public class Counter
{
    // Nom du type de ces participants
    private String name;
    // Nombre de participants de ce type
    private int count;

    /**
     * Donne un nom de type.
     * @param name  Un nom, "Fox" par exemple
     */
    public Counter(String name)
    {
        this.name = name;
        count = 0;
    }
    
    /**
     * @return Une courte description du type
     */
    public String getName()
    {
        return name;
    }

    /**
     * @return Le compte actuel pour ce type.
     */
    public int getCount()
    {
        return count;
    }

    /**
     * Incrémente le compteur de un.
     */
    public void increment()
    {
        count++;
    }
    
    /**
     * Remet le compteur à zéro.
     */
    public void reset()
    {
        count = 0;
    }
}
