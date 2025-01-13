

/* Hotel-Management-System-Project */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 100
// #define MAX_FLOORS 10
#define max_user 100
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin123"
#define USER_USERNAME "user"
#define USER_PASSWORD "user123"

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

typedef struct
{
    char name[50];
    // char lastName[50];
    char phoneNumber[15];
    char email[50];
    char address[100];
    char idType[30]; // e.g., Passport, Driver's License
    char idNumber[30];
    int roomNumber;
    int stayDuration;
    char checkInDate[15];
    char checkOutDate[15];
} customer;

// Global variables
Room hotelRooms[MAX_ROOMS];
customer c[max_user];
int roomCount = 0, MAX_FLOORS = 0, userCount = 0;

// Function prototypes
void showMenu();
void initializeRooms();
void displayRooms();
void AddRoom();
void book_room();
int calculatePrice(Room *room, int stayDuration, int month);
int isPeakSeason();
void checkout();
void savefile();
void saveAndDisplayBookedUsers();
void displaySavedUsers();
// void savefile_user();

// void printUserData() {
//     FILE *f2;
//     f2 = fopen("User.txt", "r");

//     if (f2 == NULL) {
//         printf("Error opening file!\n");
//         return;
//     }

//     int userCount;
//     fread(&userCount, sizeof(int), 1, f2);

//     if (userCount == 0) {
//         printf("No users found in the file.\n");
//     } else {
//         printf("\n--- Customer Booking Data ---\n");
//         printf("-------------------------------------------------------------\n");
//         printf("| Name             | Phone Number   | Room Number | Check-in Date  |\n");
//         printf("-------------------------------------------------------------\n");

//         customer temp;
//         for (int i = 0; i < userCount; i++) {
//             fread(&temp, sizeof(customer), 1, f2);

//             printf("| %-17s | %-15s | %-11d | %-15s |\n",
//                    temp.name, temp.phoneNumber, temp.roomNumber, temp.checkInDate);
//         }

//         printf("-------------------------------------------------------------\n");
//     }

//     fclose(f2);
// }

void printCustomerDetails(int i)
{
    printf("\nCustomer Booking Details:\n");
    printf("-------------------------------\n");
    printf("Name: %s\n", c[i].name);
    printf("Phone Number: %s\n", c[i].phoneNumber);
    printf("Email: %s\n", c[i].email);
    printf("Address: %s\n", c[i].address);
    printf("ID Type: %s\n", c[i].idType);
    printf("ID Number: %s\n", c[i].idNumber);
    // printf("Duration of Stay (in days): %d\n", stayDuration);
    // printf("Month: %d\n", month);
    printf("Check-in Date: %s\n", c[i].checkInDate);
    printf("Check-out Date: %s\n", c[i].checkOutDate);
    printf("-------------------------------\n");
}

