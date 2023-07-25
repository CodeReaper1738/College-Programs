/* 
	File Name: Driver.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: October 23, 2019
	Purpose: Elephant Program
*/

#include "Elephant.h"

int main() {
	float foodTotal = 0, foodAverage = 0;
	float allFood[size];
	int foodMax;
	string zooName;
	string elephantName[size];
	
	cout << setprecision(2) << fixed;
	
	cout << "Hello! What is the name of your Elephant Zoo? \n";
	getline(cin, zooName);
	cout << "Enter the name and how many pounds of food each elephant ate last month. " << endl;
	
	getElephantData(allFood, elephantName);
	getStats(allFood, elephantName, foodTotal, foodAverage, foodMax);
	
	cout << setw(30) << setfill('-') << '-' << endl;
	
	cout << "The total amount of food consumed by all 10 elephants at " << zooName << " is " << foodTotal << " pounds in one month." << endl;
	
	cout << "The average amount of food consumed at " << zooName << " is " << foodAverage << " pounds." << endl;
	
	cout << "The elephant who eats the most(" << allFood[foodMax] << " pounds) is " << elephantName[foodMax] << "!!" << endl;
	
	cout << setw(30) << setfill('-') << '-' << endl;
	
	return 0;
	
}





