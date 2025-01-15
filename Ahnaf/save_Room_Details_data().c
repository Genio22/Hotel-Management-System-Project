void save_Room_Details_data()
{
    FILE *file = fopen("Room_details.txt", "w");
    if (file == NULL)
    {
        printf("Error: Could not open file for saving room details.\n");
        return;
    }

    if (roomCount == 0)
    { // Check if no rooms are available
        printf("No rooms are available.\n");
        fprintf(file, "No rooms are available.\n");
        fclose(file);
        return;
    }

    // Print room data for console debuger jono
    // printf("----------------------------------------------------------------------------------------\n");
    // printf("| Room Number  | Floor | Type      | View      | AC Type      | Base Price | Occupied |\n");
    // printf("----------------------------------------------------------------------------------------\n");

    // Print headers in file akbar printf kora lagbe
    fprintf(file, "\n\n\n------------------------------------------------------------------------------------------\n");
    fprintf(file, "| Room Number  | Floor | Type      | View         | AC Type      | Base Price | Occupied |\n");
    fprintf(file, "------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].roomNumber <= 0)
        {
            printf("Error: Incomplete room data at index %d.\n", i);
            continue;
        }

        // Print room data for console debuger jono
        // printf("| %-12d | %-5d | %-9s | %-9s | %-12s | %-10d | %-8s |\n",
        //        hotelRooms[i].roomNumber, hotelRooms[i].floor, hotelRooms[i].type,
        //        hotelRooms[i].view, hotelRooms[i].ac_type,
        //        hotelRooms[i].basePrice, hotelRooms[i].isOccupied ? "Yes" : "No");

        // Print room data to file in human er jono
        fprintf(file, "| %-12d | %-5d | %-9s | %-12s | %-12s | %-10d | %-8s |\n",
                hotelRooms[i].roomNumber, hotelRooms[i].floor, hotelRooms[i].type,
                hotelRooms[i].view, hotelRooms[i].ac_type,
                hotelRooms[i].basePrice, hotelRooms[i].isOccupied ? "Yes" : "No");
    }

    fclose(file);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Room details saved and displayed successfully.\n");
}void save_Room_Details_data()
{
    FILE *file = fopen("Room_details.txt", "w");
    if (file == NULL)
    {
        printf("Error: Could not open file for saving room details.\n");
        return;
    }

    if (roomCount == 0)
    { // Check if no rooms are available
        printf("No rooms are available.\n");
        fprintf(file, "No rooms are available.\n");
        fclose(file);
        return;
    }

    // Print room data for console debuger jono
    // printf("----------------------------------------------------------------------------------------\n");
    // printf("| Room Number  | Floor | Type      | View      | AC Type      | Base Price | Occupied |\n");
    // printf("----------------------------------------------------------------------------------------\n");

    // Print headers in file akbar printf kora lagbe
    fprintf(file, "\n\n\n------------------------------------------------------------------------------------------\n");
    fprintf(file, "| Room Number  | Floor | Type      | View         | AC Type      | Base Price | Occupied |\n");
    fprintf(file, "------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].roomNumber <= 0)
        {
            printf("Error: Incomplete room data at index %d.\n", i);
            continue;
        }

        // Print room data for console debuger jono
        // printf("| %-12d | %-5d | %-9s | %-9s | %-12s | %-10d | %-8s |\n",
        //        hotelRooms[i].roomNumber, hotelRooms[i].floor, hotelRooms[i].type,
        //        hotelRooms[i].view, hotelRooms[i].ac_type,
        //        hotelRooms[i].basePrice, hotelRooms[i].isOccupied ? "Yes" : "No");

        // Print room data to file in human er jono
        fprintf(file, "| %-12d | %-5d | %-9s | %-12s | %-12s | %-10d | %-8s |\n",
                hotelRooms[i].roomNumber, hotelRooms[i].floor, hotelRooms[i].type,
                hotelRooms[i].view, hotelRooms[i].ac_type,
                hotelRooms[i].basePrice, hotelRooms[i].isOccupied ? "Yes" : "No");
    }

    fclose(file);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Room details saved and displayed successfully.\n");
}
