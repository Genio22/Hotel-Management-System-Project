void print_bill(int i)
{
    FILE *file = fopen("Print Bill.txt", "w");
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

    fprintf(file, "-------------------------------------\n");// By sAhAf🙂
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
