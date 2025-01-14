#include "Arme.h"
#include "Jeu.h"
#include <iostream>
#include <unistd.h>

int main(int argc, char const *argv[]) {
   /* Map mapp;
    Jeu J;
    J.initEnnemiTab(); // Initialiser le tableau d'ennemis par défaut à 0,0
    Personnage perso(1, 1, 1, 6);
    Arme arme(perso);
    mapp.setCellValue(perso.getPosition_X(), perso.getPosition_Y(), 6);
    

    while (J.getVies()>-1) {
        for (int i = 0; i < NBEnnemis; i++) {
            cout << "Ennemi " << i << " Position (x;y) = (" << J.ennemis[i].getPositionX() << ";" << J.ennemis[i].getPositionY() << ") Indice = "
                 << J.ennemis[i].indice << " Resistance = " << J.ennemis[i].getRes() <<" arrive? "<<boolalpha<<J.ennemis[i].arrive<< endl;
        }
        cout << "Pieces: " << J.getPieces() << endl;
        cout<<"Vies restantes: "<<J.getVies()<<endl;
        cout << endl;
        mapp.afficherMap();
        cout << endl;
        sleep(1);

        // inserer les ennemis dans la partie
        for (int i = 0; i < NBEnnemis; i++) {
            if (J.ennemis[i].getPositionX() == 0 && J.ennemis[i].getPositionY() == 0) {
                J.ennemis[i].setPosition(0, 2);
            }
        }
        //pour les ennemis en jeu
        for (int i = 0; i < NBEnnemis; i++) {
            if (J.ennemis[i].getPositionX() >= 0 && J.ennemis[i].getPositionX() < DIM- 1 &&
                J.ennemis[i].getPositionY() > 0 && J.ennemis[i].getPositionY() < DIM- 1) {
                    
                J.ennemis[i].remettreAun(mapp);
                J.ennemis[i].MoveEnnemi(mapp);

                //tirer sur ennemi
                if (J.ennemis[i].getRes() > 0 && i == 0) {
                    arme.tirer(J.getEnnemiParIndice(0));
                    J.ennemiTue(&J.getEnnemiParIndice(0));
                    J.tueEnnemiTab(&J.getEnnemiParIndice(0), mapp);
                } 
                
                J.ennemis[i].positionEnnemi(mapp);
            }
            if (J.getEnnemiParIndice(0).arrive==true) //ennemi arrive
                 {
                    J.getEnnemiParIndice(0).setRes(0);
                    J.tueEnnemiTab(&J.getEnnemiParIndice(0), mapp);
                    J.setVies(J.getVies()-1);
                 }
        }
    }
    cout<<"GAME OVER"<<endl;
    J.testRegression();*/
    return 0;
}
