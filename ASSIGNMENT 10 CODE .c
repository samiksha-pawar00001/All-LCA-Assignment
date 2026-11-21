#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int is_leap_year(int year) {
    if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        return 1;
    }
    return 0;
}

int get_days_in_month(int month, int year) {
    
    static const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 1 && is_leap_year(year)) {
        return 29;
    }
    return days[month];
}

int get_first_day_of_year(int year) {
    struct tm date = {0};
    date.tm_year = year - 1900; 
    date.tm_mon = 0;          
    date.tm_mday = 1;          
    date.tm_isdst = -1;        

    if (mktime(&date) == (time_t)-1) {
        fprintf(stderr, "Error computing weekday for year %d.\n", year);
        exit(EXIT_FAILURE);
    }
    return date.tm_wday; 
}

void print_month_calendar(int month, int year, int *start_day) {
    static const char *month_names[12] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int total_days = get_days_in_month(month, year);
    int day_of_week = *start_day;

    printf("\n   ------------ %s %d ------------\n", month_names[month], year);
    printf("   Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

   
    for (int i = 0; i < day_of_week; i++) {
        printf("     ");
    }

    for (int day = 1; day <= total_days; day++) {
        printf("%5d", day);
        day_of_week++;
        if (day_of_week == 7) {
            printf("\n");
            day_of_week = 0;
        }
    }

    if (day_of_week != 0) {
        printf("\n");
    }

    
    *start_day = day_of_week;
}

int main(void) {
    int year;

    printf("Enter the year: ");
    if (scanf("%d", &year) != 1) {
        fprintf(stderr, "Invalid input. Please enter a numeric year.\n");
        return 1;
    }

    int current_start_day = get_first_day_of_year(year);

    for (int month = 0; month < 12; month++) {
        print_month_calendar(month, year, &current_start_day);
    }

    return 0;
}
