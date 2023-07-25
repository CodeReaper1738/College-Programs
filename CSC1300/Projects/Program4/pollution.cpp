/* 
	File Name: pollution.cpp
	Author: Yago Romano
	Date: November 19, 2019
	Purpose: Pollution Program
*/
#include"pollution.h"

int main() {
	
	// Initializing string array
	string* factoryNames = new string [SIZE];
	
	// Initializing pointer arrays
	float** factoryCOData =  new float* [SIZE];
	float** factoryNO2Data = new float* [SIZE];
	float** factoryO3Data = new float* [SIZE];
	int years = 0, getYear;
	float getMax;
	string getName;
	
	cout << "\n" << setw(100) << setfill('-') << '-' << endl;
	cout << "\n" << setw(100) << setfill('-') << '-' << endl;
	
	// Function call
	enterFactoryNames(factoryNames);
	
	
	cout << "How many years of data do you have? " << endl;
	cin >> years;
	
	// checks if the user entered a letter
	while(/*!isdigit(int years) ||*/ isalpha(years)) {
		cout << "That is not a number enter again! " << endl;
		cout << "How many years of data do you have? " << endl;
		cin >> years;
	}
	
	cout << "\nPlease enter data for each factory. \n\n";
	// This for loop will allow you to input the data for all factories
	for(int i = 0; i < SIZE; i++) {
		cout << "\n" << setw(100) << setfill('-') << '-' << endl;
		cout << "\nFactory: " << *(factoryNames + i) << endl;
		
		// This will create a new pointer array and put the memory address inside the factory array
		*(factoryCOData + i) = makeArray(years);

		// Function call
		enterCOData(*(factoryCOData + i), years);
		// This will create a new pointer array and put the memory address inside the factory array
		*(factoryNO2Data + i) = makeArray(years);
		// Function call	
		enterNO2Data(*(factoryNO2Data + i), years);
		// This will create a new pointer array and put the memory address inside the factory array
		*(factoryO3Data + i) = makeArray(years);
		// Function call
		enterO3Data(*(factoryO3Data + i), years);
		
	}
	
	cout << "\n" << setw(100) << setfill('-') << '-' << endl;
	cout << "\n" << setw(100) << setfill('-') << '-' << endl;
	
	cout << "Factories over the CARBON MONOXIDE pollutant level (35): \n" << endl;
	printOverLimit(factoryNames, factoryCOData, years, CO_MAX_LIMIT);
	cout << endl;
	cout << "Factories over the NITROGEN DIOXIDE pollutant level (100): \n" << endl;
	printOverLimit(factoryNames, factoryNO2Data, years, NO2_MAX_LIMIT);
	cout << endl;
	cout << "Factories over the ozone pollutant level (0.07): \n" << endl;
	printOverLimit(factoryNames, factoryO3Data, years, O3_MAX_LIMIT);
	cout << endl;
	
	
	cout << "\n" << setw(100) << setfill('-') << '-' << endl;
	

	getLargest(factoryNames, factoryCOData, years, getYear, getMax, getName);
	cout << "\nThe " <<  getName << " factory produced the most carbon monoxide pollution with " << getMax <<
	" parts per million in year " << getYear << ". \n\n";
	getLargest(factoryNames, factoryNO2Data, years, getYear, getMax, getName);
	cout << "\nThe " <<  getName << " factory produced the most nitrogen dioxide pollution with " << getMax<<
	" parts per billion in year " << getYear << ". \n\n";
	getLargest(factoryNames, factoryO3Data, years, getYear, getMax, getName);
	
	cout << "\nThe " <<  getName << " factory produced the most ozone pollution with " << getMax <<
	" parts per million in year " << getYear << ". \n\n";
	
	cout << "\n" << setw(100) << setfill('-') << '-' << endl;
	cout << "\n" << setw(100) << setfill('-') << '-' << endl;
	
	// This will delete all the pointer arrays inside of the pointer arrays
	for(int i = 0; i < SIZE; i++) { 
		delete [] *(factoryCOData + i);
		delete [] *(factoryNO2Data + i);
		delete [] *(factoryO3Data + i);
	}
	
	// this will delete all of the factory pointer arrays
	delete [] factoryNames;
	delete [] factoryCOData;
	delete [] factoryNO2Data;
	delete [] factoryO3Data;
	
	
	
	return 0;
	
}
