#include "prog5.h"

// Purpose: This function will turn a string to a float
float convertToFloat(string s){
	istringstream i(s);
	float x;
	if (!(i >> x))
		x = 0;
	return x;
}
// Purpose: This function will allow you to choose to either create a new creature or select some that are saved in a file

int enterCreatures(int numCreatures, Creatures array[]){
	int option;
	string fileName, var;
	ifstream inputFile;
	char oneMore, isDanger;
	cout << "1. Load my creatures from file.\n2. Enter one creature manually.\n";
	cin >> option;
	while(option > 2 || option < 1) {
		cout << "\nInvalid choice. Please select 1 or 2.\n";
		cin >> option;
	}
	cin.ignore();
	if(option == 1) {
		// 100 creatures max
		if(option == 100) {
			cout << "\n\nThe zoo is at full capacity.\n\n";
			return 0;
		} else {
			cout << "\n\nWhat is the name of the file that you would like to read creatures from? (ex: filename.txt)\n";
			getline(cin, fileName);
			inputFile.open(fileName.c_str());
			// This will check if the file is opened already
			if(!inputFile.is_open()) {
				cout << "\nCould not open the selected file.\n";
				return 1;
			}else {
				
			// This will get all of the details about the creature until it reaches the end of the file
				getline(inputFile, array[numCreatures].name, '#');
				while(!inputFile.eof()){
					getline(inputFile, array[numCreatures].description, '#');
					getline(inputFile, var, '#');			
					array[numCreatures].avgLenght = convertToFloat(var);
					getline(inputFile, var,'#');
					array[numCreatures].avgHeight = convertToFloat(var);
					getline(inputFile, array[numCreatures].home, '#');
					getline(inputFile, var, '#');
					if(var == "yes")
						array[numCreatures].danger = true;
					else
						array[numCreatures].danger = false;
					getline(inputFile, var, '#');
					array[numCreatures].prices.numHours = convertToFloat(var);
					getline(inputFile, var, '#');
					array[numCreatures].prices.costHour = convertToFloat(var);
					getline(inputFile, var, '#');
					array[numCreatures].prices.costFood = convertToFloat(var);
					getline(inputFile, var, '#');
					array[numCreatures].prices.matCost = convertToFloat(var);
					getline(inputFile, array[numCreatures + 1].name, '#');
					numCreatures++;
				}
				cout << "\n" << numCreatures << " creatures from " << fileName << " have been added to the program\n";
			}
		// Close the file
		inputFile.close();
		}
	}else if (option == 2) {
		if(numCreatures == 100) {
			cout << "The zoo is at full capacity.";
			return 0;
		} else {
			oneMore = 'y';
			// This will allow you to manually enter all of the details about a creature
			while(oneMore == 'y') {
				cout << "\n\nNAME: ";
				getline(cin, array[numCreatures].name);
				cout << "\nDESCRIPTION: ";
				getline(cin, array[numCreatures].description);
				cout << "\nAVERAGE LENGTH (in feet): ";
				getline(cin, var);
				array[numCreatures].avgLenght = convertToFloat(var);
				cout << "\nAVERAGE HEIGHT (in feet): ";
				getline(cin, var);
				array[numCreatures].avgHeight = convertToFloat(var);
				cout << "\nLOCATION: ";
				getline(cin, array[numCreatures].home);
				cout << "\nIS IT A DANGEROUS CREATURE (y or n): ";
				cin >> isDanger;
				cin.ignore();
				if(isDanger == 'y')
					array[numCreatures].danger = true;
				else
					array[numCreatures].danger = false;
				cout << "\nHow many hours do you spend caring for the " << array[numCreatures].name << "?\nNUM HOURS: ";
				getline(cin, var);
				array[numCreatures].prices.numHours = convertToFloat(var);
				cout << "\nWhat is the cost per hour for caring for the " << array[numCreatures].name << "?\nCOST PER HOUR: ";
				getline(cin, var);
				array[numCreatures].prices.costHour = convertToFloat(var);
				cout << "\nHow much money do you spend on food for the " << array[numCreatures].name << "?\nFOOD COST: ";
				getline(cin, var);
				array[numCreatures].prices.costFood = convertToFloat(var);
				cout << "\nHow much money do you spend on grooming and medical supplies for the " << array[numCreatures].name << "?\nSUPPLY COST: ";
				getline(cin, var);
				array[numCreatures].prices.matCost = convertToFloat(var);
				numCreatures++;
				// This will ask the user if they want to add another creature
				cout << "Would you like to enter another creature? (y or n):";
				cin >> oneMore;
				cin.ignore();
			}
			
		}
	}
	return numCreatures;
}
// Purpose: This fucntion will delete the creature selected
int deleteCreature(int numCreatures, Creatures array[]){
	string cName;
	bool removeCreature;
	
	cout << "The following is a list of all the creatures you take care of: \n";
	for(int i = 0; i < numCreatures; i++) {
		cout << array[i].name << endl;
	}
	cout << "What creature do you wish to remove? \nCREATURE NAME: ";
	getline(cin, cName);
	removeCreature = moveArrayElements(cName, numCreatures, array);
	if(removeCreature == false) {
			cout << "\nThe creature specified was not removed.\n";
	}else if(removeCreature == true){
		cout << "\nYou have removed " << cName << ".\n";
		numCreatures--;
	}
	return numCreatures;
}
// Purpose: This function will check if the user wants to delete a creature
bool moveArrayElements(string creatureName, int numCreatures, Creatures array[]) {
	bool removeCreature = false;
	int x = 0;
	
	for(int i = 0; i < numCreatures; i++){
		// If the name wanting to be deleted matches one of the creatures names this will remove the creature and move all the other ones
		// back one position
		if(creatureName == array[i].name || x > 0) {
			array[i].name = array[i+1].name;
			array[i].description = array[i+1].description;
			array[i].avgLenght = array[i+1].avgLenght;
			array[i].avgHeight = array[i+1].avgHeight;
			array[i].home = array[i+1].home;
			array[i].danger = array[i+1].danger;
			array[i].prices.numHours = array[i+1].prices.numHours;
			array[i].prices.costHour = array[i+1].prices.costHour;
			array[i].prices.costFood = array[i+1].prices.costFood;
			array[i].prices.matCost = array[i+1].prices.matCost;
			array[i+1].name = "";
			array[i+1].description = "";
			array[i+1].avgLenght = 0;
			array[i+1].avgHeight = 0;
			array[i+1].home = "";
			array[i+1].danger = false;
			array[i+1].prices.numHours = 0;
			array[i+1].prices.costHour = 0;
			array[i+1].prices.costFood = 0;
			array[i+1].prices.matCost = 0;
			removeCreature = true;
			x++;
			
		}
	}
	return removeCreature;
}

