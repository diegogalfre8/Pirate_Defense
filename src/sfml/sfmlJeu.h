#ifndef _SFMLJEU_H
#define _SFMLJEU_H

#include "Jeu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
using namespace sf;

/**
 * @brief Gère le jeu en utilisant la bibliothèque SFML pour l'affichage graphique.
 * Cette classe gère le jeu en utilisant la bibliothèque SFML pour l'affichage graphique.
 * Elle contient des fonctionnalités pour initialiser SFML, gérer la boucle principale du jeu
 * et afficher les éléments du jeu.
 */
class sfmlJeu
{

private:
    Jeu jeu;
    RenderWindow *m_window;

    Texture personnageTexture1;
    Texture personnageTexture2;
    Texture personnageTexture3;
    Texture personnageTexture4;

    Texture ennemiTextured;
    Texture ennemiTextureg;
    Texture ennemiTextureh;
    Texture ennemiTextureb;
    Texture backgroundTexture;
    Texture barTexture;
    Texture pieceTexture;
    Texture coeurTexture;
    Texture gameover;

    CircleShape balle1,balle2,balle3,balle4;

    //choix des perso 
    RectangleShape persoN1;
    RectangleShape persoN2;
    RectangleShape persoN3;
    RectangleShape persoN4;



    bool deplacerP1 = false;
    bool deplacerP2 = false;
    bool deplacerP3 = false;
    bool deplacerP4 = false;


   Sprite backgroundSprite;
   Sprite ennemiSprited;
   Sprite ennemiSpriteg;
   Sprite ennemiSpriteh;
   Sprite ennemiSpriteb;
   Sprite barSprite;
   Sprite pieceSprite;
   Sprite coeurSprite;
   Sprite coeurSprite2;
   Sprite gameovers;
   Sprite p1;
   Sprite p2;
   Sprite p3;
   Sprite p4;

   Sprite pm1;
   Sprite pm2;
   Sprite pm3;
   Sprite pm4;



   Text txtPiece;
   Text txtScore;
   Text txtVies;
   Text txtPrix;
   Text gameOverText;
   Font font;
   

    /*sf::Font m_font;
    sf::Text m_text;

    sf::SoundBuffer m_soundbuffer;
    sf::Sound m_sound;*/

public:
    /**
     * @brief Constructeur par défaut de la classe sfmlJeu.
     * 
     * Initialise une instance de la classe sfmlJeu en créant une fenêtre de rendu SFML.
     */
    sfmlJeu();

      /**
     * @brief Destructeur de la classe sfmlJeu.
     * 
     * Libère la mémoire allouée dynamiquement pour la fenêtre de rendu SFML.
     */
    ~sfmlJeu();

    
    /**
     * @brief Initialise les éléments SFML nécessaires pour le jeu.
     * 
     * Initialise les textures, les formes géométriques et autres éléments SFML nécessaires pour le jeu.
     */
    void sfmlInit(RenderWindow * m_window);

    
    /**
     * @brief Gère la boucle principale du jeu.
     * 
     * Cette fonction gère la boucle principale du jeu, incluant la gestion des événements SFML
     * et l'affichage des éléments du jeu à l'écran.
     */
    void sfmlBoucle(RenderWindow * m_window);

     /**
     * @brief Affiche les éléments du jeu à l'écran.
     * 
     * Cette fonction affiche les différents éléments du jeu à l'écran en utilisant la fenêtre de rendu SFML.
     */
    void sfmlAff(RenderWindow * m_window);

    /**
     * @brief Affiche le texte score, vies et pieces à l'ecran
     * 
     * Cette fonction affiche différentes variables du jeu à l'écran en utilisant la fenêtre de rendu SFML.
     */

    void AffTxt(RenderWindow * m_window);
    /**
     * @brief Afiche une bar pour choisir un personage
     * 
     */
    void AffBar(RenderWindow * m_window);

    /**
     * @brief Affiche le texte GAME OVER quand le joueur n'a plus de vies.
     * 
     */
    void afficherGameOver(RenderWindow * m_window);

    /**
     * @brief Affiche les images de pieces a l'ecran.
     * 
     */
    void dessinerPiece(float positionX, float positionY,RenderWindow * m_window);

    /**
     * @brief Affiche le prix des personnages.
     * 
     */
    void afficherPrix(float positionX, float positionY, int prix,RenderWindow * m_window);

    /**
     * @brief Affiche la balle de tir sur perso.
     * 
     */
    void dessinerTir(RenderWindow * m_window);

    /**
     * @brief Fait apparaitre le menu pause si P pressed
     * 
     */
    void afficherMenuPause(RenderWindow *m_window, bool pause);
    /**
     * @brief affiche la resistance de l ennemi a l ecran
     * 
     */
    void afficherResistanceEnnemi(RenderWindow *m_window);
};
#endif
