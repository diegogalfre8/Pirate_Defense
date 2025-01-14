#include <iostream>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32
#include "winTxt.h"
#include "Jeu.h"
#include <chrono>
#include <thread>


void txtAff(WinTXT &win,  const Jeu &jeu,auto temp)
{
	int coordEnnemis[NBEnnemis][5] ;
	
	const Map &ter = jeu.getConstMap();
	const vector<Personnage> equipage = jeu.getConstEquipage();
	//const Ennemi &ennemi = jeu.getConstEnnemi();
	const Ennemi *ennemis=jeu.getConstEnnemis();

	for (int i = 0; i < NBEnnemis; ++i) {
    	coordEnnemis[i][0] = ennemis[i].getPositionX();
    	coordEnnemis[i][1] = ennemis[i].getPositionY();
		coordEnnemis[i][2] = ennemis[i].indice;
		coordEnnemis[i][3] = ennemis[i].getRes();
		coordEnnemis[i][4] = ennemis[i].arrive;


}
	

	
	win.clear();

	// Affichage de la map
	for (int x = 0; x < ter.getDimX(); ++x)
		for (int y = 0; y < ter.getDimY(); ++y)
			win.print(x, y, ter.getXYInt(x, y));
	


	for(unsigned int i=0;i<equipage.size();i++){
	win.print(equipage[i].getPosition_X(),equipage[i].getPosition_Y(),3);}

	

	win.draw(0, 0,jeu.getPieces(),jeu.getVies(),coordEnnemis,jeu.NbPersoNiveau(1),jeu.NbPersoNiveau(2),jeu.getScore());
	
	
}
void txtBoucle(Jeu &jeu)
{
	// Creation d'une nouvelle fenetre en mqode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
	WinTXT win(jeu.getConstMap().getDimX(), jeu.getConstMap().getDimY());

	auto debuJeu=chrono::steady_clock::now();

	bool ok = true;
	int c;
	
	
	do
	{
		this_thread::sleep_for(chrono::seconds(1));

		auto current_time=chrono::steady_clock::now();
		auto elapsed_time=chrono::duration_cast<chrono::seconds>(current_time-debuJeu).count();
		jeu.setScore(elapsed_time);

		txtAff(win, jeu,elapsed_time);

		#ifdef _WIN32
			Sleep(100);
		#else
		usleep(10000);
		#endif //WIN32
		jeu.actionAutomatique(0.1);
		
        c = win.getCh();
		switch (c)
		{
		case 'a':
			jeu.actionClavier('a');
			break;
		
		case 'z':
			jeu.actionClavier('z');
			break;
		/*
		case 'l':
			jeu.actionClavier('h');
			break;
		case 'o':
			jeu.actionClavier('b');
			break;*/
		case 'q':
			ok = false;
			break;
		}

	} while (ok && jeu.getVies()>0);
	cout<<"Game Over"<<endl;
	
}




