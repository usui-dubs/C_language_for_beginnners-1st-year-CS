package foxesAndRabbits;

import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;

/**
 * Représente une grille de positions de terrain.
 * Chaque position peut contenir exactement un animal.
 * 
 * @author David J. Barnes et Michael Kolling
 * @version 2008.03.30
 */
public class Field
{
    // Un générateur de nombres aléatoires pour fournir des emplacements aléatoires.
    private static final Random rand = Randomizer.getRandom();
    
    // La profondeur et la largeur du champ.
    private int depth, width;
    // Zone mémoire pour les animaux.
    private Object[][] field;

    /**
     * Représente un terrain de dimensions données.
     * @param depth Profondeur du terrain
     * @param width Largeur du terrain
     */
    public Field(int depth, int width)
    {
        this.depth = depth;
        this.width = width;
        field = new Object[depth][width];
    }
    
    /**
     * Vide le terrain
     */
    public void clear()
    {
        for(int row = 0; row < depth; row++) {
            for(int col = 0; col < width; col++) {
                field[row][col] = null;
            }
        }
    }
    
    /**
     * Efface l'emplacement donné.
     * @param location L'emplacement à effacer.
     */
    public void clear(Location location)
    {
        field[location.getRow()][location.getCol()] = null;
    }
    
    /**
     * Place un animal à une position donnée.
     * S'il y a déjà un animal à cette position, 
     * il sera perdu.
     * @param animal Animal à placer
     * @param row Ligne de la position.
     * @param col Colonne de la position.
     */
    public void place(Object animal, int row, int col)
    {
        place(animal, new Location(row, col));
    }
    
    /**
     * Place un animal à une position donnée.
     * S'il y a déjà un animal à cette position, 
     * il sera perdu.
     * @param animal Animal à placer
     * @param location Position du placement
     */
    public void place(Object animal, Location location)
    {
        field[location.getRow()][location.getCol()] = animal;
    }
    
    /**
     * Retourne l'animal à la position donnée s'il y en a un.
     * @param location Position dans le terrain
     * @return Un animal à cette position, null si aucun
     */
    public Object getObjectAt(Location location)
    {
        return getObjectAt(location.getRow(), location.getCol());
    }
    
    /**
     * Retourne l'animal à la position donnée s'il y en a un.
     * @param row Ligne de la position
     * @param col Colonne de la position
     * @return Un animal à cette position, null si aucun
     */
    public Object getObjectAt(int row, int col)
    {
        return field[row][col];
    }
    
    /**
     * Génère une position aléatoire adjacente à une
     * position donnée, éventuellement la même.
     * La position renvoyée sera dans des limites valables
     * du terrain.
     * @param location Position à partir de laquelle générer un aspect adjacent.
     * @return Une position valable dans la grille.
     */
    public Location randomAdjacentLocation(Location location)
    {
        List<Location> adjacent = adjacentLocations(location);
        return adjacent.get(0);
    }
    
    /**
     * Obtenir une liste mélangée des positions adjacentes libres.
     * @param location Obtenir les positions adjacentes.
     * @return Une liste des positions adjacentes libres.
     */
    public List<Location> getFreeAdjacentLocations(Location location)
    {
        List<Location> free = new LinkedList<Location>();
        List<Location> adjacent = adjacentLocations(location);
        for(Location next : adjacent) {
            if(getObjectAt(next) == null) {
                free.add(next);
            }
        }
        return free;
    }
    
    /**
     * Essaie de trouver une position adjacente à une position donnée
     * qui soit libre. S'il n'y en a pas, retourne null.
     * La position retournée est dans les limites
     * du terrain.
     * @param location Position à partir de laquelle générer un aspect adjacent.
     * @return Une position valable dans la grille.
     */
    public Location freeAdjacentLocation(Location location)
    {
        // Les positions libres disponibles.
        List<Location> free = getFreeAdjacentLocations(location);
        if(free.size() > 0) {
            return free.get(0);
        }
        else {
            return null;
        }
    }

    /**
     * Renvoie une liste mélangée de positions adjacentes à la position donnée.
     * La liste n'inclura pas la position elle-même.
     * Toutes les positions se trouvent dans la grille.
     * @param location La position à partir de laquelle générer des aspects adjacents.
     * @return Une liste des positions adjacentes à celle donnée.
     */
    public List<Location> adjacentLocations(Location location)
    {
        assert location != null : "Position null passée à adjacentLocations";
        // La liste des positions à renvoyer.
        List<Location> locations = new LinkedList<Location>();
        if(location != null) {
            int row = location.getRow();
            int col = location.getCol();
            for(int roffset = -1; roffset <= 1; roffset++) {
                int nextRow = row + roffset;
                if(nextRow >= 0 && nextRow < depth) {
                    for(int coffset = -1; coffset <= 1; coffset++) {
                        int nextCol = col + coffset;
                        // Exclure les positions non valables et la position initiale.
                        if(nextCol >= 0 && nextCol < width && (roffset != 0 || coffset != 0)) {
                            locations.add(new Location(nextRow, nextCol));
                        }
                    }
                }
            }
            
            // Mélange la liste. Plusieurs autres méthodes reposent sur le fait
            // que la liste est dans un ordre aléatoire.
            Collections.shuffle(locations, rand);
        }
        return locations;
    }

    /**
     * Renvoie la profondeur du champ.
     * @return La profondeur du champ.
     */
    public int getDepth()
    {
        return depth;
    }
    
    /**
     * Renvoie la largeur du champ.
     * @return La largeur du champ.
     */
    public int getWidth()
    {
        return width;
    }
}
