#include "Text.h"
#include "VideoGame.h"
#include "VideoGameLibrary.h"

//print Video Game Details Function!
void VideoGame::printVideoGameDetails()
{
    //Specifications: Print the title, year, genre, rating & number of stars. 
    
    cout << "			Game Title:   ";
    title->displayText();

    cout << "			Platform:   ";
    platform->displayText();


    cout << "			Year Released:   " << year << endl;

    cout << "			Genre:   ";
    genre->displayText();

    cout << "			Rating:   ";
    ageRating->displayText();


    cout << "			Number of Stars:   " << userRating << endl;
    cout << endl;
}

void VideoGame::printVideoGameDetailsToFile(ofstream& outFile)
{
	outFile << title->getText() << endl;
	outFile << platform->getText() << endl;
	outFile << year << endl;
	outFile << genre->getText() << endl;
	outFile << ageRating->getText() << endl;
	outFile << userRating << endl;
	
}

Text* VideoGame::getVideoGameTitle() const{
	//Returns a pointer to the Text object containing the video game title
	return this->title;
}