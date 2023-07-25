#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>

using namespace std;

int main() {
	int numPeople, numRode;
	
	cout << "How many people went to Dollywood in the last three months? ";
	cin >> numPeople;
	
	int** injuryArray[numPeople];
	
	for(int i = 0; i < numPeople; i++){
		
		
		cout << "How many rides did person " << i + 1 << " ride in the last three months? ";
		cin >> numRode;
		int* arrayPeople = new int[numRode];
		injuryArray[i] = arrayPeople;
		for(int j = 0; j < numRode; j++){
			cout << "Number of injuries on ride " << j + 1 << endl;
			cin >> &arrayPerson[j];
			cout << "\n Testing" << *arrayPerson[j] << " ";
		}
		delete [] injuryArray[i];
	}
	
	delete [] injuryArray;
	
	return 0;
}
















