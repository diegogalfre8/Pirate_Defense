#include "Ennemis.h"
#include <cassert>
Ennemi::Ennemi(){

}
//constructeur
Ennemi::Ennemi(float startX, float startY, int resistance)  {
    position=Vecteur(startX,startY);
    lastMove=0;
    res=resistance;
    arrive=false;
}

//destructeur
Ennemi::~Ennemi() {
    //cout << "Ennemi detruit " << endl;
}

//getter et setter position
float Ennemi::getPositionX() const {
    return position.getX();
}

float Ennemi::getPositionY() const {
    return position.getY();
}

void Ennemi::setPosition(float x, float y) {
    position.setX(x);
    position.setY(y);
}
/*
void Ennemi::MoveEnnemibis(Map& mapp,float dt) {
    // Verifie si l'ennemi est toujours dans les dimensions autorises
    if (position.getX() >= 0 && position.getX() < DIM-2 && position.getY() >= 0 && position.getY() < DIM-1) {
        // Dplacements
        if (mapp.getCellValue(position.getX() + 1, position.getY()) == 1 && lastMove != -1) {
            position.setX(position.getX() + dt);
            lastMove = 1;
        } else if (mapp.getCellValue(position.getX(), position.getY() + 1) == 1 && lastMove != -2) {
            position.setY(position.getY() + dt);
            lastMove = 2;
        } else if (mapp.getCellValue(position.getX() - 1, position.getY()) == 1 && lastMove != 1) {
                position.setX(position.getX() - dt);
                lastMove = -1;
        } else if (mapp.getCellValue(position.getX(), position.getY() - 1) == 1 && lastMove != 2) {
                position.setY(position.getY() - dt);
                lastMove = -2;
        }
    }
    else{
        arrive=true;
    }
}
*/

//La valeur 0 indique un espace vide et (1,2,3,4 ->droite gauche haut bas) 9 un emplacement impoosible.
void Ennemi::MoveEnnemi(const Map& mapp,float dt) {
    // Verifie si l'ennemi est toujours dans les dimensions autorises
    if (position.getX() < 0 )
    {
        position.setX(position.getX() + dt);
    }
    else if (position.getX() >= 0 && position.getX() < DIM-2 && position.getY() >= 0 && position.getY() < DIM-1) {
        // Dplacements
        if (mapp.getCellValue(position.getX(), position.getY()) == 1) {
            position.setX(position.getX() + dt);
        } else if (mapp.getCellValue(position.getX(), position.getY()) == 4) {
            position.setY(position.getY() + dt);
        } else if (mapp.getCellValue(position.getX(), position.getY()) == 2) {
                position.setX(position.getX() - dt);
        } else if (mapp.getCellValue(position.getX(), position.getY()) == 3) {
                position.setY(position.getY() - dt);
        }
    }
    else{
        arrive=true;
    }
}

void Ennemi::remettreAun(Map& mapp) {
    // Effacer la position précèdente de l'ennemi
    mapp.setCellValue(position.getX(), position.getY(), 1);
}

//getter et setter resistance
int Ennemi::getRes() const {
    return res;
}

void Ennemi::setRes(int resistance) {
    res = resistance;
}

void Ennemi::positionEnnemi(Map& mapp) {
    // Mettre a res la nouvelle position
    mapp.setCellValue(position.getX(), position.getY(), getRes());
}


