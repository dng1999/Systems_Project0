/* header for playlist */


//add song
song_node *add_song(song_node *list, song_node *song);

//search for a song
song_node *search_song(song_node *list, char *name);

//search for an artist
song_node *search_artist(song_node *list, char *artist);

//print out all entries under a certain letter
void print_letter(song_node *list, char *letter);

//print out all songs of a certain artist
void print_artist(song_node *list, char *artist);

//print out the entire library
void print_lib(song_node *list);

//shuffle - print out a series of randomly chosen songs
song_node *shuffle(song_node *list);

//delete a song
song_node *del_song(song_node *list, song_node *song);

//delete all the nodes
song_node *del_list(song_node *list);

