/* 
	File Name: lab6A.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: October 02, 2019
	Purpose: Guess a number
*/

#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>

using namespace std;

int main() {
	
	//declaring variables
	char play;
	int response;
	int randomNumber;
	int count;
	//actually random number
	srand(time(0));
	randomNumber = (rand() % 100) + 1;
	//Do you want to play
	cout << "Are you ready to play (y/n)? ";
	cin >> play;
	
	// nested loop 
	do {
		//while the number guessed is wrong
		do {
			cout << "\nEnter your guess : ";
			cin >> response;
			while(response > 100 || response < 1) {
				cout << "You entered an invalid number. Choose between 1 and 100.";
				cout << "\nEnter your guess : ";
				cin >> response;
			}
			count++;
			if (response > randomNumber) {
				cout << "\nToo High" << endl;
			} else if (response < randomNumber) {
				cout << "\nToo Low" << endl;
			} else if (response == randomNumber) {
				cout << "Corrrect! You got it in " << count << " tries!" << endl;
			}
			
			
		} while(randomNumber != response);
		
		cout << "Do you want to play again (y/n)? ";
		cin >> play;
		
		
	} while(play == 'y');
	return 0;
}