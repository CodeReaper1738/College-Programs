/* 
	File Name: functions.cpp
	Author: Yago Romano
	Date: October 29, 2019
	Purpose: Hangman Program
*/




#include "hangman.h"

/* Purpose: This function will print the stage of the hangman game */
	
void printStage(int &numGuesses){
	if (numGuesses == 0) {
		cout <<  	"  +-----+    \n";
		cout << 	"  |     |\n";
		cout << 	"  |     \n" ;
		cout << 	"  |     \n";
		cout << 	"  |     \n";
		cout << 	"  |\n"     ;
		cout << 	"  |\n"     ;
		cout << 	"  | \n"    ;
		cout << 	"  | \n" ;
		cout << "--------------\n";
	} else if (numGuesses == 1) {
		cout <<  	"  +-----+    \n";
		cout << 	"  |     | \n";
		cout << 	"  |     o \n" ;
		cout << 	"  |     \n";
		cout << 	"  |     \n";
		cout << 	"  |\n"     ;
		cout << 	"  |\n"     ;
		cout << 	"  | \n"    ;
		cout << 	"  | \n" ;
		cout << "--------------\n";
	} else if (numGuesses == 2) {
		cout <<  	"  +-----+    \n";
		cout << 	"  |     | \n";
		cout << 	"  |     o \n" ;
		cout << 	"  |     |\n";
		cout << 	"  |     | \n";
		cout << 	"  |\n"     ;
		cout << 	"  |\n"     ;
		cout << 	"  | \n"    ;
		cout << 	"  | \n" ;
		cout << "--------------\n";
		
	} else if (numGuesses == 3) {
		cout <<  	"  +-----+    \n";
		cout << 	"  |     | \n";
		cout << 	"  |     o \n" ;
		cout << 	"  |     |\\\n";
		cout << 	"  |     | \n";
		cout << 	"  |\n"     ;
		cout << 	"  |\n"     ;
		cout << 	"  | \n"    ;
		cout << 	"  | \n" ;
		cout << "--------------\n";
		
	} else if (numGuesses == 4) {
		cout <<  	"  +-----+    \n";
		cout << 	"  |     | \n";
		cout << 	"  |     o \n" ;
		cout << 	"  |    /|\\\n";
		cout << 	"  |     | \n";
		cout << 	"  |\n"     ;
		cout << 	"  |\n"     ;
		cout << 	"  | \n"    ;
		cout << 	"  | \n" ;
		cout << "--------------\n";
		
	} else if (numGuesses == 5) {
		cout <<  	"  +-----+    \n";
		cout << 	"  |     | \n";
		cout << 	"  |     o \n" ;
		cout << 	"  |    /|\\\n";
		cout << 	"  |     | \n";
		cout << 	"  |      \\\n";
		cout << 	"  |\n"     ;
		cout << 	"  | \n"    ;
		cout << 	"  | \n" ;
		cout << "--------------\n";
		
	} else if (numGuesses == 6) {
		cout <<  	"  +-----+    \n";
		cout << 	"  |     | \n";
		cout << 	"  |     o \n" ;
		cout << 	"  |    /|\\\n";
		cout << 	"  |     | \n";
		cout << 	"  |    / \\\n";
		cout << 	"  |\n"     ;
		cout << 	"  | \n"    ;
		cout << 	"  |   DEAD! \n" ;
		cout << "--------------\n";
		
	}
}
// Purpose: This function will print out the underscores with a space in between them
void printWord(char word[], char underScores[]) {
	int wordLength = strlen(word);
	cout << "\nWORD: ";
	// This prints out the underscores with a space between them
	for(int i = 0; i < wordLength; i++) {
		cout << underScores[i] << " ";
	}
	cout << "\n\n";
	
}
// Purpose: This function will print the letter that have already been guessed
void printLettersGuessed(char alphabet[], bool userGuesses[]) {
	for (int v = 0; v < 26; v++) {
		userGuesses[v];
		// This checks for the positions of the letters that are set to true to print out the letters that have been guessed
		if(userGuesses[v] == true) {
			cout << alphabet[v] << " ";
		} 
	}
	
	
}