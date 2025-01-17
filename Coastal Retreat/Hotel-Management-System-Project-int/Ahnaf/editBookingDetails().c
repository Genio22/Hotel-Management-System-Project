void editBookingDetails()
{
    int roomNumber;
    printf("Enter the room number of the booking to edit: ");
    scanf("%d", &roomNumber);
    getchar(); 

    // Find the customer by room number
    int index = -1;
    for (int i = 0; i < max_user; i++)
    {
        if (c[i].roomNumber == roomNumber)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Customer with room number %d not found.\n", roomNumber);
        return;
    }

    // Customer *customer[i] = &customers[index];

    printf("Editing details for customer in room number %d:\n", c[index].roomNumber);

    printf("Enter new name (current: %s): ", c[index].name);
    scanf(" %[^\n]s", c[index].name);

    printf("Enter new phone number (current: %s): ", c[index].phoneNumber);
    scanf(" %[^\n]s", c[index].phoneNumber);

    printf("Enter new email (current: %s): ", c[index].email);
    scanf(" %[^\n]s", c[index].email);

    printf("Enter new address (current: %s): ", c[index].address);
    scanf(" %[^\n]s", c[index].address);

    printf("Enter new ID type (current: %s): ", c[index].idType);
    scanf(" %[^\n]s", c[index].idType);

    printf("Enter new ID number (current: %s): ", c[index].idNumber);
    scanf(" %[^\n]s", c[index].idNumber);

    printf("Enter new stay duration in days (current: %d): ", c[index].stayDuration);
    scanf("%d", &c[index].stayDuration);

    printf("Enter new check-in date (current: %s): ", c[index].checkInDate);
    scanf(" %[^\n]s", c[index].checkInDate);

    printf("Enter new check-out date (current: %s): ", c[index].checkOutDate);
    scanf(" %[^\n]s", c[index].checkOutDate);

    printf("\nCustomer booking details updated successfully!\n");
    // print_bill(index);
}