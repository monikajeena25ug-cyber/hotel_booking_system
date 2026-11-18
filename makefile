hotel: main.o ui.o booking.o linkedlist.o file.o
	gcc main.o ui.o booking.o linkedlist.o file.o -o hotel

main.o: main.c
	gcc -c main.c

ui.o: ui.c
	gcc -c ui.c

booking.o: booking.c
	gcc -c booking.c

linkedlist.o: linkedlist.c
	gcc -c linkedlist.c

file.o: file.c
	gcc -c file.c
