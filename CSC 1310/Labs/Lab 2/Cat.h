#ifndef CAT_H
#define CAT_H

#include<iostream>
#include<string>

using namespace std;

class Cat{
	private: 
		string nameCat;
		string breedCat;
		string colorCat;
		
		int ageCat;
		
	public: 
		
		Cat(string name, string breed, string color, int age) {
			nameCat = name;
			breedCat = breed;
			colorCat = color;
			ageCat = age;
		}
		
		friend ostream & operator << (ostream& os, const Cat& c) {
			os << c.nameCat << ", " << c.breedCat << ", " << c.colorCat << ", " << c.ageCat << endl;
			
			return os;
		}
};

#endif