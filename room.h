#ifndef ROOM_H
#define ROOM_H

typedef enum {
    ROOM_AVAILABLE,
    ROOM_OCCUPIED,
    ROOM_MAINTENANCE
} RoomStatus;

typedef enum {
    ROOM_SINGLE,
    ROOM_DOUBLE,
    ROOM_SUITE
} RoomType;

typedef struct Room {
    int room_number;
    char guest_name[50];
    RoomType type;
    double price_per_night;
    int nights_booked;
    RoomStatus status;
} Room;

typedef struct Node {
    Room data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int total_rooms;
} RoomList;

#endif
