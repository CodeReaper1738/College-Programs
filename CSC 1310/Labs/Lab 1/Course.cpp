#include "Course.h"

Course* createCourse(string name, string location, int numSections, int creditHours){
	Course* myCourses = new Course;
	myCourses->name = name;
	myCourses->location = location;
	myCourses->numSections = numSections;
	myCourses->numHours = creditHours;
	myCourses->sections = new string[numSections];
	return myCourses;
}

void destroyCourse(Course* myCourses) {
	delete myCourses;
}

void printCourse(Course* myCourses){
	cout << "Course Name:\t" << myCourses->name << endl;
	cout << "Course Location:\t" << myCourses->location << endl;
	cout << "Course Hours:\t" << myCourses->numHours << endl;
	for(int i = 0; i < myCourses->numSections; i++){
		cout << "Course Sections:\t" << myCourses->sections[i] << endl;
	}
}