/* 
	File Name: Functions.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: October 23, 2019
	Purpose: External functions 
*/
#include "Elephant.h"


void getElephantData(float foodAmount[], string elNames[]) {
	foodAmount[size];
	elNames[size];
	
	for (int i = 0; i < size; i++) {
		cout << "Elephant " << i + 1 << ":" << endl;
		cout << "Name - ";
		getline(cin, elNames[i]);
		cout << "Food Amount - ";
		cin >> foodAmount[i];
		cin.ignore();
	}
	
}

void getStats(float amountFood[], string elephantName[], float &totalFood, float &average, int &numMax) {
	int max = amountFood[0];
	for (int i = 0; i < size; i++) {
		totalFood += amountFood[i];
		average = totalFood / 10;
		if(amountFood[i] > max) {
			max = amountFood[i];
			numMax = i;
		}
	}
	
	

}
