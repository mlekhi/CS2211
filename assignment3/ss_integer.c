#include <stdio.h>
#include <stdlib.h>

// defining characters that will make up calculator display characters
// including 11 -- 10 for characters 0-9 and one to represent the minus symbol
const char segments[11][3][3] = {
    {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}},
    {{' ', ' ', ' '}, {' ', '|', ' '}, {' ', '|', ' '}},
    {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},
    {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
    {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},
    {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
    {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},
    {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},
    {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}},
    {{' ', ' ', ' '}, {' ', '-', ' '}, {' ', ' ', ' '}},
};

// function to display a digit in the console
void display_digit(int digit, int row) {
    for (int col = 0; col < 3; col++) {
        printf("%c", segments[digit][row][col]);
    }
    // adding a space to separate the next part of the next digit
    printf("  ");
}

int main() {
    // defining a variable to log user's choice of continuing
    char choice;
    // initializing a variable to represent if the given input is negative or not
    int negative = 0;

    do {
        // represents the input number that the user gives
        int input;
        // scanning the integer
        printf("Enter an integer: ");
        scanf("%d", &input);

        // logging the integer as negative if it is negative
        if (input < 0) {
            negative = 1;
            input = -input;
        } else {
            negative = 0;
        }
        
        // represents the number being displayed
        int n = input;
        // represents the digit count of the number being displayed
        int c = 0;
        // an array of digits that indicate what digit each input number is
        int arr[10];

        // splitting the input number into individual digits in the array
        while (n > 0) {
            arr[c] = n % 10;
            n = n / 10;
            // updating the digit count
            c++;
        }

        // displaying 0 if the input number is 0
        if (c == 0) {
            arr[c] = 0;
            c++;
        }

        // looping through each digit 3 times to print them in the calculator display 3 rows 
        for (int row = 0; row < 3; row++) {
            // printing negative symbol if applicable first
            if (negative == 1) {
                display_digit(10, row);
            }

            // using display digits function to print all digits in the array
            for (int i = c - 1; i >= 0; i--) {
                display_digit(arr[i], row);
            }
            // printing new line to separate rows
            printf("\n");
        }

        // asking users to continue and logging their choice to inform if the loop will continue
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);
    } while (choice == 'Y' || choice == 'y');

    return 0;
}
