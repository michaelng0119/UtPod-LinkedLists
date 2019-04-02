//Michael Nguyen - myn99
//Last modified: 3/26/19
//EE312- Wednesday 3:00 Recitation

#include "UtPod.h"
#include "Song.h"

#include <string.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>


      /* FUNCTION - void swap 
       * swaps the contents of two song classes

       input parms - the reference to two song classes

       output parms - none

      */

      void UtPod::swap(Song &s1, Song &s2){

          if(s1 == s2) return;

          Song temp = s1;
          s1 = s2;
          s2 = temp; 

      }

      //Default constructor
      //set the memory size to MAX_MEMORY
      UtPod::UtPod(){
          songs = NULL;
          podMemSize = MAX_MEMORY;
          srand((unsigned)time(0));
      }

      //Constructor with size parameter
      //The user of the class will pass in a size.
      //If the size is greater than MAX_MEMORY or less than or equal to 0,
      //set the size to MAX_MEMORY.
      UtPod::UtPod(int size){
          songs = NULL;
          if(size>MAX_MEMORY || size<=0)
              podMemSize = MAX_MEMORY;
          else podMemSize = size;
          srand((unsigned)time(0));
      }

      /* FUNCTION - int addSong
       * attempts to add a new song to the UtPod
           o returns a 0 if successful
           o returns -1 if not enough memory to add the song

       precondition: s is a valid Song

       input parms - Song class object, including artist, title, and memory

       output parms - 0 if successful, -1 if not enough memory
      */

      int UtPod::addSong(Song const &s){
          SongNode *temp = new SongNode();
          SongNode *ptr = songs; 

          temp->s = s;

          //if input song is not fully filled, -2 is returned
          if(s.getArtist()==""||s.getTitle()==""||s.getMemory()==0)
              return -2;
          
          //if linked list is empty, head is set to temp
          if(songs == NULL){
              if(s.getMemory() < podMemSize){
                  songs = temp;
              }
              else return NO_MEMORY;
          }

          //if linked list is not empty, traverse and add at end
          else{
               while(ptr->next != NULL){
                   ptr = ptr->next;
               }

               //check for memory space. if remaining memory is not sufficient then exit
               if(s.getMemory()<=getRemainingMemory()){
                   ptr->next = temp;
               }
               else return NO_MEMORY;
          }
          return SUCCESS;
      }

      /* FUNCTION - int removeSong
       * attempts to remove a song from the UtPod
       * removes the first instance of a song that is in the the UtPod multiple times
           o returns 0 if successful
           o returns -1 if nothing is removed


         input parms - Song class object, including artist, title, and memory

         output parms - 0 if successful, -1 if nothing is removed
      */

      int UtPod::removeSong(Song const &s){
          SongNode *ptr = songs;
          SongNode *prev = NULL;

          //if input parameter is invalid song then return 2
          if(s.getArtist()==""||s.getTitle()==""||s.getMemory()==0)
             return -2;

          //if linked list is empty, return -1
          if (songs == NULL) return -1;

          //if input song is head of list, reassign head
          if(songs->s == s){
              songs = songs->next;
              delete ptr;
              return SUCCESS;
          }

          //traverse through LL to find song
          //If found, delete and reassign next values
          while(ptr!=NULL){

              if(ptr->s == s){
                  prev->next = ptr->next;
                  return SUCCESS;
              }
              prev = ptr;
              ptr = ptr->next;
          }
          return -1;

      }


      /* FUNCTION - void shuffle
       *  shuffles the songs into random order
          o will do nothing if there are less than two songs in the current list

         input parms - none

         output parms - none
      */

      void UtPod::shuffle(){
          int num = numSongs();

          for(int i = 0; i < 3*(num); i++){
              
              //Creation of 2 pointers for shuffling
              SongNode *ptr1 = songs;
              SongNode *ptr2 = songs;

              //traversal for first node using random num
              for(int j = 0; j < rand()%num; j++){
                  ptr1 = ptr1->next;
              }

              //traversal for second node using random num
              for(int j = 0; j < rand()%num; j++){
                  ptr2 = ptr2->next;
              }

              swap(ptr1->s, ptr2->s);

          }
 
          return;
      }


      /* FUNCTION - void showSongList
       * prints the current list of songs in order from first to last to standard output
       * format - Title, Artist, size in MB (one song per line)

         input parms - none

         output parms - none
      */

      void UtPod::showSongList(){

          SongNode *ptr = songs; 

          if(songs == NULL){
              cout << "No songs detected in UtPod" << endl;
              return;
          }

          //Traverse list while displaying each node's song
          while(ptr != NULL){
              cout << ptr->s << endl;
              ptr = ptr->next;
          }
  
          cout << endl;

      }


      /* FUNCTION - void sortSongList
       *  sorts the songs in ascending order
          o will do nothing if there are less than two songs in the current list

         input parms - none

         output parms - none
      */

      void UtPod::sortSongList(){

          //Selection sort method, the list will be sorted one value at a time
          for(SongNode *p = songs; p!= NULL; p = p->next){
              for(SongNode *p2 = p->next; p2!= NULL; p2 = p2->next){
                  if(p2->s < p->s){
                       swap(p2->s, p->s);
                  }
              }
          }
      }


      /* FUNCTION - void clearMemory
       * clears all the songs from memory

         input parms - none

         output parms - none
      */
      void UtPod::clearMemory(){

          //Deletes nodes starting at the head of the list. Increment head until NULL
          while(songs!=NULL){
              SongNode *temp = songs;
              songs = songs->next;
              delete temp;
          }
      }

      /* FUNCTION - int getTotalMemory
       *  returns the total amount of memory in the UtPod
          o will do nothing if there are less than two songs in the current list

         input parms - none

         output parms - none
      */

      int UtPod::getTotalMemory() {
         SongNode *ptr = songs;
         if(songs == NULL) return 0;

         int memSize = 0;

         //Traverse through list and add up memory
         while(ptr != NULL){
             memSize += ptr->s.getMemory();
             ptr = ptr->next;
         }
         return memSize;
      }



      /* FUNCTION - int getRemainingMemory
       *  returns the amount of memory available for adding new songs

         input parms - none

         output parms - none
      */

      int UtPod::getRemainingMemory(){
         return (podMemSize - getTotalMemory());
      }


      //Deconstructor calls clearMemory()
      UtPod::~UtPod(){
          clearMemory();
      }

      /* FUNCTION - int numSongs
       * returns the number of songs in the UtPod
       
         input parms - none
    
         output parms - number of songs
      */

      int UtPod::numSongs(){
      
          int numSong = 0;
          SongNode *ptr = songs;

          //Increments numSong while traversing through LL
          if(songs == NULL) return numSong;
          else{
              while(ptr!=NULL){
                  numSong++;
                  ptr = ptr->next;
              }
          }
          return numSong;
      }




