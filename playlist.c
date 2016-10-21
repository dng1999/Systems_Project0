#include <stdlib.h>
#include <string.h>
#include "sortByArtist.h"


song_node *add_song(song_node *list, song_node *song);

song_node *search_song(song_node *list, char *name);

song_node *search_artist(song_node *list, char *artist);

void print_letter(song_node *list, char *letter);

void print_artist(song_node *list, char *artist);

void print_lib(song_node *list);

song_node *shuffle(song_node *list);

song_node *del_song(song_node *list, song_node *song);

song_node *del_list(song_node *list);
