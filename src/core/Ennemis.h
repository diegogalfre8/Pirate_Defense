#ifndef _ENNEMIS_H
#define _ENNEMIS_H


#include "Map.h"
#include "Vecteur.h"
#include <iostream>
using namespace std;

/**
 * @brief La classe Ennemi représente un ennemi dans le jeu.
 */
class Ennemi {
private:
    Vecteur position;
    int lastMove;
    int res;

public:

    /**
     * @brief Constructeur par défaut de la classe Ennemi.
     * Initialise un ennemi avec des valeurs par défaut.
     */
    Ennemi();

    
    /**
     * @brief Constructeur paramétré de la classe Ennemi.
     * Initialise un ennemi avec des valeurs spécifiées.
     * 
     * @param startX La coordonnée X de départ de l'ennemi.
     * @param startY La coordonnée Y de départ de l'ennemi.
     * @param resistance La résistance de l'ennemi.
     */
    Ennemi(float startX, float startY, int resistance);

     /**
     * @brief Destructeur de la classe Ennemi.
     * Effectue les tâches de nettoyage nécessaires lorsqu'un objet Ennemi est détruit.
     */
    ~Ennemi();


    int indice;  /** L'indice de l'ennemi. */
    int nbcase; /** Le nombre de cases de l'ennemi. */
    bool arrive=true;/** Indique si l'ennemi est arrivé à sa destination. */

     /**
     * @brief Obtient la coordonnée X de la position de l'ennemi.
     * 
     * @return La coordonnée X de la position de l'ennemi.
     */
    float getPositionX() const;

    
    /**
     * @brief Obtient la coordonnée Y de la position de l'ennemi.
     * 
     * @return La coordonnée Y de la position de l'ennemi.
     */
    float getPositionY() const;

    
    /**
     * @brief Définit la position de l'ennemi.
     * 
     * @param x La coordonnée X de la nouvelle position.
     * @param y La coordonnée Y de la nouvelle position.
     */
    void setPosition(float x, float y);

     /**
     * @brief Déplace l'ennemi sur la carte.
     * 
     * @param mapp La carte sur laquelle l'ennemi se déplace.
     */
    void MoveEnnemi(const Map& mapp, float dt);

    
    /**
     * @brief Vérifie si l'ennemi est arrivé à la fin.
     * 
     * @param mapp La carte sur laquelle l'ennemi se déplace.
     */
    void arriveFin(Map& mapp);

    /**
     * @brief Remet la position précédente de l'ennemi sur la carte.
     * 
     * @param mapp La carte sur laquelle l'ennemi se déplace.
     */
    void remettreAun(Map& mapp);

     /**
     * @brief Affiche la position de l'ennemi sur la carte.
     * 
     * @param mapp La carte sur laquelle l'ennemi se déplace.
     */
    void positionEnnemi(Map& mapp);

    
    /**
     * @brief Obtient la résistance de l'ennemi.
     * 
     * @return La résistance de l'ennemi.
     */
    int getRes() const;

    
    /**
     * @brief Définit la résistance de l'ennemi.
     * 
     * @param resistance La nouvelle résistance de l'ennemi.
     */
    void setRes(int resistance);

   
    void testRegression();
};

#endif

