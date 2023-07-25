/* 
	File Name: lab11.cpp
	Author: Yago Romano, Tyler Bradshaw
	Date: November 13, 2019
	Purpose: Library book genres Program
*/
#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>

using namespace std;

// Num of libraries
const int SIZE = 4;

int main() {
	int** numBooksArray;
	int genres;
	int* genArr;
	int max, lib, gen;
	
	numBooksArray = new int*[SIZE];
	
	
	cout << "How many genres of books do you have? " << endl;
	cin >> genres;
	cout << "\n";
	for(int i = 0; i < SIZE; i++) {
		genArr = new int[genres];
		*(numBooksArray + i) = genArr;
	}
	
	cout << "Please enter the number of books in each genre. " << endl << endl;
	
	for(int i = 0; i < SIZE; i++) {
		
		for(int j = 0; j < genres; j++){
			cout << "Library " << i + 1 << " Genre " << j + 1 << ": ";
			cin >>  *(*(numBooksArray + i) + j);
			cout << endl;
			
		}
	}
	max = *(*(numBooksArray + 0) + 0);
	 
	for(int i = 0; i < SIZE; i++) {
		
		for(int j = 0; j < genres; j++){
			if(max < *(*(numBooksArray + i)+ j)) {
				max = *(*(numBooksArray + i)+ j);
				lib = i + 1;
				gen = j + 1;
			}
			
		}
	}
	
	cout << "Library " << lib << " has the largest number of books in genre " << gen << endl;
	cout << "which contains " << max << " books!";
	
	for(int i = 0; i < SIZE; i++) {
		delete [] *(numBooksArray + i);
	}
	delete [] numBooksArray;
	
	return 0;
	
	
	
	
}