/* 
	File Name: prog5.cpp
	Author: Yago Romano
	Date: November 19, 2019
	Purpose: Magical Creatures Program
*/




#include "prog5.h"





int main() {
	int option;
	Creatures array[100];
	int numCreatures = 0;
	char choice;
	
	ifstream inputFile;
	ofstream outputFile;
	
	do{
		
		cout << "\nWhat would you like to do? " << endl;;
		cout << "\t1. Enter some Magical Creatures." << endl;
		cout << "\t2. Delete a Magical Creature." << endl;
		cout << "\t3. List/Print Creatures." << endl;
		cout << "\t4. Print Statistics on Creature Cost." << endl;
		cout << "\t5. End Program. " << endl;
		cout << "\t Enter 1, 2, 3, 4, or 5." << endl;
		cout << "CHOICE: ";
		cin >> option;
		cout << "\n\n";
		
		while(option > 5 || option < 1) {
			cout << "Your choice was invalid. Choose a number 1 through 5. " << endl;
			cout << "CHOICE: ";
			cin >> option;
			cout << "\n\n";
		}
		cin.ignore();
		if(option == 1) 
			// Function call
			numCreatures = enterCreatures(numCreatures, array);
		else if(option == 2)
			numCreatures = deleteCreature(numCreatures, array);
		else if(option == 3)
			printCreatures(numCreatures, array);
		else if(option == 4)
			printStatistics(numCreatures, array);
		
	}while(option != 5);
	cout << "Would you like to save your creatures to a file? (y or n): ";
	cin >> choice;
	cin.ignore();
	cout << "\n";
	if(choice == 'y')
		// Saving the creatures file
		saveCreaturesToFile(numCreatures, array);
	
	

	return 0;
	
}










