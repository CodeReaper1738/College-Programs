/*
	Title:  	ch3practice.cpp
	Author:  	Two Pump Prairie Crockett
	Date:		2/6/2020
	Purpose:	Practice linear & binary search
*/
#include <iostream>
using namespace std;

const int SIZE = 15;

void sort(string arr[]);
void print(string arr[]);
bool linearSearch(string [], string);
bool binarySearch(string [], string);
//add prototype for linear search function
//add prototype for binary search function

int main()
{
	string userCountry;

	string countries[SIZE] = 
		{
			"China",
			"Hong Kong", 
			"Australia",
			"Canada",
			"Finland",
			"France",
			"Germany",
			"India",
			"Italy",
			"Japan",
			"Spain",
			"Sweden",
			"Thailand",
			"United Kingdom",
			"United States"
		};
		
	cout << "\nWhat is the name of your country?  ";
	getline(cin, userCountry);
	
	//linear search
	cout << "\nLinear Search says that your country ";
	if(linearSearch(countries, userCountry))
		cout << "does";
	else
		cout << "does not";
	cout << " have a confirmed case of the Coronavirus.\n";
	
	//sort is necessary for binary search
	sort(countries);
	
	//print to make sure it is sorted
	print(countries);
	
	//binary search
	cout << "\nBinary Search says that your country ";
	if(binarySearch(countries, userCountry))
		cout << "does";
	else
		cout << "does not";
	cout << " have a confirmed case of the Coronavirus.\n";
	
	return 0;
}


bool linearSearch(string countries[], string userCountry) {
	for(int i = 0; i < SIZE; i++) {
		if(countries[i] == userCountry) {
			return true;
		}
	}
	return false;
}
bool binarySearch(string countries[], string userCountry) {
	int i = 0;
	int end = SIZE - 1;
	bool corona = false;
	while(i >= end && !corona) {
		int middle = (i + end)/2;
		if(userCountry == countries[middle])
			corona = true;
		else if(userCountry < countries[middle])
			end = middle -1;
		else 
			i = middle + 1;
	}
	return corona;
}

//a simple function to sort array elements in ascending order
void sort(string arr[])
{
	string key; 
	int j;  
	
	for(int i=1; i < SIZE; i++)
	{
		key = arr[i]; 
		j = i-1; 
		while(j >= 0 && arr[j] > key) 
		{
			arr[j+1] = arr[j]; 
			j = j-1; 
		}
		arr[j+1] = key;
	}
}

//print array elements
void print(string arr[])
{
	cout << "\nSorted list of countries:\n";
	for(int x=0; x < SIZE; x++)
	{
		cout << arr[x] << "\n";
	}
	cout << endl;
}




