#include "Arme.h"
#include "Jeu.h"
#include <unistd.h> 


int main(int argc, char const *argv[])
{
    /* code */
    Map mapp;
    mapp.afficherMap();
    Jeu J; //pb de invalid pointeur
    Ennemi ennemi(0, 2, 8);  // Commence a la position (0, 2) resistance 8
    Personnage perso(1,1,1,6); //pos (1,1) , type 2 , affichage 6
    Arme arme(perso);
    mapp.setCellValue(perso.getPosition_X(),perso.getPosition_Y(),6);

    cout << "Carte initiale :" << endl;
    mapp.afficherMap();

    while (true) {
        ennemi.remettreAun(mapp);
        ennemi.MoveEnnemi(mapp);
        arme.tirer(ennemi);

        cout << "Position X,Y de l'ennemi : " << ennemi.getPositionX() << ", " << ennemi.getPositionY() << endl;
        cout << "Carte apres le deplacement de l'ennemi :"<<endl;
        if(ennemi.arrive)
        {
            ennemi.ennemiGagne();
        }
        cout<<"Resistance de l'ennemi: "<<ennemi.getRes()<<endl;

        ennemi.positionEnnemi(mapp);
        mapp.afficherMap();
        J.ennemiTue(&ennemi);
        sleep(1);
    }

    return 0;
}
