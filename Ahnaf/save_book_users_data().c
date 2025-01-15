void save_book_users_data()
{
    FILE *file = fopen("Booked_users.txt", "a");
    if (file == NULL)
    {
        printf("Error: Could not open file for saving booked users.\n");
        return;
    }
    // do one then comment it
    // fprintf(file, "------------------------------------------------------------\n");
    // fprintf(file, "| Name              | Phone Number    | Email                | Address         | ID Type    | ID Number  | Room Number  | Check-in Date   | Check-out Date  |\n");

    // printf("------------------------------------------------------------\n");
    // printf("| Name              | Phone Number    | Email                | Address         | ID Type    | ID Number  | Room Number  | Check-in Date   | Check-out Date  |\n");

    if (userCount == 0)
    {
        printf("No users have booked rooms.\n");
        // fprintf(file, "No users have booked rooms.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < userCount; i++)
    {
        if (c[i].name == NULL || c[i].roomNumber <= 0)
        {
            printf("Error: Incomplete user data at index %d.\n", i);
            continue;
        }

        fprintf(file, "| %-17s | %-15s | %-26s | %-15s | %-10s | %-10s | %-12d | %-15s | %-15s |\n",
                c[i].name, c[i].phoneNumber, c[i].email,
                c[i].address, c[i].idType, c[i].idNumber,
                c[i].roomNumber, c[i].checkInDate, c[i].checkOutDate);

        // printf("| %-17s | %-15s | %-20s | %-15s | %-10s | %-10s | %-12d | %-15s | %-15s |\n",
        //        c[i].name, c[i].phoneNumber, c[i].email,
        //        c[i].address, c[i].idType, c[i].idNumber,
        //        c[i].roomNumber, c[i].checkInDate, c[i].checkOutDate);
    }

    fclose(file);
    printf("Booked Users saved and displayed successfully.\n");
}
