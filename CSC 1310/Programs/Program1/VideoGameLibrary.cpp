#include "VideoGameLibrary.h"


void VideoGameLibrary::saveToFile(char* file) //Option 2
{
	ofstream fileName;
	fileName.open(file);
	for (int x = 0; x < numGames; x++)
	{
		videoGamesArray[x]->printVideoGameDetailsToFile(fileName);
	}
	fileName.close();

	cout << "All video games in your library have been printed to " << file << endl;
}

void VideoGameLibrary::displayVideoGameTitles()
{
	for (int x = 0; x < numGames; x++) 
	{
		videoGamesArray[x]->getVideoGameTitle()->displayText();

	}
	
}

void VideoGameLibrary::loadVideoGamesFromFile(char* fileName) //OPTION 1
{
		ifstream inFile;
		inFile.open(fileName);
		char temp[1000];
		int counter = 0;
		if (!inFile.good()) 
		{
			cout << "File failed to open";
		}
		else 
		{
			while (!inFile.eof()) 
			{
				int year, userRating;

				inFile.getline(temp, 1000);
				Text* Title = new Text(temp);

				inFile.getline(temp, 1000);
				Text* Platform = new Text(temp);

				inFile >> year;
				inFile.ignore();

				inFile.getline(temp, 1000);
				Text* Genre = new Text(temp);

				inFile.getline(temp, 1000);
				Text* ageRating = new Text(temp);

				inFile >> userRating;
				inFile.ignore(); 

				VideoGame* game = new VideoGame(Title, Platform, Genre, ageRating, year, userRating);
				if (numGames == maxGames) 
				{
					resizeVideoGameArray();
				}

				videoGamesArray[numGames] = game;
				numGames++;
				Title->displayText();
				cout << "Was added to the library\n";
				
				counter++;
			}
			cout << counter << " games were added to the video game library!" << endl;
		}
}
void VideoGameLibrary::displayVideoGames() //AKA option 5 
{
	Text* videoGameTitle;
	for (int x = 0; x < numGames; x++)
	{
		cout << "			-----------Video Game " << x + 1 << "-----------" << endl;
		videoGamesArray[x]->printVideoGameDetails();
	}
}



void VideoGameLibrary::addVideoGameToArray() // Option 3
{
	char userInput[100];
	int year, userRating;

	cout << endl;
	cin.ignore();

	cout << "Video Game TITLE:  ";
	cin.getline(userInput, 100);
	Text* gameTitle = new Text(userInput);
	cout << endl;

	cout << "Video Game PLATFORM:  ";
	cin.getline(userInput, 100);
	Text* gamePlatform = new Text(userInput);
	cout << endl;

	cout << "Video Game YEAR:  ";
	cin >> year;
	cin.ignore();
	cout << endl;

	cout << "Video Game GENRE:  ";
	cin.getline(userInput, 100);
	Text* gameGenre = new Text(userInput);
	cout << endl;

	cout << "Video Game AGE RATING:  ";
	cin.getline(userInput, 100);
	Text* gameAgeRating = new Text(userInput);
	cout << endl;

	cout << "Video Game USER RATING (out of 100):  ";
	cin >> userRating;
	cout << endl;

	VideoGame* game = new VideoGame(gameTitle, gamePlatform, gameGenre, gameAgeRating, year, userRating);
	if (numGames == maxGames)
	{
		resizeVideoGameArray();
	}
	videoGamesArray[numGames] = game;
	numGames++;
}

void VideoGameLibrary::removeVideoGameFromArray() // Option 4
{
	int choice;
	Text* videoGameTitle;
	if (numGames < 1) 
	{
		cout << "You must have at least one game to delete\n";
		
	}
	else 
	{
		for(int count = 0; count < numGames; count++)
		{
			cout << "Video Game " << count + 1 << ": ";
			videoGameTitle = videoGamesArray[count]->getVideoGameTitle();
			videoGameTitle->displayText();
			cout << endl;
		}
		
		cout << "Choose a video game to remove between 1 & " << numGames << endl;
		cin >> choice;
		cout << endl;
		
		int removeIndex = choice - 1;
		
		cout << "The Video Game ";
		videoGameTitle = videoGamesArray[removeIndex]->getVideoGameTitle();
		videoGameTitle->displayText();
		cout << " has been successfully deleted" << endl << endl;
		
	
		delete videoGamesArray[removeIndex];
		
		for(int i = removeIndex; i < (numGames - 1); i++)
		{
			videoGamesArray[i] = videoGamesArray[i+1];
		}
		
		numGames--; 
	
	}
}


void VideoGameLibrary::resizeVideoGameArray()
{
	int max = maxGames*2;
	cout <<"Resizing from " << maxGames << " to " << max << endl;
	VideoGame** tempArray = new VideoGame*[max];
	for (int i = 0; i < numGames; i++) {
		tempArray[i] = videoGamesArray[i];
	}
	
	delete [] videoGamesArray;
	videoGamesArray = tempArray;
	maxGames = max;
}