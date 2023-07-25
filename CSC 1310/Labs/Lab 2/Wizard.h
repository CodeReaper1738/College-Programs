#ifndef WIZARD_H
#define WIZARD_H

#include<iostream>
#include<string>

using namespace std;

class Wizard{
	private:
		string nameWizard;
		int ageWizard;
		int heightWizard;
	
	public: 
		Wizard(string name, int age, int height) {
			nameWizard = name;
			ageWizard = age;
			heightWizard = height;
		}
		
		friend ostream & operator << (ostream& os, const Wizard& c) {
			os << c.nameWizard << ", " << c.ageWizard << " years old, " << c.heightWizard << " inches tall\n";
			
			return os;
		}
};


#endif