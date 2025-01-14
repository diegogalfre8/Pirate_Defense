# Pirate Defense

Pirate Defense est un jeu de type tower defense développé en C++ avec une version texte sur terminal (Wintxt) ainsi qu'une version graphique jouable, utilisant SFML.

## Scénario

Votre équipage de pirates a découvert une île au trésor, mais d'autres pirates tentent de l'atteindre pour piller le trésor. Vous devez survivre aux vagues d'ennemis et les empêcher de traverser le fleuve afin de protéger le trésor de l'île.

### Personnages

- **L'équipage** : Composé de plusieurs personnages de différents niveaux, votre équipage doit défendre l'île au trésor.
![P1](https://forge.univ-lyon1.fr/p2205540/projetjeu/-/raw/main/data/Equipage1.gif?ref_type=heads)
  
- **Les ennemis** : Des pirates de résistances variés tentent d'atteindre l'île pour piller le trésor.
![E1](https://forge.univ-lyon1.fr/p2205540/projetjeu/-/raw/main/data/PersoEnnemi.gif?ref_type=heads)


## Objectif

Le but du jeu est de défendre l'île le plus longtemps possible en empêchant les ennemis d'atteindre leur destination. Vous devez créer et positionner votre équipage pour repousser les assauts ennemis.

## Participants

- Diego Galfré (P2205540)
- Cheikh Ali Abdoul-Anziz (P2101250)
- Riadh Chinoun (P2203462)


## Arborescence du Projet

Le projet est structuré comme suit :

- **bin**: Ce répertoire contient les fichiers exécutables générés après la compilation du projet.
- **build**: C'est ici que les fichiers temporaires de la compilation sont stockés.
- **data**: Ce répertoire contient les données du jeu, telles que les images, les sons, etc.
- **doc**: Documentation du projet.
- **src**: Contient le code source du projet.
  - **core**: Contient les fichiers sources de la version texte du jeu.
  - **txt**: Contient la version texte avec Wintxt
  - **sfml**: Contient les fichiers sources de la version graphique utilisant SFML.

## Installation et Exécution

### Utilisation de CMake

Ce projet utilise CMake pour la gestion de la construction du code source. Voici les étapes pour compiler le projet en utilisant CMake :

1. Assurez-vous d'avoir CMake installé sur votre système.
2. Dans le répertoire racine du projet, créer le repertoire build.
3. Exécutez la commande suivante dans build pour configurer le projet : cmake ..

### Version Texte
Pour avoir un aperçu du fontionnement du noyau du jeu en version terminal
1. Clonez le dépôt.
2. Compilez le code source avec un compilateur C++ compatible.
3. Exécutez la commande ./bin/testTxt pour lancer le jeu.

### Version Graphique (SFML)

1. Assurez-vous d'avoir SFML installé sur votre système.
2. Clonez le dépôt.
3. Compilez le code source avec un compilateur C++ compatible en incluant les bibliothèques SFML.
4. Exécutez la commande ./bin/sfmlJeu pour jouer à la version graphique du jeu.
5. Contrôles: Utilisez la souris pour placer les personnages et les éléments défensifs sur la carte.
6. À présent, moussaillon, le destin de l'île et de son trésor repose entre vos mains... Bon courage!


![Presentation](https://forge.univ-lyon1.fr/p2205540/projetjeu/-/raw/main/data/HomePirate.png?ref_type=heads)