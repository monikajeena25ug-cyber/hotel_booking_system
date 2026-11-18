#include <stdio.h>
#include <stdlib.h>
#include "file_persistence.h"
#include "linked_list.h"

#define FILE_NAME "rooms.txt"

void load_rooms_from_file(RoomList *list)
{
    FILE *file = fopen(FILE_NAME, "r");

    if (file == NULL) {
        printf("No existing room file found. Starting fresh.\n");
        return;
    }

    char line[256];
    Room room;

    while (fgets(line, sizeof(line), file) != NULL) {

        int result = sscanf(
            line,
            "%d|%49[^|]|%d|%lf|%d|%d",
            &room.room_number,
            room.guest_name,
            (int *)&room.type,
            &room.price_per_night,
            &room.nights_booked,
            (int *)&room.status
        );

        if (result != 6) {
            continue;
        }

        if (room.type < ROOM_SINGLE ||
            room.type > ROOM_SUITE ||
            room.status < ROOM_AVAILABLE ||
            room.status > ROOM_MAINTENANCE ||
            room.price_per_night < 0 ||
            room.nights_booked < 0) {
            continue;
        }

        if (!add_room(list, room)) {
            printf("Could not load room %d.\n", room.room_number);
        }
    }

    fclose(file);

    printf("Room data loaded successfully.\n");
}

void save_rooms_to_file(RoomList *list)
{
    if (list == NULL) {
        return;
    }

    FILE *file = fopen(FILE_NAME, "w");

    if (file == NULL) {
        printf("Error opening file for saving.\n");
        return;
    }

    Node *current = list->head;

    while (current != NULL) {

        fprintf(
            file,
            "%d|%s|%d|%.2f|%d|%d\n",
            current->data.room_number,
            current->data.guest_name,
            current->data.type,
            current->data.price_per_night,
            current->data.nights_booked,
            current->data.status
        );

        current = current->next;
    }

    fclose(file);

    printf("Room data saved successfully.\n");
}
