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

#include "matrix.h"
#include "io.h"

using namespace std;

bool isFull(const Matrix &m) {
    if (m.empty()) {
        return false;
    }
    size_t size = m.front().size();
    return all_of(m.begin() + 1, m.end(), [=](Line l) { return l.size() == size; });
}

bool isSquared(const Matrix &m) {
    return isFull(m) && m.size() == m.front().size();
}

Line lineSum(const Matrix &m) {
    Line sumLine;
    for (const Line &l : m) {
        sumLine.push_back(accumulate(l.begin(), l.end(), 0));
    }
    return sumLine;
}

unsigned maxCol(const Matrix &m) {

    if (m.empty()) {
        return 0;
    }

    return (*(max_element(m.begin(), m.end(), [](const Line &l1, const Line &l2) {
        return l1.size() < l2.size();
    }))).size();
}

Line colSum(const Matrix &m) {
    Line retour(maxCol(m));
    for (const Line &l : m) {
        for (auto it = l.begin(); it != l.end(); ++it) {
            retour.at(distance(l.begin(), it)) += *it;
        }
    }
    return retour;
}

bool antiDiagSum(int &sum, const Matrix &m) {
    if (isSquared(m)) {
        for (int i = 0; i < m.size(); ++i) {
            sum += m.at(i).at(m.at(i).size() - i - 1);
        }
        return true;
    }
    return false;
}

bool diagSum(int &sum, const Matrix &m) {
    if (isSquared(m)) {
        for (int i = 0; i < m.size(); ++i) {
            sum += m.at(i).at(i);
        }
        return true;
    }
    return false;
}

void display(const Matrix &m) {
    cout << "[";
    for (const Line &l : m) {
        if (l != *m.begin()) {
            cout << ",";
        }
        display(l);

    }
    cout << "]";
    JUMP;
}

void display(const Line &l) {
    cout << "[";
    for (Line::const_iterator i = l.begin(); i != l.end(); ++i) {
        if (i != l.begin()) {
            cout << ",";
        }
        cout << *i;
    }
    cout << "]";

}


Line min(const Matrix &m) {
    Line sum = lineSum(m);
    int index;
    auto min = min_element(sum.begin(), sum.end());
    index = distance(sum.begin(), min);
    return m.at(index);
}


void shuffle(Matrix &m) {
    initRandom();
    random_shuffle(m.begin(), m.end());
}

void shuffle(Matrix &m, int line) {
    initRandom();
    random_shuffle(m.at(line).begin(), m.at(line).end());
}

void sort(Matrix &m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        sort(it, m.end(), [](Line l1, Line l2) {
            return accumulate(l1.begin(), l1.end(), 0) < accumulate(l2.begin(), l2.end(), 0);
        });
    }
}

void sort(Matrix &m, int line) {
    sort(m.at(line).begin(), m.at(line).end());
}

