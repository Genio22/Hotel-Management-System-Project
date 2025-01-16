void checkout()
{
    int roomNumber = 0;
    printf("Enter Room number: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < roomCount; i++)
    {
        if (roomNumber == hotelRooms[i].roomNumber)
        {
            if (hotelRooms[i].isOccupied)
            {
                hotelRooms[i].isOccupied = 0;
                printf("You have been succesfully checkout from Room %d!\n", hotelRooms[i].roomNumber);
            }
            else
            {
                printf("Room %d is already Unoccupied. So checkout is not possible.\n", hotelRooms[i].roomNumber);
            }
            break;
        }
    }
} // By sAhAf🙂
