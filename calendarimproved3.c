#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

const char *Month[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
int day_of_the_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *days_in_week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void check_escape()
{
    if (kbhit())
    {
        char ch = getch();
        if (ch == 27)
        {
            printf("\nESC pressed. Exiting...\n");
            exit(0);
        }
    }
}

// function to check if the year is a leap or not
int leap_or_not(int year)
{
    if (year >= 1)
    {
        if (year % 4 == 0)
        {
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    return 1;
                else
                    return 0;
            }
            else
            {
                return 1;
            }
        }
        else
            return 0;
    }
    else if (year == 0)
    {
        printf("There is no year 0 in the Gregorian calendar.\n");
        return -1; // Return an error code or handle as needed
    }
    else if (year <= -1)
    {
        if ((year + 1) % 4 == 0)
        {
            if ((year + 1) % 100 == 0)
            {
                if ((year + 1) % 400 == 0)
                    return 1;
                else
                    return 0;
            }
            else
            {
                return 1;
            }
        }
        else
        {
            return 0;
        }
    }
    else
    {
        printf("Invalid year input.\n");
        return -1; // Return an error code or handle as needed
    }
}

// this function gives the first day of the year which we can set a reference to generate the entire year
int first_day(int year)
{
    if (year >= 1)
    {
        int day;
        day = ((year) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400) % 7;
        return day;
    }
    else if (year == 0)
    {
        printf("There is no year 0 in the Gregorian calendar.\n");
        return -1; // Return an error code or handle as needed
    }
    else if (year <= -1)
    {
        int day, fakeday;

        fakeday = (year * 365 + (year + 1) / 4 - (year + 1) / 100 + (year + 1) / 400) % 7;
        day = fakeday + 7;
        return day;
    }
}

