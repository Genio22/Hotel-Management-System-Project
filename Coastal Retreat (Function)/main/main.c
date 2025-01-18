/* Hotel-Management-System-Project */
#include <stdio.h>
#include <stdlib.h> // rad() use kora lagche
#include <string.h>

#define HOTEL_NAME "Paradise"
#define HOTEL_ADDRESS "Cox Bazer"
#define HOTEL_PHONE "01922322354"
#define HOTEL_EMAIL "hotelparadise@gmail.com"
#define MAX_ROOMS 100
#define MAX_FLOORS 10
#define max_user 100
#define ADMIN_USERNAME "admin"
#define ADMIN_PASSWORD "admin123"
// #define USER_USERNAME ""
// #define USER_PASSWORD "user123"

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
    char phoneNumber[15];
    char email[50];
    char address[100];
    char idType[30]; // e.g., Passport, Driver's License
    char idNumber[30];
    int roomNumber;
    int total_price;
    int base_price;
    int stayDuration;
    char checkInDate[15];
    char checkOutDate[15];
} customer;

// Global variables
Room hotelRooms[MAX_ROOMS];
customer c[max_user];
int roomCount = 0, userCount = 0;

// Function prototypes(13)

// Logo er part
void print_logo();

// Login and it menu type
int login(char *username, char *password);
void showAdminMenu();
void showUserMenu();

// void showMenu();
void initializeRooms();
void displayRooms();
void AddRoom();
void edit_Room();

// book room er part
void book_room();
int calculatePrice(Room *room, int stayDuration, int month);
int isPeakSeason();
void editBookingDetails();
// ai porjonto

void checkout();

// File er part
void save_book_users_data();
void display_book_users_data();
void save_Room_Details_data();
void display_Room_Details_data();
void print_bill(int i);

int main()
{
    int choice = 0, a = 0;

    print_logo();
    printf("\n\nWelcome to the Hotel %s\n", HOTEL_NAME);
    // printf("Enter the total number of floors in the hotel: ");
    // scanf("%d", &MAX_FLOORS);
    // getchar();

    initializeRooms(); // first e rooms Initialize kotechi based on the total number of floors.
    printf("\nPlease login to access the system:\n");
    int loginType = 0;
    while (loginType != 3)
    {
        // login type: Admin or User
        printf("1. Admin Login\n");
        printf("2. User Login\n");
        printf("3. Exit\n");
        printf("Enter your choice (1 for Admin, 2 for User): ");
        scanf("%d", &loginType);
        getchar();

        int isLoggedIn = 0;

        // Login validation for Admin or User
        if (loginType == 1)
        {
            isLoggedIn = login(ADMIN_USERNAME, ADMIN_PASSWORD);
            if (isLoggedIn)
            {
                printf("\nAdmin login successful!\n");
                break;
            }
            else
            {
                printf("\nAdmin login failed. Please try again.\n");
            }
        }
        else if (loginType == 2)
        {
            isLoggedIn = 1; // Assume user login is always successful for now
            if (isLoggedIn)
            {
                printf("\nUser login successful!\n");
                break;
            }
            else
            {
                printf("\nUser login failed. Please try again.\n");
            }
        }
        else if (loginType == 3)
        {
            printf("\nExiting system. Goodbye!\n");
            return 0;
        }
        else
        {
            printf("\nInvalid choice. Please try again.\n");
        }
    }
    // Menu loop for Admin or User
    while (choice != 7)
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
        getchar();

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
            if (loginType == 1)
            {
                edit_Room();
            }
            else
            {
                printf("Access denied. Only Admin can add rooms.\n");
            }
            break;
        case 4: 
            book_room();
            break;
        case 5: 
            if (loginType == 1)
            {
                editBookingDetails();
            }
            else
            {
                printf("Access denied. Only Admin can perform checkout.\n");
            }
        case 6:
            if (loginType == 1)
            {
                checkout();
            }
            else
            {
                printf("Access denied. Only Admin can perform checkout.\n");
            }
            break;
        case 7:// Exit
            printf("Exiting the system. Goodbye!\n");
            save_book_users_data();
            save_Room_Details_data();
            return 0;
        case 8:
            printf("Enter the index for student: ");
            scanf("%d", &a);
            print_bill(a);
            break;
        case 9:
            display_Room_Details_data();
            break;
        case 10:
            display_book_users_data();
            break;
        default: // Invalid input
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}

