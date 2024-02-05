#include <stdio.h>

int main() {
    int hours, minutes;
    
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hours, &minutes);

    char* am_pm = (hours < 12) ? "AM" : "PM";

    if (hours == 0) {
        hours = 12;
    } else if (hours > 12) {
        hours -= 12;
    }

    printf("Equivalent 12-hour time: %d:%02d %s\n", hours, minutes, am_pm);

    return 0;
}
