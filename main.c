#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "playlist.h"

int main(){
  playlist *list = (playlist *)calloc(1,sizeof(playlist));

  list = add_song(list, "angela","shangri la");
  list = add_song(list, "angela","dead or alive");
  list = add_song(list, "angela","exist");
  
  list = add_song(list,"alan walker","sing me to sleep");
  list = add_song(list,"hamo","its a wonderful world");
  list = add_song(list,"shinee","replay");
  list = add_song(list,"hydrogen sea","beating heart");

  printf("Testing print_lib:\n");
  print_lib(list);

  printf("\nTesting print_letter:\n");
  printf("a artists: /t");
  print_letter(list,'a');
 
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
  
  del_song(list,
  
  return 0;
}
