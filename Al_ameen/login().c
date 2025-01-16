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
