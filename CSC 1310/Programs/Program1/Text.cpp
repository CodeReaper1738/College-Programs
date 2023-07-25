#include "Text.h"



Text::Text(const char* text)
{	
	//get the length of the string passed to this function
	textLength = strlen(text);
	
	//dynamically allocate a new character array
	char* tempTextArray = new char[(textLength)+1];
	
	//Now put text inside of tempTextArray
	strcpy(tempTextArray, text); 
	
	//put the text sent to this function into the newly created array
	this->textArray = tempTextArray;	
}

Text::~Text()
{
	cout << "Text Destructor: released memory from textArray\n";
	delete [] textArray;
}

void Text::displayText() const
{
	//print the c-string (textArray) to the screen
	cout << textArray;
}

const char* Text::getText() const
{
	//returns a pointer to a const. char. array
	return textArray;
}

int Text::getLength() const
{
	//returns length of the string
	return textLength;
}