#include <stdlib.h>
#include <string.h>
#include "sortByArtist.h"


song_node *add_song(song_node *list, char *artist, char *name){
  song_node *song = (song_node *) calloc(sizeof(song_node),1);
  song -> artist = artist;
  song -> name = name;
  //a=97
  int pos = strncmp(song->artist,'a',1);
  insert_order(list[pos], song);
  return song;
}


song_node *search_song(song_node *list, char *name){
  while(list){
    return find_song(list,name);
  }
  return NULL;
}

song_node *search_artist(song_node *list, char *artist){
  int pos = strncmp(artist,'a',1);
  find_artist(list[pos],artist);
  return NULL;
}


void print_letter(song_node *list, char *letter){
  int pos = strcmp(letter,'a');
  print_list(list[pos]);
}

void print_artist(song_node *list, char *artist){
  int pos = strcmp(letter,'a');
  while(list[pos]){
    if (list[pos]->artist == artist){
      printf("%s - %s",list[pos]->artist, list[pos]->name);
    }
    list[pos] = list[pos]->next;
  }
}

void print_lib(song_node *list){
  while(list){
    print_list(list);
    list = list->next;
  }
}

void *shuffle(song_node *list){
  int i=0;
  while(i<3){
    sranddev();
    int randNo = rand()%26;
    printf("%s",random_song(list[randNo]));
  }
}

song_node *del_song(song_node *list, song_node *song){
  int pos = strncmp(artist,'a',1);
  remove_node(list[pos],song);
}

song_node *del_list(song_node *list){
  while(list){
    song_node *tmp = list->next;
    free(list);
    list = tmp
  }
  return NULL;
}
