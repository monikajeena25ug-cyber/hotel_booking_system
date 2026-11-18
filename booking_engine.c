# include <stdio.h>
# include <string.h>
# include "room.h"

// CheckIn function to check in a guest to a room
void checkIn(Node *room)
{
    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }
    if (room -> data.status != ROOM_AVAILABLE) {
        printf("Room is not available for check-in.\n");
        return;
    }
    if (room -> data.status == ROOM_AVAILABLE) {
        printf("Room %d is available.\n", room -> data.room_number);
    }

printf ("Enter guest name: ");
    scanf("%s", room -> data.guest_name);
    printf("Guest %s checked in to room %d.\n", room -> data.guest_name, room -> data.room_number);

printf("Enter number of nights: ");
   scanf("%d", &room->data.nights_booked);
while (getchar() != '\n' && !feof(stdin)){
}
printf("Guest %s will stay for %d nights.\n", 
        room -> data.guest_name, room -> data.nights_booked);

  room -> data.status = ROOM_OCCUPIED;
printf("Room %d status updated to occupied.\n", room -> data.room_number);
}

// CheckOut function to check out a guest from a room and bill them for their stay

void checkOut(Node *room)
{
    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }
    if (room -> data.status != ROOM_OCCUPIED) {
        printf("Room is not occupied.\n");
        return;
    }
     double total_cost = room -> data.price_per_night * room -> data.nights_booked;
    printf("Total cost for room %d: $%.2f\n",
       room->data.room_number, total_cost);
    printf("Guest %s checked out from room %d.\n", room -> data.guest_name, room -> data.room_number);
    

    room -> data.status = ROOM_AVAILABLE;
    strcpy(room->data.guest_name, "N/A");
    room->data.nights_booked = 0;
    printf("Room %d status updated to available.\n", room -> data.room_number);

}

// ChangeRoomStatus function to change the status of a room
void changeRoomStatus(Node *room, RoomStatus new_status)
{
    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }

    if (new_status != ROOM_AVAILABLE &&
        new_status != ROOM_MAINTENANCE) {
        printf("Invalid room status.\n");
        return;
    }
    
    if (room -> data.status == ROOM_OCCUPIED && new_status == ROOM_OCCUPIED) {
        printf("Cannot change status. Room is currently occupied.\n");
        return;
    }
    room -> data.status = new_status;
    printf("Room %d status updated to %s.\n", room -> data.room_number,
           new_status == ROOM_AVAILABLE ? "available" : "maintenance");
}
