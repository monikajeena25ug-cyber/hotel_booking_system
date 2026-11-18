#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

void initialize_list(RoomList *list)
{
    if (list == NULL) {
        return;
    }

    list->head = NULL;
    list->total_rooms = 0;
}

Node *create_node(Room room)
{
    Node *new_node = malloc(sizeof(Node));

    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    new_node->data = room;
    new_node->next = NULL;

    return new_node;
}

int add_room(RoomList *list, Room room)
{
    if (list == NULL) {
        return 0;
    }

    if (find_room(list, room.room_number) != NULL) {
        printf("Room number already exists.\n");
        return 0;
    }

    Node *new_node = create_node(room);

    if (new_node == NULL) {
        return 0;
    }

    new_node->next = list->head;
    list->head = new_node;
    list->total_rooms++;

    return 1;
}

Node *find_room(RoomList *list, int room_number)
{
    if (list == NULL) {
        return NULL;
    }

    Node *current = list->head;

    while (current != NULL) {
        if (current->data.room_number == room_number) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

int delete_room(RoomList *list, int room_number)
{
    if (list == NULL) {
        return 0;
    }

    Node *current = list->head;
    Node *previous = NULL;

    while (current != NULL) {
        if (current->data.room_number == room_number) {

            if (current->data.status == ROOM_OCCUPIED) {
                printf("Cannot delete an occupied room.\n");
                return 0;
            }

            if (previous == NULL) {
                list->head = current->next;
            } else {
                previous->next = current->next;
            }

            free(current);
            list->total_rooms;

            return 1;
        }

        previous = current;
        current = current->next;
    }

    return 0;
}

void display_rooms(const RoomList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("No rooms available.\n");
        return;
    }

    Node *current = list->head;

    while (current != NULL) {
        printf("\nRoom Number: %d\n",
               current->data.room_number);

        printf("Price per night: %.2f\n",
               current->data.price_per_night);

        printf("Nights booked: %d\n",
               current->data.nights_booked);

        printf("Guest: %s\n",
               current->data.guest_name);

        printf("Status: ");

        switch (current->data.status) {
            case ROOM_AVAILABLE:
                printf("Available\n");
                break;

            case ROOM_OCCUPIED:
                printf("Occupied\n");
                break;

            case ROOM_MAINTENANCE:
                printf("Maintenance\n");
                break;

            default:
                printf("Unknown\n");
        }

        current = current->next;
    }
}

int count_rooms(const RoomList *list)
{
    if (list == NULL) {
        return 0;
    }

    return list->total_rooms;
}

void free_room_list(RoomList *list)
{
    if (list == NULL) {
        return;
    }

    Node *current = list->head;

    while (current != NULL) {
        Node *temp = current;
        current = current->next;
        free(temp);
    }

    list->head = NULL;
    list->total_rooms = 0;
}
