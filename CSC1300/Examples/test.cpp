#include<iostream>

using namespace std;

struct Employee{
	string name;
	int intID;
	float yearSalary;
	int numYearsWorked;
};
int main() {
	Employee stuff;
	cout << "\nWhat is your name? ";
	getline(cin, stuff.name);
	cout << "\nWhat is your ID? ";
	cin >> stuff.intID;
	cout << "\nWhat is your yearly salary? ";
	cin >> stuff.yearSalary;
	cout << "How many years have you worked at their company? ";
	cin >> stuff.numYearsWorked;
	
	return 0;
}