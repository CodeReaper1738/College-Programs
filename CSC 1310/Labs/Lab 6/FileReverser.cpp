/*****************************************************************
	Title:  	FileReverser.cpp - template 
	Date:  		2-24-2020
	Author: 	Yago Romano
	Purpose:	template linked list stack
******************************************************************/

#include "Stack.h"

int main() {
	ifstream inFile;
	ofstream outFile;
	char letter;
	Stack<char> reword;
	
	//Opening files
	inFile.open("file1.txt");
	outFile.open("file2.txt");
	
	
	if(!inFile)
		cout << "File could not be opened!\n";
	else 
		cout << "Opening File1.txt as input\n";
	
	cout << "Opening File2.txt as output\n";
	
	cout << "Reading one character at a time from file1.txt and pushing the character onthe stack.\n";
	
	// Runs until reaches the end of the file
	inFile.get(letter);
	while(!inFile.eof()){
		
		reword.push(letter);
		inFile.get(letter);
	}
	
	cout << "Done reading all of file1.txt.  All characters from the file have been pushed on the stack.\n" << endl;	
	
	cout << "Popping one character at a time from the stack and writing the character tofile2.txt.\n";
	while(!reword.isEmpty()){
		reword.pop(letter);
		outFile << letter;
	}
	
	cout << "Done!  See your results in file2.txt.\n";
	
	inFile.close();
	outFile.close();
	
	return 0;
}