void print_logo()
{
    printf("                                  (                               \n");
    printf("   (                   )     (    )\\ )        )                )  \n");
    printf("   )\\          )    ( /(   ) )\\  (()/\\  (  ( /((     (    ) ( /(  \n");
    printf(" (((_)  (   ( /( (  )\\()| /(((_)  /(_))))\\ )\\())(   ))\\( /( )\\()) \n");
    printf(" )\\___  )\\  )(_)))\\(_))/)(_))_   (_)) /((_|_))(()\\ /((_)(_)|_))/  \n");
    printf("((/ __|((_)((_)_((_) |_((_)_| |  | _ (_)) | |_ ((_|_))((_)_| |_   \n");
    printf(" | (__/ _ \\/ _` (_-<  _/ _` | |  |   / -_)|  _| '_/ -_) _` |  _|  \n");
    printf("  \\___\\___/\\__,_/__/\\__\\__,_|_|  |_|_\\___| \\__|_| \\___\\__,_|\\__|  \n");
    printf("                                                                  by Team Scorpion");
}
// By sAhAf🙂

// admin and user login interfage
int login(char *username, char *password)
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
    printf("\n********************************************\n");
    printf("*        Welcome to HOTEL %s        *\n", HOTEL_NAME);
    printf("********************************************\n");
    // printf("*                 ADMIN                    *\n");
    printf("*  1. Display Available Rooms              *\n");
    printf("*  2. Add a Room                           *\n");
    printf("*  3. Edit Room details                    *\n");
    printf("*  4. Room Booking                         *\n");
    printf("*  5. Edit Booking Details                 *\n");
    printf("*  6. Checkout                             *\n");
    printf("*  7. Exit                                 *\n");
    printf("********************************************\n");
    printf("Enter your choice: ");
}

void showUserMenu()
{
    printf("\n********************************************\n");
    printf("*        Welcome to HOTEL %s         *\n", HOTEL_NAME);
    printf("********************************************\n");
    printf("*  1. Display Available Rooms              *\n");
    printf("*  4. Room Booking                          *\n");
    printf("*  7. Exit                                 *\n");
    printf("********************************************\n");
    printf("Enter your choice: ");
} // code by al amin (login function )

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

// done by tahsin
void AddRoom()
{
    int roomNumber, floor, basePrice, isOccupied;
    char type[20], view[20], ac_type[20];

    if (roomCount < MAX_ROOMS) // Ensure roomCount is less than MAX_ROOMS
    {
        // Prompt user for room details
        printf("Enter Room Number: ");
        scanf("%d", &roomNumber);
        printf("Enter Floor: ");
        scanf("%d", &floor);
        getchar();
        printf("Enter Room Type (e.g., Single, Double, Deluxe): ");
        scanf("%[^\n]s", type);
        getchar();
        printf("Enter View (e.g., Sea, City): ");
        scanf("%[^\n]s", view);
        getchar();
        printf("Enter AC type (AC, Non AC): ");
        scanf("%[^\n]s", ac_type);
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
        strcpy(hotelRooms[roomCount].ac_type, ac_type);

        roomCount++;
        printf("\n\n  ------ Room added successfully.------  \n");
        printf("Room Number: %d\nFloor: %d\nRoom Type: %s\nView: %s\nAC Type: %s\nBase Price: %d\nOccupied: %d\n",
               roomNumber, floor, type, view, ac_type, basePrice, isOccupied);
    }
    else
    {
        printf("Sorry, Can not add more room ! Please try later.\n");
    }
}

