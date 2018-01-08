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

#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;
using Line   = vector<int>;
using Matrix = vector<Line>;

bool isSquared(Matrix& m);

Line lineSum(Matrix& m);

Line colSum(Matrix& m);

bool antiDiagSum(int& sum, Matrix& m);

bool diagSum(int& sum, Matrix& m);

void display(Matrix& m);

void display(Line& l);

Line min(Matrix& m);

void shuffle(Matrix& m);

void shuffle(Matrix& m, int line);

void sort(Matrix& m);

void sort(Matrix& m, int line);

int main(){
    return EXIT_SUCCESS;
}


