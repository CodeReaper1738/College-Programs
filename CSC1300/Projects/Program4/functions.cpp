/* 
	File Name: functions.cpp
	Author: Yago Romano
	Date: November 19, 2019
	Purpose: Pollution Program
*/

#include "pollution.h"


// Purpose: This function will allow the user to enter the names of each factory
// if they user enters the same name for two different factories it will force the 
// user to enter new names for the factories
void enterFactoryNames(string* factoryNames){
	do {
		for(int i = 0; i < SIZE; i++) {
			cout << "\nName of FACTORY " << i + 1<< ": ";
			getline(cin, *(factoryNames + i));
			cout << "\n";
			
		}
		if(*(factoryNames + 0) == *(factoryNames + 1) || *(factoryNames + 0) == *(factoryNames + 2) || *(factoryNames + 1) == *(factoryNames + 2)){
			cout << "Two of the factories have the same name!\n " << endl;
			cout << "Enter three different factories! " << endl;
		}
		// checks for factories to see if they are named the same
	} while(*(factoryNames + 0) == *(factoryNames + 1) || *(factoryNames + 0) == *(factoryNames + 2) || *(factoryNames + 1) == *(factoryNames + 2));
}

// Purpose: this function makes a new pointer array and returns it
float *makeArray(int years) {
	float* newArr = new float[years];
	return newArr;
}
// Purpose: This function allows the user to enter the data of the factories
// for the carbon monoxide
void enterCOData(float* factoryCOData, int years){
	cout << "\nCarbon Monoxide (CO) average level per hour (in parts per million) " << endl;
	for(int i = 0; i < years; i++){
		cout << "\n\tYear " << i + 1 << ": ";
		cin >> *(factoryCOData + i);
		
	}
	
}
// Purpose: This function allows the user to enter the data of the factories
// for the nitrogen dioxide
void enterNO2Data(float* factoryNO2Data, int years){
	cout << "\nNitrogen Dioxide (NO2) average level per hour (in parts per billion) " << endl;
	for(int i = 0; i < years; i++){
		cout << "\n\tYear " << i + 1 << ": ";
		cin >> *(factoryNO2Data + i);
	}
}

// Purpose: This function allows the user to enter the data of the factories
// for the ozone
void enterO3Data(float* factoryO3Data, int years){

	cout << "\nOzone (O3) average level per 8 hours (in parts per million) " << endl;
	for(int i = 0; i < years; i++){
		cout << "\n\tYear " << i + 1 << ": ";
		cin >> *(factoryO3Data + i);
	}
}

// Purpose: This function prints the names of the companies that are
// above the limit
void printOverLimit(string* factoryNames, float** getData, int years, const float getLimit){
	vector<bool> var(SIZE);
	for(int i = 0; i < SIZE; i++) {
		var.at(i) = false;
	}
	for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < years; j++) {
			if(*(*(getData + i) + j) > getLimit) {
				var.at(i) = true;
			}
		}
	}
	for(int i = 0; i < SIZE; i++){
		if(var.at(i) == true) {
			cout << *(factoryNames + i) << endl;
		}
		
	}
	if(var.at(0) == false && var.at(1) == false && var.at(2) == false) {
		cout << "Yay! There are no factories are over the limit " << endl;
	}		
	
}
void getLargest(string* factoryNames, float** getData, int years, int& getYear, float& getAmount, string& name){
	getAmount = *(*(getData + 0) + 0);
	for(int i = 0; i < SIZE; i++){
		for(int j = 0; j < years; j++) {
			if(*(*(getData + i) + j) > getAmount) {
				getAmount = *(*(getData + i) + j);
				name = *(factoryNames + i);
				getYear = j + 1;
				
			}
		}
	}

}