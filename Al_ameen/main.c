int login(const char *username, const char *password) {
    char inputUsername[20], inputPassword[20];

    printf("Enter Username: ");
    scanf("%s", inputUsername);
    printf("Enter Password: ");
    scanf("%s", inputPassword);

    if (strcmp(username, inputUsername) == 0 && strcmp(password, inputPassword) == 0) {
        return 1; 
    } else {
        return 0; 
    }
}

void showAdminMenu() {
    printf("\n--- Admin Menu ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Add a Room\n");
    printf("3. Book a Room\n");
    printf("4. Checkout\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
}

void showUserMenu() {
    printf("\n--- User Menu ---\n");
    printf("1. Display Available Rooms\n");
    printf("2. Book a Room\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
}
