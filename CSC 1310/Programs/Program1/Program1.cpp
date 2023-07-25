/*
	Driver for the program 1
	Program1 - CSC1310
	Yago Romano
	
	2/13/2020
*/
#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"




using namespace std;

int main() {
	int option, maxGames;
	char fileName[25];
	
	cout << "\nHow many video games can your library hold?";
	cin >> maxGames;
	cin.ignore();
	
	VideoGameLibrary* gameLibrary = new VideoGameLibrary(maxGames);
	
	do{
		do{
			cout << "\nWhat would you like to do?\n";
			cout << "1. Load video games from file.\n";
			cout << "2. Save video games to a file.\n";
			cout << "3. Add a video game.\n";
			cout << "4. Remove a video game.\n";
			cout << "5. Display all video games.\n";
			cout << "6. Remove ALL video games from this library and end program.\n";
			cout << "CHOOSE 1-6: ";
			cin >> option;
			cin.ignore();
			cin.clear();
			
			if(option > 6 || option < 1) 
				cout << "\nThat was an invalid input\n";
		}while(option > 6 || option < 1);
		
		switch(option) {
			case 1:
					cout << "\nWhat is the name of the file? (example.txt): "; 
					cin >> fileName;	
					gameLibrary->loadVideoGamesFromFile(fileName);
					break;
			case 2: 
					cout << "\nWhat do you want to name the file? (example.txt): ";
					cin >> fileName;
					gameLibrary->saveToFile(fileName);
					break;
			case 3:
					gameLibrary->addVideoGameToArray();
					break;
			case 4:
					gameLibrary->removeVideoGameFromArray();
					break;
			case 5:
					gameLibrary->displayVideoGames();
					break;
			case 6:
					delete gameLibrary;
					cout << "\nGOODBYE!" << endl;
					break;
			
		}
	} while(option != 6);
	
	return 0;
}