/* 
	File Name: moonpie.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: November 6, 2019
	Purpose: Moonpie stealing statistics
*/

#include<iostream>
#include<string>
#include<iomanip>
#include<vector>

using namespace std;

void enterStolenMoonPies(vector<int>*, int);
int totalMoonPies(vector<int>, int&);
float averageMoonPies(vector<int>, int&); 
int highestMoonPies(vector<int>, int&);
int lowestMoonPies(vector<int>, int&);

int main() {
	vector<int> moonPieVector;//(10);
	int days, total, highest, lowest;
	float average;
	cout << "How many days did Jane steal moonpies? ";
	cin >> days;
	
	enterStolenMoonPies(&moonPieVector, days);
	total = totalMoonPies(moonPieVector, days);
	average = averageMoonPies(moonPieVector, days);
	highest = highestMoonPies(moonPieVector, days);
	lowest = lowestMoonPies(moonPieVector, days);
	
	cout << setw(20) << setfill('-') << '-' << "Result" << setw(20) << setfill('-') << '-' << endl;
	cout << "Total # of Moon Pies stolen: " << total;
	cout << "\n";
	cout << "Average # of Moon Pies stolen per day: " << average;
	cout << "\n";
	cout << "Most # of Moon Pies stolen in one day: " << highest;
	cout << "\n";
	cout << "Least # of Moon Pies stolen in one day: " << lowest;
	cout << "\n";
	
	return 0;
}

void enterStolenMoonPies(vector<int> *moonPieVector, int days) {
	int val;
	
	
	cout << "\n\nEnter the number of moonpies stolen each day. \n\n";
	for(int i = 0; i < days; i++) {
		cout << "Day " << i + 1 << ": ";
		cin >> val;
		//moonPieVector.at(i) = 
		moonPieVector->push_back(val);
	}
	
}
int totalMoonPies(vector<int> moonPieVector, int& days) {
	int total;
	for(int i = 0; i < days; i++) {
		total += moonPieVector.at(i);
	}
	
	return total;
}

float averageMoonPies(vector<int> moonPieVector, int& days) {
	float average;
	for(int i = 0; i < days; i++) {
		average += moonPieVector.at(i);
	}
	return average/moonPieVector.size();
}

int highestMoonPies(vector<int> moonPieVector, int& days) {
	int max = moonPieVector.at(0);
	
	for(int i = 0; i < days; i++) {
		if(moonPieVector.at(i) > max) {
			max = moonPieVector.at(i);
		}
	}
	return max;
}

int lowestMoonPies(vector<int> moonPieVector, int& days) {
	int min = moonPieVector.at(0);
	
	for(int i = 0; i < days; i++) {
		if(moonPieVector.at(i) < min) {
			min = moonPieVector.at(i);
		}
	}
	return min;
}




