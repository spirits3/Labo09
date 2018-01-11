/*
--------------------------------------------------------------------------------------------------------
Laboratory : 05 Calendar
File       : io.cpp
Author(s)  : Jonathan Zaehringer, Pierre Kohler
Date       : 1.11.2017

Aim        : Library to interacte with user and display a table

Comment(s) : 

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2
--------------------------------------------------------------------------------------------------------
*/
#include <iostream>
#include <iomanip>

#include "io.h"

using namespace std;

// -------------------------------
// User input functions
// -------------------------------

/**
 *
 * @param question
 * @return Asks a question to the user and returns a character
 */
unsigned char getChar(const string& question) {
    const string ERROR = "La valeur n'est pas un caractère.";

    unsigned char result;
    bool badValue;

    do {
        cout << question;
        cin >> result;

        if ((badValue = cin.fail())) {
            RESET_BUFFER;
        }

    } while (badValue && cout << ERROR << endl);

    CLEAN_BUFFER;

    return result;
}

/**
 *
 * @param question
 * @return Asks a question to the user and returns an integer
 */
int getInt(const string& question) {
    const string ERROR = "La valeur n'est pas un entier.";

    int result;
    bool badValue;

    do {
        cout << question;
        cin >> result;

        if ((badValue = cin.fail())) {
            RESET_BUFFER;
        }

    } while (badValue && cout << ERROR << endl);

    CLEAN_BUFFER;

    return result;
}

/**
 * @brief Checks the buffer for a potential mistake
 * @param value
 * @return if the buffer was inputed with an error,
 *         return a boolean screaming false
 */
bool getInt(int& value) {
    cin >> value;

    if (cin.fail()) {
        RESET_BUFFER;
        return true;
    }

    return false;   
}

/**
 *
 * @param min
 * @param max
 * @param question
 * @return The number of value between two bounds
 */
int getIntBetween(int min, int max, const string& question) {
    const string ERROR = string(" n'est pas compris entre ") + to_string(min) + " et " + to_string(max) + ".";

    int result;

    do {
        result = getInt(question);
    } while ((result > max || result < min) && cout << result << ERROR << endl);

    return result;
}

/**
 * Deletes a character from the buffer
 */
void trashChar(){
    cin.get();
}

/**
 *
 * @param yes
 * @param no
 * @param question
 * @return a bool that makes the program go on or exit.
 */
bool wantsUserRedo(const unsigned char& yes,const unsigned char& no, const string& question) {
    const string ERROR = "ne répond pas à la question.";

    unsigned char result;

    do {
        result = getChar(question);
    } while ((result != yes && result != no) && cout << "'" << result << "'" << ERROR << endl);

    return (result == yes);
}

/**
 * Waits for the user to interact with the program.
 */
void waitUserInteraction() {
    cout << "presser ENTER pour quitter";
    
    CLEAN_BUFFER;
}

// -------------------------------
// Printing functions
// -------------------------------

/**
 * Prints a cell
 * @param value
 * @param width
 */
void printCell(int value, int width) {
    cout << right << setw(width) << value;
}

/**
 * Prints a cell
 * @param value
 * @param width
 */
void printCell(char value, int width) {
    cout << right << setw(width) << value;
}
