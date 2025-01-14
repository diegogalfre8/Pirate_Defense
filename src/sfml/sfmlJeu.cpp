#include <cassert>
#include <time.h>
#include "sfmlJeu.h"
#include <stdlib.h>

using namespace sf;

#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 49;


sfmlJeu::sfmlJeu() : jeu()
{
}


void sfmlJeu::sfmlInit(RenderWindow *m_window)
{

    if (!backgroundTexture.loadFromFile("data/MapPirate.png")) {
        cout << "erreur de chargement du fond" << endl;
    }
   backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setScale(static_cast<float>(m_window->getSize().x-145) / backgroundTexture.getSize().x, static_cast<float>(m_window->getSize().y+40) / backgroundTexture.getSize().y);
   
   //init image ennemi droite
    if (!ennemiTextured.loadFromFile("data/ennemiboatd.png")) {
        cout << "Erreur lors du chargement de l'image de l'ennemi." << endl;
    }
    ennemiSprited.setTexture(ennemiTextured);
    ennemiSprited.setScale(90.0f / ennemiTextured.getSize().x, 80.0f / ennemiTextured.getSize().y);
    //init image ennemi gauche
    if (!ennemiTextureg.loadFromFile("data/ennemiboatg.png")) {
        cout << "Erreur lors du chargement de l'image de l'ennemi." << endl;
    }
    ennemiSpriteg.setTexture(ennemiTextureg);
    ennemiSpriteg.setScale(90.0f / ennemiTextureg.getSize().x, 80.0f / ennemiTextureg.getSize().y);
    //init image ennemi haut
    if (!ennemiTextureh.loadFromFile("data/ennemiboath.png")) {
        cout << "Erreur lors du chargement de l'image de l'ennemi." << endl;
    }
    ennemiSpriteh.setTexture(ennemiTextureh);
    ennemiSpriteh.setScale(55.0f / ennemiTextureh.getSize().x, 100.0f / ennemiTextureh.getSize().y);
    //init image ennemi bas
    if (!ennemiTextureb.loadFromFile("data/ennemiboatb.png")) {
        cout << "Erreur lors du chargement de l'image de l'ennemi." << endl;
    }
    ennemiSpriteb.setTexture(ennemiTextureb);
    ennemiSpriteb.setScale(55.0f / ennemiTextureb.getSize().x, 100.0f / ennemiTextureb.getSize().y);


     // init image perso 2
    if (!personnageTexture2.loadFromFile("data/Equipage2.gif")) {
        cerr << "Erreur lors du chargement de l'image du personnage." << endl;
    }
    p2.setTexture(personnageTexture2);
    p2.setScale(60.0f / personnageTexture2.getSize().x, 60.0f / personnageTexture2.getSize().y);

    pm2.setTexture(personnageTexture2);
    pm2.setScale(60.0f / personnageTexture2.getSize().x, 60.0f / personnageTexture2.getSize().y);

    //ini image perso1
    if (!personnageTexture1.loadFromFile("data/Equipage1.gif")) {
        cerr << "Erreur lors du chargement de l'image du personnage." << endl;
    }
    p1.setTexture(personnageTexture1);
    p1.setScale(60.0f / personnageTexture1.getSize().x, 60.0f / personnageTexture1.getSize().y);

    pm1.setTexture(personnageTexture1);
    pm1.setScale(60.0f / personnageTexture1.getSize().x, 60.0f / personnageTexture1.getSize().y);

    //ini image perso3
    if (!personnageTexture3.loadFromFile("data/Equipage3.gif")) {
        cerr << "Erreur lors du chargement de l'image du personnage." << endl;
    }
    p3.setTexture(personnageTexture3);
    p3.setScale(60.0f / personnageTexture3.getSize().x, 60.0f / personnageTexture3.getSize().y);

    pm3.setTexture(personnageTexture3);
    pm3.setScale(60.0f / personnageTexture3.getSize().x, 60.0f / personnageTexture3.getSize().y);
    
    //init image perso4
    if (!personnageTexture4.loadFromFile("data/Equipage4.gif")) {
        cerr << "Erreur lors du chargement de l'image du personnage." << endl;
    }
    p4.setTexture(personnageTexture4);
    p4.setScale(60.0f / personnageTexture4.getSize().x, 60.0f / personnageTexture4.getSize().y);
    pm4.setTexture(personnageTexture4);
    pm4.setScale(60.0f / personnageTexture4.getSize().x, 60.0f / personnageTexture4.getSize().y);

    //init police caractere
     if (!font.loadFromFile("data/pixelfont.ttf")) {
        cerr << "Erreur lors du chargement de la police de caractères" <<endl;
    }
    //init bar 
    if (!barTexture.loadFromFile("data/menupersos.jpg")) {
        cout << "erreur de chargement du menue" << endl;
    }
    barSprite.setTexture(barTexture);
    barSprite.setScale(950/ backgroundTexture.getSize().x, static_cast<float>(m_window->getSize().y) / backgroundTexture.getSize().y);

    persoN1.setFillColor(Color::Transparent);
    persoN2.setFillColor(Color::Transparent);
    persoN3.setFillColor(Color::Transparent);
    persoN4.setFillColor(Color::Transparent);

    persoN1.setSize(Vector2f(155,90));
    persoN2.setSize(Vector2f(155,90));
    persoN3.setSize(Vector2f(155,90));
    persoN4.setSize(Vector2f(155,90));

    balle1.setRadius(5);
    balle2.setRadius(5);
    balle3.setRadius(5);
    balle4.setRadius(5);

    balle1.setFillColor(Color::White);
    balle2.setFillColor(Color::Green);
    balle3.setFillColor(Color::Blue);
    balle4.setFillColor(Color::Black);

}

