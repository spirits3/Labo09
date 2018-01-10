/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09 Matrices
 Fichier     : random.cpp
 Auteur(s)   : Florian Schaufelberger, Jeremy Zerbib
 Date        : 15.01.2018

 But         : Init random

 Remarque(s) :

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
*/

#include <ctime>
#include <cstdlib>
#include "random.h"

/**
 * Initialize the random
 */
void initRandom() {
    static bool done = false;

    unless (done) {
        std::srand(std::time(0));

        done = true;
    }
}
