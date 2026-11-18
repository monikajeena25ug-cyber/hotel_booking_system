#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "room.h"
#include "UI.h"
#include "booking_engine.h"
#include "linked_list.h"
#include "file_persistence.h"

// Get integer input
int get_choice(const char *message)
{
    char input[100];
    int choice;
    char extra;

    printf("%s", message);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return -1;
    }

    if (sscanf(input, "%d %c", &choice, &extra) != 1) {
        printf("Invalid input.\n");
        return -1;
    }

    return choice;
}

// Get string input
void get_string(char *text, int size)
{
    if (fgets(text, size, stdin) != NULL) {
        text[strcspn(text, "\n")] = '\0';
    }
}

// Display room information
void display_room(Room *room)
{
    if (room == NULL) {
        printf("Room not found.\n");
        return;
    }

    printf("\n----- ROOM DETAILS -----\n");
    printf("Room Number: %d\n", room->room_number);
    printf("Guest Name: %s\n", room->guest_name);
    printf("Price per Night: %.2f\n", room->price_per_night);

    printf("Room Type: ");

    switch (room->type) {
        case ROOM_SINGLE:
            printf("Single\n");
            break;

        case ROOM_DOUBLE:
            printf("Double\n");
            break;

        case ROOM_SUITE:
            printf("Suite\n");
            break;

        default:
            printf("Unknown\n");
    }

    printf("Room Status: ");

    switch (room->status) {
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

    printf("------------------------\n");
}

// Display all rooms
void list_rooms(RoomList *list)
{
    if (list == NULL || list->head == NULL) {
        printf("No rooms available.\n");
        return;
    }

    display_rooms(list);
}

// Select a room
Node *select_room(RoomList *list)
{
    int room_number = get_choice("Enter room number: ");

    if (room_number <= 0) {
        printf("Invalid room number.\n");
        return NULL;
    }

    Node *room = find_room(list, room_number);

    if (room == NULL) {
        printf("Room not found.\n");
    }

    return room;
}

// Add room through UI
void add_room_menu(RoomList *list)
{
    Room room;

    room.room_number = get_choice("Enter room number: ");

    if (room.room_number <= 0) {
        printf("Invalid room number.\n");
        return;
    }

    printf("\nSelect Room Type:\n");
    printf("1. Single\n");
    printf("2. Double\n");
    printf("3. Suite\n");

    int type = get_choice("Enter choice: ");

    if (type < 1 || type > 3) {
        printf("Invalid room type.\n");
        return;
    }

    room.type = (RoomType)(type - 1);

    printf("Enter price per night: ");

    char price_input[100];
    char extra;
    if (fgets(price_input, sizeof(price_input), stdin) == NULL ||
        sscanf(price_input, "%lf %c",
               &room.price_per_night, &extra) != 1 ||
        room.price_per_night < 0) {
        printf("Invalid price.\n");
        return;
    }

    strcpy(room.guest_name, "N/A");
    room.nights_booked = 0;
    room.status = ROOM_AVAILABLE;

    if (add_room(list, room)) {
        printf("Room added successfully.\n");
    } else {
        printf("Room could not be added. Check for duplicate room number.\n");
    }
}

// Room operations menu
void room_operations_menu(Node *room)
{
    if (room == NULL) {
        return;
    }

    int choice;

    do {
        printf("\n----- ROOM OPERATIONS -----\n");
        printf("1. View Room Details\n");
        printf("2. Check In\n");
        printf("3. Check Out\n");
        printf("4. Change Room Status\n");
        printf("0. Back\n");

        choice = get_choice("Enter your choice: ");

        switch (choice) {
            case 1:
                display_room(&room->data);
                break;

            case 2:
                checkIn(room);
                break;

            case 3:
                checkOut(room);
                break;

            case 4: {
                printf("\n1. Available\n");
                printf("2. Maintenance\n");

                int status = get_choice("Choose new status: ");

                if (status == 1) {
                    changeRoomStatus(room, ROOM_AVAILABLE);
                } else if (status == 2) {
                    changeRoomStatus(room, ROOM_MAINTENANCE);
                } else {
                    printf("Invalid status.\n");
                }

                break;
            }

            case 0:
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}

// Main menu
void main_menu(RoomList *list)
{
    int choice;

    do {
        printf("\n===== HOTEL BOOKING SYSTEM =====\n");
        printf("1. Add Room\n");
        printf("2. List Rooms\n");
        printf("3. Select Room\n");
        printf("0. Save and Exit\n");

        choice = get_choice("Enter your choice: ");

        switch (choice) {
            case 1:
                add_room_menu(list);
                break;

            case 2:
                list_rooms(list);
                break;

            case 3: {
                Node *room = select_room(list);

                if (room != NULL) {
                    room_operations_menu(room);
                }

                break;
            }

            case 0:
                save_rooms_to_file(list);
                printf("Exiting Hotel Booking System.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 0);
}
