/**
 * @file Vecteur.h
 * @brief Module gerant un vecteur
 */
#ifndef _VECTEUR_H
#define _VECTEUR_H
#include <iostream>
using namespace std;

/**
 * @brief un vecteur est composé de cordonnées x,y: float
 *
 */
class Vecteur
{
private:
    float x, y;
public:
    /**
     * @brief Constructeur par défaut de la classe Vecteur.
     * Initialise un vecteur avec des valeurs par défaut.
     */
    Vecteur();

     /**
     * @brief Constructeur paramétré de la classe Vecteur.
     * Initialise un vecteur avec les coordonnées spécifiées.
     * 
     * @param x0 La composante X du vecteur.
     * @param y0 La composante Y du vecteur.
     */
    Vecteur(float x0,float y0);

    /**
     * @brief Destructeur de la classe Vecteur.
     * Effectue les tâches de nettoyage nécessaires lorsqu'un objet Vecteur est détruit.
     */
    ~Vecteur();

     /**
     * @brief Obtient la composante X du vecteur.
     * 
     * @return La composante X du vecteur.
     */
    float getX() const;

     /**
     * @brief Obtient la composante Y du vecteur.
     * 
     * @return La composante Y du vecteur.
     */
    float getY() const;

     /**
     * @brief Définit la composante X du vecteur.
     * 
     * @param x1 La nouvelle valeur de la composante X du vecteur.
     */
    void setX(float x1);

     /**
     * @brief Définit la composante Y du vecteur.
     * 
     * @param y1 La nouvelle valeur de la composante Y du vecteur.
     */
    void setY(float y1);
};
#endif

