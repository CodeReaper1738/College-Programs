#ifndef LIST_H
#define LIST_H

#include<iostream>

using namespace std;

class LinkedList{
	private:
		// Declare a structure for the list
		struct ListNode
		{
			string value; 
			struct ListNode *next;  	
		};

		ListNode *head;		
		ListNode *tail;
	public: 
		
		LinkedList()
		{ 
			head = NULL; 
			tail = NULL;
		}
		
	~LinkedList(){
		ListNode *nodePtr;   // To traverse the list
		ListNode *nextNode;  // To point to the next node

		// Position nodePtr at the head of the list.
		nodePtr = head;

		// While nodePtr is not at the end of the list...
		while (nodePtr != NULL)
		{
			// Save a pointer to the next node.
			nextNode = nodePtr->next;

			// Delete the current node.
			delete nodePtr;

			// Position nodePtr at the next node.
			nodePtr = nextNode;
		}
	}
	void appendNode(string num)
	{
		ListNode *newNode;  // To point to a new node

		// Allocate a new node and store num there.
		newNode = new ListNode;
		newNode->value = num;
		newNode->next = NULL;

		// If there are no nodes in the list make newNode the first node.
		if (!head ) 
		{
			head = newNode;
			tail = newNode;
		}
		else  // Otherwise, insert newNode at end.
		{
			//set the current last node's next pointer to the new node
			tail->next = newNode;
			
			//now the tail is the new node
			tail = newNode;
		}
	}
	void insertNode(string num)
	{
		ListNode *nodePtr;
		ListNode *newNode;
		
		newNode = new ListNode;
		newNode->value = num;
		
		int position = 0;

	// Position node at the head of the list.
		ListNode *node = head;

		// While node points to a node, traverse the list.
		while (node)
		{
			//see if this node matches the value
			if(node->value > num){
				break;
			}
			//increment position
			position++;

			// Move to the next node.
			node = node->next;
		}
		if(!head)
		{
			if(position != 0)
			{
				//can't insert node at position (>0) if there is not already a node
				cout << "\n\nUnable to insert a node at position " << position << " because there are currently no nodes in the list.  I am going to insert this node at position 0.\n\n";
			}
			head = newNode;
			tail = newNode;
		}
		else
		{
			nodePtr = head;
			int nodeCount = 0;
			if(position == 0)
			{
				newNode->next = head->next;
				head = newNode;
			}
			while(nodePtr != tail && nodeCount < position)
			{
				nodeCount++;
				if(nodeCount == position)
					break;
				nodePtr = nodePtr->next;
			}
			
			//now nodePtr is positioned 1 node BEFORE the node we want to insert
			if(nodePtr->next == NULL) //we are appending this node to the end
				tail = newNode;
				
			newNode->next = nodePtr->next;
			nodePtr->next = newNode;
			
		}
		
	}
	void deleteNode(string num)
	{
		ListNode *nodePtr;       // To traverse the list
		ListNode *previousNode;  // To point to the previous node

		// If the list is empty, do nothing.
		if (!head)
			return;

		// Determine if the first node is the one.
		if (head->value == num)
		{
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else
		{
			// Initialize nodePtr to head of list
			nodePtr = head;

			// Skip all nodes whose value member is 
			// not equal to num.
			while (nodePtr != NULL && nodePtr->value != num)
			{  
				previousNode = nodePtr;
				nodePtr = nodePtr->next;
			}

			// If nodePtr is not at the end of the list, 
			// link the previous node to the node after
			// nodePtr, then delete nodePtr.
			if (nodePtr)
			{
				if(nodePtr == tail)
				{
					tail = previousNode;
				}
				previousNode->next = nodePtr->next;
				delete nodePtr;
			}
		}
	}


	//searches for a value (num) and returns the position or -1 if can't be found
	int search(string num)
	{
		ListNode *nodePtr;  // To move through the list
		int position;

		// Position nodePtr at the head of the list.
		nodePtr = head;
		position = 0;

		// While nodePtr points to a node, traverse the list.
		while (nodePtr)
		{
			//see if this node matches the value
			if(nodePtr->value == num)
				return position;
			
			//increment position
			position++;

			// Move to the next node.
			nodePtr = nodePtr->next;
		}
		return -1; //node couldn't be found
	}

	void displayList() const
	{
		ListNode *nodePtr;  // To move through the list

		if(head != NULL)
		{
			// Position nodePtr at the head of the list.
			nodePtr = head;
			// While nodePtr points to a node, traverse the list.
			while (nodePtr)
			{
				// Display the value in this node.
				cout << nodePtr->value << endl;

				// Move to the next node.
				nodePtr = nodePtr->next;
			}
		}
		else
			cout << "\nThere are no nodes in the list.\n\n";
	}

};





#endif