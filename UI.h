#ifndef UI_H
#define UI_H

#include "room.h"

// Main menu
void main_menu(RoomList *list);

// Add room menu
void add_room_menu(RoomList *list);

// Display all rooms
void list_rooms(RoomList *list);

// Display room details
void display_room(Room *room);

// Select a room
Node *select_room(RoomList *list);

// Room operations menu
void room_operations_menu(Node *room);

// Input functions
int get_choice(const char *message);
void get_string(char *text, int size);

#endif
