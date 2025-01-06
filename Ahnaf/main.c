
/* Hotel-Management-System-Project */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
// #define MAX_FLOORS 10

// Room structure
typedef struct
{
    int roomNumber;
    int floor;
    char type[20];
    char view[20];
    char ac_type[20];
    int basePrice;
    int isOccupied;
} Room;

// Global variables
Room hotelRooms[MAX_ROOMS];
int roomCount = 0, MAX_FLOORS = 0;

// Function prototypes
void showMenu();
void initializeRooms();
void displayRooms();
void AddRoom();
void book_room();
void checkout();

int main()
{
    int choice = 0;
    printf("Enter the floor: ");

    scanf("%d", &MAX_FLOORS);
    initializeRooms(MAX_FLOORS);

    while (choice != 5)
    {
        showMenu();
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            displayRooms();
            break;
        case 2:
            AddRoom();
            break;
        case 3:
            book_room();
            break;
        case 4:
            checkout();
            break;
        case 5:
            printf("See you. Bye:)");
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void showMenu()
{
    printf("\n--- Hotel Management System ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Add a Room\n");
    printf("3. Room Booking\n");
    printf("4. Checkout\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

// rand();

void initializeRooms(int MAX_FLOORS)
{
    int roomNumber = 1;
    char *type[] = {"single", "double"};
    char *view[] = {"Sea View", "City View"};
    char *ac_type[] = {"AC Room", "Non AC Room"};
    int basePrice[] = {1350, 2000, 1200};
    int basePrice1[] = {3000, 5000};
    for (int floor = 1; floor <= MAX_FLOORS; floor++) // total floor in building
    {
        for (int i = 0; i < 4; i++) // akta floor e 4 ta room
        {
            hotelRooms[roomCount].roomNumber = (floor * 100) + (i + 1); // one kore room number bariteche // new fix room number by floor

            hotelRooms[roomCount].floor = floor; // for each iteration floor remain same
            // (rand() % 2 == 0)                      // amni akt logic to get value for other parameter
            strcpy(hotelRooms[roomCount].type, type[rand() % 2]);
            strcpy(hotelRooms[roomCount].view, view[rand() % 2]);
            strcpy(hotelRooms[roomCount].ac_type, ac_type[rand() % 2]);
            if (!strcmp(hotelRooms[roomCount].view, "Sea View") && !strcmp(hotelRooms[roomCount].ac_type, "AC Room"))
            {

                hotelRooms[roomCount].basePrice = basePrice1[rand() % 2];
            }
            else
            {
                hotelRooms[roomCount].basePrice = basePrice[rand() % 3];
            }
            hotelRooms[roomCount].isOccupied = 0;
            roomCount++;
        }
    }
    printf("Default rooms initialized!\n");
}
// done by tahsin
void AddRoom()
{
    int roomNumber, floor, basePrice, isOccupied;
    char type[20], view[20];

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

        roomCount++;
        printf("\n\n  ------ Room added successfully.------  \n");
        printf("Room Number: %d\nFloor: %d\nRoom Type: %s\nView: %s\nBase Price: %d\nOccupied: %d\n",
               roomNumber, floor, type, view, basePrice, isOccupied);
    }
    else
    {
        printf("Cannot add more rooms. Maximum capacity reached.\n");
    }
}

void displayRooms()
{
    printf("\n--- Available Rooms ---\n");
    for (int i = 0; i < roomCount; i++)
    {
        if (!hotelRooms[i].isOccupied)
        {
            printf("Room Number: %d, Floor: %d, Type: %s, View: %s, AC type: %s, Base Price: %dtake\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].floor,
                   hotelRooms[i].type, hotelRooms[i].view, hotelRooms[i].ac_type,
                   hotelRooms[i].basePrice);
        }
    }
    printf("\n--- Occupied Rooms ---\n");
    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].isOccupied)
        {
            printf("Room Number: %d, Floor: %d, Type: %s, View: %s, AC type: %s, Base Price: %dtake\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].floor,
                   hotelRooms[i].type, hotelRooms[i].view, hotelRooms[i].ac_type,
                   hotelRooms[i].basePrice);
        }
    }
}

void book_room()
{
    int roomNumber = 0;
    printf("Enter Room number: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < roomCount; i++)
    {
        if (roomNumber == hotelRooms[i].roomNumber)
        {
            if (!hotelRooms[i].isOccupied)
            {
                hotelRooms[i].isOccupied = 1;
                printf("Room %d has been booked successfully!\n", hotelRooms[i].roomNumber);
            }
            else
            {
                printf("Room %d is already booked.\n", hotelRooms[i].roomNumber);
            }
            break;
        }
    }
}

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
    // done by sa
}

// void book_room(char hotel[ROOMS][20], int room) {
//     if (strcmp(hotel[room], "Available") == 0) {
//         strcpy(hotel[room], "Booked");
//         printf("Room %d has been booked successfully!\n", room + 1);
//     } else {
//         printf("Room %d is already booked.\n", room + 1);
//     }
// }

// int calculatePrice(Room *room, int stayDuration, int month) {
//     int price = room->basePrice;

//     if (isPeakSeason(month)) {
//         price *= 1.2;
//     }

//     if (stayDuration > 7) {
//         price *= 0.85;
//     } else if (stayDuration < 3) {
//         price *= 1.15;
//     }

//     if (strcmp(room->view, "Sea View") == 0) {
//         price *= 1.2;
//     }

//     return price * stayDuration;
// }

// By sAhAf🙂

// By TeaM ScorPIoN🙂
