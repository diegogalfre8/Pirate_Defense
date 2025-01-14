#ifndef MAP_H
#define MAP_H
const int DIM=20;

/**
 * @brief La classe Map représente la carte du jeu.
 */
class Map {
private:
    int dimX=DIM;
    int dimY=DIM;
public:

    /**
     * @brief La matrice représentant la carte du jeu.
     * La valeur 0 indique un espace vide et (1,2,3,4 ->droite gauche haut bas) 9 un emplacement impoosible.
     */
     int Mapp[DIM][DIM] = {
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9},
        {9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 4, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 9, 9, 9, 9, 9, 4, 9, 0, 0, 9, 1, 1, 1, 1, 1, 1, 4, 0, 0},
        {3, 0, 0, 0, 0, 9, 4, 9, 0, 0, 9, 3, 9, 9, 9, 9, 9, 4, 0, 0},
        {3, 0, 0, 0, 0, 9, 4, 9, 0, 0, 9, 3, 0, 0, 0, 0, 9, 4, 0, 0},
        {3, 0, 0, 0, 0, 9, 4, 9, 0, 0, 9, 3, 0, 0, 0, 0, 9, 4, 0, 0},
        {3, 0, 0, 0, 0, 9, 4, 9, 0, 0, 9, 3, 0, 0, 0, 9, 9, 4, 0, 0},
        {3, 0, 0, 0, 0, 9, 4, 9, 0, 0, 9, 3, 0, 0, 4, 2, 2, 2, 0, 0},
        {3, 0, 0, 0, 0, 9, 4, 9, 0, 0, 9, 3, 0, 0, 4, 9, 9, 0, 0, 0},
        {3, 0, 0, 0, 0, 9, 4, 9, 9, 9, 9, 3, 0, 0, 4, 9, 9, 0, 0, 0},
        {3, 0, 0, 0, 0, 9, 1, 1, 1, 1, 1, 3, 0, 0, 4, 9, 9, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 9, 9, 9, 9, 9, 9, 9, 0, 4, 9, 9, 0, 0, 0},
        {3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 9, 9, 9, 9, 9},
        {3, 9, 9, 9, 9, 9, 9, 9, 0, 0, 9, 9, 0, 0, 1, 1, 1, 1, 1, 1},
        {3, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 9, 9, 9, 9, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {3, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9}};


     /**
     * @brief Affiche la carte du jeu.
     * Cette méthode affiche la carte du jeu dans la console.
     */
    void afficherMap() const;

     /**
     * @brief Obtient la valeur de la cellule à la position spécifiée.
     * 
     * @param x La coordonnée X de la cellule.
     * @param y La coordonnée Y de la cellule.
     * @return La valeur de la cellule à la position spécifiée.
     */
    int getCellValue(float x, float y) const;

    /**
     * @brief Définit la valeur de la cellule à la position spécifiée.
     * 
     * @param x La coordonnée X de la cellule.
     * @param y La coordonnée Y de la cellule.
     * @param value La nouvelle valeur de la cellule.
     */
    void setCellValue(int x, int y, int value);

     /**
     * @brief Obtient la dimension X de la carte.
     * 
     * @return La dimension X de la carte.
     */
    int getDimX()const;

    
    /**
     * @brief Obtient la dimension Y de la carte.
     * 
     * @return La dimension Y de la carte.
     */
    int getDimY() const;

     /**
     * @brief Obtient la valeur de la cellule à la position spécifiée.
     * 
     * @param x La coordonnée X de la cellule.
     * @param y La coordonnée Y de la cellule.
     * @return La valeur de la cellule à la position spécifiée.
     */
    int getXYInt(const int x,const int y) const;
};

#endif
