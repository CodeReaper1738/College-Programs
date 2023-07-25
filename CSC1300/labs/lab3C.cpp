// This program calculates the circumference of a circle.
#include<iostream>
#include<cmath>
#include<string>

using namespace std;

int main()
{
	const float PI = 3.14159;
	string fullName;
	float diameter;

	float circumference;
	
	cout << "\n\nWhat is the diameter of the circle?\n";
	cin >> diameter;
	cin.ignore();
	
	cout << "\n\nWhat is your first & last name?\n";
	getline(cin, fullName);

	// Calculate the circumference.
	circumference = PI * diameter;
	
	// Display the circumference.
	cout << "\n\nHello, " << fullName;
	cout << "! The circumference of your circle is: " << circumference;
	cout << endl << endl;
	
	return 0;
}