#ifndef PROG5_H
#define PROG5_H

#include<iostream>
#include<string>
#include<iomanip>
#include<cctype>
#include<cstring>
#include<vector>
#include<sstream>
#include<fstream>


using namespace std;

struct Cost {
	int numHours;
	float costHour;
	float costFood;
	float matCost;
	
};
struct Creatures {
	string name;
	string description;
	float avgLenght;
	float avgHeight;
	string home;
	bool danger;
	Cost prices;
};

float convertToFloat(string);
int enterCreatures(int, Creatures[]);
int deleteCreature(int, Creatures[]);
bool moveArrayElements(string, int, Creatures[]);
void printCreatures(int, Creatures[]);
void printStatistics(int, Creatures[]);
void saveCreaturesToFile(int, Creatures[]);	

#endif