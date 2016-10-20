compile1: sortByArtist.c
	gcc sortByArtist.c

run: a.out
	./a.out

clean:
	rm *~	
	rm *#
