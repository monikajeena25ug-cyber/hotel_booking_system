#include <stdio.h>

#include "room.h"
#include "UI.h"
#include "linked_list.h"
#include "file_persistence.h"

int main(void)
{
    RoomList list;

    initialize_list(&list);

    load_rooms_from_file(&list);

    main_menu(&list);

    save_rooms_to_file(&list);

    free_room_list(&list);

    printf("\nHotel Booking System closed.\n");

    return 0;
}