sfmlJeu::~sfmlJeu()
{
    if (m_window != NULL)
        delete m_window;

}

void sfmlJeu::sfmlAff(RenderWindow *m_window)
{
    m_window->clear(Color(230, 240, 255, 255));
	const vector<Personnage> equip = jeu.getConstEquipage();
	const Ennemi *ennemi=jeu.getConstEnnemis();
    const vector<Arme> armes=jeu.getConstArmes();
    Map mapp = jeu.getConstMap();

    //Affiche la map
    m_window->draw(backgroundSprite);

    //affiche ennemi
     for (int i = 0; i < NBEnnemis; i++) {
        float x = (float)(ennemi[i].getPositionX());
        float y = (float)(ennemi[i].getPositionY());
        if (x==0 && y == 0)
        {
            continue;
        }
        float xPos = (x * (jeu.getConstMap().getDimX() - 1) * TAILLE_SPRITE )/ jeu.getConstMap().getDimX(); //position en pixels
        float yPos = (y * (jeu.getConstMap().getDimY() - 1) * TAILLE_SPRITE)/ jeu.getConstMap().getDimY();
        if (x == 0 && y == 0) {

            ennemiSprited.setPosition(0, 2 * TAILLE_SPRITE+((TAILLE_SPRITE - ennemiSprited.getLocalBounds().height) / 2));
        } 
        else {
        if(mapp.getCellValue(x,y)==1)
        {
            ennemiSprited.setPosition(xPos,yPos-TAILLE_SPRITE/2);
            m_window->draw(ennemiSprited);
        }
        if(mapp.getCellValue(x,y)==2)
        {
            ennemiSpriteg.setPosition(xPos,yPos-TAILLE_SPRITE/2);
            m_window->draw(ennemiSpriteg);
        }
        if(mapp.getCellValue(x,y)==3)
        {
            ennemiSpriteh.setPosition(xPos,yPos-TAILLE_SPRITE/2);
            m_window->draw(ennemiSpriteh);
        }
        if(mapp.getCellValue(x,y)==4)
        {
            ennemiSpriteb.setPosition(xPos,yPos-TAILLE_SPRITE/2);
            m_window->draw(ennemiSpriteb);
        }
        }
    }

    // Affiche les personnages
    for (unsigned int i = 0; i < equip.size(); i++) {
        float x = (float)(equip[i].getPosition_X());
        float y = (float)(equip[i].getPosition_Y());
        float xPos = x * TAILLE_SPRITE + (TAILLE_SPRITE - p1.getLocalBounds().width) / 2;
        float yPos = y * TAILLE_SPRITE + (TAILLE_SPRITE - p1.getLocalBounds().height) / 2;
        if (equip[i].getType()==1){
            p1.setPosition(xPos, yPos);
            m_window->draw(p1);
        }
        if(equip[i].getType()==2){
            p2.setPosition(xPos, yPos);
            m_window->draw(p2);
        }
         if(equip[i].getType()==3){
            p3.setPosition(xPos, yPos);
            m_window->draw(p3);
        }
        if(equip[i].getType()==4){
            p4.setPosition(xPos, yPos);
            m_window->draw(p4);
        }
        dessinerTir(m_window);
            
    }
    AffBar(m_window);
    AffTxt(m_window);
    if (deplacerP1){
         m_window->draw(pm1);
    }
    if (deplacerP2){
        m_window->draw(pm2);
    }
    if(deplacerP3){
        m_window->draw(pm3);
    }
    if(deplacerP4){
        m_window->draw(pm4);
    }

  m_window->display();
}
void sfmlJeu::AffTxt(RenderWindow *m_window)
{
    int espace=600;
    
    //aff texte Vies
    txtVies.setFont(font);
    txtVies.setString("Vies : " + to_string(jeu.getVies())); 
    txtVies.setCharacterSize(24);
    txtVies.setFillColor(sf::Color::White);
    txtVies.setPosition(10.0f, 10.0f);
    m_window->draw(txtVies);
    //image coeur
    if (!coeurTexture.loadFromFile("data/coeurpixel.png")) {
        cerr << "Erreur lors du chargement de l'image du coeur." << endl;
    }
    coeurSprite.setTexture(coeurTexture);
    coeurSprite.setPosition(108.0f, 20.0f);
    coeurSprite.setScale(1.2f, 1.2f);
    m_window->draw(coeurSprite);

    //aff texte Score 
    txtScore.setFont(font);
    txtScore.setString("Score : " + to_string(jeu.getScore()));
    txtScore.setCharacterSize(24);
    txtScore.setFillColor(sf::Color::White);
    txtScore.setPosition((txtVies.getPosition().x+espace+250)/ 2.0f, 10.0f);
    m_window->draw(txtScore);

    //aff texte Piece
    txtPiece.setFont(font);
    txtPiece.setString("Pieces : " + to_string(jeu.getPieces()));
    txtPiece.setCharacterSize(24);
    txtPiece.setFillColor(sf::Color::White);
    txtPiece.setPosition(espace+150, 10.0f);
    m_window->draw(txtPiece);

    //coeur ennemi
    float x=jeu.getEnnemiParIndice(0).getPositionX()* TAILLE_SPRITE;
    float y=jeu.getEnnemiParIndice(0).getPositionY()* TAILLE_SPRITE;
    coeurSprite2.setTexture(coeurTexture);
    coeurSprite2.setPosition(x+20,y-50);
    coeurSprite2.setScale(1.0f, 1.0f);
    m_window->draw(coeurSprite2);
    afficherResistanceEnnemi(m_window);
    m_window->display();
}

