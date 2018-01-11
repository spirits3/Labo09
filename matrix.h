/*
 -----------------------------------------------------------------------------------
 Laboratoire : 09 Matrices
 Fichier     : matrix.cpp
 Auteur(s)   : Florian Schaufelberger, Jeremy Zerbib
 Date        : 15.01.2018

 But         : Toolbox for operations on matrices

 Remarque(s) :

 Compilateur : MinGW-g++ <x.y.z>
 -----------------------------------------------------------------------------------
*/

#ifndef LABO09_MATRIX_H
#define LABO09_MATRIX_H

#include <vector>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <ctime>
#include "random.h"

using Line   = std::vector<int>;
using Matrix = std::vector<Line>;

bool isFull(const Matrix &m);

bool isSquared(const Matrix &m);

Line lineSum(const Matrix &m);

Line colSum(const Matrix &m);

bool antiDiagSum(int &sum, const Matrix &m);

bool diagSum(int &sum, const Matrix &m);

void display(const Matrix &m);

void display(const Line &l);

Line min(const Matrix &m);

void shuffle(Matrix &m);

void shuffle(Matrix &m, int line);

void sort(Matrix &m);

void sort(Matrix &m, int line);


#endif //LABO09_MATRIX_H
