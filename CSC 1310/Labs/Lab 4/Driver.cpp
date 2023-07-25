#include "Song.h"
#include "Timer.h"
#include <iostream>
#include <fstream>
using namespace std;

//LOOK!!  ENTER YOUR FUNCTION PROTOTYPES HERE
void insertionSort(Song*, int);
void reverseBubbleSort(Song*, int);
void quickSort(Song*, int, int);
int partition(Song*, int, int);
const int SIZE = 150000;
int main()
{
	Song *mySongArray;
	mySongArray = new Song[SIZE];
	int numSongs = 0;
	float length;
	string temp;
	
	ofstream outFile;
	ifstream inFile;

	time_t start, end;
	char filename[50];
	cout << "\n\nWhat is the name of the file with songs? (example.txt)\n";
	cin >> filename;
	inFile.open(filename);
	
	if(!inFile)
	{
		cout << "\n\nSorry, I can't open the file songs.txt\n\n";
		exit(1);
	}
	
	while(getline(inFile, temp) && numSongs != 150000)
	{
		mySongArray[numSongs].setTitle(temp);
		getline(inFile, temp);
		mySongArray[numSongs].setArtist(temp);
		inFile >> length;
		inFile.ignore();
		mySongArray[numSongs].setLength(length);
		numSongs++;
	}
	cout << "\n\nYou have created " << numSongs << " Song objects.\n\n";
	
	
	
	//sort the songs using insertion sort and print them out to the text file sortFileInsertion.txt
	start = getTime(); //Starts timer.   
	
	//LOOK!!!!  CALL THE INSERTION SORT ALGORITHM HERE
	//This shit aint working m8s
	insertionSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileInsertion.txt");
	cout << "\nInsertion sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs in reverse order using bubble sort & print them out to the text file sortFileReverseBubble.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE REVERSE BUBBLE SORT ALGORITHM HERE
	reverseBubbleSort(mySongArray, numSongs);
	
	end = getTime(); //Ends timer.
	outFile.open("sortFileReverseBubble.txt");
	cout << "\nReverse bubble sort: " << totalTime(start, end) << " seconds\n\n";
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	
	//sort the songs with quick sort & print them out to sortFileQuick.txt
	start = getTime(); //Starts timer. 
	
	//LOOK!!!!  CALL THE QUICKSORT ALGORITHM HERE
	quickSort(mySongArray, 0, numSongs-1);
	
	end = getTime(); //Ends timer.
	cout << "\nQuicksort: " << totalTime(start, end) << " seconds\n\n";
	outFile.open("sortFileQuick.txt");
	for(int x=0; x<numSongs; x++)
	{
		outFile << mySongArray[x];
	}
	outFile.close();
	
	
	delete [] mySongArray;
	return 0;
}

//LOOK!  WRITE YOUR INSERTION SORT FUNCTION HERE
void insertionSort(Song* library, int size) {
	Song swap;
	int x;
	cout << "Insertion Sort in Progress" << endl;
	for (int i = 1; i < size; i++) {
		swap = library[i];
		x = i - 1;
		while (x >= 0 && (library[x].getTitle() > swap.getTitle())) {
			library[x + 1] = library[x];
			x = x - 1;
		}
		library[x + 1] = swap;
	}
}


//LOOK!  WRITE YOUR REVERSE BUBBLE SORT FUNCTION HERE
void reverseBubbleSort(Song* library, int songNum) {
	Song temp;
	cout << "Sorting by Reverse Bubble Sort" << endl;
	for (int element = (songNum - 1); element > 0; element--) {
		for (int i = 0; i < element; i++) {
			if (library[i].getTitle() < library[i + 1].getTitle()) {
				temp = library[i];
				library[i] = library[i + 1];
				library[i + 1] = temp;
			}
		}
	}
}


//LOOK!  WRITE YOUR RECURSIVE QUICK SORT FUNCTION HERE
void quickSort(Song* library, int min, int max) {
	int pLocation = 0;
	//cout << "Sorting by Quick Sort" << endl;
	if (min >= max) {
		//cout << "Running" << endl;
		return;
	}
	pLocation = partition(library, min, max);
	quickSort(library, min, pLocation);
	quickSort(library, pLocation + 1, max);
}


//LOOK!  WRITE YOUR PARTITION FUNCTION HERE
int partition(Song* library, int left, int right) {
	int middle;
	Song temp;
	bool done = false;

	middle = left + (right - left) / 2;
	temp = library[middle];
	int l = left;
	int r = right;
	while (!done) {
		while (library[l].getTitle() < temp.getTitle()) {
			l++;
		}
		while (library[r].getTitle() > temp.getTitle()) {
			r--;
		}
		if (l >= r) {
			done = true;
		}
		else {
			temp = library[l];
			library[l] = library[r];
			library[r] = temp;
			++l;
			--r;
		}
	}
	return r;
}
