#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;


int main () {

    float width, height, area;

    const int paintCoverage = 350;



    cout << "Wall Width: ";
    cin >> width;
    cout << "\nWall Height: ";
    cin >> height;

    area = width * height;

    cout << setprecision(2) << fixed;

    cout << "The wall is " << area << " square feet." << endl;
    cout << "You will need " << (int)ceil(area / paintCoverage) << " cans of paint";
}
