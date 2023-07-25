#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<vector>

using namespace std;

struct Drinks {
	string drinkName;
	float drinkCost;
	int numOfDrinks;
};

const int SIZE = 5;
int main() {
	
	int choice = 6;
	Drinks dMachine[SIZE] = {	("Cola      ", 0.75, 20)
								("Root Beer ", 0.75, 20)
								("Lemon-Lime", 0.75, 20)
								("Grape Soda", 0.80, 20)
								("Cream Soda", 0.80, 20)
							};
							
/*	for(int i = 0; i < SIZE; i++) {
		cout << "\nEnter drink " << i + 1 << " name: ";
		getline(cin, dMachine[i].name);
		cout << "\nPrice:";
		cin >> dMachine[i].cost;
		cout << "\nnum;
	}
*/	
	do {
		cout << "--------------------------------------------" << endl;
		for(int i = 0; i < SIZE; i++) {
			cout << i + 1 << ") " << dMachine[i].drinkName << "\t\t" << dMachine[i].drinkCost
			<< "\t\t" << dMachine[i].numOfDrinks << "\t\t";
		}
		cout << "\nChoose 6 to exit: ";
		cout << "\nChoose one: ";
		cin >> choice;
		
	} while(choice != 6);
	
	return 0;
}