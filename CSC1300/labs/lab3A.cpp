#include<iostream>
#include<string>

using namespace std;

int main() {
	int integer;
	double inpDbl;
	char character;
	string inpString;
	
	cout << "Enter integer: " << endl;
	cin >>  integer;
	cout << "Enter double: " << endl;
	cin >> inpDbl;
	cout << "Enter character: " << endl;
	cin >> character;
	cout << "Enter String: " << endl;
	getline(cin, inpString);
	
	cout << endl << integer << " " << inpDbl << " " << character << " " << inpString << endl;
	cout << endl << inpString << " " << character << " " << inpDbl << " " << integer << endl;
	cout << inpDbl << " cast to an integer is " << (int)inpDbl;
}