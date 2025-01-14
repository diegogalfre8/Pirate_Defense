 #include "Vecteur.h"
 Vecteur::Vecteur(float x0,float y0){
    x=x0;
    y=y0;
}
 Vecteur::Vecteur(){
    
}


float Vecteur::getX() const{
        return x;
    }

float Vecteur::getY() const {
        return y;
    }

void Vecteur::setX(float x1) {
        x = x1;
}

void Vecteur::setY(float y1) {
    y = y1;
}
Vecteur::~Vecteur(){
}
