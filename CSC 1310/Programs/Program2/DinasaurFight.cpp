/*****************************************************************
	Title:  	DinasaurFight.cpp
	Date:  		3-11-2020
	Author: 	Yago Romano
	Purpose:	Play a dinosaur fighting game 
******************************************************************/

#include "LinkedList.h"
#include "Dinasaur.h"

void MergeSort(LinkedList<Dinasaur>*, int, int);
void Merge(LinkedList<Dinasaur>*, int, int, int);
bool BinarySearch(string [], string, int, int);

int main() {
	ifstream inFile;
	
	LinkedList<Dinasaur> list;
	int numRounds = 0;
	Dinasaur pOne, pTwo;
	int dinoOne, dinoTwo, number;
	int healthOne, dmgOne, healthTwo, dmgTwo, dmgMadeOne, dmgMadeTwo;
	string playAgain, playerOne, playerTwo, showDino, dinoN1, dinoN2;
	string dinoNames[100];
	bool match = false;
	int count = 0, x = 0;

	srand(0);
	int dieRoll;
	inFile.open("dinosaurFile.txt");
	if(!inFile){
		cout << "\nThe file could not be opened.\n This program is about to end.\n";
		return -1;
	}
	string temp;
	getline(inFile, temp);
	while(!inFile.eof()){
		int hitPoints, lifePoints;
		string name, description;
		match = false;
		name=temp;
		
		
		getline(inFile, description);
		inFile >> lifePoints;
		inFile >> hitPoints;
		inFile.ignore();
		//putting all the dinasaur names in the array for the binary search
		Dinasaur value(name, description, lifePoints, hitPoints);
		match = BinarySearch(dinoNames, name, 0, count + 1); 
		
		
		if(!match) {
			cout << name << " was added to the list of dinasaurs that can fight" << endl;
			list.appendNode(value);
			x++;
			MergeSort(&list, 0, list.getLength() - 1);
			
		} else {
			cout << name << " was skipped because it is already in the list. \n";
		}	
		dinoNames[count] = name;
		count++;
		getline(inFile, temp);
	}
	cout << x << " dinosaurs from dinosaurFile.txt have been added to the zoo " << endl;
	
	//MergeSort(&list, 0, list.getLength());
	
	cout << "\n" << setw(80) << setfill('|') << '|' << endl;
	cout << setw(80) << '|' << endl;
	cout << setw(80) << setfill('v') << 'v' << endl;
	
	do{
		Dinasaur value;
		
		
		cout << "\nEnter the name of player one! ";
		getline(cin, playerOne);
		cout << "\nEnter the name of player two! ";
		getline(cin, playerTwo);
		cout << "\nWould you like to see the Dinosaur details? (y or n): ";
		cin >> showDino;
		if(showDino == "y") {
			for(int i = 0; i < list.getLength(); i++) {
				
				cout << "\n" << setw(80) << setfill('*') << '*' << endl; 
				value = list.getNodeValue(i);
				cout << "---------------Dinasaur " << (i + 1) << " ---------------" << endl;
				value.printDinasaur();
			}
		}
		cout << endl;
		x = 0;
		for(int i = 0; i < list.getLength(); i++) {
			value = list.getNodeValue(i);
			
			
			if(x == 4) {
				cout << endl;
				x = 0;
			}
			cout << i + 1 << "-" << value.getDinoName() << setw(3) << setfill(' ') << "\t";
			x++;
			
		}
		cout << "\n\n" << playerOne << " ENTER THE DINOSAUR NUMBER YOU CHOOSE TO FIGHT!! ";
		cin >> dinoOne;
		pOne = list.getNodeValue(dinoOne - 1);
		cout << "\n\n" << playerTwo << " ENTER THE DINOSAUR NUMBER YOU CHOOSE TO FIGHT!! ";
		cin >> dinoTwo;
		pTwo = list.getNodeValue(dinoTwo - 1);
		healthOne = pOne.getDinoLifePoints();
		healthTwo = pTwo.getDinoLifePoints();
		dmgOne = pOne.getDinoHitPoints();
		dmgTwo = pTwo.getDinoHitPoints();
		dinoN1 = pOne.getDinoName();
		dinoN2 = pTwo.getDinoName();
		cin.ignore();
		do {
			cout << "\n" << setw(80) << setfill('|') << '|' << endl;
			cout << setw(80) << '|' << endl;
			cout << setw(80) << '|' << endl;
			cout << setw(80) << '|' << endl;
			cout << setw(80) << '|' << endl;
			cout << setw(80) << setfill('v') << 'v' << endl;
			cout << "\n******************** Round " << numRounds + 1 << " ********************" << endl;
			cout << playerOne << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << playerTwo << "'s " << dinoN2 << " \n";
			
			cin.get();
			dieRoll = rand() % 6 + 1;
			dmgMadeOne = dmgOne * dieRoll;
			healthTwo -= dmgMadeOne;
			
			cout << "\n\n YOU HIT " << dinoN2 << " FOR " << dmgMadeOne << " POINTS. \n";
			
			cout << endl << dinoN2 << " NOW HAS " << healthTwo << endl << endl;
			
			if(healthTwo <= 0) {
				cout << "\nPlayer: " << playerOne << " won the game \n";
				break;
			}
			cout << playerTwo << ", HIT ENTER TO ROLL THE DIE TO DO DAMAGE TO " << playerOne << "'s " << dinoN1 << " \n";
			cin.get();
			dieRoll = rand() % 6 + 1;
			dmgMadeTwo = dmgTwo * dieRoll;
			healthOne -= dmgMadeTwo;
			
			cout << "\n\n YOU HIT " << dinoN1 << " FOR " << dmgMadeTwo << " POINTS. \n";
			cout << endl << dinoN1 << " NOW HAS " << healthOne << endl << endl;
			
			if(healthOne <= 0) {
				cout << "\nPlayer: " << playerTwo << " won the game \n";
				break;
			}
		
			
			
			numRounds++;
			
			if(numRounds == 3) {
				if(healthOne > healthTwo) {
					cout << "Player: " << playerOne << " won the game ";
				} else {
					cout << "Player: " << playerTwo << " won the game ";
				}
			}
			
		} while(numRounds < 3);
		
		cout << "Do you want to play again? Enter yes to play Again! (y or n): ";
		cin >> playAgain;
		cin.ignore();
	}while(playAgain == "y" || playAgain == "Y");
	
	for(int i = 0; i < list.getLength() - 1; i++) {
		list.deleteNode(i);
	}
	//delete list;
	inFile.close();
	return 0;
}




