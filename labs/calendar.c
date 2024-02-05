#include <stdio.h>

int main() {
    int days_in_month, start_day;
    
    printf("Enter number of days in month: ");
    scanf("%d", &days_in_month);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &start_day);

    int day_counter = 1;

    for (int week = 0; week < 5; week++) {
        for (int day = 0; day < 7; day++) {
            if (week == 0 && day < start_day - 1) {
                printf("   ");
            } else {
                if (day_counter <= days_in_month) {
                    printf("%2d ", day_counter);
                    day_counter++;
                } else {
                    break;
                }
            }
        }
        printf("\n"); 
    }

    return 0;
}
