#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "room.h"

void initialize_list(RoomList *list);
Node *create_node(Room room);
int add_room(RoomList *list, Room room);
Node *find_room(RoomList *list, int room_number);
int delete_room(RoomList *list, int room_number);
void display_rooms(const RoomList *list);
int count_rooms(const RoomList *list);
void free_room_list(RoomList *list);

#endif
