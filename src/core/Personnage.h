/**
*@brief Module gerant un personage 
*@file Personnage.h
*/

#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H
#include "Vecteur.h"
#include "Map.h"

/**
 * @brief Énumération représentant les différents niveaux de personnage.
 */
enum niveau {niveau1=1,niveau2=2,niveau3=3,niveau4=4,niveau5=5};

/**
 * @brief Représente un personnage du jeu.
 */
class Personnage
{
private:
    niveau type;/** Niveau du personnage. */
    Vecteur position;
    
public:

    /**
     * @brief Constructeur par défaut de la classe Personnage.
     */
    Personnage();

     /**
     * @brief Constructeur de la classe Personnage.
     * @param x Position en abscisse du personnage.
     * @param y Position en ordonnée du personnage.
     * @param t Type du personnage.
     * @param n Niveau du personnage.
     */
    Personnage(float x, float y,int t,int n);
    
    /**
     * @brief Destructeur de la classe Personnage.
     */
    ~Personnage();

     /**
     * @brief Obtient la position en abscisse du personnage.
     * @return La position en abscisse du personnage.
     */
    float getPosition_X()const;

       /**
     * @brief Obtient la position en ordonnée du personnage.
     * @return La position en ordonnée du personnage.
     */
    float getPosition_Y()const;

    
    /**
     * @brief Obtient l'identifiant du personnage.
     * @return L'identifiant du personnage.
     */
    void testRegression();

     /**
     * @brief Obtient le type du personnage.
     * @return Le type du personnage.
     */
    int  getType() const;
};

#endif


