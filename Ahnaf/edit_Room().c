
// code by Tahsin
void edit_Room()
{
    int roomNumber, floor, basePrice, isOccupied, edit = 0;
    char type[20], view[20], ac_type[30];
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].roomNumber == roomNumber && hotelRooms[i].isOccupied == 0) // Ensure roomCount is less than MAX_ROOMS
        {
            printf("Enter Floor: ");
            scanf("%d", &floor);
            getchar();
            printf("Enter Room Type (e.g., Single, Double,): ");
            scanf("%[^\n]s", type);
            getchar();
            printf("Enter View (e.g., Sea, City): ");
            scanf("%[^\n]s", view);
            getchar();
            printf("Enter AC type (AC, Non AC): ");
            scanf("%[^\n]s", ac_type);
            getchar();
            printf("Enter Base Price: ");
            scanf("%d", &basePrice);
            printf("Is the room occupied? (1 for Yes, 0 for No): ");
            scanf("%d", &isOccupied);

            hotelRooms[i].floor = floor;
            hotelRooms[i].basePrice = basePrice;
            hotelRooms[i].isOccupied = isOccupied;
            strcpy(hotelRooms[i].type, type);
            strcpy(hotelRooms[i].view, view);

            printf("\n\n  ------ Room edited successfully.------  \n");
            printf("Room Number: %d\nFloor: %d\nRoom Type: %s\nView: %s\nBase Price: %d\nOccupied: %d\n",
                   roomNumber, floor, type, view, basePrice, isOccupied);
            edit = 1;
        }
    }
    if (!edit)
    {
        printf("Cannot add more rooms. Maximum capacity reached.\n");
    }
}
