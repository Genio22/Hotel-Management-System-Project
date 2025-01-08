// done by tahsin
void book_room()
{

   int roomNumber = 0;
    char customer_name[MAX_ROOMS][50];
    char check_in_date[MAX_ROOMS][50];
    char check_out_date[MAX_ROOMS][50];

    printf("Enter Room number: ");
    scanf("%d", &roomNumber);
    printf("Enter Name: ");
    scanf ("%s", &customer_name);
    printf("Enter Check In Date: ");
    scanf ("%s", &check_in_date);
    printf("Enter Check Out Date: ");
    scanf ("%s", &check_out_date);

    int found =0;
    for(int i = 0; i < roomCount; i++)
    {
       if(roomNumber == hotelRooms[i].roomNumber)
       {
         found =1;
       }
       if(!hotelRooms[i].isOccupied)
       {
        hotelRooms[i].isOccupied= 1;
        printf("Room %d has been booked successfully!\n", hotelRooms[i].roomNumber);
       }
       else
       {
        printf("Room %d is already booked.\n", hotelRooms[i].roomNumber);
       }
        break;
        }

       if (!found)
       {
        printf("Room number %d does not exist. Please try again.\n", roomNumber);
       }

}
