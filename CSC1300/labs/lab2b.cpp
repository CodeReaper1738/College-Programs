#include<iostream>

#include<iomanip>

using namespace std;

int main () {
	int customers = 16500;
	int oneWeek = customers * 0.15;
	
	cout << setprecision(0) << fixed;
	
	cout << "Num of people who drink more than one a week: " << oneWeek << endl;
	cout << "Num of people who drink more than one a week prefer Citrus flavored: " << oneWeek * 0.58 << endl;
	
	return 0;
}