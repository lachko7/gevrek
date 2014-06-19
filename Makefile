all: board

board: deck.o board.o card.o manapool.o player.o shuffle.o
	gcc deck.o player.o card.o shuffle.o manapool.o board.o -o board

deck.o: deck.c deck.h	
	gcc -c deck.c deck.h 
	
player.o: player.c player.h
	gcc -c player.c player.h

board.o: board.h  player.h
	gcc -c board.h board.c player.h 

manapool.o: manapool.c manapool.h	
	gcc -c manapool.c manapool.h 

card.o: card.c card.h
	gcc -c card.c card.h

shuffle.o: shuffle.h shuffle.c
	gcc -c shuffle.h shuffle.c

clean:
	rm -f *.o board



