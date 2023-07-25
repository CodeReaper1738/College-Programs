/*****************************************************************
	Title:  	Dinasaur.h
	Date:  		3-11-2020
	Author: 	Yago Romano
	Purpose:	To set all of the dinosaur qualities
******************************************************************/

#ifndef DINASAUR_H
#define DINASAUR_H

#include<iostream>
#include<fstream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
using namespace std;

class Dinasaur{
	private:
		//Dino name, and description
		string name;
		string description;
		// Dino life and healths
		int lifePoints;
		int hitPoints;
	public:
		Dinasaur() {
			
		}
		
		Dinasaur(string dName, string Description, int life, int hit){
			// Setting all dinasaur objects to the values passed to the constructor
			this->name = dName;
			this->description = Description;
			this->lifePoints = life;
			this->hitPoints = hit;
		}
		
		void setDinoHitPoints(int damage) {
			this->hitPoints = damage;
		}
		void setDinoDescription(string stats) {
			this->description = stats;
		}
		void setDinoName(string dinoName) {
			this->name = dinoName;
		}
		int getDinoHitPoints() const {
			return this->hitPoints;
		}
		int getDinoLifePoints() const {
			return this->lifePoints;
		}
		string getDinoDescription() const {
			return this->description;
		}
		string getDinoName() const {
			return this->name;
		}
		void setDinoLifePoints(int health)  {
			this->lifePoints = health;
		}
		
		
		void printDinasaur() {
			// Printing out all of the dinasaur stats
			cout << "\nName of Dinasaur: " << getDinoName() << "\n";
			cout << "\nDescription: " << getDinoDescription() << "\n";
			cout << "\nLife Points: " << getDinoLifePoints() << "\n";
			cout << "\nHit Points: " << getDinoHitPoints() << "\n";
		}
	
};


#endif