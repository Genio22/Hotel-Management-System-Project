void display_book_users_data()
{
    FILE *file = fopen("Booked_users.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    char line[256];
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| Name              | Phone Number   | Email                     | Address                    | ID Type    | ID Number     | Room Number   | Check-in Date   | Check-out Date  |\n");
    // printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // line diya full 1 block array access
    fgets(line, sizeof(line), file);

    // Read and print the rest of the lines
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line); // Print the line as is
    }

    fclose(file);
}
