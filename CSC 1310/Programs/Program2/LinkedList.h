/*****************************************************************
	Title:  	LinkedList.h -  template
	Date:  		3-11-2020
	Author: 	Yago Romano
	Purpose:	create a list to hold dinosaurs and functions for them 
******************************************************************/


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Dinasaur.h"

template<typename T>
class LinkedList {
	private: 
		struct ListNode{
			T objects;
			struct ListNode *next; // Points to the next node
		};
		
		// List beginning pointer
		ListNode *head; 
		// List end pointer
		ListNode *tail;
		int numNodes;
		
	public:
		// Setting all objects to nothing
		LinkedList() {
			head = NULL;
			tail = NULL;
			numNodes = 0;
		}
		
		~LinkedList(){
			// To go through the list
			ListNode *nodePtr;
			// To point to the next node
			ListNode *nextNode;
			
			nodePtr = head;
			
			while(nodePtr){
				// Save a pointer to the next node
				nextNode = nodePtr->next;
				// Deletes the node
				delete nodePtr;
				
				nodePtr = nextNode;
				numNodes--;
			}
			
		}
		// returns the number of nodes in the list.
		int getLength()
		{
			return numNodes;
		}
		void deleteNode(int num)
		{
			ListNode *nodePtr;       // To traverse the list
			ListNode *previousNode;  // To point to the previous node
			
			
			if (num == 0){
				nodePtr = head->next;
				delete head;
				head = nodePtr;
				numNodes--;
			
			} else {
				// Initialize nodePtr to head of list
				nodePtr = head;
				int pos = 0;
				// Skip all nodes whose value member is 
				// not equal to num.
				while (pos != num)
				{  
					previousNode = nodePtr;
					nodePtr = nodePtr->next;
					pos++;
				}

				// If nodePtr is not at the end of the list, link the previous node to the node after
				// nodePtr, then delete nodePtr.
				
				if(nodePtr == tail)
				{
					tail = previousNode;
				}
				previousNode->next = nodePtr->next;
				delete nodePtr;
				numNodes--;
				
			}
		}
		void appendNode(T num)
		{
			// To point to a new node
			ListNode *newNode;  

			// Allocate a new node and store num there.
			newNode = new ListNode;
			newNode->objects = num;
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
			numNodes++;
		}
		T getNodeValue(int position)
		{
			ListNode *nodePtr;
			if(!head)
				cout << "There is a problem with the list \n";
			else
			{
				if(position == 0)
					return head->objects;
				nodePtr = head;
				int currentPos = 0;
				while(nodePtr != NULL && position >= currentPos)
				{
					if(position == currentPos)
						return nodePtr->objects;
					currentPos++;
					nodePtr = nodePtr->next;				
				}
			}
			//return 0;
		}
		void insertNode(T num, int position)
		{
			ListNode *nodePtr;
			ListNode *newNode;
			
			ListNode *previousNode;
			
			newNode = new ListNode;
			newNode->objects = num;
			newNode->next = NULL;
			
			numNodes++;
			
			if(!head)
			{

				head = newNode;
				tail = newNode;
			}
			else 
			{
				nodePtr = head;
				int nodeCount = 0;
				if(position == 0)
				{
					newNode->next = head;
					head = newNode;
					return;
				}
				
				//now nodePtr is positioned 1 node BEFORE the node we want to insert
				if(position >= this->getLength() - 1) //we are appending this node to the end
				{
					newNode->next = NULL;
					tail->next = newNode;
					tail = newNode;
					return;
				}
				
				while(nodeCount != position)
				{
					previousNode = nodePtr;
					nodeCount++;
					nodePtr = nodePtr->next;
				}
				newNode->next = nodePtr;
				previousNode->next = newNode;
				
				
			}
			
		}
		
		
};

#endif