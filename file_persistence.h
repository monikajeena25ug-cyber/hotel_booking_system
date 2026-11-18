#ifndef FILE_PERSISTENCE_H
#define FILE_PERSISTENCE_H

#include "room.h"

void load_rooms_from_file(RoomList *list);
void save_rooms_to_file(RoomList *list);
int add_room(RoomList *list, Room room);
#endif
