#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include "sfmlJeu.h"

using namespace std;

int main()
{
    sf::RenderWindow window(sf::VideoMode(1090, 920), "Pirate Defense");
    sfmlJeu sj;

    // Chargement de l'image du fond
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("data/HomePirate.png")) {
        cout << "Erreur de chargement du fond." << endl;
        return 1;
    }
    sf::Sprite backgroundSprite(backgroundTexture);

    // Chargement et lecture du son de fond
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("data/musique_pirate.wav")) {
        cout << "Erreur de chargement du son de fond." << endl;
        return 1;
    }
    sf::Sound sound;
    sound.setBuffer(buffer);
    sound.setVolume(100);
    sound.setLoop(true); // Lecture en boucle
    sound.play();

    // Chargement du son de clic pour le bouton
    sf::SoundBuffer buffer2;
    if (!buffer2.loadFromFile("data/clic_start.wav")) {
        return 1;
    }
    sf::Sound sound2;
    sound2.setBuffer(buffer2);

    // Chargement de l'image du bouton "Start"
    sf::Texture buttonNormalTexture;
    if (!buttonNormalTexture.loadFromFile("data/BoutonStart.png")) {
        cout << "Erreur de chargement de l'image du bouton." << endl;
        return 1;
    }
    sf::Sprite buttonNormalSprite(buttonNormalTexture);

    // Chargement de l'image du bouton "Start" pressé
    sf::Texture buttonPressedTexture;
    if (!buttonPressedTexture.loadFromFile("data/BoutonStartPressed.png")) {
        cout << "Erreur de chargement de l'image du bouton pressé." << endl;
        return 1;
    }
    sf::Sprite buttonPressedSprite(buttonPressedTexture);

    // Définition de la taille et position du bouton "Start"
    buttonNormalSprite.setScale(0.5f, 0.5f);
    buttonPressedSprite.setScale(0.5f, 0.5f);
    buttonNormalSprite.setPosition((window.getSize().x - buttonNormalSprite.getGlobalBounds().width) / 2, window.getSize().y - buttonNormalSprite.getGlobalBounds().height - 35);
    buttonPressedSprite.setPosition((window.getSize().x - buttonPressedSprite.getGlobalBounds().width) / 2, window.getSize().y - buttonPressedSprite.getGlobalBounds().height - 35);

    // Création du bouton de son
    sf::Texture Boutonsound;
    if (!Boutonsound.loadFromFile("data/Boutonson.png")) {
        cerr << "Erreur de chargement de l'image du bouton de son." << endl;
        return 1;
    }
    sf::Sprite SoundSprite(Boutonsound);
    SoundSprite.setPosition(10, window.getSize().y - SoundSprite.getGlobalBounds().height - 10);

    // Chargement de l'image du bouton de son coupé
    sf::Texture NoSoundTexture;
    if (!NoSoundTexture.loadFromFile("data/BoutonSonS.png")) {
        cerr << "Erreur de chargement de l'image du bouton de pause." << endl;
        return 1;
    }
    sf::Sprite NoSoundSprite(NoSoundTexture);
    NoSoundSprite.setPosition(10, window.getSize().y - NoSoundSprite.getGlobalBounds().height - 10);

    bool buttonPressed = false;
    bool Spause = true;

    // Boucle principale
    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                // Vérification si le clic est sur le bouton "Start"
                if (buttonNormalSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    sound2.play();
                    cout << "Bouton start cliqué !" << endl;
                    sj.sfmlInit(&window);
                    sj.sfmlBoucle(&window);
                    buttonPressed = true;
                }
                // Vérification si le clic est sur le bouton de son
                if (SoundSprite.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    // Inverser l'état du son
                    if (Spause) {
                        sound.stop();
                    } else {
                        sound.play();
                    }
                    Spause = !Spause; // Inverser l'état de Spause
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
        if (Spause) {
            window.draw(SoundSprite); // Afficher le bouton son normal
        } else {
            window.draw(NoSoundSprite); // Afficher le bouton son coupé
        }
        window.display();
    }

    return 0;
}
