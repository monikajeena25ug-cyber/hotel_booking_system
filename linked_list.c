#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
// Initialize an empty linked list
void initialize_list(roomList *list)
{
    list->head = NULL;
    list->total_rooms = 0;
}
// Create a new node dynamically
Node *create_node(Room room)
{
    Node *new_node = malloc(sizeof(Node));
    if (new_node == NULL)
    {
        printf("memory allocation failed!\n");
        return NULL;
    }
    new_node->data = room;
    new_node->next = NULL;
    return new_node;
}
// Insert a new room into the linked list
int insert_room(roomList *list, room room)
{
    // Checking duplicate room number
    if (find_room(list, room.room_number) != NULL)
    {
        printf("room number already exists!\n");
        return 0;
    }
    // creating new node
    Node *new_node = create_node(room);
    if (new_node == NULL)
    {
        return 0;
    }
    // If list is empty
    if (list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        // traverse to the last node
        Node *temp = list->head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        // Insert at the end
        temp->next = new_node;
    }
    list->total_rooms++;
    printf("room %d added successfully!\n", room.room_number);
    return 1;
}
// find a room using room number
Node *find_room(roomList *list, int room_number)
{
    Node *temp = list->head;
    while (temp != NULL)
    {
        if (temp->data.room_number == room_number)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}
// Delete a room from the linked list
int delete_room(roomList *list, int room_number)
{
    Node *temp = list->head;
    Node *previous = NULL;
    // Check empty list
    if (temp == NULL)
    {
        printf("the room list is empty!\n");
        return 0;
    }
    // Search for room
    while (temp != NULL &&
           temp->data.room_number != room_number)
    {
        previous = temp;
        temp = temp->next;
    }
    // Room not found
    if (temp == NULL)
    {
        printf("Room not found!\n");
        return 0;
    }
     // Deleting first node
    if (previous == NULL)
    {
        list->head = temp->next;
    }
    else
    {
        previous->next = temp->next;
    }
    free(temp);
    list->total_rooms;
    printf("room %d deleted successfully!\n", room_number);
    return 1;
}
// Display all rooms
void display_rooms(const roomList *list)
{
    Node *temp = list->head;
    if (temp == NULL)
    {
        printf("\n No rooms available in the list.\n");
        return;
    }
    printf("\n");
    printf("\n");
    printf("%-10s %-15s %-12s %-12s %-12s\n",
           "Room No.",
           "Guest",
           "Type",
           "Price",
           "Status");
    printf("\n");
    while (temp != NULL)
    {
        char *type;
        char *status;
        switch (temp->data.type)
        {
            case room_single:
                type = "single";
                break;
            case room_double:
                type = "double";
                break;
            case room_suite:
                type = "suite";
                break;
            default:
                type = "unknown";
        }
        switch (temp->data.status)
        {
            case room_available:
                status = "available";
                break;
            case room_occupied:
                status = "occupied";
                break;
            case room_maintenance:
                status = "maintenance";
                break;
            default:
                status = "unknown";
        }
        printf("%-10d %-15s %-12s %-12.2f %-12s\n",
               temp->data.room_number,
               temp->data.guest_name,
               type,
               temp->data.price_per_night,
               status);
        temp = temp->next;
    }
    printf("\n");
    printf("total rooms: %d\n", list->total_rooms);
}
// Count total rooms
int count_rooms(const roomList *list)
{
    int count = 0;
    Node *temp = list->head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    } return count;
}
// Free all dynamically allocated nodes
void free_room_list(roomList *list)
{
       Node *temp = list->head;
    while (temp != NULL)
    {
        Node *next_node = temp->next;
        free(temp);
           temp = next_node;
    }
    list->head = NULL;
    list->total_rooms = 0;
    printf("all linked list memory released successfully.\n");
}
