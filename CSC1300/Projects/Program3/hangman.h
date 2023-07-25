#ifndef HANGMAN_H
#define HANGMAN_H

// Headers
#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>

// Standard namespace
using namespace std;

// Function prototypes
void printStage(int&);
void printWord(char[], char[]);
void printLettersGuessed(char[], bool[]);


#endif