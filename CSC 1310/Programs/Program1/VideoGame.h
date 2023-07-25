#ifndef VIDEOGAME_H
#define VIDEOGAME_H


#include "Text.h"

class VideoGame
{
    private:
            Text* title;     //a pointer to a Text object, which will hold the title of the video game
            Text* platform;     //a pointer to a Text object, which will hold the platforms that the video game is available
            Text* genre;     //a pointer to a Text object, which will hold the genre of the video gam
            Text* ageRating;     //a pointer to a Text object, which will hold the age rating of the video game
            int year;     //an integer representing the year the video game was released
            int userRating;     //1-100 from IGDB
public:
            //constructors
            VideoGame(Text* a, Text* b, Text* c, Text* d, int e, int f) //This function should be called when all video game information is known and it will create a new videogame with this information
            {
                this->title = a;
                this->platform = b;
                this->genre = c;
                this->ageRating = d;
                this->year = e;
                this->userRating = f;
            }

            //destructors
            ~VideoGame() //This function is automatically called when a Video game object is destroyed.  This function releases the dynamically allocated text arrays in the Video game
            {
                delete title;
				delete platform;
				delete genre;
				delete ageRating;
				
				cout << "VideoGame destructor: Released memory for title, platform, genre, & rating." << endl;
                
            }


            //print Video Game Details Function!
            void printVideoGameDetails();

            void printVideoGameDetailsToFile(ofstream&);
//ACCESSOR FUNCTIONS
            Text* getVideoGameTitle() const;
};


#endif