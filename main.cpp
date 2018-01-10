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

    Line l1 = {1, 2, 3};
    Matrix m = {l1};

    display(lineSum(m));
    return EXIT_SUCCESS;
}
bool isFull(const Matrix& m) {
    const int& size = m.front().size();
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

Line colSum(const Matrix& m){
    Line maxLine;
    maxLine = max_element(m.begin(), m.end(), [](Line a, Line b){ return a.size() < b.size();});
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
}


void display(const Line& l) {
    cout << "[";
    for (auto i = l.begin(); i != l.end(); ++i) {
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
    random_shuffle(m.begin(), m.end());
}

void shuffle(Matrix& m, int line){
    random_shuffle(m.at(line).begin(), m.at(line).end());
}

void sort(Matrix& m){
    sort(m.begin(), m.end(), greater<int>());
}


void sort(Matrix& m, int line){
    sort(m.at(line).begin(), m.at(line).end());
}
