#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <iostream>
using namespace std;

template<typename Booyah>
class LinkedList
{
	private:
		struct ListNode
		{
			Booyah value;
			ListNode* next;
		};
		
		ListNode* head;
		ListNode* tail;
		
	public:
		LinkedList() {
			head = NULL;
			tail = NULL;
		}
		~LinkedList() {
			ListNode* nodePtr;
			ListNode* nextPtr;
			nodePtr = head;
			while(nodePtr) {
				nextPtr = nodePtr->next;
				delete nodePtr;
				nodePtr = nextPtr;
			}
		}
		void appendNode(Booyah value)
		{
			ListNode* newNode;
			
			newNode = new ListNode;
			newNode->next = NULL;
			newNode->value = value;
			
			if(!head) {
				head = newNode;
				tail = newNode;
			}
			else
			{
				tail->next = newNode;
				tail = newNode;
			}	
		}
		void displayList()
		{
			ListNode* nodePtr;
			if(!head){
				cout << "\nThere are no nodes in the list.\n";
			} else {
				nodePtr = head;
				while(nodePtr) {
					cout << nodePtr->value << endl;
					nodePtr = nodePtr->next;
				}
			}
		}
};



#endif