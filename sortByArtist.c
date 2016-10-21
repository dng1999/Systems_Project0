#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int length = 0;

//-----------SONG_NODE FUNCTIONS
song_node *insert_front(song_node *list, song_node *song){
  if (!length){
    return song;
  }
  else {
    song->next = list;
    length++;
    return song;
  }
}

song_node *insert_order(song_node *list, song_node *song){
  if (!length){
    length++;
    return song;
  }
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
  //if same artist
  if ((strcmp(song->artist,list->artist))==0){
    while ((strcmp(song->name,list->name))<0){
      list = list->next;
      before = list;
    }
  }
  //if not same artist or same artist diff song
  before->next = song;
  song->next = list;
  length++;
  return list;
}

void print_list(song_node *list){
  while (list){
    printf("*%s - %s* ",list->artist, list->name);
    list = list->next;
  }
  printf("end");
}

song_node *find_song(song_node *list, char *name){
  while(list){
    if (list->name == name){
      return list;
    }
    else {
      list = list->next;
    }
  }
  return NULL;
}

song_node *find_artist(song_node *list, char *artist){
  while(list){
    if (list->artist == artist){
      return list;
    }
    else {
      list = list->next;
    }
  }
  return NULL;
}

song_node *random_song(song_node *list){
  if (!length){
    return NULL;
  }
  srand(time(NULL));
  int randNo = rand()%length;
  while (randNo){
    list = list->next;
    randNo--;
  }
  return list;
}

song_node *remove_node(song_node *list, song_node *song){
  if (list == song){
    song_node *tmp = song->next;
    free(song);
    return tmp;
  }
  else {
    while (list){
      if (list->next == song){
	list->next == song->next;
	free(song);
	return list;
      }
      else {
	list = list->next;
      }
    }
  }
}

song_node *free_list(song_node *list){
  song_node *head = (song_node *) calloc(sizeof(song_node),1);
  song_node *tmp = (song_node *) calloc(sizeof(song_node),1);
  while (list){
    tmp = list->next;
    free(list);
    list = tmp;
  }
  return head;
}
