all:
	gcc main.c UI.c booking_engine.c linked_list.c file_persistence.c -o hotel.exe

run:
	hotel.exe

clean:
	del hotel.exe
