#include<iostream>

#include<iomanip>

using namespace std;

int main () {
	double stockPrice = 35.00;
	double stockComm = 0.02;
	double stockAmount = stockPrice * 750; 
	double stockTotal = (stockAmount * stockComm) + stockAmount;
	
	cout << setprecision(2) << fixed;
	
	cout << "Amount paid for the stock: $" << stockAmount << endl;
	cout << "Commision paid on the sale: $" << stockAmount * stockComm << endl;
	cout << "Total amount paid for stock: $" << stockTotal << endl;
	
	return 0;
}