/* 
	File Name: program2.cpp
	Author: Yago Romano
	Date: October 08, 2019
	Purpose: Halloween House program
*/

#include<iostream>
#include<string>
#include<fstream>
#include<ctime>
#include<iomanip>
#include<cctype>

using namespace std;

int main() {
	//declaring all the variables
	char test, del;
	int option, start;
	time_t rawtime;
	float price, amount;
	float candyTotal, costumeTotal, decorationTotal;
	float num1, num2, num3;
	string str;
	
	// Initializing a constant variable
	const float TAX = 0.0975;
	
	// Decimals set to 2
	
	cout << setprecision(2) << fixed;
	
	// creating output files
	ofstream outputFile;
	ifstream inputFile;
	
	// assignment 
	test = 'n';
	
	outputFile << setprecision(2) << fixed;
	// This will run until the user wants to end the program
	do {
		
		
		// This will create a dashed line above
		cout << "\n\n" << setfill('-') << setw(60) << "-" << endl << endl;
		
		// Name of the House
		cout << "Halloweiner House Management Program" << endl << endl;
		
		// Menu items ask the user what do they want to do
		do {
			cout << "Please select from the following menu items: " << endl;
			cout << "1.\tEnter sales." << endl;
			cout << "2.\tTally Sales for the Day." << endl;
			cout << "3.\tDelete Sales for the Day." << endl;
			cout << "4.\tEnd Program." << endl;
			cout << "Choose 1, 2, 3 or 4: ";
			
			// Menu items input
			cin >> start;
			if (start > 4 || start < 1) {
				
				// This will output if they enter the wrong value
				cout << "\nYou entered an invalid value\n" << endl;
				cout << "Try again!\n" << endl;
			}
			
		} while(start > 4 || start < 1 );
		
		// Depending on what the user inputs for the menu items
		if (start == 1) {
			cout << "\nYou chose to enter sales" << endl << endl; 
			
			// This opens the file and saves it if it is opened again
			
			outputFile.open("Sales.txt", ios::app);
			
			do  {
				
				
				
				// This will repeat until valid number is entered
				do {
					// What is the user here to buy
					cout << "Choose the department from the following menu:" << endl;
					cout << "1.\tCandy" << endl;
					cout << "2.\tCostumes" << endl;
					cout << "3.\tDecorations" << endl;
					cout << "Choose 1, 2 or 3: ";
					
					// It will be stored here 
					cin >> option;
				} while(option > 3 || option < 1);
				
				
				// User decision on price of the item
				cout << "\nWhat is the price of the item? ";
				cin >> price;
				
				// User decision on the amount 
				cout << "\nHow many did you want to buy? ";
				cin >> amount;
				
				
				// The if else will store the total price of each option in the file
				// Saves the user input differently depending on the user option
				switch(option) {
					case 1: // This outputs candy to the file
							outputFile << "Candy" << endl;
							// This outputs the total price of candy 
							outputFile << (price * amount) + (price * amount * TAX) << endl;
							break;
					case 2: // This outputs costumes to the file
							outputFile << "Costumes" << endl;
							// This outputs the total price of costumes 
							outputFile << (price * amount) + (price * amount * TAX) << endl;
							break;
					case 3: // This outputs decorations to the file
							outputFile << "Decorations" << endl;
							// This outputs the total price of decorations 
							outputFile << (price * amount) + (price * amount * TAX) << endl;
							break;
				}
				
				// Does the user want to enter more sales
				cout << "\nDo you want to enter more sales? (y or n): ";
				cin >> test;
				
				// New line
				cout << "\n";
			
			} while(test == 'y');
			
			// This will close the output file
			outputFile.close();
			
				
		} else if (start == 2) {
			
			cout << "\nYou chose to total sales";
			inputFile.open("Sales.txt", ios::app);
			candyTotal = 0;
			costumeTotal = 0;
			decorationTotal = 0;
			
			time(&rawtime);
			
			// This will print out the time of the computer
			cout << "\n\n\nTOTAL SALES ON " << ctime(&rawtime) << endl << endl;
			
			
			// This will read until the end of the file
			while(!inputFile.eof()){
				
				
				// This will read the first line of the file
				inputFile >> str;
				if (!inputFile.eof()){
					if (str == "Candy") {
						
						// Sum of all of the candy input
						inputFile >> num1;
						candyTotal += num1;
					} else if (str == "Costumes") {
						
						// Sum of all of the costumes input
						inputFile >> num2;
						costumeTotal += num2;
					} else if (str == "Decorations") {
						
						// Sum of all of the decorations input
						inputFile >> num3;
						decorationTotal += num3;
					}
				}
			}
			
			// Output a dashed line
			cout << setfill('-') << setw(60) << "-" << endl;
			
			//Both the options and the prices will be printed out aligned to the right
			
			cout << right << setfill(' ') << setw(12) << "Candy:";
			cout << setw(11) << candyTotal << endl;
			cout << setw(12) << "Costumes:";
			cout << setw(11) <<  costumeTotal << endl;
			cout << "Decorations:";
			cout << setw(11) << decorationTotal << endl;
			
			// Output a dashed line
			cout << setfill('-') << setw(60) << "-" << endl << endl;
			
			
			// This will close the inputFile
			inputFile.close();
			
		} else if (start == 3) {
			
			// This will test for the right input of the user
			cout << "\nDo you wish to delete the Sales.txt file? (y or n): ";
			cin >> del;
			
			//Do they want to delete files 
			
			if (del == 'y') {
				
				// This will delete the file with all of the values stored for candy, costumes, or decorations if typed y.
				
				if(remove("Sales.txt") != 0) {
					
					cout << "\nError deleting file!\n" << endl;
					
				} else {
					
					cout << "\nFile deleted\n" << endl;
				}
			} else {
				cout << "\nYou chose not to delete the file." << endl;
			}
			
		} else if (start == 4) {
			
			// End program
			
			cout << "\n\nThank You and Have a Spooky day!" << endl;
			
			// This will delete the file 
			
			if(remove("Sales.txt") != 0);
			
			break;
		}
	} while (test == 'n');
	
	
	
	return 0;
}