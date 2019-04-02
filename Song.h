#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>

using namespace std;

class Song {

    private:
        string artist;
        string title;
        int memory;

    public:
        Song();
        Song(string artist);
        Song(string artist, string title);
        Song(string artist, string title, int memory);
        
        //Retrieving functions that access the different variables of the class 
        string getArtist() const;
        string getTitle() const;
        int getMemory() const;
    
        //Setting functions that access the different variables of the class
        void setArtist(string _artist);
        void setTitle(string _title);
        void setMemory(int _memory);
        void swap(Song &s2);

        //Operator overloads that signify the operators for the song class
        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);
};

//Output stream overload that allows for song class to be printed
ostream& operator << (ostream& out, const Song &s);


#endif
