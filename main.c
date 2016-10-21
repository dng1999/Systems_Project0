#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//a single song
typedef struct song_node{
  char *name;
  char *artist;
  struct song_node *next;
} song_node;

//array of song_nodes
typedef struct playlist{
  song_node * table[26];
} playlist;

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

song_node *remove_node(song_node *list, char *artist, char *name){
  if (list->artist == artist && list->name == name){
    song_node *tmp = list->next;
    free(list);
    return tmp;
  }
  else {
    while (list){
      if (list->next->artist == artist && list->next->name == name){
	list->next = list->next->next;
	free(list->next);
	return list;
      }
      else {
	list = list->next;
      }
    }
  }
  return list;
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

song_node *add_song(playlist *list, char *artist, char *name){
  song_node *song = (song_node *) calloc(sizeof(song_node),1);
  song -> artist = artist;
  song -> name = name;
  //a=97
  int pos = strncmp(song->artist,"a",1);
  list->table[pos]= insert_order(list->table[pos], song);
  return song;
}


song_node *search_song(playlist *list, char *name){
  int i = 0;
  song_node *ret = NULL;
  for (i;i<26;i++){
    song_node *ret = find_song(list->table[i],name);
  }
  return ret;
}

song_node *search_artist(playlist *list, char *artist){
  int pos = strncmp(artist,"a",1);
  find_artist(list->table[pos],artist);
  return NULL;
}


void print_letter(playlist *list, char *letter){
  int pos = strcmp(letter,"a");
  print_list(list->table[pos]);
}

void print_artist(playlist *list, char *artist){
  int pos = strncmp(artist,"a",1);
  while(list->table[pos]){
    if (list->table[pos]->artist == artist){
      printf("*%s - %s* ",list->table[pos]->artist, list->table[pos]->name);
    }
    list->table[pos] = list->table[pos]->next;
  }
  printf("end");
}

void print_lib(playlist *list){
  int i = 0;
  for(i;i<26;i++){
    print_list(list->table[i]);
  }
}

void *shuffle(playlist *list){
  int i=0;
  while(i<3){
    sranddev();
    int randNo = rand()%26;
    printf("%s",random_song(list->table[randNo]));
  }
}

song_node *del_song(playlist *list, char *artist, char *name){
  int pos = strncmp(artist,"a",1);
  remove_node(list->table[pos],artist,name);
}

song_node *del_list(playlist *list){
  int i = 0;
  for(i;i<26;i++){
    free_list(list->table[i]);
  }
  return NULL;
}

int main(){
  playlist *list = (playlist *)calloc(1,sizeof(playlist));

  add_song(list, "angela","shangri la");
  add_song(list, "angela","dead or alive");
  add_song(list, "angela","exist");
  
  add_song(list,"alan walker","sing me to sleep");
  add_song(list,"hamo","its a wonderful world");
  add_song(list,"shinee","replay");
  add_song(list,"hydrogen sea","beating heart");

  printf("Testing print_lib:\n");
  print_lib(list);

  printf("\nTesting print_letter:\n");
  printf("a artists: /t");
  print_letter(list,"a");
 
  printf("\nTesting search_song:\n");
  printf("looking for *shangri la*\n");
  search_song(list, "shangri la");
  printf("looking for *separation*\n");
  search_song(list, "separation");

  printf("\nTesting search_artist:\n");
  printf("looking for angela\n");
  search_artist(list, "angela");
  printf("\nlooking for hamo\n");
  search_artist(list, "hamo");
  
  printf("\nTesting print_artist:\n");
  printf("angela:\t");
  print_artist(list,"angela");
  printf("\nshinee:\t");
  print_artist(list,"shinee");
  
  printf("\nTesting shuffle:\n");
  shuffle(list);

  printf("\nTesting del_song:\n");  
  del_song(list,"alan walker","sing me to sleep");
  
  printf("\nTesting del_list:\n");
  del_list(list);
  
  return 0;
}

