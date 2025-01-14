
#include "Personnage.h"
#include <cassert>
#include <cassert>

Personnage::Personnage(){
    type=niveau1;
    position=Vecteur(0,0); 
}

Personnage::Personnage(float x, float y,int type, int valeur){
    position=Vecteur(x,y);
    assert(type >= niveau1 && type <= niveau5);
    this->type = static_cast<niveau>(type);
}
 
float Personnage::getPosition_X()const{
    return position.getX();
}
float Personnage::getPosition_Y()const{
    return position.getY();
}
int Personnage::getType()const{
    return type;
}

Personnage::~Personnage(){
    
}
void Personnage::testRegression(){

    Personnage p;
    assert(p.getPosition_X()>=0 && p.getPosition_Y()>=0);
    assert (p.getType()==1);

}

