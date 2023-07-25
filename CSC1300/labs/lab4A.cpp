/* 
	File Name: lab4A.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: September 18, 2019
	Purpose: Caffeine Half life
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	//Initializing a variable
	double caffeine = 0.00;
	
	// set decimal output to two
	cout << setprecision(2) << fixed;
	cout << "How much caffeine did you intake? " << endl;
	cin >> caffeine;
	
	// Output the amount of caffeine
	cout << "After 6 hours: " << caffeine / 2.00 << " mg" << endl;
	cout << "After 12 hours: " << caffeine / 4.00 << " mg" << endl;
	cout << "After 18 hours: " << caffeine / 8.00 << " mg" << endl;
	
	return 0;
}