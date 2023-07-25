/* 
	File Name: lab12.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: November 20, 2019
	Purpose: Esports Program
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<vector>


using namespace std;

struct Player {
	string name;
	string hometown;
	int age;
	int numGames;
};

int main() {
	int numPlayers;
	int mostHours, leastHours;
	int* addHours;
	string mostName, leastName;
	

	
	cout << "\nHow many esports players are there at TTU who major in CSC? " << endl;
	cin >> numPlayers;
	cin.ignore();
	Player* array = new Player[numPlayers];
	addHours = new int[numPlayers];
	for(int i = 0; i < numPlayers; i++) {
		addHours[i] = 0;
	}
	
	cout << "\nPlease enter in information about each player: " << endl;
	int** playerHours = new int*[numPlayers];
	
	
	for(int i = 0; i < numPlayers; i++){
		cout << "\nPlayer " << i + 1 << ": " << endl;
		cout << "\tName: ";
		cin.ignore();
		getline(cin, array[i].name);
		cout << "\tHometown: ";
		getline(cin, array[i].hometown);

		cout << "\tAge: ";
		cin >> array[i].age;
		
		cout << "\tHow many games does " << array[i].name << " Play? ";
		cin >> array[i].numGames;
		playerHours[i] = new int[array[i].numGames];
		for(int j = 0; j < array[i].numGames; j++) {
			
			cout << "\t\tNumber of hours " << array[i].name << " played game " << j + 1 << ": ";
			cin >> playerHours[i][j];
			addHours[i] += playerHours[i][j];
			
		}
		
		
	}
	
	mostHours = addHours[0];
	leastHours = mostHours;
	for(int i = 0; i < numPlayers; i++) {
		if(addHours[i] > mostHours) {
			mostHours = addHours[i];
			mostName = array[i].name;
		} else if(addHours[i] < leastHours){
			leastHours = addHours[i];
			leastName = array[i].name;
		}
		
	}
	
	cout << "\n\nThe player who played the most hours (" << mostHours << " hours) is " << mostName;
	cout << "\n\nThe player who played the least hours (" << leastHours << " hours) is " << leastName;
	
	
	for(int i = 0; i < numPlayers; i++){
		delete [] playerHours[i];
	}
	delete [] playerHours;
	delete [] addHours;
	delete [] array;
	
}