#include "Song.h"

#include <string>
#include <iostream>

using namespace std;

        Song::Song(){
            artist = "";
            title = "";
            memory = 0;
        }

        Song::Song(string _artist){
            artist = _artist;
            title = "";
            memory = 0;
        }

        Song::Song(string _artist, string _title){
            artist = _artist;
            title = _title;
            memory = 0;
        }

        Song::Song(string _artist, string _title, int _memory){
            artist = _artist;
            title = _title;
            memory = _memory;
        }

        string Song::getArtist() const{
            return artist;
        }
        
        string Song::getTitle() const{
            return title;
        }

        int Song::getMemory() const{
            return memory;
        }

        void Song::setArtist(string _artist){
            artist = _artist;
        }
     
        void Song::setTitle(string _title){
            title = _title;
        }
 
        void Song::setMemory(int _memory){
            memory = _memory;
        }

        void Song::swap(Song &s2){
            Song temp = s2;
            s2 = *this;
            *this = temp;
        }


//Operators will check if a song is greater than, less than, or equal to another song
//Order is artist > title > memory
        bool Song::operator >(Song const &rhs){
            if(getArtist()>rhs.getArtist())
                return 1;
            else{
                if(getArtist()==rhs.getArtist()){
                    if(getTitle()<rhs.getTitle())
                        return 0;
                    else{
                        if(getTitle()==rhs.getTitle())
                            return(getMemory()>rhs.getMemory());
                    }
                }                
                else return 0;
            }
        }
   
        bool Song::operator <(Song const &rhs){
             if(getArtist()<rhs.getArtist())
                return 1;
            else{
                if(getArtist()==rhs.getArtist()){
                    if(getTitle()>rhs.getTitle())
                        return 0;
                    else{
                        if(getTitle()==rhs.getTitle())
                            return(getMemory()<rhs.getMemory());
                    }
                }                
                else return 0;
            }
        }
    
        bool Song::operator ==(Song const &rhs){
            return((getArtist()==rhs.getArtist())&&(getTitle()==rhs.getTitle())&&(getMemory()==rhs.getMemory()));
        }


        ostream& operator << (ostream& out, const Song &s){
             out << s.getTitle() << ", " << s.getArtist() << ", " << s.getMemory() << " MB";
             return out;
        }