void sfmlJeu::dessinerPiece(float positionX, float positionY,RenderWindow *m_window) {
    if (!pieceTexture.loadFromFile("data/piecepixel.png")) {
        cerr << "Erreur lors du chargement de l'image de la pièce." << endl;
    }
    pieceSprite.setTexture(pieceTexture);
    pieceSprite.setPosition(positionX, positionY);
    m_window->draw(pieceSprite);
}

void sfmlJeu::afficherPrix(float positionX, float positionY, int prix,RenderWindow *m_window) {
    txtPrix.setFont(font);
    txtPrix.setString(to_string(prix));
    txtPrix.setCharacterSize(20);
    txtPrix.setFillColor(sf::Color::White);
    txtPrix.setPosition(positionX,positionY);
    m_window->draw(txtPrix);
    dessinerPiece(txtPiece.getPosition().x+132.0f,txtPiece.getPosition().y+10.0f,m_window);
}



void sfmlJeu::AffBar(RenderWindow *m_window){
    int espaceHaut=170;
    barSprite.setPosition((jeu.getConstMap().getDimX() * TAILLE_SPRITE)-52,0);
    m_window->draw(barSprite);

    persoN1.setPosition(barSprite.getPosition().x,165);
    m_window->draw(persoN1);
    afficherPrix(persoN1.getPosition().x+110,persoN1.getPosition().y+60,10,m_window);
    dessinerPiece(persoN1.getPosition().x+130,persoN1.getPosition().y+67,m_window);

    persoN2.setPosition(barSprite.getPosition().x,persoN1.getPosition().y+espaceHaut);
    m_window->draw(persoN2);
    afficherPrix(persoN2.getPosition().x+100,persoN2.getPosition().y+60,20,m_window);
    dessinerPiece(persoN2.getPosition().x+130,persoN2.getPosition().y+67,m_window);


    persoN3.setPosition(barSprite.getPosition().x,persoN2.getPosition().y+espaceHaut);
    m_window->draw(persoN3);
    afficherPrix(persoN3.getPosition().x+100,persoN3.getPosition().y+60,30,m_window);
    dessinerPiece(persoN3.getPosition().x+130,persoN3.getPosition().y+67,m_window);


    persoN4.setPosition(barSprite.getPosition().x,persoN3.getPosition().y+espaceHaut);
    m_window->draw(persoN4);
    afficherPrix(persoN4.getPosition().x+100,persoN4.getPosition().y+60,40,m_window);
    dessinerPiece(persoN4.getPosition().x+130,persoN4.getPosition().y+67,m_window);

}

