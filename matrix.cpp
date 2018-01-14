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

/**
 * check if the matrix is full
 * @param  m matrix
 * @return   bool
 */
bool isFull(const Matrix &m) {
    if (m.empty()) {
        return false;
    }
    size_t size = m.front().size();
    return all_of(m.begin() + 1, m.end(), [=](Line l) { return l.size() == size; });
}

/**
 * check if the matrix is squarred
 * @param  m matrix
 * @return   bool
 */
bool isSquared(const Matrix &m) {
    return isFull(m) && m.size() == m.front().size();
}

/**
 * vector with sum of value in each line of the matrix 
 * @param  m matrix
 * @return   Line (vector<int>)
 */
Line lineSum(const Matrix &m) {
    Line sumLine;
    for (const Line &l : m) {
        sumLine.push_back(accumulate(l.begin(), l.end(), 0));
    }
    return sumLine;
}

/**
 * will check what is the maxCol of the matrix
 * @param  m matrix
 * @return   unsigned
 */
unsigned maxCol(const Matrix &m) {

    if (m.empty()) {
        return 0;
    }

    return (*(max_element(m.begin(), m.end(), [](const Line &l1, const Line &l2) {
        return l1.size() < l2.size();
    }))).size();
}

/**
 * sum in each coloumn of the matrix
 * @param  m matrix
 * @return   Line (vector<int>)
 */
Line colSum(const Matrix &m) {
    Line retour(maxCol(m));
    for (const Line &l : m) {
        for (auto it = l.begin(); it != l.end(); ++it) {
            retour.at(distance(l.begin(), it)) += *it;
        }
    }
    return retour;
}

/**
 * sum of the antidiag of the squarred matrix
 * @param  sum int sum that we will use outside the function
 * @param  m   matrix
 * @return     bool (check if the matrix is squarred)
 */
bool antiDiagSum(int &sum, const Matrix &m) {
    if (isSquared(m)) {
        for (int i = 0; i < m.size(); ++i) {
            sum += m.at(i).at(m.at(i).size() - i - 1);
        }
        return true;
    }
    return false;
}

/**
 * sum of the diagonal of the matrix
 * @param  sum int sum that we will use outside the function
 * @param  m   matrix
 * @return     bool (check if the matrix is squarred)
 */
bool diagSum(int &sum, const Matrix &m) {
    if (isSquared(m)) {
        for (int i = 0; i < m.size(); ++i) {
            sum += m.at(i).at(i);
        }
        return true;
    }
    return false;
}

/**
 * display the matrix
 * @param m matrix
 */
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

/**
 * display a vector
 * @param l Line l (vector<int> l)
 */
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

/**
 * check which sum of vector is the small one and will return the vector
 * @param  m matrix
 * @return   Line (vector<int>)
 */
Line min(const Matrix &m) {
    Line sum = lineSum(m);
    int index;
    auto min = min_element(sum.begin(), sum.end());
    index = distance(sum.begin(), min);
    return m.at(index);
}

/**
 * shuffle the order of the vector in the matrix
 * @param m matrix
 */
void shuffle(Matrix &m) {
    initRandom();
    random_shuffle(m.begin(), m.end());
}

/**
 * shuffle a Line of the matrix
 * @param m    matrix
 * @param line line (vector<int>)
 */
void shuffle(Matrix &m, int line) {
    if(line < m.size()){
        initRandom();
        random_shuffle(m.at(line).begin(), m.at(line).end());
    }
}

/**
 * will sort the matrix between the sum of line in ascending order
 * @param m matrix
 */
void sort(Matrix &m) {
    for (auto it = m.begin(); it != m.end(); ++it) {
        sort(it, m.end(), [](Line l1, Line l2) {
            return accumulate(l1.begin(), l1.end(), 0) < accumulate(l2.begin(), l2.end(), 0);
        });
    }
}

/**
 * will sort line in the matrix in ascending order
 * @param m    matrix
 * @param line Line (vector<int>)
 */
void sort(Matrix &m, int line) {
    if(line < m.size())
        sort(m.at(line).begin(), m.at(line).end());
}