bool BinarySearch(string arr[], string dinoName, int beg, int end)
{
	int mid;
	
	if (beg > end){
		
		//cout << "\nAll the dinasaurs are unique\n";
		return false;

	} else {
		
		mid = (beg + end) / 2;
	
		if(arr[mid] == dinoName){

			//cout << "/nNumber is found at " << mid << " index \n";
			return true;

		} else if (dinoName > arr[mid]) {

			BinarySearch (arr, dinoName, mid+1, end);

		} else if (dinoName < arr[mid]) {

			BinarySearch (arr, dinoName, beg , mid-1);
		}
	} 
}

void MergeSort(LinkedList<Dinasaur> *list, int beg, int end) {
	int mid = 0;
   
  
	if (beg < end)   {
		// Find the midpoint in the partition
		mid = (beg + end) / 2;  
		//recursively sort left partition
		MergeSort(list, beg, mid); 
		//recursively sort right partition
		MergeSort(list, mid + 1, end); 
		Merge(list, beg, mid, end);
    }
}

void Merge(LinkedList<Dinasaur> *list, int beg, int mid, int end) {
	int mergedSize = end - beg + 1;               
	int mergePos = 0;                          
	int left;                           
	int right;                         
	LinkedList<Dinasaur>* mergedDinasaurs = new LinkedList<Dinasaur>;
   
	left = beg;                               
	right = mid + 1; 
	
   // Add smallest element from left or right partition to merged arr
	while (left <= mid && right <= end) {
		if (list->getNodeValue(left).getDinoName() < list->getNodeValue(right).getDinoName()) {
			 mergedDinasaurs->insertNode(list->getNodeValue(left), mergePos);
			++left;
		}
		else {
			mergedDinasaurs->insertNode(list->getNodeValue(right), mergePos);
			++right;
		 
		}
		++mergePos;
	
	}
   
   // If left partition is not empty, add remaining elements to merged numbers
   while (left <= mid) {
	   mergedDinasaurs->insertNode(list->getNodeValue(left), mergePos);
	  ++left;
	  ++mergePos;
	  
   }
   
   // If right partition is not empty, add remaining elements to merged numbers
   while (right <= end) {
	  mergedDinasaurs->insertNode(list->getNodeValue(right), mergePos);
	  ++right;
	  ++mergePos;
   }
   
   // Copy merge number back to arr
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
	   list->deleteNode(mergePos + beg);
	  list->insertNode(mergedDinasaurs->getNodeValue(mergePos), mergePos + beg);
	  
   }
   delete mergedDinasaurs;
}