void sfmlJeu::afficherResistanceEnnemi(RenderWindow *m_window) {
    Text ResiE;
    ResiE.setFont(font);
    ResiE.setCharacterSize(20);
    ResiE.setFillColor(Color::White);
    float x = jeu.getEnnemiParIndice(0).getPositionX() * TAILLE_SPRITE;
    float y = jeu.getEnnemiParIndice(0).getPositionY() * TAILLE_SPRITE;
    ResiE.setString(to_string(jeu.getEnnemiParIndice(0).getRes()));
    ResiE.setPosition(x, y - 58);
    m_window->draw(ResiE);
}

bool deplacerP1 = false;
sf::Vector2f sourisPer;

void sfmlJeu::afficherGameOver(RenderWindow *m_window) {
    gameOverText.setFont(font);
    gameOverText.setString("GAME OVER");
    gameOverText.setCharacterSize(50);
    gameOverText.setFillColor(Color::Red);
    FloatRect textBounds = gameOverText.getLocalBounds();
    gameOverText.setOrigin(textBounds.left + textBounds.width / 2.0f, textBounds.top + textBounds.height / 2.0f);
    gameOverText.setPosition(m_window->getSize().x / 2.0f, m_window->getSize().y / 2.0f);
    m_window->draw(gameOverText);

    if (!gameover.loadFromFile("data/gameover.png")) {
        cerr << "Erreur lors du chargement de l'image de la pièce." << endl;
    }
    gameovers.setTexture(gameover);
    gameovers.setScale(1.0f / 3.0f, 1.0f / 3.0f);
    gameovers.setPosition(m_window->getSize().x / 2.0f -110, m_window->getSize().y / 2.0f -250);
    m_window->draw(gameovers);
    m_window->display();
}

void sfmlJeu::dessinerTir(RenderWindow *m_window) {
     vector<Arme> armes=jeu.getConstArmes();
    for (unsigned int i =0;i<armes.size();i++){
        for(unsigned int j=0;j<armes[i].getBalles().size();j++){
            if(armes[i].getBalle(j).getPosition_X() < DIM || armes[i].getBalle(j).getPosition_Y() < DIM || armes[i].getBalle(j).getPosition_X() > 0 || armes[i].getBalle(j).getPosition_Y() > 0){
                if(armes[i].getDegat()==1){
                    balle1.setPosition(armes[i].getBalle(j).getPosition_X()*TAILLE_SPRITE, armes[i].getBalle(j).getPosition_Y()*TAILLE_SPRITE+12);
                }
                if(armes[i].getDegat()==3){
                    balle2.setPosition(armes[i].getBalle(j).getPosition_X()*TAILLE_SPRITE, armes[i].getBalle(j).getPosition_Y()*TAILLE_SPRITE+12);
                }
                if(armes[i].getDegat()==8){
                    balle3.setPosition(armes[i].getBalle(j).getPosition_X()*TAILLE_SPRITE, armes[i].getBalle(j).getPosition_Y()*TAILLE_SPRITE+12);
                }
                if(armes[i].getDegat()==12){
                    balle4.setPosition(armes[i].getBalle(j).getPosition_X()*TAILLE_SPRITE, armes[i].getBalle(j).getPosition_Y()*TAILLE_SPRITE+12);
                }

                if(balle1.getPosition().x!=0 && balle1.getPosition().x!=0){
                    m_window->draw(balle1);
                }
                if(balle2.getPosition().x!=0 && balle2.getPosition().y!=0){
                    m_window->draw(balle2);
                }
                if(balle3.getPosition().x!=0 && balle3.getPosition().y!=0){
                    m_window->draw(balle3);
                }
                if(balle4.getPosition().x!=0 && balle4.getPosition().y!=0){
                    m_window->draw(balle4);
                }

            }
            
        }
        
    }
   
}

