/* 
	File Name: lab7.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: October 11, 2019
	Purpose: GRINGOTT"S BANK
*/

#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

void DisplayMenuGetChoice();
void GoblinSickDays();
int DisplayCoolMessage();


int main() {
	int choice;
	int totalDisplayed = 0;
	do {
		DisplayMenuGetChoice();
		cin >> choice;
		while(choice > 3 || choice < 1) {
			cout << "Please enter a valid option: "; 
			DisplayMenuGetChoice(); 
		}
			switch (choice) {
			case 1: 
					GoblinSickDays();
					break;
			case 2: DisplayCoolMessage();
					totalDisplayed++;
					break;
			case 3: cout << "\nYou chose to display the cool message " << totalDisplayed <<  " times." << endl;
				
					cout << "\nBye" << endl;
					break;
			}
		
	} while (choice != 3);
		
	return 0;
}

void DisplayMenuGetChoice() {
	
	cout << "\nWELCOME TO GRINGOTT's BANK! " << endl;
	cout << "Please choose one of the following options: " << endl;
	cout << "\t1 - Enter Goblin Sick Days " << endl;
	cout << "\t2 - Display Something Cool " << endl;
	cout << "\t3 - End the Program " << endl;	

}

void GoblinSickDays() {
	int sick, worked, totalSick, gobNum;
	cout << "How many Goblin tellers worked at Gringotts during each of the last three years? " << endl;
	cin >> worked;
	
	for(gobNum = 1; gobNum <= worked; gobNum++) {
		for(int year = 1; year < 4; year++) {
			
			cout << "How many sick days was Goblin " << gobNum << " out for, during year " << year << "? ";
			cin >> sick;
			totalSick += sick;
		}
	}
	cout << "The " << gobNum - 1 << " Goblin(s) were out sick for a total of " << totalSick - 1 << " days during the last 3 years."; 
}
int DisplayCoolMessage() {
	
    cout << "  /$$$$$$            /$$                                 /$$     /$$  " << endl;           
	cout << " /$$__  $$          |__/                                | $$    | $$  " << endl;           
	cout << "| $$  \\__/  /$$$$$$  /$$ /$$$$$$$   /$$$$$$   /$$$$$$  /$$$$$$ /$$$$$$   /$$$$$$$" << endl;
	cout << "| $$ /$$$$ /$$__  $$| $$| $$__  $$ /$$__  $$ /$$__  $$|_  $$_/|_  $$_/  /$$_____/" << endl;
	cout << "| $$|_  $$| $$  \\__/| $$| $$  \\ $$| $$  \\ $$| $$  \\ $$  | $$    | $$   |  $$$$$$" << endl;
	cout << "| $$  \\ $$| $$      | $$| $$  | $$| $$  | $$| $$  | $$  | $$ /$$| $$ /$$\\____  $$" << endl;
	cout << "|  $$$$$$/| $$      | $$| $$  | $$|  $$$$$$$|  $$$$$$/  |  $$$$/|  $$$$//$$$$$$$/" << endl;
	cout << " \\______/ |__/      |__/|__/  |__/ \\____  $$ \\______/    \\___/   \\___/ |_______/ " << endl;
	cout << "				   /$$  \\ $$                                     " << endl;
	cout << "				  |  $$$$$$/                                     " << endl;
	cout << "				  \\______/                                      " << endl;

}