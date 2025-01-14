#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1096, 920), "Pirate Defense");

    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("data/HomePirate.png")) {
        cout << "erreur de chargement du fond" << endl;
        return 1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("data/musique_pirate.wav")) {
        cout << "erreur de chargement du son1" << endl;
        return 1;
    }

    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    sound.setLoop(true); // Définit la lecture en boucle
    sound.play();

    sf::SoundBuffer buffer2;
    if (!buffer2.loadFromFile("data/clic_start.wav")) {
        return 1;
    }
    sf::Sound sound2;
    sound2.setBuffer(buffer2);

    sf::Texture buttonNormalTexture;
    if (!buttonNormalTexture.loadFromFile("data/BoutonStart.png")) {
        cout << "erreur de chargement de l'image du bouton" << endl;
        return 1;
    }
    sf::Sprite buttonNormalSprite(buttonNormalTexture);

    sf::Texture buttonPressedTexture;
    if (!buttonPressedTexture.loadFromFile("data/BoutonStartPressed.png")) {
        cout << "erreur de chargement de l'image du bouton" << endl;
        return 1;
    }
    sf::Sprite buttonPressedSprite(buttonPressedTexture);

    // Définir la taille souhaitée du bouton
    buttonNormalSprite.setScale(0.5f, 0.5f);
    buttonPressedSprite.setScale(0.5f, 0.5f);

    // Positionner le bouton au centre de la fenêtre
    buttonNormalSprite.setPosition((window.getSize().x - buttonNormalSprite.getGlobalBounds().width) / 2, window.getSize().y - buttonNormalSprite.getGlobalBounds().height - 35);
    buttonPressedSprite.setPosition((window.getSize().x - buttonPressedSprite.getGlobalBounds().width) / 2, window.getSize().y - buttonPressedSprite.getGlobalBounds().height - 35);


    bool buttonPressed = false;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (buttonNormalSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    sound2.play();
                    cout << "Bouton cliqué !" << endl;
                    buttonPressed = true;
                }
            }
            if (event.type == sf::Event::MouseButtonReleased) {
                if (buttonPressed) {
                    buttonPressed = false;
                }
            }
        }

        window.clear(sf::Color::White);
        window.draw(backgroundSprite);
        if (buttonPressed) {
            window.draw(buttonPressedSprite);
        } else {
            window.draw(buttonNormalSprite);
        }
        window.display();
    }

    return 0;
}
