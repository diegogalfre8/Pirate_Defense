/**
 * @file Jeu.h
 * @brief gère le module jeu
 */

const int NBEnnemis=5;

#ifndef _JEU_H
#define _JEU_H
#include "Personnage.h"
#include "Ennemis.h"
#include "Map.h"
#include "Arme.h"
#include <vector> 

/**
 * @brief Représente le jeu avec ses personnages, ennemis, carte, niveau, score, vies et pièces.
 */

class Jeu
{
private:
    vector<Personnage> equipage;
    Map carte;
    Ennemi ennemi;
    int niveau;
    int score;
    int vies;
    int pieces;
    Arme arme;
    vector<Arme> armes;
    

public:
     
   /**
     * @brief Constructeur par défaut de la classe Jeu.
     */
    Jeu();

    
    /**
     * @brief Destructeur de la classe Jeu.
     */
    ~Jeu();

    
    /**
     * @brief Gère les actions du joueur à partir du clavier.
     * @param c Caractère entré par le joueur.
     */
    void actionClavier(char c);
    /**
     * @brief Gère les action du joueur à partir de la souris
     * @param x coordonée du paersonage (int )
     * @param y coordonée du paersonage (int )
     * @param c choix du niveau du personnage ( touche du clavier a,z)(char)
     */

    void actionSourisP(int x,int y,char c);

     /**
     * @brief Tableau d'ennemis.
     * 
     * Cet attribut représente un tableau statique d'ennemis dans le jeu. La taille du tableau est déterminée par la constante NBEnnemis.
     * Chaque élément du tableau est un objet de type Ennemi.
     * 
     * @note Ce tableau est directement accessible depuis l'extérieur de la classe.
     */
    Ennemi ennemis[NBEnnemis];

    /**
     * @brief Retourne une copie constante de l'équipage.
     * @return Une copie constante de l'équipage.
     */
    const vector<Personnage> getConstEquipage() const;

     /**
     * @brief Retourne une référence constante à la carte du jeu.
     * @return Une référence constante à la carte du jeu.
     */
    const Ennemi* getConstEnnemis() const;

     /**
     * @brief Gère les actions automatiques du jeu.
     */
    const Ennemi& getConstEnnemi() const;

     /**
     * @brief Retourne une référence constante à la carte du jeu.
     * @return Une référence constante à la carte du jeu.
     */
    const Map & getConstMap() const;

    /**
    * @brief Récupère un vecteur constant d'armes dans le jeu. 
    * @return Un vecteur constant contenant toutes les armes dans le jeu.
    */
    const vector<Arme> getConstArmes() const;

    /**
     * @brief Gère les actions automatiques du jeu.
     */
    void actionAutomatique(float dt);

     /**
     * @brief Retourne le niveau actuel du jeu.
     * @return Le niveau actuel du jeu.
     */
    int getNiveau()const;

     /**
     * @brief Définit le niveau actuel du jeu.
     * @param n Nouveau oid modifierPositionEnnemi(int index, float newX, float newY);
};niveau du jeu.
     */
    void setNiveau(int n);

     /**
     * @brief Retourne le score actuel du joueur.
     * @return Le score actuel du joueur.
     */
    int getScore()const;

    /**
     * @brief Définit le score du jeu. 
     * @param s Le score à définir.
     */
    void setScore(int s);

     /**
     * @brief Définit le score actuel du joueur.
     * @param s Nouveau score du joueur.
     */
     /**
     * @brief Retourne le nombre de pièces collectées par le joueur.
     * @return Le nombre de pièces collectées par le joueur.
     */
    int getPieces()const;

    /**
     * @brief Définit le nombre de pièces collectées par le joueur.
     * @param p Nouveau nombre de pièces collectées par le joueur.
     */
    void setPieces(int p);

     /**
     * @brief Retourne le nombre de vies restantes du joueur.
     * @return Le nombre de vies restantes du joueur.
     */
    int getVies()const;

     /**
     * @brief Définit le nombre de vies restantes du joueur.
     * @param v Nouveau nombre de vies restantes du joueur.
     */
    void setVies(int v);

     /**
     * @brief Traite le cas où un ennemi est tué.
     * @param ennemiPtr Pointeur vers l'ennemi tué.
     */
    void ennemiTue(Ennemi* ennemiPtr);

    /**
     * @brief Initialise le tableau d'ennemis.
     */
    void initEnnemiTab();

     /**
     * @brief Retourne une référence à l'ennemi à l'indice spécifié.
     * @param i Indice de l'ennemi à récupérer.
     * @return Une référence à l'ennemi à l'indice spécifié.
     */
    Ennemi& getEnnemi(int i);

     /**
     * @brief Gère le cas où un ennemi est tué et le retire de la carte.
     * @param ennemiPtr Pointeur vers l'ennemi tué.
     * @param mapp Carte du jeu.
     */
    void tueEnnemiTab(Ennemi* ennemiPtr,Map& mapp);

    /**
     * @brief Retourne une référence à l'ennemi avec l'indice spécifié.
     * @param indice Indice de l'ennemi à récupérer.
     * @return Une référence à l'ennemi avec l'indice spécifié.
     */
    Ennemi& getEnnemiParIndice(int indice);

    /**
     * @brief Initialise les positions des ennemis dans le jeu.
    */
    void initEnnemiJeu();

    /**
    * @brief Compte le nombre de personnages d'un niveau spécifique dans l'équipage.
    * @param n Le niveau du personnage.
    * @return Le nombre de personnages du niveau spécifié dans l'équipage.
    */
    unsigned int NbPersoNiveau(int n) const;

    
    /**
     * @brief Verifie si l'ennemi arrive au bout de chemin
     * @brief si c'est le cas, le joueur perd une vie
    */
    void ennemiArrive(Ennemi* ennemi);

     void actiontir(float dt);


    void testRegression();
    bool CordonnePersonnageValide(int x,int y){
         return ( carte.getCellValue(x,y)==1 || carte.getCellValue(x+1,y)==1 || carte.getCellValue(x,y+1)==1 || x>=20 ||x<=0 || y>=20 ||y<=0 || carte.getCellValue(x,y-1)==1 ||carte.getCellValue(x-1,y)==1);
    }
    //actionClavier()
};
#endif