/* comment */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
#define MAX_FLOORS 10

// Room structure
typedef struct
{
    int roomNumber;
    int floor;
    char type[20];
    char view[20];
    int basePrice;
    int isOccupied;
} Room;

// Global variables
Room hotelRooms[MAX_ROOMS];
int roomCount = 0;


// Function prototypes
void showMenu();
void initializeRooms();
void displayRooms();
void AddRoom();
// void roombook();

int main()
{
    int choice = 0;
    initializeRooms();
    
    while (choice != 3)
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

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
void showMenu() {
    printf("\n--- Hotel Management System ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Add a Room\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}

void initializeRooms()
{
    int roomNumber = 100;
    for (int floor = 1; floor <= MAX_FLOORS; floor++) // total floor in building
    {
        for (int i = 0; i < 4; i++) // akta floor e 4 ta room
        {
            hotelRooms[roomCount].roomNumber = roomNumber++; // one kore room number bariteche

            hotelRooms[roomCount].floor = floor; // for each iteration floor remain same
            if (i % 2 == 0)                      // amni akt logic to get value for other parameter
            {
                strcpy(hotelRooms[roomCount].type, "Single");
                strcpy(hotelRooms[roomCount].view, "Sea View");
                hotelRooms[roomCount].basePrice = 1350;
            }
            else
            {
                strcpy(hotelRooms[roomCount].type, "Double");
                strcpy(hotelRooms[roomCount].view, "City View");
                hotelRooms[roomCount].basePrice = 2000;
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
        printf("Enter Room Type (e.g., Single, Double): ");
        scanf("%s", type);
        printf("Enter View (e.g., Sea, City): ");
        scanf("%s", view);
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
        printf("\n\n  ---- Room added successfully.------\n");
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
            printf("Room Number: %d, Floor: %d, Type: %s, View: %s, Base Price: %dtake\n",
                   hotelRooms[i].roomNumber, hotelRooms[i].floor,
                   hotelRooms[i].type, hotelRooms[i].view,
                   hotelRooms[i].basePrice);
        }
    }
}

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
