/*
--------------------------------------------------------------------------------------------------------
Laboratory : 05 Calendar
File       : io.h
Author(s)  : Jonathan Zaehringer, Pierre Kohler
Date       : 1.11.2017

Aim        : Header of io.cpp, define macro to clean buffer, reset buffer,
                wait interaction from user and user want redo the software

Compiler   : Apple LLVM version 8.0.0 (clang-800.0.42.1) or MinGW-g++ 4.9.2
--------------------------------------------------------------------------------------------------------
*/
#ifndef IO_HEADER
#define IO_HEADER

#include <string>
#include <iostream>
#include <limits>

#define CLEAN_BUFFER cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define RESET_BUFFER cin.clear(); CLEAN_BUFFER
#define JUMP std::cout << endl

// ---------------------
// User input functions
// ---------------------
unsigned char getChar(const std::string& question); 
int getInt(const std::string& question); 
int getIntBetween(int min, int max, const std::string& question);

bool wantsUserRedo(const unsigned char& yes,const unsigned char& no, const std::string& question);
void waitUserInteraction();

void trashChar();

// ---------------------
// Printing functions
// ---------------------
void printCell(int value, int width);
void printCell(char value, int width);

#endif
