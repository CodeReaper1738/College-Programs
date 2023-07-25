#include <iostream>
#include "LinkedList.h"

using namespace std;

int main()
{
	LinkedList<string> dogBreeds;
	dogBreeds.appendNode("Corgi");
	dogBreeds.appendNode("English Bulldog");
	dogBreeds.appendNode("Dalmation");
	dogBreeds.appendNode("German Shepard");
	dogBreeds.appendNode("Poodle");
	
	dogBreeds.displayList();
	
	cout << "\n\nGoodbye!\n\n";
	return 0;
}