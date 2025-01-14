/**
 * @file Arme.h
 * @author CHINOUN Riadh
 * @brief module qui gère une arme 
 * 
 */
#ifndef _ARME_H
#define _ARME_H
#include <iostream>
#include <vector> 
#include "Personnage.h"
#include "Tir.h"
#include "Ennemis.h"
using namespace std;

/**
 * @brief Une arme est représentée par un type qui dépend du niveau d'un personnage, la puissance des dégâts (entier), et un tableau de balles.
 */
class Arme
{
private:
    int type;
    int degat;
    Vecteur position;
    vector<Tir> balles;
public:

    /**
     * @brief Constructeur par défaut de la classe Arme.
     * Initialise une arme avec des valeurs par défaut.
     */
    Arme();

    
    /**
     * @brief Constructeur paramétré de la classe Arme.
     * Initialise une arme en fonction du niveau du personnage.
     * 
     * @param p Le personnage pour lequel l'arme est créée.
     */
    Arme (Personnage p);

     /**
     * @brief Obtient la balle tirée par l'arme à l'indice spécifié.
     * 
     * @param i L'indice de la balle à obtenir.
     * @return La balle tirée par l'arme à l'indice spécifié.
     */
    Tir getBalle(int i)const;
    vector<Tir> getBalles()const;

     /**
     * @brief Obtient le type de l'arme.
     * 
     * @return Le type de l'arme.
     */
    int getType() ;

     /**
     * @brief Obtient la puissance des dégâts de l'arme.
     * 
     * @return La puissance des dégâts de l'arme.
     */
    int getDegat();

     /**
     * @brief Effectue un tir avec l'arme sur l'ennemi spécifié.
     * Diminue la résistance (vie) de l'ennemi en fonction des dégâts de l'arme.
     * 
     * @param ennemi L'ennemi sur lequel tirer.
     */
    void tirer(Ennemi &ennemi,float dt); 
    void tirerfluide(Ennemi &ennemi,float dt); 

     /**
     * @brief gère les balle qui sort de l'ecrant ou  (renitialise la position de la balle)
     * @param i  l'indice de la balle dans le tableau
     */
    void chargerBalle(int i);


    void testRegression();

     /**
     * @brief Destructeur de la classe Arme.
     * Effectue les tâches de nettoyage nécessaires lorsqu'un objet Arme est détruit.
     */
    ~Arme();
};


#endif