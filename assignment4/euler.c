// CS2211a 2023, Section 1
// Assignment 4
// Maya Lekhi
// 251280006
// mlekhi
// Nov 14, 2023

#include <stdio.h>

// helper function i made to calculate factorials
int factorial(int n) {

    // returning 1 if they are trying to compute the factorial of 0 or 1
    if (n == 0 || n == 1) {
        return 1;

    // computing the factorial for integers larger than 1 (non base case)
    } else {
        // setting factorial value to 1; 1 is the lowest possible factorial
        int factorial = 1;

        // looping up until n 
        // starting at 2 to account for n being 0 and 1 cases being handled
        for (int i = 2; i <= n; i++) {
            // multiplying by i with the existing value to calculate the factorial
            factorial *= i;
        }

        return factorial;
    }
}

// function to calculate euler's number based on num
double euler(double smallNum) {

    // setting the variables needed to approximate/calculate euler's number
    double e = 1.0;
    double curTerm = 1.0;
    int n = 0;

    // iterating until 1/n! >= smallNum condition is met
    while (smallNum <= curTerm) {
        // incrementing n up to increase the denominator value in the calculations
        n++;
        // calculating the current term
        curTerm = 1.0 / factorial(n);
        // adding it to the sum of the previous terms for euler's approx
        e += curTerm;
    }

    return e;
}

// main function
int main() {

    // initializing and recieving input for our small number
    double smallNum;
    printf("enter small number that will be used to approximate the constant: ");
    scanf("%lf", &smallNum);

    // validating if the number entered is not negative
    if (smallNum <= 0) {
        printf("input must be a positive small number!\n");
    } else {
        // running the valid input through the euler function 
        double eulersApprox = euler(smallNum);
        // printing the resulting approximation
        printf("euler's number approximation: %lf", eulersApprox);
    }

    return 0;
}
