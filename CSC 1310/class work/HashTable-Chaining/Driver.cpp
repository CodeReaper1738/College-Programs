#include <iostream>
#include "HashTable.h"
using namespace std;

int main()
{
	string size;
	string value;
	
	cout << "\nHello.\n\n";
	
	cout <<"What size is the table?   ";
	getline(cin, size);
	
	//create a Hash Table
	HashTable myHashTable(size);
	
	//add some keys and values
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\nEnter a value:  ";
	cin >> value;
	myHashTable.putValue(value, value);
	
	cout << "\n\nHERE IS THE TABLE:\n\n";
	myHashTable.printHashTable();
	cout << endl << endl;
	
	
	
}