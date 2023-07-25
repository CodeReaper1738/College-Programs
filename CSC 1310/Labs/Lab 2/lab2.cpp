/***************************************************************
 *	Title:  lab2.cpp                                           *
 *	Author:  April Crockett, edited by Yago Romano and Alex Noack*
 *	Date:  1-27-2020                                           *
 *	Purpose:  Lab 2 assignment on Classes and Template Classes *
 ***************************************************************/


#include "Train.h"
#include "Cat.h"
#include "Wizard.h"
#include <iostream>
using namespace std;

int main()
{
	//Create a Wizard Train object
    Train<Wizard*> wizardTrain("Hogwarts Express", "Kings Cross Station, London", 10);
	
	//Create wizards & then add them to the Wizard Train
    Wizard* wizard1 = new Wizard("Bill", 32, 65);
    wizardTrain.addPassenger(wizard1);
    Wizard* wizard2 = new Wizard("Jill", 24, 45);
    wizardTrain.addPassenger(wizard2);
    Wizard* wizard3 = new Wizard("Will", 10, 42);
    wizardTrain.addPassenger(wizard3);
    Wizard* wizard4 = new Wizard("Neal", 88, 73);
    wizardTrain.addPassenger(wizard4);
	
	//Print all the Wizard Train passengers
    cout << "\n\nHere are the wizards who have boarded the " << wizardTrain.getTrainName() << "!\n\n";
    wizardTrain.printPassengers();

    cout << endl << endl;

	//Create a Cat Train object
    Train<Cat*> kittyTrain("Hello Kitty Express", "Japan", 10);
	
	//Create Cats & then add them to the Cat Train
    Cat* cat1 = new Cat("Yella Cat", "mixed", "orange & yellow", 8);
    kittyTrain.addPassenger(cat1);
    Cat* cat2 = new Cat("Mouth", "mixed", "black & white", 8);
    kittyTrain.addPassenger(cat2);
    Cat* cat3 = new Cat("Chloe", "siamese", "black & white", 3);
    kittyTrain.addPassenger(cat3);
    Cat* cat4 = new Cat("Brutus", "hairless", "skin color", 4);
    kittyTrain.addPassenger(cat4);
    Cat* cat5 = new Cat("Wally", "catdog", "lime", 1);
    kittyTrain.addPassenger(cat5);
    Cat* cat6 = new Cat("Gladass", "siamese", "black & white", 6);
    kittyTrain.addPassenger(cat6);
	
	//Print all the Cat Train passengers
    cout << "Here are the cats who have boarded the " << kittyTrain.getTrainName() << "!\n\n";
    kittyTrain.printPassengers();

    cout << endl << endl;
    return 0;

}