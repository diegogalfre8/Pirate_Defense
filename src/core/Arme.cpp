#include "Arme.h"
#include <cmath>
#include <cassert>



Arme::Arme(){}

Arme::~Arme() {}

Arme::Arme(Personnage p)
{
    if (p.getType()==1){
        type=1;
        degat=1;
    }
    else if (p.getType()==2){
        type=2;
        degat=3;
    }
     else if (p.getType()==3){
        type=3;
        degat=8;
    }
     else if (p.getType()==4){
        type=4;
        degat=12;
    }
    else{
        cout<<"erreur sur l'affectation de niveau de l'arme fichier arme.cpp"<<endl;
    }
    balles.push_back(Tir(p.getPosition_X(),p.getPosition_Y()));
    position.setX(p.getPosition_X());
    position.setY(p.getPosition_Y());
    
}
Tir Arme::getBalle(int i) const{
    return balles[i];
}
vector<Tir> Arme::getBalles() const{
    return balles;
}
int Arme::getDegat(){
    return degat;
}
int Arme::getType(){
    return type;
}
void Arme::tirer(Ennemi &ennemi,float dt){
    assert(ennemi.getRes()>=0);
    if (ennemi.getRes()>=0){
        ennemi.setRes(ennemi.getRes()-degat);
    }
}

void Arme::chargerBalle(int i){
    balles[i].setPosition_X(position.getX());
    balles[i].setPosition_Y(position.getY());
    balles[i].setDirection_X(0);
    balles[i].setDirection_Y(0);
}

void Arme::tirerfluide(Ennemi &ennemi,float dt){
    for (unsigned int i = 0; i < balles.size(); ++i) {
        balles[i].tirVersEnnemi(ennemi.getPositionX(), ennemi.getPositionY(), dt);
        float distance = sqrt(pow(getBalle(i).getPosition_X() - ennemi.getPositionX(), 2) +
             pow(getBalle(i).getPosition_Y()- ennemi.getPositionY(), 2));
        if (balles[i].getPosition_X() > DIM || balles[i].getPosition_Y() > DIM || balles[i].getPosition_X() < 0 || balles[i].getPosition_Y() < 0 || distance < 0.5) {
            chargerBalle(i);
        }
    }
}


void Arme::testRegression(){
    Arme arme;
    
}
