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


  printf("Testing find:\n");
  printf("a artists: /t");
  print_list(playlist,'p');

  return 0;
}
