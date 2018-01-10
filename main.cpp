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
#include <numeric>
#include <algorithm>
#include <ctime>
#include "random.h"

using namespace std;
using Line   = vector<int>;
using Matrix = vector<Line>;

bool isFull     (const Matrix& m);

bool isSquared  (const Matrix& m);

Line lineSum    (const Matrix& m);

Line colSum     (const Matrix& m);

bool antiDiagSum(int& sum, const Matrix& m);

bool diagSum    (int& sum, const Matrix& m);

void display    (const Matrix& m);

void display    (const Line& l);

Line min        (const Matrix& m);

void shuffle    (Matrix& m);

void shuffle    (Matrix& m, int line);

void sort       (Matrix& m);

void sort       (Matrix& m, int line);

int main(){
    int sum = 0;
    Line l1 = {1, 2, 3};
    Line l2 = {4, 0, 0};
    Line l3 = {4, 5, 6, 7};
    //Non full matrix
    Matrix m = {l3, l1, {}};
    //Full and squared matrix
    Matrix m1 = {l1, l1, l1};
    //Full but non squared matrix
    Matrix m2 = {l1, l2};

    cout << "m est complète : "  << isFull(m)  << " et carrée : " << isSquared(m)  << endl;
    cout << "m1 est complète : " << isFull(m1) << " et carrée : " << isSquared(m1) << endl;
    cout << "m2 est complète : " << isFull(m2) << " et carrée : " << isSquared(m2) << endl;

    display(m);
    display(m1);
    display(m2);

    display(lineSum(m));
    cout << endl;
    display(lineSum(m1));
    cout << endl;
    display(lineSum(m2));
    cout << endl;

    display(colSum(m));
    cout << endl;
    display(colSum(m1));
    cout << endl;
    display(colSum(m2));
    cout << endl;

    antiDiagSum(sum, m);
    cout << sum << endl;
    antiDiagSum(sum, m1);
    cout << sum << endl;
    antiDiagSum(sum, m2);
    cout << sum << endl;


    diagSum(sum, m);
    cout << sum << endl;
    diagSum(sum, m1);
    cout << sum << endl;
    diagSum(sum, m2);
    cout << sum << endl;


    return EXIT_SUCCESS;
}

bool isFull(const Matrix& m) {
    if (m.empty()){
        return false;
    }
    size_t size = m.front().size();
    return all_of(m.begin()+1, m.end(), [=](Line l){ return l.size() == size; });
}

bool isSquared(const Matrix& m) {
    return isFull(m) && m.size() == m.front().size();
}

Line lineSum(const Matrix& m){
    Line sumLine;
    for (const Line& l : m) {
        sumLine.push_back(accumulate(l.begin(), l.end(), 0));
    }
    return sumLine;
}

unsigned maxCol (const Matrix& m) {

    if (m.empty()){
        return 0;
    }

    return (*(max_element(m.begin(), m.end(), [](const Line& l1, const Line& l2){
        return l1.size() < l2.size(); }))).size();
}

Line colSum(const Matrix& m){
    Line retour(maxCol(m));
    for (const Line& l : m) {
        for (auto it = l.begin(); it != l.end(); ++it){
            retour.at(distance(l.begin(), it)) += *it;
        }
    }
    return retour;
}

bool antiDiagSum(int& sum, const Matrix& m){
	if (isSquared(m)){
        for(int i = 0; i < m.size(); ++i){
            sum += m.at(i).at(m.at(i).size() - i - 1);
        }
        return true;
    }
    return false;
}

bool diagSum(int& sum, const Matrix& m){
	if (isSquared(m)){
        for(int i = 0; i < m.size(); ++i){
            sum += m.at(i).at(i);
        }
        return true;
    }
    return false;
}

void display(const Matrix& m) {
    cout << "[";
    for (const Line& l : m) {
        if (l != *m.begin()){
            cout << ",";
        }
        display(l);

    }
    cout << "]";
    cout << endl;
}

void display(const Line& l) {
    cout << "[";
    for (Line::const_iterator i = l.begin(); i != l.end(); ++i) {
        if (i != l.begin()) {
            cout << ",";
        }
        cout << *i;
    }
    cout << "]";

}


Line min(const Matrix& m){
    Line sum = lineSum(m);
    int index;
    auto min = min_element(sum.begin(), sum.end());
    index = distance(sum.begin(), min);
    return m.at(index);
}


void shuffle(Matrix& m){
    initRandom();
    random_shuffle(m.begin(), m.end());
}

void shuffle(Matrix& m, int line){
    initRandom();
    random_shuffle(m.at(line).begin(), m.at(line).end());
}

void sort(Matrix& m){
	for(int i = 0; i < m.size(); ++i){
	    sort(m,i);
		sort(m.begin(), m.end());
		}
}

void sort(Matrix& m, int line){
    sort(m.at(line).begin(), m.at(line).end());
}