void edit_Room()
{
    int roomNumber, floor, basePrice, isOccupied, edit = 0;
    char type[20], view[20], ac_type[30];
    printf("Enter Room Number: ");
    scanf("%d", &roomNumber);
    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].roomNumber == roomNumber && hotelRooms[i].isOccupied == 0) // Ensure roomCount is less than MAX_ROOMS
        {
            printf("Enter Floor: ");
            scanf("%d", &floor);
            getchar();
            printf("Enter Room Type (e.g., Single, Double,): ");
            scanf("%[^\n]s", type);
            getchar();
            printf("Enter View (e.g., Sea, City): ");
            scanf("%[^\n]s", view);
            getchar();
            printf("Enter AC type (AC, Non AC): ");
            scanf("%[^\n]s", ac_type);
            getchar();
            printf("Enter Base Price: ");
            scanf("%d", &basePrice);
            printf("Is the room occupied? (1 for Yes, 0 for No): ");
            scanf("%d", &isOccupied);

            hotelRooms[i].floor = floor;
            hotelRooms[i].basePrice = basePrice;
            hotelRooms[i].isOccupied = isOccupied;
            strcpy(hotelRooms[i].type, type);
            strcpy(hotelRooms[i].view, view);

            printf("\n\n  ------ Room edited successfully.------  \n");
            printf("Room Number: %d\nFloor: %d\nRoom Type: %s\nView: %s\nBase Price: %d\nOccupied: %d\n",
                   roomNumber, floor, type, view, basePrice, isOccupied);
            edit = 1;
        }
    }
    if (!edit)
    {
        printf("Cannot add more rooms. Maximum capacity reached.\n");
    }
}

void displayRooms()
{
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
    } // By sAhAf🙂

    printf("----------------------------------------------------------------------------------\n");
}

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

    // if (strcmp(room->view, "Sea View") == 0)
    //{
    //     price *= 1.2;
    // }

    return price * stayDuration;
} // By sAhAf🙂

int isPeakSeason(int month)
{
    // peak season months ->June (6), July (7), November (11), December (12)
    if (month == 6 || month == 7 || month == 11 || month == 12)
    {
        return 1;
    }
    return 0;
} // By sAhAf🙂

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