void sfmlJeu::afficherMenuPause(RenderWindow* m_window, bool pause) {
    // Chargement des textures des boutons
    Texture resumeTexture, restartTexture, homeTexture;
    if (!resumeTexture.loadFromFile("data/Resumebouton.png") ||
        !restartTexture.loadFromFile("data/Restartbouton.png") ||
        !homeTexture.loadFromFile("data/Homebouton.png")) {
         cerr << "Erreur lors du chargement de l'image des boutons." << endl;
    }
    Sprite resumeButton(resumeTexture), restartButton(restartTexture), homeButton(homeTexture);
    
    float taille = 2.5; // Facteur d'échelle
    resumeButton.setScale(taille, taille);
    restartButton.setScale(taille, taille);
    homeButton.setScale(taille, taille);
    // Positionnement des boutons
    float espacement = 20.0f; // Espacement entre les boutons
    float totalHeight = resumeButton.getGlobalBounds().height + restartButton.getGlobalBounds().height + homeButton.getGlobalBounds().height + espacement * 2;
    float startY = (m_window->getSize().y - totalHeight) / 2.0f;
    float startX = m_window->getSize().x / 2.0f - resumeButton.getGlobalBounds().width / 2.0f;

    resumeButton.setPosition(startX, startY);
    restartButton.setPosition(startX, startY + resumeButton.getGlobalBounds().height + espacement);
    homeButton.setPosition(startX, startY + resumeButton.getGlobalBounds().height + restartButton.getGlobalBounds().height + espacement * 2);

    while (pause) {
        m_window->draw(resumeButton);
        m_window->draw(restartButton);
        m_window->draw(homeButton);
        m_window->display();
        Event event;
        while (m_window->pollEvent(event)) {
            if (event.type == Event::Closed) {
                m_window->close();
                pause = false;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::P) {
                pause = false;
            }
            //clics de souris
            if (event.type == Event::MouseButtonPressed) {
                Vector2f mousePosition = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                if (resumeButton.getGlobalBounds().contains(mousePosition)) {
                    pause = false;
                }
                else if (restartButton.getGlobalBounds().contains(mousePosition)) {
                    cout << "Redemarrer" << endl;
                }
                else if (homeButton.getGlobalBounds().contains(mousePosition)) {
                    cout << "Accueil" << endl;
                }
            }
        }
    }
}


