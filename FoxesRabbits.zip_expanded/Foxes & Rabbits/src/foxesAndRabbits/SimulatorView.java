package foxesAndRabbits;

import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.util.LinkedHashMap;
import java.util.Map;

/**
 * Une vue graphique de la grille de simulation.
 * Chaque position est représentée par un rectangle coloré 
 * selon son contenu. La vue utilise une couleur de fond par défaut.
 * On peut définir les couleurs pour chaque espèce par un appel à
 * la méthode setColor.
 * 
 * @author David J. Barnes et Michael Kolling
 * @version 2008.03.30
 */
public class SimulatorView extends JFrame
{
    // Couleurs pour les positions vides.
    private static final Color EMPTY_COLOR = Color.white;

    // Couleur pour les objets sans couleur définie.
    private static final Color UNKNOWN_COLOR = Color.gray;

    private final String STEP_PREFIX = "Pas : ";
    private final String POPULATION_PREFIX = "Population : ";
    private JLabel stepLabel, population;
    private FieldView fieldView;
    
    // Un objet map pour stocker les couleurs des participants à la simulation
    private Map<Class, Color> colors;
    // Un objet statistics qui calcule et mémorise des informations sur la simulation
    private FieldStats stats;

    /**
     * Crée une vue de largeur (width) et hauteur (height) données.
     * @param height La hauteur de la simulation.
     * @param width  La largeur de la simulation.
     */
    public SimulatorView(int height, int width)
    {
        stats = new FieldStats();
        colors = new LinkedHashMap<Class, Color>();

        setTitle("Simulation renards et lapins");
        stepLabel = new JLabel(STEP_PREFIX, JLabel.CENTER);
        population = new JLabel(POPULATION_PREFIX, JLabel.CENTER);
        
        setLocation(100, 50);
        
        fieldView = new FieldView(height, width);

        Container contents = getContentPane();
        contents.add(stepLabel, BorderLayout.NORTH);
        contents.add(fieldView, BorderLayout.CENTER);
        contents.add(population, BorderLayout.SOUTH);
        pack();
        setVisible(true);
    }
    
    /**
     * Définit la couleur à utiliser pour une classe donnée d'animaux.
     * @param animalClass L'objet Class de l'animal.
     * @param color La couleur à utiliser pour la classe donnée.
     */
    public void setColor(Class animalClass, Color color)
    {
        colors.put(animalClass, color);
    }

    /**
     * @return La couleur utilisée pour une classe donnée d'animaux.
     */
    private Color getColor(Class animalClass)
    {
        Color col = colors.get(animalClass);
        if(col == null) {
            // pas de couleur définie pour cette classe
            return UNKNOWN_COLOR;
        }
        else {
            return col;
        }
    }

    /**
     * Montre l'état actuel du terrain.
     * @param step Le pas de l'itération.
     * @param field Etat du terrain à représenter
     */
    public void showStatus(int step, Field field)
    {
        if(!isVisible()) {
            setVisible(true);
        }
            
        stepLabel.setText(STEP_PREFIX + step);
        stats.reset();
        
        fieldView.preparePaint();

        for(int row = 0; row < field.getDepth(); row++) {
            for(int col = 0; col < field.getWidth(); col++) {
                Object animal = field.getObjectAt(row, col);
                if(animal != null) {
                    stats.incrementCount(animal.getClass());
                    fieldView.drawMark(col, row, getColor(animal.getClass()));
                }
                else {
                    fieldView.drawMark(col, row, EMPTY_COLOR);
                }
            }
        }
        stats.countFinished();

        population.setText(POPULATION_PREFIX + stats.getPopulationDetails(field));
        fieldView.repaint();
    }

    /**
     * Détermine si la simulation doit continuer.
     * @return true Si plus d'une espèce est vivante.
     */
    public boolean isViable(Field field)
    {
        return stats.isViable(field);
    }
    
    /**
     * Fournit une vue graphique d'un terrain rectangulaire. C'est une classe
     * imbriquée (une classe définie dans une classe) qui
     * définit un composant spécifique pour l'interface utilisateur.
     * Ce composant affiche le terrain.
     * Il s'agit de code IUG assez avancé - vous pouvez l'ignorer
     * dans vos projets si vous le voulez.
     */
    private class FieldView extends JPanel
    {
        private final int GRID_VIEW_SCALING_FACTOR = 6;

        private int gridWidth, gridHeight;
        private int xScale, yScale;
        Dimension size;
        private Graphics g;
        private Image fieldImage;

        /**
         * Crée un nouveau composant FieldView.
         */
        public FieldView(int height, int width)
        {
            gridHeight = height;
            gridWidth = width;
            size = new Dimension(0, 0);
        }

        /**
         * Indique au gestionnaire d'IUG la taille que nous souhaitons avoir.
         */
        public Dimension getPreferredSize()
        {
            return new Dimension(gridWidth * GRID_VIEW_SCALING_FACTOR,
                                 gridHeight * GRID_VIEW_SCALING_FACTOR);
        }

        /**
         * Prépare un nouvel affichage. Comme le composant a pu être
         * redimensionné, recalcule le facteur d'échelle.
         */
        public void preparePaint()
        {
            if(! size.equals(getSize())) {  // si la taille a changé...
                size = getSize();
                fieldImage = fieldView.createImage(size.width, size.height);
                g = fieldImage.getGraphics();

                xScale = size.width / gridWidth;
                if(xScale < 1) {
                    xScale = GRID_VIEW_SCALING_FACTOR;
                }
                yScale = size.height / gridHeight;
                if(yScale < 1) {
                    yScale = GRID_VIEW_SCALING_FACTOR;
                }
            }
        }
        
        /**
         * Colorie une position de la grille du terrain avec une couleur donnée.
         */
        public void drawMark(int x, int y, Color color)
        {
            g.setColor(color);
            g.fillRect(x * xScale, y * yScale, xScale-1, yScale-1);
        }

        /**
         * Le composant de visualisation du terrain doit être réaffiché. Copier
         * l'image interne sur l'écran.
         */
        public void paintComponent(Graphics g)
        {
            if(fieldImage != null) {
                Dimension currentSize = getSize();
                if(size.equals(currentSize)) {
                    g.drawImage(fieldImage, 0, 0, null);
                }
                else {
                    // Redimensionne l'image précédente.
                    g.drawImage(fieldImage, 0, 0, currentSize.width, currentSize.height, null);
                }
            }
        }
    }
}
