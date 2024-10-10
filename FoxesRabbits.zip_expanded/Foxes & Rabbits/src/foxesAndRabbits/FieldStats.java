package foxesAndRabbits;

import java.awt.Color;
import java.util.HashMap;

/**
 * Cette classe collecte et fournit des données statistiques sur l'état
 * d'un terrain. Elle est flexible : elle crée et maintient un compteur
 * pour chaque classe d'objets présente sur le terrain.
 * 
 * @author David J. Barnes et Michael Kolling
 * @version 2008.03.30
 */
public class FieldStats
{
    // Compteurs pour chacun des types d'entités (fox, rabbit, etc.) de la simulation.
    private HashMap<Class, Counter> counters;
    // Indique si les compteurs sont à jour ou non.
    private boolean countsValid;

    /**
     * Construit un objet FieldStats.
     */
    public FieldStats()
    {
        // Définit une collection de compteurs pour chaque type
        // d'animal que l'on peut trouver.
        counters = new HashMap<Class, Counter>();
        countsValid = true;
    }

    /**
     * Obtenir les détails de ce qui se trouve sur le terrain.
     * @return Une chaîne décrivant se qui se trouve sur le terrain.
     */
    public String getPopulationDetails(Field field)
    {
        StringBuffer buffer = new StringBuffer();
        if(!countsValid) {
            generateCounts(field);
        }
        for(Class key : counters.keySet()) {
            Counter info = counters.get(key);
            buffer.append(info.getName());
            buffer.append(": ");
            buffer.append(info.getCount());
            buffer.append(' ');
        }
        return buffer.toString();
    }
    
    /**
     * Invalide l'ensemble de statistiques courant ; remet
     * tous les compteurs à zéro.
     */
    public void reset()
    {
        countsValid = false;
        for(Class key : counters.keySet()) {
            Counter count = counters.get(key);
            count.reset();
        }
    }

    /**
     * Incrémente de un le compteur d'une classe d'animaux.
     * @param animalClass La classe de l'animal à incrémenter.
     */
    public void incrementCount(Class animalClass)
    {
        Counter count = counters.get(animalClass);
        if(count == null) {
            // pas encore de compteur pour cette espèce - en créer une
            count = new Counter(animalClass.getName());
            counters.put(animalClass, count);
        }
        count.increment();
    }

    /**
     * Signale que les compteurs d'animaux sont à jour.
     */
    public void countFinished()
    {
        countsValid = true;
    }

    /**
     * Détermine si la simulation est encore "vivante",
     * c'est-à-dire si elle peut continuer.
     * @return true s'il y a plus d'une espèce vivante.
     */
    public boolean isViable(Field field)
    {
        // nombre de compteurs non nuls
        int nonZero = 0;
        if(!countsValid) {
            generateCounts(field);
        }
        for(Class key : counters.keySet()) {
            Counter info = counters.get(key);
            if(info.getCount() > 0) {
                nonZero++;
            }
        }
        return nonZero > 1;
    }
    
    /**
     * Calcule le nombre de renards (foxes) et lapins (rabbits).
     * Ces nombres ne sont pas mis à jour lors du placement des
     * animaux, mais seulement sur demande.
     * @param field Le terrain pour lequel générer les statistiques.
     */
    private void generateCounts(Field field)
    {
        reset();
        for(int row = 0; row < field.getDepth(); row++) {
            for(int col = 0; col < field.getWidth(); col++) {
                Object animal = field.getObjectAt(row, col);
                if(animal != null) {
                    incrementCount(animal.getClass());
                }
            }
        }
        countsValid = true;
    }
}
