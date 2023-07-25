#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
using namespace std;

struct Course {
	string name, location;
	string* sections;
	int numSections, numHours;
};

Course* createCourse(string, string, int, int);
void destroyCourse(Course*);
void printCourse(Course*);

#endif