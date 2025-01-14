#include "Tir.h"
#include <cmath>

double calculerNorme(Vecteur vecteur) {
    double somme_carres = vecteur.getX() *vecteur.getX()+vecteur.getY()*vecteur.getY();
    return (float) sqrt(somme_carres);
}
Tir::Tir(float x,float y){
    position.setX(x);
    position.setY(y);
    direction.setX(0);
    direction.setY(0);
    tire=false;
   
}
Tir::Tir(){};
Tir::~Tir(){
    //cout<<"balle d'etruit"<<endl;
}

float Tir::getPosition_X(){
    return position.getX();
}
float Tir::getPosition_Y(){
    return position.getY();
}
void Tir::setPosition_X(float x){
    position.setX(x);
}
void Tir::setPosition_Y(float y){
    position.setY(y);
}
void Tir::tirVersEnnemi(float x,float y,float dt){
    if(direction.getX()==0 && direction.getY()==0  ){
        if(x!=0 && y!=0){
            Vecteur d=Vecteur(x-position.getX(),y-position.getY());
            float norme=calculerNorme(d);
            direction.setX(d.getX()/norme);
            direction.setY(d.getY()/norme);
        }
        
    }
    position.setX(position.getX()+ direction.getX()*dt*5);
    position.setY(position.getY()+ direction.getY()*dt*5);
}

void Tir::setDirection_X(float x){
    direction.setX(x);
}
void Tir::setDirection_Y(float y){
    direction.setY(y);
}

Vecteur Tir::getDirection(){
    return direction;
}