// Purpose: This function will print out all the information about each creatures to either the screen or a file
void printCreatures(int numCreatures, Creatures array[]) {
	bool choice = false;
	string fileName;
	ofstream outputFile;
	int option;
	
	cout << "1. Print creatures to the screen.\n2. Print creatures to a File" << endl;
	cin >> option;
	cout << "\n\n";
	while(option > 2 || option < 1){
		cout << "Invalid choice enter 1 or 2! ";
		cin >> option;	
	}
	cin.ignore();
	if(option == 1){
		for(int i = 0; i < numCreatures; i++){
			cout << "\n " << setw(30) << setfill('-') << '-' << endl;
			cout << "\nCREATURE " << i + 1 << ":";
			cout << "\nName:        " << array[i].name;
			cout << "\nDescription: \n";
			cout << "\t" << array[i].description;
			cout << "\n\nLength:       " << array[i].avgLenght << " feet";
			cout << "\nHeight:       " << array[i].avgHeight << " feet";
			cout << "\nLocation:       " << array[i].home;
			cout << "\nDangerous?       ";
			if(array[i].danger == true)
				cout << "yes";
			else
				cout << "no";
			cout << setw(40) << setfill(' ') << left << "\nNumber of hours to care for creature:" << setw(10) << right << '$' << array[i].prices.numHours;
			cout << setw(40) << left <<  "\nCost per hour of taking care of creature:" << setw(10) << right << '$' << array[i].prices.costHour;
			cout << setw(40) << left << "\nCost to feed creature:" << setw(10) <<  right << '$' << array[i].prices.costFood;
			cout << setw(40) << left << "\nGrooming & Supplies cost:" << setw(10) << right << '$' << array[i].prices.matCost << endl;
		}
	}
	else if(option == 2){
		cout << "What is the name of the file you would like to print to? ";
		getline(cin, fileName);
		outputFile.open(fileName.c_str());
		for(int i = 0; i < numCreatures; i++){
			outputFile << setw(50) << setfill('-') << '-' << endl;
			outputFile << "\nCREATURE " << i + 1 << ":";
			outputFile << "\nName:        " << array[i].name;
			outputFile << "\nDescription: \n";
			outputFile << "\t" << array[i].description;
			outputFile << "\n\nLength:       " << array[i].avgLenght << " feet";
			outputFile << "\nHeight:       " << array[i].avgHeight << " feet";
			outputFile << "\nLocation:       " << array[i].home;
			outputFile << "\nDangerous?       ";
			if(array[i].danger == true)
				outputFile << "\nyes";
			else
				outputFile << "\nno";
			// These files will be aligned will the setw and setfill
			outputFile << setw(50) << setfill(' ') << left << "\nNumber of hours to care for creature:" << setw(20) << right << '$' << array[i].prices.numHours;
			outputFile << setw(50) << left <<  "\nCost per hour of taking care of creature:" << setw(20) << right << '$' << array[i].prices.costHour;
			outputFile << setw(50) << left << "\nCost to feed creature:" << setw(20) <<  right << '$' << array[i].prices.costFood;
			outputFile << setw(50) << left << "\nGrooming & Supplies cost:" << setw(20) << right << '$' << array[i].prices.matCost << endl;

		}
	}
	cout << "Your creatures have been written to " << fileName;
	outputFile.close();
}

