/* 
	File Name: hangman.cpp
	Author: Yago Romano
	Date: October 08, 2019
	Purpose: Hangman Program
*/

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>
//#include "functions.cpp"
//#include "header.h"

using namespace std;

int main() {
	char word[21];
	char underScores[21];
	char alphabet[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool userGuesses[26];
	char playAgain;
	
	string wordBank[] = { "afganistan", "penguins", "infraction", "underscore", "reconstruct", "", "", "", "", "" };
	ifstream inputFile;
	ofstream outputFile;
	
	
	
	// open input File 
	outputFile.open("wordbank.txt");
	inputFile.open("wordbank.txt");
	// Check to see if the file opens
	if (inputFile.fail()) {
		cout << "A word could not be found in the word bank!" << endl;
	}
	
	// This will write all the words in wordBank in the input File
	for(int i = 0; i < 10; i++) {
		inputFile >> i;
		outputFile << i << "\n";
	}
	
	srand(time(0));
	int number = rand() % 10;
	
	do {
		
		
		
		
		
		cout << "Do you want to play again? ";
		cin >> playAgain;
		cout << "\n";
	} while(playAgain == 'y' || playAgain == 'Y');
}