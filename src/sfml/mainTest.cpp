
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
const int DIM=10;

int main()
{
    int Mapp[DIM][DIM] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 1, 1, 1},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    sf::RenderWindow window(sf::VideoMode(DIM*32,DIM*32), "Pirate Defense"); //titre de la fenetre
    sf::RectangleShape rectangle(sf::Vector2f(50, 50)); // Taille du rectangle (largeur x hauteur)
    rectangle.setFillColor(sf::Color::Red);
     // Obtenir la taille de la fenêtre
    sf::Vector2u windowSize = window.getSize();

    // Calculer les coordonnées pour placer le rectangle au milieu de la fenêtre
    float posX = (windowSize.x - rectangle.getSize().x) / 2.0f;
    float posY = (windowSize.y - rectangle.getSize().y) / 2.0f;
    // Définir la position du rectangle
    rectangle.setPosition(posX, posY);

    sf::RectangleShape terre(sf::Vector2f(50,50));
    terre.setFillColor(sf::Color::Green);
    
    while (window.isOpen()) {
        sf::Event event;
        
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed){
                window.close();}

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&& posX>0) {
            posX -= 0.5;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && posX+rectangle.getSize().x<800) {
            posX +=0.5;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && posY>0) {
            posY -= 0.5;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && posY+rectangle.getSize().y<600) {
            posY += 0.5;
        }
        rectangle.setPosition(posX,posY);
        window.clear(sf::Color::White);
         for(int x=0;x<DIM;x++){
            for (int y=0;y<DIM;y++){
                if (Mapp[y][x]==0){
                 terre.setPosition(sf::Vector2f(x*32,y*32));
                 window.draw(terre);
                 cout<<"dans la boucle"<<endl;
                }
        
                
            }
        }

        window.draw(rectangle);
        window.display();
    }

	return 0;
}

