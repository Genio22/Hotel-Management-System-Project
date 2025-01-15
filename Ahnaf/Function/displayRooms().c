void displayRooms()
{
    printf("\nRoom Data:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| Room No | Floor | Type     | View       | AC Type     | Occupied | Price  |\n");
    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < roomCount; i++)
    {
        printf("| %-7d | %-5d | %-8s | %-10s | %-11s | %-8s | %-6d |\n",
               hotelRooms[i].roomNumber,
               hotelRooms[i].floor,
               hotelRooms[i].type,
               hotelRooms[i].view,
               hotelRooms[i].ac_type,
               hotelRooms[i].isOccupied ? "Yes" : "No",
               hotelRooms[i].basePrice);
    } // By Al Amin🙂

    printf("----------------------------------------------------------------------------------\n");
}