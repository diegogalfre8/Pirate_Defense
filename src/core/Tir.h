/**
 * @file tir.h
 * @brief module qui gère un tir
 */


#ifndef TIR_H
#define TIR_H
#include "Vecteur.h"
#include "Personnage.h"
#include "Ennemis.h"

/**
 * @brief Représente un tir dans le jeu, caractérisé par sa position et sa direction.
 */

class Tir
{
private:
        Vecteur position; 
        Vecteur direction; 
       
public:
        Tir();
        bool tire;
        
    /**
     * @brief Constructeur de la classe Tir.
     * @param P Personnage à partir duquel le tir est effectué.
     * @param E Ennemi sur lequel le tir est dirigé.
     */
        Tir(float x,float y);
        void tirVersEnnemi(float x,float y,float dt);
        ~Tir();

        /**
     * @brief Obtient la position du tir.
     * @return La position du tir.
     */
   
      float getPosition_X();
      float getPosition_Y();
      void setPosition_X(float x);
      void setPosition_Y(float y);

      void setDirection_X(float x);
      void setDirection_Y(float y);

        /**
     * @brief Obtient la direction du tir.
     * @return La direction du tir.
     */
        Vecteur getDirection();
};
#endif