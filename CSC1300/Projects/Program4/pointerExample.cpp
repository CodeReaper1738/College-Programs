#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>

using namespace std;

int main() {
	int numPeople;
	int* numRoller;
	int** injuryArray;
	
	
	
	
	cout << "How many people went to dollywood in the last three months? ";
	cin>> numPeople;
	
	injuryArray = new int*[numPeople];
	numRoller = new int[numPeople];
	
	for (int i = 0; i < numPeople; i++){
		cout << "How many rides did person: " << i + 1 << " ride in the last three months? ";
		cin >> *(numRoller + i);
		injuryArray[i] = new int[*(numRoller + i)];
		for(int j = 0; j < *(numRoller + i); j++){
			cout << "How many injuries in roller coaster " << i + 1 << ": ";
			cin >> injuryArray[i][j];	
		}
	}
	
	for(int i = 0; i < numPeople; i++){
		cout << "\n Person" << i+1 << ":\n";
		for(int j = 0; j < *(numRoller + i); j++){
			cout << "Coaster " << j+1 << ": ";
			cout << injuryArray[i][j] << endl;
		}
		cout << endl;
	}
	
	cout << "\nDone";
	
	
	for(int i = 0; i < numPeople; i++) {
		delete [] injuryArray[i];
	}
	delete [] numRoller;
	delete [] injuryArray;
	
	
	return 0;
}