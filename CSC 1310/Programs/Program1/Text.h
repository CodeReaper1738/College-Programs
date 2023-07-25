#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Text
{
	private:
		const char* textArray; // a pointer to a constant character array
		int textLength; //an integer representing the number of characters stored in the textArray

	public:
	
		Text(const char* text);	

		~Text();

		void displayText() const;

		const char* getText() const;

		int getLength() const;

};

#endif