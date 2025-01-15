void display_Room_Details_data()
{
    FILE *file = fopen("Room_details.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    char line[256];
    // printf("----------------------------------------------------------------------------------------\n");
    // printf("| Room Number  | Floor | Type      | View      | AC Type      | Base Price | Occupied |\n");// By sAhAf🙂
    // printf("----------------------------------------------------------------------------------------\n");

    // line diya full 1 block array access
    fgets(line, sizeof(line), file);

    // Read and print the rest of the lines
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line); // Print the line as is
    }

    fclose(file);
}
