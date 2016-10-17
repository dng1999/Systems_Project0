#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//a single song
typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

//array of song_node
song_node *table[26];

int main(){
  return 0;
}

////////SONG_NODE FUNCTIONS
song_node *insert_front(song_node *list, song_node *song){
  song->next = list;
  return song;
}

song_node *insert_order(song_node *list, song_node *song){
  //if song should be first in list
  if ((strcmp(song->artist,list->artist))<0){ //if song comes before list
    return insert_front(list,song);
  }
  //point where song should go after
  song_node *before = list;
  while ((strcmp(song->artist,list->artist))<0){ //while song comes before list
    list = list->next;
    before = list;
  }
  //if 
  
}
