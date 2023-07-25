/*****************************************************************
	Title:  	LinkedList.cpp - Class Implementation File for 
				LinkedList Class
	Date:  		2-24-2020
	Author: 	Yago Romano, Yoshinori agari
	Purpose:	Linked List
******************************************************************/

#include "List.h"

int main() {
	LinkedList List;
	int position = 0;
	
	
	List.appendNode("boogeyman");
	List.appendNode("ghost");
	List.appendNode("scarecrow");
	List.appendNode("witch");
	List.appendNode("zombie");
	
	cout << "Entering several strings to the list..." << endl;
	List.displayList();
	cout << endl;
	List.insertNode("vampire");
	cout << "Inserting the word 'vapire' into the list...\n";
	
	List.displayList();
	cout << endl;
	
	List.deleteNode("ghost");
	cout << "Deleting the string 'ghost' from the list...\n";
	List.displayList();
	cout << endl;
	cout << "All list nodes have been removed";
	

	return 0;
}