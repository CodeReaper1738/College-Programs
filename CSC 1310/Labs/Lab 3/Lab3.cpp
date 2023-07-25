/*
	Title:  Lab3.cpp
	Author: Yago Romano, Yoshinori agari
	Purpose:  Demonstrate your knowledge of recursive functions
*/

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cstring>
using namespace std;

//function prototypes for the recursive functions
int sumOfNumbers(int);
bool isMember(int*, int, int);
void stringReverser(string, int);
bool isPalindrome(string);
int multiply(int, int);

const int ARRAY_SIZE = 10;

int main()
{
	int choice, num, num1, num2;
	int myArray[ARRAY_SIZE];
	srand(time(NULL));
	string userString, userStrWithoutSpaces, userStrModified;
	
	do{
		
		cout << "\n\nWhat do you want to do?\n";
		cout << "\t1.  Sum of Numbers\n";
		cout << "\t2.  IsMember Array Function\n";
		cout << "\t3.  String Reverser\n";
		cout << "\t4.  Palindrome Detector\n";
		cout << "\t5.  Recursive Multiplication\n";
		cout << "\t6.  End the Program\n";
		cout << "CHOOSE 1-6:  ";
		cin >> choice;
		while(choice < 1 || choice > 6)
		{
			cout << "\nInvalid input!  CHOOSE 1-6:  ";
			cin >> choice;
		}
		switch(choice)
		{
			case 1:
				cout << "\n\nSUM OF NUMBERS\n";
				cout << "Enter an integer:  ";
				cin >> num;
				//print out the result of the sumOfNumbers function here
				cout << sumOfNumbers(num);
				break;
				
				
			case 2:
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					myArray[x] = (rand()%100)+1;
				}
				cout << "\n\nISMEMBER ARRAY FUNCTION\n";
				cout << "Enter an integer:  ";
				cin >> num;
				cout << "\nHere are the array values:  ";
				for(int x=0; x<ARRAY_SIZE; x++)
				{
					cout << myArray[x] << " ";
				}
				//print if the value that the user entered is in the array or not here
				if(isMember(myArray, num, ARRAY_SIZE)){
					cout << "\nThe value is in the array\n";
				} else 
					cout << "\nThe value is not in the array\n";
				
				break;
				
				
				
			case 3:
				cout << "\n\nSTRING REVERSER\n";
				cout << "Enter a string and I will reverse it:  ";
				cin.ignore();
				getline(cin, userString);
				//call string reverser function here
				stringReverser(userString, userString.size());
				break;
				
				
			case 4:
				cout << "\n\nPALINDROME DETECTOR\n";
				cout << "Enter a string and I will tell you if it is a palindrome:  ";
				cin.ignore();
				getline(cin, userString);
				
				//change string to be all uppercase
				for(int x=0; x<userString.length(); x++)
				{
					userString[x] = toupper(userString[x]);
				}
				
				//remove spaces and commas from string
				userStrModified = userString;
				for(int x=0; x<userStrModified.size(); x++)
				{
					if(userStrModified[x] == ' ') 
					{
						userStrModified.erase(x, 1);
					}
					if(userStrModified[x] == ',') 
					{
						userStrModified.erase(x, 1);
					}
				}
				
				//print out whether the user's string is a palindrome or not here.
				if(isPalindrome(userStrModified)) {
					cout << "\nYes! " << userStrModified << " Is a palindrome!\n";
				} else 
					cout << "\nNo! " << userStrModified << " Is not a palindrome!\n";
				//when you print out the user's string, print out the uppercase version that doesn't have the spaces removed.
				
				break;
				
				
			case 5:
				cout << "\n\nRECURSIVE MULTIPLICATION\n";
				cout << "Enter in the first integer:  ";
				cin >> num1;
				cout << "\nEnter in the second integer:  ";
				cin >> num2;
				//print out the value returned from the multiply function here
				cout << multiply(num1, num2);
				break;
				
		}		
	}while(choice != 6);
	
	cout << "\n\nGOODBYE!\n\n";
	return 0;
}




//implement the five recursive functions below!!!!


int sumOfNumbers(int num){
	if(num <= 0)
		return 0;
	else if(num == 1)
		return 1;
	else 
		return sumOfNumbers(num - 1) + num;
}

bool isMember(int* arr, int value , int size) {
	if(size == 0) {
		return false;
	} else if(arr[size-1] == value) {
		return true;
	} else {
		return isMember(arr, value, size-1);
	}
}
void stringReverser(string object, int len){
	if(len > 0) {
		cout << object.at(len - 1);
		stringReverser(object, len - 1);
	}
}
bool isPalindrome(string text){
	if(text.length() <= 1) {
		return true;
	}
	else if(text.at(0) == text.at(text.length() - 1)) {
		text = text.substr(1, text.length()-2);
		return isPalindrome(text);
	} else 
		return false;
	
}
int multiply(int x, int y) {
	if(x == 0)
		return 0;
	else if(x == 1) 
		return y;
	else {
		return multiply(x - 1, y) + y;
		
	}
}


