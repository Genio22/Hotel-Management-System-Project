// done by tahsin
void AddRoom()
{
    int roomNumber, floor, basePrice, isOccupied;
    char type[20], view[20], ac_type[20];

    if (roomCount < MAX_ROOMS) // Ensure roomCount is less than MAX_ROOMS
    {
        // Prompt user for room details
        printf("Enter Room Number: ");
        scanf("%d", &roomNumber);
        printf("Enter Floor: ");
        scanf("%d", &floor);
        getchar();
        printf("Enter Room Type (e.g., Single, Double): ");
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

        // Populate hotelRooms array
        hotelRooms[roomCount].roomNumber = roomNumber;
        hotelRooms[roomCount].floor = floor;
        hotelRooms[roomCount].basePrice = basePrice;
        hotelRooms[roomCount].isOccupied = isOccupied;
        strcpy(hotelRooms[roomCount].type, type);
        strcpy(hotelRooms[roomCount].view, view);
        strcpy(hotelRooms[roomCount].ac_type, ac_type);

        roomCount++;
        printf("\n\n  ------ Room added successfully.------  \n");
        printf("Room Number: %d\nFloor: %d\nRoom Type: %s\nView: %s\nAC Type: %s\nBase Price: %d\nOccupied: %d\n",
               roomNumber, floor, type, view, ac_type, basePrice, isOccupied);
    }
    else
    {
        printf("Sorry, Can not add more room ! Please try later.\n");
    }
}
