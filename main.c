#include <stdio.h>
#include "room.h"
#include "linkedlist.h"
#include "ui.h"
#include "booking.h"
#include "file.h"

int main()
{
    RoomList list;

    initialize_list(&list);

    load_rooms_from_file(&list);

    main_menu(&list);

    return 0;
}
