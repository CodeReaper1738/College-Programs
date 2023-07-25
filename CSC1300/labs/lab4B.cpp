/* 
	File Name: lab4B.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: September 18, 2019
	Purpose: Seasons
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	// Declaring a var
	int date;
	
	string month;
	
	
	
	
	cout << "What month? " << endl;
	getline(cin, month);
	cout << "What day? " << endl;
	cin >> date;
	
	
	if(month == "January") {
		cout << "winter" << endl;
	}
	else if(month == "February") {
		cout << "winter" << endl;
	}	
	else if(month == "March"){	
		if (date < 20) {
			cout << "winter" << endl;
		} else {
			cout << "spring" << endl;
		}
	}	
	else if(month == "April"){
		cout << "spring" << endl;
	}
	else if(month == "May"){
		cout << "spring" << endl;
	}
	else if(month == "June"){
		if (date < 21) {
			cout << "spring" << endl;
		} else {
			cout << "summer" << endl;
		}
	}
	else if (month == "July"){
		cout << "summer" << endl;
	}
	else if(month == "August"){
		cout << "summer" << endl;
	}
	else if(month == "September"){
		if (date < 22) {
			cout << "summer" << endl;
		} else {
			cout << "autumn" << endl;
		}
	}
	else if(month == "October"){
		cout << "autumn" << endl;
	}
	else if(month == "November"){
		cout << "autumn" << endl;
	}
	else if(month == "December") {
		if (date < 21) {
			cout << "autumn" << endl;
		} else {
			cout << "winter" << endl;
		}
	} else {
		cout << "Invalid" << endl;
		
	}
	
	
	
	

}
