#include <stdio.h>
#include <stdlib.h>

// function to get the next operator of the expression
char get_op(void) {
    char next_op;

    while (1) {
        // read next character in input
        next_op = getchar();
        // continuing past spaces and tabs
        if (next_op == ' ' || next_op == '\t') {
            continue;
        // retuning the next operator should there be a plus, minus, or new line upcoming
        } else if (next_op == '+' || next_op == '-' || next_op == '\n') {
            return next_op;
        // exiting the program if the operator is invalid
        } else {
            printf("Invalid operator\n");
            exit(EXIT_FAILURE);
        }
    }
}

//  get the next numeric value of the expression
float get_num(void) {
    // scanning the next number, skipping over spaces until next number
    float next_num;
    scanf("%f", &next_num);
    // returning next number
    return next_num;
}

// value of the current sub simple arithmetic expression
float sub_sim_exp(float sub_exp) {
    // getting the next operator to signal what the upcoming calculation is
    char next_op = get_op();
    // retuning the result if a new line is encountered
    if (next_op == '\n') {
        return sub_exp;
    // if the operator is a plus, recursively processing the addition
    } else if (next_op == '+') {
        float next_num = get_num();
        return sub_sim_exp(sub_exp + next_num);
    // if the operator is a minus, recursively processing the subtraction
    } else if (next_op == '-') {
        float next_num = get_num();
        return sub_sim_exp(sub_exp - next_num);
    // exiting the program if the entered operator is invalid
    } else {
        printf("Invalid operator\n");
        exit(EXIT_FAILURE);
    }
}

// the simple arithmetic expression is evaluated using a recursive function call
float sim_exp(void) {
    float num = get_num();
    return sub_sim_exp(num);
}

int main() {
    // initializing a variable to log user's choice of continuing
    char choice;

    do {
        // getting users to enter their expression
        printf("Enter an arithmetic expression: ");
        // evaluate the expression and print the result
        float result = sim_exp();
        printf("Result: %f\n", result);

        // asking users to continue and logging their choice to inform if the loop will continue
        printf("Do you want to continue? (Y/N): ");
        scanf(" %c", &choice);

    } while (choice == 'Y' || choice == 'y');

    return 0;
}