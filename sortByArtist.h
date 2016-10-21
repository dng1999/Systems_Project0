/* header file for sorting by artist*/

//a single song
typedef struct song_node{
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

//insert node at front
song_node *insert_front(song_node *list, song_node *song);

//insert node in order
song_node *insert_order(song_node *list, song_node *song);

//print the entire list
void print_list(song_node *list);

//find and return a pointer to an individual song based on song name
song_node *find_song(song_node *list, char *name);

//find and return a pointer to the first song of an artist based on artist name
song_node *find_artist(song_node *list, char *artist);

//return a pointer to random element in the list
song_node *random_song(song_node *list);

//remove a single node from the list
song_node *remove_node(song_node *list, song_node *song);

//free the entire list
//should return null
song_node *free_list(song_node *list);