// this function prints the calender
void print_calender(int year, int first_day, int leap)
{
    // Function to print the calendar for the given year
    // This is a placeholder function. The actual implementation would go here.

    if (year < 0)
    {
        printf("======================================\n");
        printf("      Calender for the year %d BC\n", -year);
        printf("======================================\n");
    }
    else
    {
        printf("======================================\n");
        printf("      Calender for the year %d\n", year);
        printf("======================================\n");
    }

    // Further implementation would be needed to print the full calendar
    for (int month = 0; month < 12; month++)
    {
        if (month == 1 && leap)
        {
            day_of_the_month[1] = 29; // February in a leap year
        }
        printf("\n\n------------%s-------------\n", Month[month]);
        printf(" Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        int days_in_month = day_of_the_month[month];

        int day;
        for (day = 0; day < first_day; day++)
        {
            printf("     ");
        }
        for (int date = 1; date <= day_of_the_month[month]; date++)
            if (date < 10)
            {
                printf("  %d  ", date);
                if ((date + first_day) % 7 == 0)
                    printf("\n");
            }
            else
            {
                printf("  %d ", date);
                if ((date + first_day) % 7 == 0)
                    printf("\n");
            }
        first_day = (first_day + day_of_the_month[month]) % 7;
    }
    printf("\n======================================\n");
    check_escape();
}

// this are the lists of the several international and national days celebrated, all are listed according to the months
int special_day(int month, int date)
{
    switch (month)
    {
    case 1:
        if (date == 1)
        {
            printf("New Year's Day\n");
            return 0;
        }
        else if (date == 20 || date == 21 || date == 22)
        {
            printf("Martin Luther King Jr. Day\n");
            return 0;
        }
        else if (date == 4)
        {
            printf("world Braille Day\n");
            return 0;
        }
        else if (date == 12)
        {
            printf("National Youth Day (India)\n");
            return 0;
        }
        else if (date == 15)
        {
            printf(" Army day\n");
            return 0;
        }
        else if (date == 25)
        {
            printf("National Voter's Day\n India Tourism Day\n");
            return 0;
        }
        else if (date == 26)
        {
            printf("Republic Day\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;

    case 2:
        if (date == 4)
        {
            printf("World Cancer Day\n");
            return 0;
        }
        else if (date == 14)
        {
            printf("Valentine's Day\n");
            return 0;
        }
        else if (date == 21)
        {
            printf("International Mother Language Day\n");
            return 0;
        }
        else if (date == 20)
        {
            printf("World Day of Social Justice\n");
            return 0;
        }
        else if (date == 28)
        {
            printf("National Science Day\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 3:
        if (date == 8)
        {
            printf("International Women's Day\n");
            return 0;
        }
        else if (date == 15)
        {
            printf("World Consumer Day\n");
            return 0;
        }
        else if (date == 20)
        {
            printf("International Day Of Happiness\n");
            return 0;
        }
        else if (date == 21)
        {
            printf("World Forestry Day\n");
            return 0;
        }
        else if (date == 22)
        {
            printf("World Water Day\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 4:
        if (date == 7)
        {
            printf("World Health Day\n");
            return 0;
        }
        else if (date == 5)
        {
            printf("National Maritime Day (India)\n");
            return 0;
        }
        else if (date == 22)
        {
            printf("Earth Day\n");
            return 0;
        }
        else if (date == 25)
        {
            printf("World Malaria Day\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 5:
        if (date == 1)
        {
            printf("International Workers' Day\n");
            return 0;
        }
        else if (date == 4)
        {
            printf("Star Wars Day\n");
            return 0;
        }
        else if (date == 5)
        {
            printf("Cinco de Mayo\n");
            return 0;
        }
        else if (date == 9)
        {
            printf("Europe Day\n");
            return 0;
        }
        else if (date == 12)
        {
            printf("International Nurses Day\n");
            return 0;
        }
        else if (date == 15)
        {
            printf("International Day of Families\n");
            return 0;
        }
        else if (date == 17)
        {
            printf("World Telecommunication and Information Society Day\n");
            return 0;
        }
        else if (date == 20)
        {
            printf("World Bee Day\n");
            return 0;
        }
        else if (date == 25)
        {
            printf("Africa Day\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 6:
        if (date == 5)
        {
            printf("World Environment Day\n");
            return 0;
        }
        else if (date == 14)
        {
            printf("World Blood Donor Day\n");
            return 0;
        }
        else if (date == 17)
        {
            printf("World Day to Combat Desertification and Drought\n");
            return 0;
        }
        else if (date == 21)
        {
            printf("International Yoga Day\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 7:
        if (date == 1)
        {
            printf("Canada Day\n");
            return 0;
        }
        else if (date == 4)
        {
            printf("Independence Day (USA)\n");
            return 0;
        }
        else if (date == 14)
        {
            printf("Bastille Day (France)\n");
            return 0;
        }
        else if (date == 20)
        {
            printf("International Chess Day\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 8:
        if (date == 15)
        {
            printf("Independence Day (India)\n");
            return 0;
        }
        else if (date == 19)
        {
            printf("World Humanitarian Day\n");
            return 0;
        }
        else if (date == 23)
        {
            printf("International Day for the Remembrance of the Slave Trade and its Abolition\n");
            return 0;
        }
        else if (date == 9)
        {
            printf("Nagasaki Day\n");
            return 0;
        }
        else if (date == 29)
        {
            printf("International Day against Nuclear Tests\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 9:
        if (date == 5)
        {
            printf("International Day of Charity\n");
            return 0;
        }
        else if (date == 8)
        {
            printf("International Literacy Day\n");
            return 0;
        }

        else if (date == 16)
        {
            printf("World Ozone Day\n");
            return 0;
        }
        else if (date == 21)
        {
            printf("International Day of Peace\n");
            return 0;
        }
        else if (date == 27)
        {
            printf("World Tourism Day\n");
            return 0;
        }
        else if (date == 14)
        {
            printf("Hindi Divas\n");
            return 0;
        }
        else
        {
            return -1;
        }
        break;
    case 10:
        if (date == 1)
        {
            printf("International Day of Older Persons\n");
            return 0;
        }
        else if (date == 2)
        {
            printf("International Day of Non-Violence\n");
            return 0;
        }
        else if (date == 4)
        {
            printf("World Animal Day\n");
            return 0;
        }
        else if (date == 5)
        {
            printf("World Teachers' Day\n");
            return 0;
        }
        else if (date == 10)
        {
            printf("World Mental Health Day\n");
            return 0;
        }
        else if (date == 16)
        {
            printf("World Food Day\n");
            return 0;
        }
        else if (date == 24)
        {
            printf("United Nations Day\n");
            return 0;
        }
        break;
    case 11:
        if (date == 11)
        {
            printf("Veterans Day (USA)\n");
            return 0;
        }
        else if (date == 14)
        {
            printf("World Diabetes Day\n");
            return 0;
        }
        else if (date == 16)
        {
            printf("International Day for Tolerance\n");
            return 0;
        }
        else if (date == 20)
        {
            printf("Universal Children's Day\n");
            return 0;
        }
        else if (date == 25)
        {
            printf("International Day for the Elimination of Violence against Women\n");
            return 0;
        }
        break;
    case 12:
        if (date == 1)
        {
            printf("World AIDS Day\n");
            return 0;
        }
        else if (date == 10)
        {
            printf("Human Rights Day\n");
            return 0;
        }
        else if (date == 25)
        {
            printf("Christmas Day\n");
            return 0;
        }
        break;

    default:
        return -1; // No special day for the given month and date
        break;
    }
}

// this is the function which saves the notes based on the date
void save_note_of_date_based_on_date(int month, int date)
{
    FILE *file;
    char filename[100];
    char note[100];
    printf("Enter the note for %d/%d:", date, month);
    getchar(); // Clear the newline character left by previous scanf
    fgets(note, sizeof(note), stdin);

    sprintf(filename, "note_%02d_%02d.txt", date, month);

    file = fopen(filename, "a");
    if (file == NULL)
    {
        printf("Error opening file");
        return;
    }

    fprintf(file, "%s", note);
    fclose(file);
    printf("Note saved successfully for %d/%d\n", date, month);
}

// this is the function which reads the notes which are saved based on the date
void read_note_of_date_based_on_date(int month, int date)
{
    FILE *file;
    char filename[100];
    char note[100];

    sprintf(filename, "note_%02d_%02d.txt", date, month);

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("No code found on %d/%d\n", date, month);
        return;
    }
    printf("Note for %d/%d:\n", date, month);
    while (fgets(note, sizeof(note), file))
    {
        printf("%s", note);
    }
    fclose(file);
}

// just to check if the date is valid or not and to print the day of the week on that date and also to check if there is any special day on that date or not
int date_validator(int month, int date, int leap)

{
    if (month < 1 || month > 12)
    {
        printf("Invalid month. Please enter a value between 1 and 12.\n");
        return -1; // Return an error code or handle as needed
    }

    if (month == 2 && leap)
    {
        day_of_the_month[1] = 29; // February in a leap year
    }

    if (date < 1 || date > day_of_the_month[month - 1])
    {
        printf("Invalid date. Please enter a value between 1 and %d for month %d.\n", day_of_the_month[month - 1], month);
        return -1; // Return an error code or handle as needed
    }

    return 0; // Valid date
}

// funtion to check the day of the week on a specific date and also to check if there is any special day on that date or not
void something_with_date(int year)
{
    int month, date;

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printf("Enter the date from 1 to %d: ", day_of_the_month[month - 1]);
    scanf("%d", &date);

    if (date_validator(month, date, leap_or_not(year)) == -1)
    {
        printf("\n");
        return; // Return early if the date is invalid
    }

    int first_day_of_year = first_day(year);
    int total_days = 0;

    for (int i = 0; i < month - 1; i++)
    {
        if (i == 1 && leap_or_not(year))
        {
            total_days += 29;
        }
        else
        {
            total_days += day_of_the_month[i];
        }
    }
    total_days += date;

    int day_of_the_week = (first_day_of_year + total_days - 1) % 7;
    printf("\nThe day on %d/%d/%d is %s.\n", date, month, year, days_in_week[day_of_the_week]);
    if (special_day(month, date) == -1)
    {
        printf("There is no special day on this date.\n");
    }
    char choice;
    char action;

    printf("\n do you want to save or read a note for this date? (y/n):");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {

        printf("press r/R for reading the note\n press w/W for writting the note\n");
        scanf(" %c", &action);
        if (action == 'w' || action == 'W')
        {
            save_note_of_date_based_on_date(month, date);
        }
        else if (action == 'r' || action == 'R')
        {
            read_note_of_date_based_on_date(month, date);
        }
        else
        {
            printf("Invalid choice. Returning to the main menu.\n");
        }
    }
    else
    {
        printf("Returning to main menu.\n");
    }
}

// The main function serves as the entry point of the program,
// allowing users to input a year and interact with the calendar functionalities.
// It handles user input, displays the calendar, checks for leap years,
// and provides options for further interactions based on user choices.
int main()
{
    int year;
    printf("Enter any year: ");
    scanf("%d", &year);

    if (year == 0)
    {
        printf("There is no year 0.\n");
    }

    print_calender(year, first_day(year), leap_or_not(year));
    if (leap_or_not(year) == 1)
    {
        printf("\n The year %d is a leap year.\n", year);
    }
    else
    {
        printf("\n The year %d is not a leap year.\n", year);
    }

    char choice; // Consume the newline character left by scanf
    printf(" \n If you want to check another year , press y or Y \n If you want to add or read a note , press d or D \n Press x or X to exit\n ");
    scanf(" %c", &choice);

    switch (choice)
    {
    case 'y':
    case 'Y':
        main();
        break;

    case 'd':
    case 'D':
        something_with_date(year);
        break;

    case 'x':
    case 'X':
        printf("Exiting the program");
        break;

    default:

        printf("Invalid choice. Enter again .\n");
        break;
    }
    return 0;
}
