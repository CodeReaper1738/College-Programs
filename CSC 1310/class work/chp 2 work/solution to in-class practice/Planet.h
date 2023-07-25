#ifndef PLANET_H
#define PLANET_H

#include <iostream>
using namespace std;

class Planet
{
	private:
		double minSurfaceTemp;
		double maxSurfaceTemp;
		double radius;
		
	public:
		//CONSTRUCTOR
		Planet()
		{
			minSurfaceTemp = 0.0;
			maxSurfaceTemp = 0.0;
			radius = 0.0;
			cout << "\nCreating a Planet!\n";
		}
		
		Planet(double rad)
		{
			minSurfaceTemp = 0.0;
			maxSurfaceTemp = 0.0;
			radius = rad;
			cout << "\nCreating a Planet with an overloaded constructor!\n";
		}
		
		//DESTRUCTOR
		~Planet()
		{
			//cout << "\nDestroying a Planet!\n";
		}
	
		//ACCESSOR FUNCTIONS
		double getMinSurfaceTemp() const;
		double getMaxSurfaceTemp() const;
		double getRadius() const;
		
		//MUTATOR FUNCTIONS
		void setMinSurfaceTemp(double min);
		void setMaxSurfaceTemp(double max);
		void setRadius(double r);
		
		friend ostream & operator << (ostream& os, const Planet& p)
		{
			os << "\n\nMin Surface Temp:  " << p.minSurfaceTemp << "\n";
			os << "Max Surface Temp:  " << p.maxSurfaceTemp << "\n";
			os << "Radius: " << p.radius << "\n";
			return os;
		}
		
		friend Planet operator+(const Planet &p1, const Planet &p2)
		{
			return Planet(p1.radius + p2.radius);
		}
		
};


#endif