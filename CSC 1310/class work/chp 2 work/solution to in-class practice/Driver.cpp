#include "Planet.h"
#include "AddPrint.h"
#include <iostream>
using namespace std;

int main()
{
	int num1, num2;
	Planet planet1, planet2;
	double minTemp, maxTemp, radius;
	
	cout << "\nGive me an integer: ";
	cin >> num1;
	
	cout << "\nGive me another integer: ";
	cin >> num2;
	
	AddPrint<int> addprint_1;
	cout << "\nThe numbers added together is " << addprint_1.add(num1, num2) << endl;
	addprint_1.print(num1);
	addprint_1.print(num2);
	
	cout <<"--------------------------------------------\n";
	
	
	cout << "\nWhat is the min surface temp of planet 1?  ";
	cin >> minTemp;
	planet1.setMinSurfaceTemp(minTemp);
	cout << "\nWhat is the max surface temp of planet 1?  ";
	cin >> maxTemp;
	planet1.setMaxSurfaceTemp(maxTemp);
	cout << "\nWhat is the radius of planet 1?  ";
	cin >> radius;
	planet1.setRadius(radius);
	
	
	cout << "\nWhat is the min surface temp of planet 2?  ";
	cin >> minTemp;
	planet2.setMinSurfaceTemp(minTemp);
	cout << "\nWhat is the max surface temp of planet 2?  ";
	cin >> maxTemp;
	planet2.setMaxSurfaceTemp(maxTemp);
	cout << "\nWhat is the radius of planet 2?  ";
	cin >> radius;
	planet2.setRadius(radius);
	
	AddPrint<Planet> addprint_2;
	
	Planet newPlanet = addprint_2.add(planet1, planet2);
	cout << "\nThe radius of the two planets added together is ";
	cout << newPlanet.getRadius();
	
	cout << "\n\nPlanet One:\n";
	addprint_2.print(planet1);
	cout << "Planet Two:\n";
	addprint_2.print(planet2);
	
	cout << endl;
	return 0;
}