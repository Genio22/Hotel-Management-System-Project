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
