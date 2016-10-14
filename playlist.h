/* header for playlist */


//add song
struct song_node *add_song(struct song_node *list, struct song_node *song);

//search for a song
struct song_node *find_song(struct song_node *list, char *name);

//search for an artist
struct song_node *find_artist(struct song_node *list, char *artist);

//print out all entries under a certain letter
void print_letter(struct song_node *list, char *letter);

//print out all songs of a certain artist
void print_artist(struct song_node *list, char *artist);

//print out the entire library
void print_list(struct song_node *list);

//shuffle - print out a series of randomly chosen songs
struct song_node *shuffle(struct song_node *list);

//delete a song
struct song_node *del_song(struct song_node *list, struct song_node *song);

//delete all the nodes
struct song_node *del_list(struct song_node *list);

