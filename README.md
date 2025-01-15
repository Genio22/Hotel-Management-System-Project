# Hotel Management System Project

## Project Overview
This project is a Hotel Management System written in C. It manages hotel rooms, bookings, check-ins, check-outs, and generates invoices. The system includes separate functionalities for admins and users, ensuring efficient hotel management.

## Features
### Admin Functionalities:
- Add new rooms
- Display available rooms
- Book rooms for customers
- Check out customers
- Save and display room details
- Save and display booked users' data
- Generate and print invoices

### User Functionalities:
- Display available rooms
- Book rooms

## File Structure
```
Hotel-Management-System-Project/
│
├── Ahnaf/
│   └── janina/
│       └── jani_na.c
│
├── README.md
└── (Other directories and files)
```

## Compilation and Execution Instructions
1. **Clone the repository**:
    ```sh
    git clone https://github.com/Genio22/Hotel-Management-System-Project.git
    cd Hotel-Management-System-Project/Ahnaf/janina
    ```

2. **Compile the program**:
    ```sh
    gcc jani_na.c -o hotel_management
    ```

3. **Run the executable**:
    ```sh
    ./hotel_management
    ```

## Detailed Description
### Global Constants
- `HOTEL_NAME`: The name of the hotel.
- `HOTEL_ADDRESS`: The address of the hotel.
- `HOTEL_PHONE`: The phone number of the hotel.
- `HOTEL_EMAIL`: The email address of the hotel.
- `MAX_ROOMS`: Maximum number of rooms in the hotel.
- `MAX_FLOORS`: Maximum number of floors in the hotel.
- `max_user`: Maximum number of users.
- `ADMIN_USERNAME`: Default admin username.
- `ADMIN_PASSWORD`: Default admin password.
- `USER_PASSWORD`: Default user password.

### Structures
- **Room**: Contains details about each room such as room number, floor, type, view, AC type, base price, and occupancy status.
- **Customer**: Contains customer details such as name, phone number, email, address, ID type, ID number, room number, total price, base price, stay duration, check-in, and check-out dates.

### Functions
- **Initialization and Utility Functions**:
  - `print_logo()`: Prints the hotel logo.
  - `initializeRooms()`: Initializes the hotel rooms with predefined types, views, AC types, and base prices.
  - `displayRooms()`: Displays all rooms and their details.
  - `AddRoom()`: Adds a new room to the hotel.
- **Login and Menu Functions**:
  - `login(const char *username, const char *password)`: Handles login for admin and users.
  - `showAdminMenu()`: Displays the admin menu.
  - `showUserMenu()`: Displays the user menu.
- **Room Booking and Checkout Functions**:
  - `book_room()`: Books a room based on user preferences such as room type, AC type, and view.
  - `calculatePrice(Room *room, int stayDuration, int month)`: Calculates the total price for the stay, considering peak season and stay duration discounts.
  - `isPeakSeason(int month)`: Checks if the given month is a peak season.
  - `checkout()`: Handles the checkout process for a room.
- **File Handling Functions**:
  - `save_book_users_data()`: Saves booked user data to a file.
  - `display_book_users_data()`: Displays booked user data from a file.
  - `save_Room_Details_data()`: Saves room details to a file.
  - `display_Room_Details_data()`: Displays room details from a file.
  - `print_bill(int i)`: Prints the bill for a customer.

## How to Use
### Admin Steps
1. **Login as Admin**:
    - Username: `admin`
    - Password: `admin123`
2. **Admin Menu**:
    - Display available rooms
    - Add a new room
    - Book a room
    - Checkout a customer
    - Save and display room details
    - Save and display booked users' data
    - Generate and print invoices

### User Steps
1. **User Menu**:
    - Display available rooms
    - Book a room

## Example Usage
### Hotel Logo
```
                                  (                               
   (                   )     (    )\ )        )                )  
   )\          )    ( /(   ) )\  (()\/  (  ( /((     (    ) ( /(  
 (((_)  (   ( /( (  )\()| /(((_)  /(_))))\ )\())(   ))\( /( )\()) 
 )\___  )\  )(_)))\(_))/)(_))_   (_)) /((_|_))(()\ /((_)(_)|_))/  
((/ __|((_)((_)_((_) |_((_)_| |  | _ (_)) | |_ ((_|_))((_)_| |_   
 | (__/ _ \/ _` (_-<  _/ _` | |  |   / -_)|  _| '_/ -_) _` |  _|  
  \___\___/\__,_/__/\__\__,_|_|  |_|_\___| \__|_| \___\__,_|\__|  
                                                                  
                                                        by Team Scorpion
```

### Admin Menu
```
********************************************
*        Welcome to HOTEL Paradise         *
********************************************
*  1. Display Available Rooms              *
*  2. Add a Room                           *
*  3. Room Booking                         *
*  4. Checkout                             *
*  5. Exit                                 *
********************************************
Enter your choice: 
```

## Contributors
We all are together **Team Scorpion**:
- Ahnaf
- Al Amin
- Riad
- Tahsin

## License
This project is licensed under the MIT License. See the LICENSE file for details.

