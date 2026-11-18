#ifndef linkedlist_h
#define linkedlist_h

#include "room.h"

// Initialize linked list
void initialize_list(roomList *list);

// Create a new node
Node *create_node(room room);

// Insert a new room
int insert_room(roomList *list, Room room);

// Find room using room number
Node *find_room(roomList *list, int room_number);

// Delete a room
int delete_room(roomList *list, int room_number);

// Display all rooms
void display_rooms(const roomList *list);

// Count total rooms
int count_rooms(const roomList *list);

// Free all allocated memory
void free_room_list(roomList *list);

#endif