void save_Room_Details_data()
{
    FILE *file = fopen("Room_details.txt", "w");
    if (file == NULL)
    {
        printf("Error: Could not open file for saving room details.\n");
        return;
    }

    if (roomCount == 0)
    { // Check if no rooms are available
        printf("No rooms are available.\n");
        fprintf(file, "No rooms are available.\n");
        fclose(file);
        return;
    }

    // Print room data for console debuger jono
    // printf("----------------------------------------------------------------------------------------\n");
    // printf("| Room Number  | Floor | Type      | View      | AC Type      | Base Price | Occupied |\n");// By sAhAf🙂
    // printf("----------------------------------------------------------------------------------------\n");

    // Print headers in file akbar printf kora lagbe
    fprintf(file, "\n\n\n------------------------------------------------------------------------------------------\n");
    fprintf(file, "| Room Number  | Floor | Type      | View         | AC Type      | Base Price | Occupied |\n");
    fprintf(file, "------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < roomCount; i++)
    {
        if (hotelRooms[i].roomNumber <= 0)
        {
            printf("Error: Incomplete room data at index %d.\n", i);
            continue;
        }

        // Print room data for console debuger jono
        // printf("| %-12d | %-5d | %-9s | %-9s | %-12s | %-10d | %-8s |\n",
        //        hotelRooms[i].roomNumber, hotelRooms[i].floor, hotelRooms[i].type,
        //        hotelRooms[i].view, hotelRooms[i].ac_type,
        //        hotelRooms[i].basePrice, hotelRooms[i].isOccupied ? "Yes" : "No");

        // Print room data to file in human er jono
        fprintf(file, "| %-12d | %-5d | %-9s | %-12s | %-12s | %-10d | %-8s |\n",
                hotelRooms[i].roomNumber, hotelRooms[i].floor, hotelRooms[i].type,
                hotelRooms[i].view, hotelRooms[i].ac_type,
                hotelRooms[i].basePrice, hotelRooms[i].isOccupied ? "Yes" : "No");
    }

    fclose(file);
    printf("----------------------------------------------------------------------------------------\n");
    printf("Room details saved and displayed successfully.\n");
}

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
    // printf("| Name              | Phone Number    | Email                      | Address         | ID Type    | ID Number  | Room Number  | Check-in Date   | Check-out Date  |\n");
    // By sAhAf🙂

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

void display_book_users_data()
{
    FILE *file = fopen("Booked_users.txt", "r");
    if (file == NULL)
    {
        printf("Error: Could not open file for reading.\n");
        return;
    }

    char line[256];
    printf("|------------------------------------------------------------------------------------------------------------------------------------------------------------------------|\n");
    printf("| Name            | Phone Number   | Email                     | Address                   | ID Type      | ID Number     | Room Number | Check-in Date | Check-out Date |\n");
    // printf("-------------------------------------------------------------------------------------------------------------------------------------------------------------\n");

    // line diya full 1 block array access
    fgets(line, sizeof(line), file);

    // Read and print the rest of the lines
    while (fgets(line, sizeof(line), file))
    {
        printf("%s", line); // Print the line as is // By sAhAf🙂
    }

    fclose(file);
}

void print_bill(int i)
{
    char f[30];
    sprintf(f, "Print Bill %d.txt", userCount);
    FILE *file = fopen(f, "w");
    // Write the invoice data to the file
    fprintf(file, "Hotel %s\n", HOTEL_NAME);
    fprintf(file, "Address: %s\n", HOTEL_ADDRESS);
    fprintf(file, "Phone: %s\n", HOTEL_PHONE);
    fprintf(file, "Email: %s\n\n", HOTEL_EMAIL);

    fprintf(file, "-------------------------------------\n");
    fprintf(file, "              Guest Invoice\n");
    fprintf(file, "-------------------------------------\n\n");

    fprintf(file, "Guest Name: %s\n", c[i].name);
    fprintf(file, "Phone Number: %s\n", c[i].phoneNumber);
    fprintf(file, "Email: %s\n", c[i].email);
    fprintf(file, "Address: %s\n", c[i].address);
    fprintf(file, "Room Number: %d\n\n", c[i].roomNumber);

    fprintf(file, "-------------------------------------\n");
    fprintf(file, "Description           Rate (per night)  Nights Stayed  Amount (BDT)\n");
    fprintf(file, "Room Rent (Standard)  3,000             4              %d\n", c[i].base_price);
    fprintf(file, "Service Charge (5%)                                        600\n");
    fprintf(file, "VAT (10%)                                                1,260\n");
    fprintf(file, "Additional Charges                                       0\n");
    fprintf(file, "-------------------------------------\n");
    fprintf(file, "Total Amount (BDT):                                     %d\n\n", c[i].total_price);

    fprintf(file, "-------------------------------------\n");
    fprintf(file, "Check-in Date: %s\n", c[i].checkInDate);
    fprintf(file, "Check-out Date: %s\n", c[i].checkOutDate);
    fprintf(file, "Payment Method: Cash/Card\n\n");

    fprintf(file, "-------------------------------------\n");
    fprintf(file, "Thank you for staying with us!\n");
    fprintf(file, "We look forward to welcoming you again.\n");
    fprintf(file, "-------------------------------------\n");
    fclose(file);
}

// By sAhAf🙂

// By TeaM ScorPIoN🙂
