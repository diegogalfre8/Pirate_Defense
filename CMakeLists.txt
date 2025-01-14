cmake_minimum_required(VERSION 3.22.1)

project(Projet)



set(SRCS  
    ./src/core/mainAzits.cpp 
    ./src/core/Jeu.cpp 
    ./src/core/Personnage.cpp   
    ./src/core/Map.cpp 
    ./src/core/Tir.cpp 
    ./src/core/Arme.cpp 
    ./src/core/Jeu.cpp 
    ./src/core/Ennemis.cpp 
    ./src/core/Vecteur.cpp)

set(SRCSTxt  
    ./src/txt/main_txt.cpp 
    ./src/txt/txtJeu.cpp 
    ./src/txt/winTxt.cpp  
    ./src/core/Jeu.cpp 
    ./src/core/Personnage.cpp   
    ./src/core/Map.cpp 
    ./src/core/Tir.cpp 
    ./src/core/Arme.cpp 
    ./src/core/Jeu.cpp 
    ./src/core/Ennemis.cpp 
    ./src/core/Vecteur.cpp)



set(INCLUDES ./src/core/)
set(INCLUDES ./SFML-2.6.1)
set(INCLUDES2 ./src/core/ ./src/txt)


set(SRCS2 
    ./src/core/mainDiego.cpp  
    ./src/core/Jeu.cpp 
    ./src/core/Personnage.cpp   
    ./src/core/Map.cpp 
    ./src/core/Tir.cpp 
    ./src/core/Arme.cpp 
    ./src/core/Jeu.cpp 
    ./src/core/Ennemis.cpp 
    ./src/core/Vecteur.cpp) 

set(SRCS3 
    ./src/core/mainRihade.cpp  
    ./src/core/Jeu.cpp 
    ./src/core/Personnage.cpp   
    ./src/core/Map.cpp 
    ./src/core/Tir.cpp 
    ./src/core/Arme.cpp 
    ./src/core/Jeu.cpp 
    ./src/core/Ennemis.cpp 
    ./src/core/Vecteur.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(testAzits ${SRCS})
target_include_directories(testAzits PUBLIC ${INCLUDES})

add_executable(testTxt ${SRCSTxt})
target_include_directories(testTxt PUBLIC ${INCLUDES2})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(testDiego ${SRCS2})
target_include_directories(testDiego PUBLIC ${INCLUDES})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)
add_executable(testRihade ${SRCS3})
target_include_directories(testRihade PUBLIC ${INCLUDES})




set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -ggdb")

target_link_directories(testAzits PUBLIC ${DIR_LIBS})
target_link_libraries(testAzits ${LIBS})

target_link_directories(testTxt PUBLIC ${DIR_LIBS})
target_link_libraries(testTxt ${LIBS})

target_link_directories(testDiego PUBLIC ${DIR_LIBS})
target_link_libraries(testDiego ${LIBS})

target_link_directories(testRihade PUBLIC ${DIR_LIBS})
target_link_libraries(testRihade ${LIBS})


# Recherche de SFML
find_package(SFML 2.5 COMPONENTS graphics window system audio REQUIRED)

# Ajout de l'exécutable
add_executable(sfml src/sfml/mainTest.cpp)
set(SRCSSFML src/sfml/sfmlJeu.cpp  ./src/core/Jeu.cpp ./src/core/Personnage.cpp   ./src/core/Map.cpp ./src/core/Tir.cpp ./src/core/Arme.cpp ./src/core/Jeu.cpp ./src/core/Ennemis.cpp ./src/core/Vecteur.cpp)
set(INCLUDESSFML ./src/core ./src/sfml)
add_executable(sfmlJeu  src/sfml/main.cpp ${SRCSSFML})
target_include_directories(sfmlJeu PUBLIC ${INCLUDESSFML})
# Liaison des bibliothèques SFML
target_link_libraries(sfml  PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)
target_link_libraries(sfmlJeu PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

add_executable(sfmldiego src/sfml/sfmldiego.cpp  ${SRCSSFML})
target_include_directories(sfmldiego PUBLIC ${INCLUDESSFML})
target_link_libraries(sfmldiego PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

