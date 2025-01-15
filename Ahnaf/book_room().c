void book_room()
{
    int roomNumber = 0;
    char type[30], view[30], ac[30];
    int foundroom[MAX_ROOMS];
    int foundcount = 0;
    int room_found = 0, stayDuration, month;

    printf("Enter the room type (single/double): ");
    scanf("%[^\n]s", type);
    getchar();

    // Filter by type and store it in custom local array
    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].isOccupied == 0 && strcmp(hotelRooms[i].type, type) == 0)
        {
            foundroom[foundcount++] = i; // adding all required type to foundroom
        }
    }

    printf("Do you want ac or non ac room? -> ");
    scanf("%[^\n]s", ac);
    getchar();

    // Filter by ac
    for (int i = 0; i < foundcount;)
    {
        if (strcmp(hotelRooms[foundroom[i]].ac_type, ac) != 0)
        {
            for (int j = i; j < foundcount - 1; j++)
            {
                foundroom[j] = foundroom[j + 1]; // match shara gulo remove
            }
            foundcount--;
        }
        else
        {
            i++;
        }
    }

    printf("Do you prefer Sea View or City View? ");
    scanf("%[^\n]s", view);
    getchar();

    // Filter by view
    for (int i = 0; i < foundcount;)
    {
        if (strcmp(hotelRooms[foundroom[i]].view, view) != 0)
        {
            for (int j = i; j < foundcount - 1; j++)
            {
                foundroom[j] = foundroom[j + 1]; // removing the not match item
            }
            foundcount--;
        }
        else
        {
            i++;
        }
    }

    if (foundcount == 0)
    {
        printf("No available rooms match your criteria.\n");
    }
    else
    {
        printf("\nRoom Data:\n");
        printf("-----------------------------------------------------------------------------\n");
        printf("| Room No | Floor | Type     | View       | AC Type     | Occupied | Price  |\n");
        printf("-----------------------------------------------------------------------------\n");

        for (int i = 0; i < foundcount; i++)
        {
            printf("| %-7d | %-5d | %-8s | %-10s | %-11s | %-8s | %-6d |\n",
                   hotelRooms[foundroom[i]].roomNumber,
                   hotelRooms[foundroom[i]].floor,
                   hotelRooms[foundroom[i]].type,
                   hotelRooms[foundroom[i]].view,
                   hotelRooms[foundroom[i]].ac_type,
                   hotelRooms[foundroom[i]].isOccupied ? "Yes" : "No",
                   hotelRooms[foundroom[i]].basePrice);
        }

        printf("----------------------------------------------------------------------------------\n");
        printf("Enter the Room Number to book: ");
        scanf("%d", &roomNumber);
        getchar();
        // printf("%d\n", roomNumber);
    }

    for (int i = 0; i < max_user; i++)
    {
        c[i].roomNumber = 0;
    }

    for (int i = 0; i < foundcount; i++)
    {
        int idx = foundroom[i];
        if (hotelRooms[idx].roomNumber == roomNumber)
        {
            // printf("%d\n", hotelRooms[foundroom[i]].roomNumber);
            room_found = 1;
            for (int j = 0; j < max_user; j++)
            {
                if (c[j].roomNumber == 0)
                {
                    // printf("%d", j);
                    // By sAhAf🙂
                    printf("Name: ");
                    scanf("%[^\n]s", c[j].name);
                    getchar();
                    printf("Phone Number: ");
                    scanf("%[^\n]s", c[j].phoneNumber);
                    getchar();
                    printf("Email: ");
                    scanf("%[^\n]s", c[j].email);
                    getchar();
                    printf("Enter Address: ");
                    scanf("%[^\n]s", c[j].address);
                    getchar();
                    printf("Enter ID Type (e.g., Passport, Driver's License): ");
                    scanf("%[^\n]s", c[j].idType);
                    getchar();
                    printf("Enter ID Number: ");
                    scanf("%[^\n]s", c[j].idNumber);
                    getchar();
                    printf("Enter the duration of stay (in days): ");
                    scanf("%d", &stayDuration);
                    getchar();
                    printf("Enter the current month (1-12): ");
                    scanf("%d", &month);
                    getchar();
                    printf("Enter Check-in Date (dd/mm/yyyy): ");
                    scanf("%[^\n]s", c[j].checkInDate);
                    getchar();
                    printf("Enter Check-out Date (dd/mm/yyyy): ");
                    scanf("%[^\n]s", c[j].checkOutDate);
                    getchar();
                    c[j].roomNumber = roomNumber;
                    c[j].base_price = hotelRooms[idx].basePrice;
                    c[j].total_price = calculatePrice(&hotelRooms[foundroom[i]], stayDuration, month);
                    hotelRooms[foundroom[i]].isOccupied = 1;
                    // printf("Mr/Ms %s. You room %d have successfully been booked! \nTotal price for %d days is: %d\n",
                    //        c[j].name, roomNumber, stayDuration, totalPrice);
                    printf("\n\n\n");
                    printf("************************************************************************\n");
                    printf("         Dear %s, \n", c[j].name);
                    printf("         Your booking for room number %d \n", roomNumber);
                    printf("         The total price for your stay of %d days is: %d \n", stayDuration, c[j].total_price);
                    printf("         Thank you for choosing our hotel. We look forward to your stay.\n");
                    printf("************************************************************************\n");
                    printf("\n");
                    printf("\t\t\tYour bill have been printed\n\n\n");
                    print_bill(j);
                    userCount++;
                    break;
                }
            }
            break;
        }
    }
    if (room_found == 0 && foundcount != 0)
    {
        printf("The given room doesn't meet your requirement.\n");
    }
}