// This function will print all of the prices for taking care of each creature and it will print out a total price also
void printStatistics(int numCreatures, Creatures array[]){
	float totalCost, creaturesTotal = 0;
	
	cout << setprecision(2) << fixed;
	cout << "\n\nCost of each creature for one week: \n\n";
	cout<< setw(25) << setfill(' ') << left << "Creature" << setw(25) << right << "Cost\n";
	
	for(int i = 0; i < numCreatures; i++){
		// Adding the total cost
		totalCost = (array[i].prices.numHours * array[i].prices.costHour) + array[i].prices.costFood + array[i].prices.matCost;
		cout<< setw(25) << left << array[i].name << '$' << setw(25) << right << totalCost << endl;
		creaturesTotal += totalCost;
	}
	cout << setw(25) << left << "Total Cost:" << '$' << setw(25) << right << creaturesTotal << endl;
}

// Purpose: This function will save your creatures to a preferred file name
void saveCreaturesToFile(int numCreatures, Creatures array[]){
	ofstream outputFile;
	string fileName;
	// Input the file name where you want to save the creatures
	cout << "What is the name of the file you would like to save your creatures on? ";
	getline(cin, fileName);
	outputFile.open(fileName.c_str());
	for(int i = 0; i < numCreatures; i++) {
		// This will print out the information of the creature
		outputFile << "\nCREATURE " << i+1 << ":";
		outputFile << array[i].name;
		outputFile << "#";
		outputFile << array[i].description;
		outputFile << "#" << array[i].avgLenght;
		outputFile << "#" << array[i].avgHeight;
		outputFile << "#" << array[i].home;
		outputFile << "#";
		if(array[i].danger == true)
			outputFile << "yes";
		else
			outputFile << "no";
		// This will print out to a file the price of each thing for the Creature
		outputFile << "#" << array[i].prices.numHours;
		outputFile << "#" << array[i].prices.costHour;
		outputFile << "#" << array[i].prices.costFood;
		outputFile << "#" << array[i].prices.matCost;
	}
	// Close the file
	outputFile.close();
	cout << "\nYour creatures were successfully saved to the " << fileName << " file.";
	
}