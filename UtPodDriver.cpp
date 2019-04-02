#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[]){

      UtPod pod;

      cout<<endl<<"Michael Nguyen - myn99" << endl << "UtPod Program" << endl << endl << endl;

      Song s1("Frederic Chopin", "Etudes, Op. 25: No. 5 in E Minor", 30);
      Song s2("Schoolboy Q", "Collard Greens ft. Kendrick Lamar", 21);
      Song s3("Sam Hunt", "Body Like a Back Road", 200);
      Song s4("Mason Ramsey", "Famous", 19);
      Song s5("Mason Ramsey", "Lovesick Blues", 58);
      Song s6("Mason Ramsey", "Famous", 20);


      Song a1("A", "A", 60);
      Song a2("A", "B", 60);
      Song a3("A", "A", 60);
      Song a4("A", "A", 40);
      Song a5("A", "b", 10);
      Song a6("B", "A", 40);
      Song a7("B", "B", 10);
      Song a8("Z", "Z", 10);
      Song a9("A", "A", 1000);

      pod.addSong(s1);
      pod.addSong(s2);
      pod.addSong(s3);
      pod.addSong(s4);
      pod.addSong(s5);
      pod.addSong(s6);
 
      cout<<"Songs displayed in order of creation" << endl<<endl;
      pod.showSongList();

      cout<<"Total memory via getTotalMemory() - " << pod.getTotalMemory()<<endl<<endl;
      cout<<"Remaining memory via getRemainingMemory() - " << pod.getRemainingMemory()<<endl<<endl;
 
      pod.shuffle();
    
      cout<<"Songs displayed in shuffled order" << endl<<endl;
      pod.showSongList();

      pod.sortSongList();

      cout<<"Songs display in sorted order (Sorted by artist, title, memory)" << endl<<endl;
      pod.showSongList();

      pod.removeSong(s1);
      pod.removeSong(s2);
      pod.removeSong(s3);
      cout<<"I've removed all songs not performed by Mason Ramsey"<<endl<<endl;
      pod.showSongList();

      pod.clearMemory();

      cout<<"UtPod is cleared, following message results from showSongList()" << endl<<endl;
      pod.showSongList();

      pod.addSong(a1);
      pod.addSong(a2);
      pod.addSong(a3);
      pod.addSong(a4);
      pod.addSong(a5);
      pod.addSong(a6);
      pod.addSong(a7);
      pod.addSong(a8);


      cout<<"Songs displayed in order of creation" << endl<<endl;
      pod.showSongList();

      cout<<"Total memory via getTotalMemory() - " << pod.getTotalMemory()<<endl<<endl;
      cout<<"Remaining memory via getRemainingMemory() - " << pod.getRemainingMemory()<<endl<<endl;

      cout<<"Song a9 with memory-" << a9.getMemory() << " is attempted to be added to UtPod. \nError code = " << pod.addSong(a9)<<endl<<endl; 

 
      pod.shuffle();
    
      cout<<"Songs displayed in shuffled order" << endl<<endl;
      pod.showSongList();

      pod.sortSongList();

      cout<<"Songs display in sorted order (Sorted by artist, title, memory)" << endl<<endl;
      pod.showSongList();

      pod.clearMemory();

      cout<<"UtPod is cleared, following message results from showSongList()" << endl<<endl;
      pod.showSongList();



//    Song s1 = new Song("Beatles", "Hay Jude", 4);

}
