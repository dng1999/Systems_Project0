compile: main.o playlist.o sortByArtist.o
	gcc main.o playlist.o sortByArtist.o -o a.out

run: a.out
	./a.out

clean:
	rm *~	
	rm *#
