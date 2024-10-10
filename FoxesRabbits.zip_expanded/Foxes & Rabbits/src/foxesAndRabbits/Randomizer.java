package foxesAndRabbits;

import java.util.Random;

/**
 * Assure un contrôle sur la randomisation de la simulation.
 * 
 * @author David J. Barnes et Michael Kolling
 * @version 2008.03.30
 */
public class Randomizer
{
    // La base par défaut pour contrôler la randomisation.
    private static final int SEED = 1111;
    // Un objet Random partagé, si nécessaire.
    private static final Random rand = new Random(SEED);
    // Détermine si un générateur aléatoire partagé doit être fourni.
    private static final boolean useShared = true;

    /**
     * Constructeur des objets de la classe Randomizer
     */
    public Randomizer()
    {
    }

    /**
     * Fournit un générateur aléatoire.
     * @return Un objet aléatoire.
     */
    public static Random getRandom()
    {
        if(useShared) {
            return rand;
        }
        else {
            return new Random();
        }
    }
    
    /**
     * Réinitialise la randomisation.
     * Ceci n'aura aucun effet si la randomisation ne passe pas par
     * un générateur Random partagé.
     */
    public static void reset()
    {
        if(useShared) {
            rand.setSeed(SEED);
        }
    }
}
