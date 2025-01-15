// code by Riad Mahmud
void initializeRooms()
{
    int roomNumber = 1;
    char *type[] = {"single", "double", "deluxe"};
    char *view[] = {"sea view", "city view"};
    char *ac_type[] = {"ac", "non ac"};
    int basePrice[] = {1350, 1200, 1000, 1500};
    int basePrice1[] = {3000, 5000};
    for (int floor = 1; floor <= MAX_FLOORS; floor++) // total floor in building
    {
        for (int i = 1; i < 5; i++) // akta floor e 4 ta room
        {
            hotelRooms[roomCount].roomNumber = (floor * 100) + i; // one kore room number bariteche // new fix room number by floor

            hotelRooms[roomCount].floor = floor; // for each iteration floor remain same
            // (rand() % 2 == 0)                      // amni akt logic to get value for other parameter // By sAhAf🙂
            strcpy(hotelRooms[roomCount].type, type[rand() % 3]);
            strcpy(hotelRooms[roomCount].view, view[rand() % 2]);
            strcpy(hotelRooms[roomCount].ac_type, ac_type[rand() % 2]);
            if ((!strcmp(hotelRooms[roomCount].view, "Sea View") && !strcmp(hotelRooms[roomCount].ac_type, "AC Room")) || !strcmp(hotelRooms[roomCount].type, "deluxe"))
            {

                hotelRooms[roomCount].basePrice = basePrice1[rand() % 2];
            }
            else
            {
                hotelRooms[roomCount].basePrice = basePrice[rand() % 4];
            }
            hotelRooms[roomCount].isOccupied = 0;
            roomCount++;
        }
    }
    // printf("Default rooms initialized!\n");
}
