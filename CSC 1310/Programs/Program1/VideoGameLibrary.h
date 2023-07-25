#ifndef VIDEOGAMELIBRARY_H
#define VIDEOGAMELIBRARY_H

#include "VideoGame.h"



class VideoGameLibrary 
{
    private:
        VideoGame** videoGamesArray;
        int maxGames;
        int numGames;

    public:
        VideoGameLibrary(int m) 
        {
            videoGamesArray = new VideoGame*[m];
            maxGames = m;
            numGames = 0;
        }

        ~VideoGameLibrary()
        {
            for (int i = 0; i < numGames; i++) 
			{
                delete videoGamesArray[i];
            }
            delete[] videoGamesArray;

        };

        void resizeVideoGameArray();
        void addVideoGameToArray();
        void displayVideoGames();
        void displayVideoGameTitles();
        void loadVideoGamesFromFile(char*);
        void removeVideoGameFromArray();
        void saveToFile(char*);
};
#endif