int main()
{
    int choice = 0;

    printf("Welcome to the Hotel Management System\n");
    printf("Enter the total number of floors in the hotel: ");
    scanf("%d", &MAX_FLOORS);
    getchar(); // Clear the newline character from the input buffer.

    // Initialize rooms based on the total number of floors.
    initializeRooms(MAX_FLOORS);

    printf("\nPlease login to access the system:\n");
    int loginType = 0;

    // Prompt for login type: Admin or User
    printf("1. Admin Login\n");
    printf("2. User Login\n");
    printf("Enter your choice (1 for Admin, 2 for User): ");
    scanf("%d", &loginType);
    getchar(); // Clear the newline character from the input buffer.

    int isLoggedIn = 0;

    // Login validation for Admin or User
    if (loginType == 1)
    {
        isLoggedIn = login(ADMIN_USERNAME, ADMIN_PASSWORD);
        if (isLoggedIn)
        {
            printf("\nAdmin login successful!\n");
        }
        else
        {
            printf("\nAdmin login failed. Exiting system.\n");
            return 0;
        }
    }
    else if (loginType == 2)
    {
        isLoggedIn = login(USER_USERNAME, USER_PASSWORD);
        if (isLoggedIn)
        {
            printf("\nUser login successful!\n");
        }
        else
        {
            printf("\nUser login failed. Exiting system.\n");
            return 0;
        }
    }
    else
    {
        printf("\nInvalid login type. Exiting system.\n");
        return 0;
    }

    // Menu loop for Admin or User
    while (choice != 5)
    {
        if (loginType == 1) // Admin menu
        {
            showAdminMenu();
        }
        else // User menu
        {
            showUserMenu();
        }

        scanf("%d", &choice);
        getchar(); // Clear the newline character from the input buffer.

        switch (choice)
        {
        case 1: // Display rooms
            displayRooms();
            break;
        case 2: // Add a room (Admin only)
            if (loginType == 1)
            {
                AddRoom();
            }
            else
            {
                printf("Access denied. Only Admin can add rooms.\n");
            }
            break;
        case 3: // Book a room
            book_room();
            break;
        case 4: // Checkout
            if (loginType == 1)
            {
                checkout();
            }
            else
            {
                printf("Access denied. Only Admin can perform checkout.\n");
            }
            break;
        case 5: // Exit
            printf("Exiting the system. Goodbye!\n");
            savefile(); // Save data to file before exiting
            saveAndDisplayBookedUsers();
            return 0;
        case 6:
            displaySavedUsers();
            break;
        default: // Invalid input
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


/*
int main()
{
    int choice = 0;
    printf("Enter the floor: ");

    scanf("%d", &MAX_FLOORS);
    initializeRooms(MAX_FLOORS);
    // savefile();

    while (choice != 5)
    {
        showMenu();
        scanf("%d", &choice);
        getchar();
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
            printCustomerDetails(0);
            savefile();
            saveAndDisplayBookedUsers();
            // savefile_user();
            printf("Data Saved in file");
            // printUserData();
            return 0;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
*/

// admin and user login interfage
int login(const char *username, const char *password)
{
    char inputUsername[20], inputPassword[20];

    printf("Enter Username: ");
    scanf("%s", inputUsername);
    printf("Enter Password: ");
    scanf("%s", inputPassword);

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void showAdminMenu()
{
    printf("\n--- Hotel Management System ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Add a Room\n");
    printf("3. Room Booking\n");
    printf("4. Checkout\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void showUserMenu()
{
    printf("\n--- User Menu ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Book a Room\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
} // code by al amin (login function )

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
    /*printf("\n--- Available Rooms ---\n");
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
    }*/
    printf("\nRoom Data:\n");
    printf("-----------------------------------------------------------------------------\n");
    printf("| Room No | Floor | Type     | View       | AC Type     | Occupied | Price  |\n");
    printf("-----------------------------------------------------------------------------\n");

    for (int i = 0; i < roomCount; i++)
    {
        printf("| %-7d | %-5d | %-8s | %-10s | %-11s | %-8s | %-6d |\n",
               hotelRooms[i].roomNumber,
               hotelRooms[i].floor,
               hotelRooms[i].type,
               hotelRooms[i].view,
               hotelRooms[i].ac_type,
               hotelRooms[i].isOccupied ? "Yes" : "No",
               hotelRooms[i].basePrice);
    }

    printf("----------------------------------------------------------------------------------\n");
}

void book_room()
{
    int roomNumber = 0;
    char type[30], view[30], ac[30];
    int foundroom[MAX_ROOMS];
    int foundcount = 0;
    int found = 0, stayDuration, month;

    printf("Enter the room type (single/double): ");
    scanf("%[^\n]s", type);
    getchar(); // to clear the buffer

    // Filter by type and store it in custom local array
    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].isOccupied == 0 && strcmp(hotelRooms[i].type, type) == 0)
        {
            foundroom[foundcount++] = i;
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
                foundroom[j] = foundroom[j + 1]; // removing the not match item
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
    }
    printf("Enter the Room Number to book: ");
    scanf("%d", &roomNumber);
    getchar();
    printf("%d\n", roomNumber);

    for (int i = 0; i < max_user; i++)
    {
        c[i].roomNumber = 0;
    }

    for (int i = 0; i < foundcount; i++)
    {
        if (hotelRooms[foundroom[i]].roomNumber == roomNumber)
        {
          printf("%d\n", hotelRooms[foundroom[i]].roomNumber);
            for (int j = 0; j < max_user; j++)
            {
                if (c[j].roomNumber == 0)
                {
                    printf("%d", j);
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
                    getchar(); // To clear newline from buffer

                    printf("Enter ID Type (e.g., Passport, Driver's License): ");
                    scanf("%[^\n]s", c[j].idType);
                    getchar();

                    printf("Enter ID Number: ");
                    scanf("%[^\n]s", c[j].idNumber);
                    getchar();
                    printf("Enter the duration of stay (in days): ");
                    scanf("%d", &stayDuration);
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
                    int totalPrice = calculatePrice(&hotelRooms[foundroom[i]], stayDuration, month);
                    hotelRooms[foundroom[i]].isOccupied = 1;
                    printf("Mr/Ms %s. You room %d have successfully been booked! \nTotal price for %d days is: %d\n",
                           c[j].name, roomNumber, stayDuration, totalPrice);
                    userCount++;
                    break;
                }
            }
            break;
        }
        else
        {
            printf("The given room doesn't meet you requirement");
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
    // done by sahaf
}

void savefile()
{
    FILE *f1;
    f1 = fopen("text2.txt", "w");
    // for (int i = 0; i < roomCount; i++)
    // {
    // fwrite(hotelRooms, sizeof(Room), 1, f1);
    //}
    for (int i = 0; i < MAX_ROOMS; i++)
    {
        fwrite(&roomCount, sizeof(int), 1, f1);
        fwrite(hotelRooms, sizeof(Room), roomCount, f1);
    }
    fclose(f1);
}

int calculatePrice(Room *room, int stayDuration, int month)
{
    int price = room->basePrice;

    if (isPeakSeason(month))
    {
        price *= 1.2;
    }

    if (stayDuration > 7)
    {
        price *= 0.85;
    }
    else if (stayDuration < 3)
    {
        price *= 1.15;
    }

    //if (strcmp(room->view, "Sea View") == 0)
    //{
    //    price *= 1.2;
    //}

    return price * stayDuration;
}

int isPeakSeason(int month)
{
    // peak season months ->June (6), July (7), November (11), December (12)
    if (month == 6 || month == 7 || month == 11 || month == 12)
    {
        return 1;
    }
    return 0;
}

// By sAhAf🙂

// By TeaM ScorPIoN🙂
void saveAndDisplayBookedUsers() {
    FILE *file = fopen("booked_users.txt", "a");
    if (file == NULL) {
        printf("Error: Could not open file for saving booked users.\n");
        return;
    }
    // do one then comment it
    // fprintf(file, "------------------------------------------------------------\n");
    // fprintf(file, "| Name              | Phone Number    | Email                | Address         | ID Type    | ID Number  | Room Number  | Check-in Date   | Check-out Date  |\n");

    // printf("------------------------------------------------------------\n");
    // printf("| Name              | Phone Number    | Email                | Address         | ID Type    | ID Number  | Room Number  | Check-in Date   | Check-out Date  |\n");

    if (userCount == 0) {  // Replace 'userCount' with your counter variable
        printf("No users have booked rooms.\n");
        fprintf(file, "No users have booked rooms.\n");
        fclose(file);
        return;
    }

    for (int i = 0; i < userCount; i++) {  // Replace 'userCount' with your counter variable
        if (c[i].name == NULL || c[i].roomNumber <= 0) {  // Replace 'c' with your array name
            printf("Error: Incomplete user data at index %d.\n", i);
            continue;
        }

        fprintf(file, "| %-17s | %-15s | %-20s | %-15s | %-10s | %-10s | %-12d | %-15s | %-15s |\n",
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


void displaySavedUsers() {
    FILE *file = fopen("booked_users.txt", "r");
    if (file == NULL) {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    char line[256];
    printf("------------------------------------------------------------\n");
    printf("| Name              | Phone Number    | Email                | Address         | ID Type    | ID Number  | Room Number  | Check-in Date   | Check-out Date  |\n");
    printf("------------------------------------------------------------\n");

    // Skip the header line
    fgets(line, sizeof(line), file);

    // Read and print the rest of the lines
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);  // Print the line as is
    }

    fclose(file);
}


/*
void saveAndDisplayBookedUsers()
{
    FILE *f;
    f = fopen("booked_users.txt", "w");
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    fprintf(f, "Name, Phone Number, Email, Address, ID Type, ID Number, Room Number, Stay Duration, Check-in Date, Check-out Date\n");

    printf("Booked Users:\n");
    printf("------------------------------------------------------------\n");
    printf("| %-17s | %-15s | %-20s | %-15s | %-10s | %-10s | %-11s | %-13s | %-13s |\n",
           "Name", "Phone Number", "Email", "Address", "ID Type", "ID Number", "Room Number", "Check-in Date", "Check-out Date");

    for (int i = 0; i < max_user; i++)
    {
        if (c[i].roomNumber != 0)
        { // Checking if the user has booked a room
            fprintf(f, "%s, %s, %s, %s, %s, %s, %d, %d, %s, %s\n",
                    c[i].name,
                    c[i].phoneNumber,
                    c[i].email,
                    c[i].address,
                    c[i].idType,
                    c[i].idNumber,
                    c[i].roomNumber,
                    c[i].stayDuration,
                    c[i].checkInDate,
                    c[i].checkOutDate);

            // Displaying on console
            printf("| %-17s | %-15s | %-20s | %-15s | %-10s | %-10s | %-11d | %-13s | %-13s |\n",
                   c[i].name,
                   c[i].phoneNumber,
                   c[i].name,
                   c[i].phoneNumber,
                   c[i].email,
                   c[i].address,
                   c[i].idType,
                   c[i].idNumber,
                   c[i].roomNumber,
                   c[i].stayDuration,
                   c[i].checkInDate,
                   c[i].checkOutDate);
        }
    }

    fclose(f);
    printf("User data saved to file and displayed successfully!\n");
}
*/
// void savefile_user()
// {
//     FILE *f2;
//     f2 = fopen("User.txt", "a"); // Use "a" mode to append data
//     if (f2 == NULL)
//     {
//         printf("Error opening file!\n");
//         return;
//     }

//     int userCount = 0;
//     for (int i = 0; i < max_user; i++)
//     {
//         if (c[i].roomNumber != 0) // Only count customers with a booked room
//         {
//             userCount++;
//         }
//     }

//     // Write the number of users (Only if there's any booking)
//     if (userCount > 0)
//     {
//         fwrite(&userCount, sizeof(int), 1, f2);

//         // Write only the users with valid bookings
//         for (int i = 0; i < max_user; i++)
//         {
//             if (c[i].roomNumber != 0) // Only save customers with a booked room
//             {
//                 fwrite(&c[i], sizeof(customer), 1, f2);
//             }
//         }
//     }

//     fclose(f2);

//     // Read and print customer booking data
//     f2 = fopen("User.txt", "r"); // Open the file again in read mode
//     if (f2 == NULL)
//     {
//         printf("Error opening file for reading!\n");
//         return;
//     }

//     // Read the number of users
//     fread(&userCount, sizeof(int), 1, f2);

//     printf("\n--- Customer Booking Data ---\n");
//     printf("-------------------------------------------------------------\n");
//     printf("| Name             | Phone Number   | Room Number | Check-in Date  |\n");
//     printf("-------------------------------------------------------------\n");

//     customer temp;
//     for (int i = 0; i < userCount; i++)
//     {
//         fread(&c, sizeof(customer), 1, f2);

//         printf("| %-17s | %-15s | %-11d | %-15s |\n",
//                c[i].name, c[i].phoneNumber, c[i].roomNumber, c[i].checkInDate);
//     }

//     printf("-------------------------------------------------------------\n");

//     fclose(f2);
// }

// // void book_room(char hotel[ROOMS][20], int room) {
// //     if (strcmp(hotel[room], "Available") == 0) {
// //         strcpy(hotel[room], "Booked");
// //         printf("Room %d has been booked successfully!\n", room + 1);
// //     } else {
// //         printf("Room %d is already booked.\n", room + 1);
// //     }
// // }
