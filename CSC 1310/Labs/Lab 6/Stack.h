#ifndef STACK_H
#define STACK_H

#include<iostream>
#include<fstream>
using namespace std;

// Stack template
template <typename T>
class Stack
{
	private:
	   // Structure for the stach nodes
	   struct StackNode
	   {
		  T value;         
		  StackNode *next;  // Pointer to next node
	   };
	   
	   StackNode *top;     

	public:
	   //Constructor
	   Stack() {
		   top = NULL; 
	   }

	void push(T item)
	{
	   StackNode *newNode = NULL; 

	   // Allocate a new node and store num there.
	   newNode = new StackNode;
	   newNode->value = item;

	   // If there are no nodes in the list
	   // make newNode the first node.
	   if (isEmpty())
	   {
		  top = newNode;
		  newNode->next = NULL;
	   }
	   else  // Otherwise, insert NewNode before top.
	   {
		  newNode->next = top;
		  top = newNode;
	   }
	}

	void pop(T &item)
	{
	   StackNode *temp = NULL; // Temporary pointer

	   // First make sure the stack isn't empty.
	   if (isEmpty())
	   {
		  cout << "The stack is empty.\n";
	   }
	   else  // pop value off top of stack
	   {
		  item = top->value;
		  temp = top->next;
		  delete top;
		  top = temp;
	   }
	}

	bool isEmpty()
	{
	   bool status;

	   if (!top)
		  status = true;
	   else
		  status = false;

	   return status;
	}
};
#endif