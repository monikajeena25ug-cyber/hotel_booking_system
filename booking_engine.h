#ifndef BOOKING_ENGINE_H
#define BOOKING_ENGINE_H

#include "room.h"

void checkIn(Node *room);
void checkOut(Node *room);
void changeRoomStatus(Node *room, RoomStatus new_status);

#endif
