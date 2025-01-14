#ifndef WINTXT_H
#define WINTXT_H

//! \brief une fen�tre texte est un tableau 2D de caracteres
class WinTXT
{
private:
    int dimx;  //!< \brief largeur
    int dimy;  //!< \brief heuteur
    int *win; //!< \brief stocke le contenu de la fen�tre dans un tableau 1D mais on y accede en 2D

public:
    WinTXT(int dx, int dy);
    void clear(char c = ' ');
    void print(int x, int y, int c);
    void print(int x, int y, int *c);
    void draw(int x, int y, int piece, int vies, int tab[5][5],int nbPers1,int nbPers2,int temps);
    int *getWin();
    void pause();
    char getCh();
};

void termClear();

#endif
