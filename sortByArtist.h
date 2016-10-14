/* header file for sorting by artist*/

//insert node at front
struct song_node *insert_front(struct song_node *list, struct song_node *song);

//insert node in order
struct song_node *insert_order(struct song_node *list, struct song_node *song);

//print the entire list
void print_list(struct song_node *list);

//find and return a pointer to an individual song based on song name
struct song_node *find_song(struct song_node *list, char *name);

//find and return a pointer to the first song of an artist based on artist name
struct song_node *find_artist(struct song_node *list, char *artist);

//return a pointer to random element in the list
struct song_node *random_song(struct song_node *list);

//remove a single node from the list
struct song_node *remove_node(struct song_node *list, struct song_node *song);

//free the entire list
//should return null
struct node *free_list(struct node *list);
