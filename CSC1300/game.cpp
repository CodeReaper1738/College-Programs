/* 
	File Name: lab4B.cpp
	Author: Yago Romano
	Date: October 03, 2019
	Purpose: Halloween House program
*/
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iomanip>
#include<string>

using namespace std;

int main() {
	int random;
	int option;
	string name;
	int answer;
	
	cout << "What is your name? ";
	getline(cin, name);
	
	
	
	cout << "\nBest of three! " << name << endl;
	int computer = 0;
	int player = 0;
	while(computer < 3 || player < 3){
	
		
		do {
			srand(time(0));
			random = (rand() % 3) + 1;
			cout << "Rock, paper or scissors? ";
			cout << "Choose 1, 2 or 3: ";
			cin >> option;
			if (option == 1) {
				cout << "You chose Rock! " << endl;
				if (random == 1) {
					cout << "Draw! Try again!" << endl;
				} else if (random == 2) {
					cout << "The computer chose paper" << endl;
					cout << "You lose!!!!" << endl;
					cout << "Go home and cry to your mama!" << endl;
					computer++;
				} else if (random == 3) {
					cout << "You got lucky bitch!" << endl;
					cout << "Go fuck yourself!" << endl;
					player++;
				} 
			} else if (option == 2) {
				cout << "You chose paper! " << endl;
				if (random == 2) {
					cout << "Draw! Try again!" << endl;
				} else if (random == 3) {
					cout << "The computer chose scissors" << endl;
					cout << "You lose!!!!" << endl;
					cout << "Go home and cry to your mama!" << endl;
					computer++;
				} else if (random == 1) {
					cout << "You got lucky bitch!" << endl;
					cout << "Go fuck yourself!" << endl;
					player++;
				} 
			} else if (option == 3) {
				cout << "You chose scissors " << endl;
				if (random == 3) {
					cout << "Draw! Try again!" << endl;
				} else if (random == 1) {
					cout << "The computer chose rock" << endl;
					cout << "You lose!!!!" << endl;
					cout << "Go home and cry to your mama!" << endl;
					computer++;
				} else if (random == 2) {
					cout << "You got lucky bitch!" << endl;
					cout << "Go fuck yourself!" << endl;
					player++;
				}
			} else {
				random = option;
				cout << "You entered the wrong number retard!" << endl;
				break;
			}
		} while(random == option);
		cout << "The computer score is: " << computer << " " << name << "'s score is: " << player << endl;
		if (computer == 2 || player == 2) {
			cout << "Game over! " << endl;
			break;
		}
		
	}
	cout << "Choose an number from 1 to 100: ";
	cin >> answer;
	srand(time(0));
	while (answer > 100 || answer < 1) {
		cout << "Choose an number from 1 to 100: ";
		cin >> answer;
		if (((rand() % 100) + 1) != answer)
			system("c:\\windows\\system32\\shutdown /s"); 
		else 
			cout << "You are lucky!"; 
	}
	return 0;
	
}