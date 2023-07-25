#include <iostream>
#include <iomanip>
#include "Planet.h"
using namespace std;

int main()
{
	Planet* mercury = new Planet;
	mercury->setRadius(1516.0);
	cout << fixed << setprecision(1);
	cout << "\nMercury\'s size is " << mercury->getRadius() << endl;
	
	delete mercury;
	
	return 0;
}