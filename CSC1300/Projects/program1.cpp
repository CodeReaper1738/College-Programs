/*
	File name: program1.cpp
	Author: Yago Romano
	Date: 09/03/2019
	Purpose: Life expectancy application!!
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	// declaring all of the variables
	int totalAge;
	string name;
	int age;
	char gender, smoke, drinkAlcohol, pets, caretaker, dBreakfast;
	char famDied, dFruits, dVegetables;
	int weight;
	int exercise;
	int married;
	int jobStress;
	int friends;
	int educationLevel;
	int x;
	
	// requesting the name and age of the person
	cout << "\n\n\n******** Life Expectancy Calculator ********\n " << endl;
	cout << "\n Enter your name: ";
	getline(cin, name);
	cout << "\n\n\n Enter your age: ";
	cin >> age;
	
	//setting the basic life expectancy
	
	if (age <= 65) {
		totalAge = 77;
	} else {
		totalAge = age + 5;
	}
	
	// Male or female
	cout << "\n\n\n Are you a male or female? (Enter m or f): ";
	cin >> gender;
	
	//Depending on the gender it affects life expectancy in different ways
	
	if (gender == 'f') {
		totalAge = totalAge + 4;
	} else {
		totalAge = totalAge;
	}
	
	// Weight status 
	
	cout << "\n\n\n What is your weight status? \n\n " << endl;
	cout << "(1)Underweight, (2)Just right, (3)Overweight, (4)Obese\n" << endl;
	cout << "(Enter 1, 2, 3 or 4): ";
	cin >> weight;
	
	//Depending on the weight status 
	if (weight == 1) {
		totalAge = totalAge - 1;
	} else if (weight == 2) {
		totalAge = totalAge + 5;
	} else if (weight == 3) {
		totalAge = totalAge - 2;
	} else {
		totalAge = totalAge - 5;
	} 
	
	// Do they smoke
	cout << "\n\n\n Do you smoke cigarettes? (Enter y or n): ";
	cin >> smoke;
	
	//Depending if they smoke 
	
	if (smoke == 'y') {
		totalAge = totalAge - 5;
	} else { 
		totalAge = totalAge + 5;
	}
	
	// Do they drink alcohol
	cout << "\n\n\n Do you drink more than one alcoholic beverage every day?" << endl;
	cout << "\n (Enter y or n): ";
	cin >> drinkAlcohol;
	
	// //Depending on the alcohol consumption 
	
	if (drinkAlcohol == 'y') {
		totalAge = totalAge - 5;
	} else { 
		totalAge = totalAge + 2;
	}
	
	// Exercise
	
	cout << "\n\n\n Do you exercise? \n" << endl;
	cout << "(1)None, (2)Very Little, (3)Periodically, (4)Active, (5)Athlete \n" << endl;
	cout << "(Enter 1, 2, 3, 4 or 5): ";
	cin >> exercise;
	
	////Depending on the amount of exercise 
	
	if (exercise == 1) {
		totalAge = totalAge - 5;
	} else if (exercise == 2) {
		totalAge = totalAge - 2;
	} else if (exercise == 3) {
		totalAge = totalAge;
	} else if (exercise == 4) {
		totalAge = totalAge + 5;
	} else {
		totalAge = totalAge + 7;
	}
	
	// Own Pets
	
	cout << "\n\n\n Do you have a pet? (Enter y or n): ";
	cin >> pets;
	
	// //Depending if they own pets 
	
	if (pets == 'y') {
		totalAge = totalAge + 3;
	} else {
		totalAge = totalAge - 1;
	}
	
	// Romantic status
	
	cout << "\n\n\n Are you married?" << endl;
	cout << "(1)Divorced, (2)Single, (3)Married, (4)Happily Married" << endl;
	cout << "(Enter 1, 2, 3, or 4): ";
	cin >> married;
	
	// //Depending on their romantic status 
	
	if (married == 1) {
		totalAge = totalAge - 5;
	} else if (married == 2) {
		totalAge = totalAge - 2;
	} else if (married == 3) {
		totalAge = totalAge + 2;
	} else { 
		totalAge = totalAge + 5;
	}
	
	// Caretaker
	
	cout << "\n\n\n Are you a caretaker? (Enter y or n): ";
	cin >> caretaker;
	
	//Depending if they are a caretaker 
	
	if (caretaker == 'y') {
		totalAge = totalAge - 2;
	} else {
		totalAge = totalAge;
	}
	
	// How they feel about their job
	
	cout << "\n\n\n How do you feel about your job?" << endl;
	cout << "(1)Hate it!, (2)Dislike it, (3)It\'s ok, (4)Enjoyable, (5)Love it!" << endl;
	cout << "(Enter 1, 2, 3, 4, or 5): ";
	cin >> jobStress;
	
	
	//Depending on how they feel about their job 
	
	if (jobStress == 1) {
		totalAge = totalAge - 5;
	} else if (jobStress == 2) {
		totalAge = totalAge - 2;
	} else if (jobStress == 3) {
		totalAge = totalAge;
	} else if (jobStress == 4) {
		totalAge = totalAge + 2;
	} else {
		totalAge = totalAge + 5;
	}
	
	// Daily Breakfast
	
	cout << "\n\n\n Do you eat breakfast every day? (Enter y or n): ";
	cin >> dBreakfast;
	
	//Depending on if they eat breakfast daily 
	if (dBreakfast == 'y') {
		totalAge = totalAge + 5;
	} else {
		totalAge = totalAge - 2;
	} 
	
	// Biological parents or grandparents die before age of 50
	
	cout << "\n\n\n Did either of your biological parents or any of you biological" << endl;
	cout << "grandparents die before of age 50? (Enter y or n): ";
	cin >> famDied;
	
	// Depending on if their biological parents or granparents died before age of 50
	
	if (famDied == 'y') {
		totalAge = totalAge - 2;
	} else {
		totalAge = totalAge + 5;
	}
	
	// Daily fruit consumption
	
	cout << " \n\n\n Do you eat fruits every day? (Enter y or n): ";
	cin >> dFruits;
	
	// Depending on the fruit consumption
	
	if (dFruits == 'y') {
		totalAge = totalAge + 5;
	} else {
		totalAge = totalAge - 5;
	}
	
	// Daily vegetable consumption
	
	cout << "\n\n\n Do you eat vegetables every day? (Enter y or n): ";
	cin >> dVegetables;
	
	// Depending on vegetable consumption
	
	if (dVegetables == 'y') {
		totalAge = totalAge + 5;
	} else { 
		totalAge = totalAge - 5;
	}
	
	// Hang out with friends
	
	cout << "\n\n\n Do you hang out with your friends?" << endl;
	cout << "(1)Never, (2)Periodically, (3)Often" << endl;
	cout << "(Enter 1, 2 or 3): ";
	cin >> friends;
	
	// Depending on if they hang out with friends
	
	if (friends == 1) {
		totalAge = totalAge - 2;
	} else if (friends == 2) {
		totalAge = totalAge;
	} else {
		totalAge = totalAge + 2;
	}
	
	// Education level
	
	 cout << "\n\n\nWhat is your education level?" << endl;
	cout << "(1)No degrees, (2)Highschool degree, (3)Associates degree," << endl;
	cout << "(4)Bachelors degree, (5)Masters/PHD degree" << endl;
	cout << "(Enter 1, 2, 3, 4, or 5): ";
	cin >> educationLevel;
	
	// Depending on education level
	
	if (educationLevel == 1) {
		totalAge = totalAge - 5;
	} else if (educationLevel == 2) {
		totalAge = totalAge - 2;
	} else if (educationLevel == 3) {
		totalAge = totalAge + 2;
	} else if (educationLevel == 4) {
		totalAge = totalAge + 5;
	} else {
		totalAge = totalAge + 7;
	}
	
	
	// Outputs the end result of life expectancy, age, and name
	
	cout << "\n\n\n************************************************";
	
	cout << "\n\n\nName:\t" << name;
	cout << "\n\n\nCurrent Age:\t" << age;
	cout << "\n\n\n Life Expectancy:\t" << totalAge << endl << endl;
	
	
	
	
	return 0;
	
} 