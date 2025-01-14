#include "Jeu.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include <unistd.h>
#include <cassert>
using namespace std;


    
void Jeu::initEnnemiTab()
 {
    for (int i=0; i<=NBEnnemis;i++)
    {
        ennemis[i] = Ennemi(0,0,16);
        ennemis[i].indice = i;
        ennemis[i].nbcase = 0;
    }
 }

 
Jeu::Jeu()
{
    initEnnemiTab();
    equipage.push_back(Personnage(8,5,1,2));
    ennemi=Ennemi(0,0,10);
    carte=Map();
    niveau=0;
    score=0;
    pieces=0;
    vies=5;
    arme=Arme(equipage[0]);
    armes.push_back(Arme(equipage[0]));
}

Jeu::~Jeu(){
    cout<<"jeu detruit"<<endl;
}


void Jeu::actionClavier(char c){
    int x,y;
    if(c=='a'){
        do{
         x=2 +rand() % (18 - 3);
         y=2 +rand() % (18 - 3);
        }while (carte.getCellValue(x,y)==0);

        if (pieces>=10){
            equipage.push_back(Personnage(x,y,1,3));
            armes.push_back(Arme(Personnage(x,y,1,0)));
            pieces=pieces-10;
        }
        
    }
    if(c=='z'){
        do{
         x=2 +rand() % (18 - 3);
         y=2 +rand() % (18 - 3);
        }while (carte.getCellValue(x,y)==0);
        if(pieces >=20){
            equipage.push_back(Personnage(x,y,2,4));
            armes.push_back(Arme(Personnage(x,y,2,0)));
            pieces=pieces-20;
        }
        
    }

}

 void Jeu::actionSourisP(int x,int y,char c){
    if(c=='z'){
        if(pieces >=20 && carte.getCellValue(x,y)==0){
            equipage.push_back(Personnage(x,y,2,4));
            armes.push_back(Arme(Personnage(x,y,2,0)));
            pieces=pieces-20;
            cout<<"ennemi ajouter "<<endl;
        }
        
    }
    if(c=='a'){

        if (pieces>=10 && carte.getCellValue(x,y)==0){
            equipage.push_back(Personnage(x,y,1,3));
            armes.push_back(Arme(Personnage(x,y,1,0)));
            pieces=pieces-10;
        }
        
    }
    if(c=='b'){
         if (pieces>=30 && carte.getCellValue(x,y)==0){
            equipage.push_back(Personnage(x,y,3,3));
            armes.push_back(Arme(Personnage(x,y,3,0)));
            pieces=pieces-30;
        }
    }
    if(c=='c'){
         if (pieces>=40 && carte.getCellValue(x,y)==0){
            equipage.push_back(Personnage(x,y,4,3));
            armes.push_back(Arme(Personnage(x,y,4,0)));
            pieces=pieces-40;
        }
    }

 }
 void Jeu::actiontir(float dt){
    for(unsigned int i=0;i<armes.size();i++){
       armes[i].tirerfluide(getEnnemiParIndice(0),dt);
    }
 }

 void Jeu::actionAutomatique(float dt){
    // inserer les ennemis dans la partie
    //initEnnemiJeu();
    //pour les ennemis en jeu
    
    for(unsigned int i=0;i<armes.size();i++){
       armes[i].tirer(getEnnemiParIndice(0),dt);
        ennemiTue(&getEnnemiParIndice(0));
        tueEnnemiTab(&getEnnemiParIndice(0), carte);
    }
    
 }
 
 unsigned int Jeu::NbPersoNiveau(int n) const{
    unsigned int nb=0;
    for (unsigned int i=0;i<equipage.size();i++){
        if(equipage[i].getType()==n){
            nb+=1;
        }
    }
    return nb;
 }

const vector<Personnage> Jeu::getConstEquipage() const{
    return equipage;
}

const Ennemi* Jeu::getConstEnnemis() const {
    return ennemis;
}

const Ennemi  &Jeu::getConstEnnemi() const{
    return ennemi;
}

Ennemi& Jeu::getEnnemi(int index) {
    if (index >= 0 && index < NBEnnemis) {
        return ennemis[index];
    } else {
        throw std::out_of_range("Index d'ennemi invalide");
    }
}

const Map & Jeu::getConstMap() const{
    return carte;
}

//getters setters


//niveau
int Jeu::getNiveau()const{
    return niveau;
}

void Jeu::setNiveau(int n) {
    niveau = n;
}

//score
int Jeu::getScore()const{
    return score;
}

void Jeu::setScore(int s) {
    score = s;
}

//pieces
int Jeu::getPieces()const{
    return pieces;
}

void Jeu::setPieces(int p) {
    pieces = p;
}

//vies
int Jeu::getVies()const{
    return vies;
}

void Jeu::setVies(int v) {
    vies = v;
}

void Jeu::ennemiTue(Ennemi* ennemiPtr) {
    if(ennemiPtr->getRes()<=0)
    {
        cout << "Ennemi mort" << endl;
        setPieces(getPieces() + 5); 
    }
}

void Jeu::ennemiArrive(Ennemi* ennemi){
    if (ennemi->arrive)
    {
        setVies(getVies()-1);
    }
}

int modulo(int a, int b) {
    return (a % b + b) % b;
}

void Jeu::initEnnemiJeu(){
    for (int i = 0; i < NBEnnemis; i++) {
            if (ennemis[i].getPositionX() == 0 && ennemis[i].getPositionY() == 0) {
                ennemis[i].setPosition(0, 4);
                break;
            }
        }
}




void Jeu::tueEnnemiTab(Ennemi* ennemiPtr,Map& mapp){ //tab infini
    if (ennemiPtr->getRes() <= 0 || ennemiPtr->arrive==true){
        //mapp.setCellValue(ennemiPtr->getPositionX(),ennemiPtr->getPositionY(),1);
        ennemiPtr->setPosition(0,4);
        ennemiPtr->setRes(getScore()*1.2+10);
        ennemiPtr->arrive=false;
        cout<< getEnnemiParIndice(0).getRes()<<endl;
        
        // Décaler les indices avec modulo
        for (int i = 0; i< NBEnnemis ; i++) {
            ennemis[i].indice = modulo(ennemis[i].indice-1,NBEnnemis);
        }
    }
    

}



 Ennemi& Jeu::getEnnemiParIndice(int ind) {
    for (int i = 0; i < NBEnnemis; ++i) {
        if (ennemis[i].indice == ind) {
            return ennemis[i];
        }
    }
   
    throw runtime_error( "Aucun ennemi trouvé avec cet indice.");
}


void Jeu::testRegression(){
    Jeu jeu;
    for (int i=0;i<5;i++){
        assert(ennemis[i].getRes()>=0 && ennemis[i].getPositionX()>=0 && ennemis[i].getPositionY()>=0);
    }
    for(unsigned int i=0;i<equipage.size();i++){
        equipage[i].testRegression();
    }
    cout<<"tout les teste passé"<<endl;
}
/**
 * @return const vector<Arme> 
 */
 const vector<Arme> Jeu::getConstArmes() const{
    return armes;
 }