/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09 Matrices
 Fichier     : main.cpp
 Auteur(s)   : Florian Schaufelberger, Jeremy Zerbib
 Date        : 15.01.2018

 But         : Use of "vector" tables and "algorithms"

 Remarque(s) :

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
*/

#include <cstdlib>
#include <vector>
#include <iostream>
#include "matrix.h"
#include "io.h"

using namespace std;


//To test the functions you can simply uncomment the lines below.

int main() {
    Line l1 = {1, 2, 3};
    Line l2 = {4, 0, 0};
    Line l3 = {4, 5, 6, 7};
    Line l4 = {12, 32, 0};
    //Non full matrix
    Matrix m = {l3, l1, {}};
    //Full and squared matrix
    Matrix m1 = {l1, l1, l1};
    //Full but non squared matrix
    Matrix m2 = {l1, l2};
    //Squared matrix with different lines;
    Matrix m3 = {l1, l2, l4};

//    cout << "m est complète : " << isFull(m) << " et carrée : " << isSquared(m) << endl;
//    cout << "m1 est complète : " << isFull(m1) << " et carrée : " << isSquared(m1) << endl;
//    cout << "m2 est complète : " << isFull(m2) << " et carrée : " << isSquared(m2) << endl;
//
//    int sum = 0;
//    display(m);
//    JUMP;
//    display(m1);
//    JUMP;
//    display(m2);
//    JUMP;
//    display(m3);
//    JUMP;
//
//    display(lineSum(m));
//    JUMP;
//    display(lineSum(m1));
//    JUMP;
//    display(lineSum(m2));
//    JUMP;
//
//    display(colSum(m));
//    JUMP;
//    display(colSum(m1));
//    JUMP;
//    display(colSum(m2));
//    JUMP;
//
//    antiDiagSum(sum, m);
//    cout << sum << endl;
//    sum = 0;
//    antiDiagSum(sum, m1);
//    cout << sum << endl;
//    sum = 0;
//    antiDiagSum(sum, m2);
//    cout << sum << endl;
//    sum = 0;
//    antiDiagSum(sum, m3);
//    cout << sum << endl;
//    sum = 0;
//
//
//    diagSum(sum, m);
//    cout << sum << endl;
//    sum = 0;
//    diagSum(sum, m1);
//    cout << sum << endl;
//    sum = 0;
//    diagSum(sum, m2);
//    cout << sum << endl;
//    sum = 0;
//    diagSum(sum, m3);
//    cout << sum << endl;
//    sum = 0;
//
//    display(min(m));
//    display(min(m1));
//    display(min(m2));
//    display(min(m3));
//
//    shuffle(m);
//    display(m);
//    JUMP;
//
//    shuffle(m1);
//    display(m1);
//    JUMP;
//
//    shuffle(m2);
//    display(m2);
//    JUMP;
//
//    shuffle(m3);
//    display(m3);
//    JUMP;
//
//    shuffle(m, 0);
//    display(m.at(0));
//
//    shuffle(m, 1);
//    display(m.at(1));
//
//    sort(m2);
//    display(m2);
//    JUMP;
//
//    sort(m3, 0);
//    sort(m3, 1);
//    sort(m3, 2);
//
//    display(m3);

    waitUserInteraction();
    return EXIT_SUCCESS;
}
