#include "Map.h"
#include <iostream>
#include <cassert>

using namespace std;

// Afficher la map, de 1 jusqu a dim-1 pour exclure les bords et gerer les ennemis
void Map::afficherMap() const {
    for (int i = 1; i < DIM - 1; ++i) {
        for (int j = 1; j < DIM - 1; ++j) {
            cout << Mapp[i][j] << ' ';
        }
        cout << endl;
    }
}

int Map::getCellValue(float x, float y) const {
    int xx=x;
    int yy=y;
    return Mapp[yy][xx];
}

void Map::setCellValue(int x, int y, int value) {
    Mapp[y][x] = value;
}
int Map::getDimX() const{
    return dimX;
};
int Map::getDimY() const{
    return dimY;
};
int Map::getXYInt(const int x,const int y) const{
    assert(x>=0);
    assert(x>=0);
    assert(x < dimX);
    assert(y < dimY);
    return Mapp[x][y];
}