void sfmlJeu::sfmlBoucle(RenderWindow *m_window)
{
    Clock clock;
    Clock clock2;
    Clock clock3;
    Clock score;
    Clock init;
    bool jeuTermine = false;
    bool pause = false;
    bool pscore=false; //score en pause
    int score2=0;
    const vector<Arme> armes=jeu.getConstArmes();
    while (m_window->isOpen())
    {
        if (!pause)
        {
            if(!pscore){//si pscore a faux ->

                jeu.setScore(score.getElapsedTime().asSeconds() * 2+score2);
            }
            else{
                jeu.setScore(score2);
                pscore=false;
            }

            float elapsed = clock.getElapsedTime().asSeconds();//iteration jeu
            float elapsed2 = clock2.getElapsedTime().asSeconds();//ennemis
            float elapsed3 = clock3.getElapsedTime().asSeconds();//tirs
            float elapseinit = init.getElapsedTime().asSeconds();//init
        if (elapseinit > 1.5  && !jeuTermine)
        {
            jeu.initEnnemiJeu();
            init.restart();
        }

        if (elapsed2 > 0.1 && !jeuTermine)
        {
            for (int i = 0; i < NBEnnemis; i++) {
                if (jeu.ennemis[i].getPositionX() >= 0 && jeu.ennemis[i].getPositionX() <= DIM- 1 &&
                    jeu.ennemis[i].getPositionY() > 0 && jeu.ennemis[i].getPositionY() <= DIM- 1) {
                    //ennemis[i].remettreAun(carte);
                    jeu.ennemis[i].MoveEnnemi(jeu.getConstMap(),elapsed2);
                    //ennemis[i].positionEnnemi(carte);
                }
            }
            clock2.restart();
        }
        if (elapsed3 > 0.005  && !jeuTermine)
        {
            jeu.actiontir(elapsed3*5);
            dessinerTir(m_window);
            clock3.restart();
        }

        if (elapsed > 0.5 && !jeuTermine)
        {
            for (int j = 0; j<NBEnnemis; j++)
            {
                jeu.ennemiArrive(&jeu.ennemis[j]);
            }
            jeu.actionAutomatique(elapsed);
            clock.restart();
        }
        if (jeu.getVies() <= 0 && !jeuTermine)
        {
            jeu.actionAutomatique(elapsed);
            sfmlAff(m_window);
            afficherGameOver(m_window);
            jeuTermine = true;
        }

        Event event;
        while (m_window->pollEvent(event))
        {
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::P) {
                pause = true;
            }
            if (event.type == Event::Closed) {
                m_window->close();
            }
                
                if (event.type == Event::KeyPressed)
                {
                    switch (event.key.code)
                    {
                    case Keyboard::A:
                        jeu.actionClavier('a');
                        break;
                    case Keyboard::Z:
                        jeu.actionClavier('z');
                        break;
                    default:
                        break;
                    }
                }

                if (event.type == Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == Mouse::Left)
                    {
                        Vector2f positionS = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        if (persoN1.getGlobalBounds().contains(positionS))
                        {
                            deplacerP1 = true;
                        }
                        if (persoN2.getGlobalBounds().contains(positionS))
                        {
                            deplacerP2 = true;
                        }
                        if (persoN3.getGlobalBounds().contains(positionS))
                        {
                            deplacerP3 = true;
                        }
                        if (persoN4.getGlobalBounds().contains(positionS))
                        {
                            deplacerP4 = true;
                        }
                    }
                }
                else if (event.type == sf::Event::MouseButtonReleased) {
                    //Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                    if (event.mouseButton.button == sf::Mouse::Left && deplacerP1) {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        jeu.actionSourisP(static_cast<float>(sourisPo.x / TAILLE_SPRITE), static_cast<float>(sourisPo.y / TAILLE_SPRITE), 'a');
                        pm1.setPosition(m_window->getSize().x+60,0);
                        deplacerP1 = false; //Relacher le perso
                    }
                    if (event.mouseButton.button == sf::Mouse::Left && deplacerP2) {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        jeu.actionSourisP(static_cast<float>(sourisPo.x / TAILLE_SPRITE), static_cast<float>(sourisPo.y / TAILLE_SPRITE), 'z');
                        pm2.setPosition(m_window->getSize().x+60,0);
                        deplacerP2 = false; 
                    }
                    if (event.mouseButton.button == sf::Mouse::Left && deplacerP3) {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        jeu.actionSourisP(static_cast<float>(sourisPo.x / TAILLE_SPRITE), static_cast<float>(sourisPo.y / TAILLE_SPRITE), 'b');
                        pm3.setPosition(m_window->getSize().x+60,0);
                        deplacerP3 = false; 
                    }
                    if (event.mouseButton.button == sf::Mouse::Left && deplacerP4) {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        jeu.actionSourisP(static_cast<float>(sourisPo.x / TAILLE_SPRITE), static_cast<float>(sourisPo.y / TAILLE_SPRITE), 'c');
                        pm4.setPosition(m_window->getSize().x+60,0);
                        deplacerP4 = false;
                    }
                }

                if (event.type == Event::MouseMoved)
                {

                    if (deplacerP1)
                    {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                       // cout<<"Perso en  deplacement"<<endl;
                        pm1.setPosition(sourisPo-Vector2f(30,30));
                    }
                    if (deplacerP2)
                    {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        pm2.setPosition(sourisPo-Vector2f(30,30));
                    }
                    if (deplacerP3)
                    {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        pm3.setPosition(sourisPo-Vector2f(30,30));
                    }
                    if (deplacerP4)
                    {
                        Vector2f sourisPo = m_window->mapPixelToCoords(Mouse::getPosition(*m_window));
                        pm4.setPosition(sourisPo-Vector2f(30,30));
                    }
                }
            }
        }
        else
        {//en pause
            score2=jeu.getScore();
           afficherMenuPause(m_window, pause);
            clock.restart();
            clock2.restart();
            init.restart();
            score.restart();
            pause = false;
            pscore=true;
        }
        if (!jeuTermine)
            sfmlAff(m_window);
    }
    score.restart();
}