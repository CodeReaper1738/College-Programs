/* 
	File Name: hangman.cpp
	Author: Yago Romano
	Date: October 29, 2019
	Purpose: Hangman Program
*/


#include "hangman.h"



int main() {
	// character array declaration
	char word[21];
	char underScores[21];
	char alphabet[27]= "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	bool userGuesses[26];
	char playAgain = 'y';
	string getWord;
	char letter;
	int i, count, checkWord, check, wordLength, index, wrongGuesses;
	bool letterFound;
	//string randomWord;
	
	ifstream inputFile;
	
	
	// Opens the file
	inputFile.open("wordBank.txt");	
	
	// Checks for the file to see if it can pull a word 
	if(!inputFile.good()) {
		cout << "The word could not be found in the word bank! " << endl;
	}
	
	
	do {
		count = 0;
		wrongGuesses = 0;
		
		// Pulls a word from the file
		inputFile >> getWord;
		
		// Copies the word from the file and puts it into the word array
		strcpy(word, getWord.c_str());
		
		// sets all of the characters in userGuesses to false
		for (int x = 0; x < 26; x++) {
			userGuesses[x] = false;
		}
		// Copies the word from the file and puts it into the underScores array
		strcpy(underScores, getWord.c_str());
		// sets all of the characters in underScores to an underscore
		for (int j = 0; j < strlen(word); j++) {
			underScores[j] = '_';
			
		}
		
		
		
		
		do {
			
			cout << setw(100) << setfill('*') << '*' << endl;
			// Calls the functions
			printWord(word, underScores);
			printStage(wrongGuesses);
			
			cout << "LETTERS YOU HAVE ALREADY GUESSED: ";
			
			printLettersGuessed(alphabet, userGuesses);
			
			// checks if there is a letter guessed 
			if(count == 0){
				cout << "(none have been guessed yet) ";
			} 
			// This is a new line
			cout << "\n";
			
			do {
				
				cout << "\n" << setw(100) << setfill('-') << '-' << endl;
				// Requests the user to input a letter 
				cout << " What letter do you want to guess? ";
				// Stores the letter
				cin >> letter;
				cout << "\n";
			
			} while(!isalpha(letter));
			
			// this will get the letter uppercase
			letter = toupper(letter);
			
			
			for(int z = 0; z < 26; z++) {
				// Checks to see if you have already guessed a letter
				
				while(alphabet[z] == letter && userGuesses[z] == true) {
					// Loop checks for a to see if you entered a letter
					cout << " You entered the same letter. Guess again! ";
					cin >> letter;
					letter = toupper(letter);
					cout << "\n";
					
					
				}
				
				// If letter has not been guessed it makes the that same position true in the user guesses array
				if(letter == alphabet[z] /*&& userGuesses == false*/)  {
					userGuesses[z] = true;
				}
			}
			// Turns the underscore into a letter if the letter is guesses right
			for (int r = 0; r < strlen(word); r++) {
				if(letter == word[r]) {
					// sets the underscore position to the letter 
					underScores[r] = word[r];
					
				}
			}
			letterFound = false;
	
			
			for(int index = 0; index < strlen(word); index++) {
				// Checks to see if the letter matches with a letter with a letter from the word
				if(letter == word[index]) {
					cout << setw(30) << setfill('>') << '>' << " CORRECT! " << setw(30) << setfill('<') << '<';
					underScores[index] = word[index];
					letterFound = true;
					
					break;
				// Checks to see if the letter doesn't match with a letter from the word
				} else if(letterFound != true && index == strlen(word) - 1) {
					cout << setw(30) << setfill('>') << '>' << " Wrong " << setw(30) << setfill('<') << '<';
					// Increments the stage funtion
					wrongGuesses++;
					
				}
			}
			// Gets you to click enter to proceed to the next step
			
			cout << "\n\nPress Enter to continue. ";
			cin.get();
			cin.get();
			
			// Compares the two strings
			checkWord = strcmp(underScores, word);
			
			// Checks to see if you guessed all of the letters of the word correctly
			if(checkWord == 0) {
				cout << "\nYou Win! The word was: " << getWord << ".";
				break;
			// Checks to see if you have missed the maximum amount of times	
			} else if(wrongGuesses == 6) {
				// Prints the last stage
				printStage(wrongGuesses);
				
			}
			count++;
			
		// This will run until the game is over
		} while (wrongGuesses != 6);
		
		
		

		// Checks to see if this made it to the end of the file and if it does it will restart the word bank
		if (!inputFile.eof()) {
			
			
			do {
				
				cout << "\n\nDo you want to play again? (y or n)";
				cin >> playAgain;
				cout << "\n";
			// Checks is they input a letter or not
			} while(!isalpha(playAgain));
		} else {
		// Restarts the file if it gets to the last word
			inputFile.clear();
			inputFile.seekg(0, ios::beg);
		}
	// The program will run until the user decides to stop playing 
	}while(playAgain == 'y' || playAgain == 'Y');
	
	
	// This will close the file
	inputFile.close();
	
	return 0;
}



