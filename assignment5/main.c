// CS2211a 2023, Section 1
// Assignment 5
// Maya Lekhi
// 251280006
// mlekhi
// Dec 4, 2023

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "matrix.h"

// helper function to delete whitespace after string and add null char at the end
void endWhiteSpace(char *str) {
    // getting length of string
    int end = strlen(str) - 1;

    // going through the string backwards to delete all whitespace
    while (end >= 0 && isspace((unsigned char)str[end])) {
        // decrementing end
        end--;
    }

    // adding null terminator @ end
    str[end + 1] = '\0';
}

int main() {
    // making a matrix
    Matrix matrix = matrix_construction();

    // declaring string and integer to store index variables
    char string[150];
    int integer;
    int result;

    // creating a while loop to continue adding to the tree unless the input does not start with an integer
    while ((result = scanf("%d ", &integer)) == 1) {    
        // checking for end of file
        if (result == EOF || result == 0) {
            break;
        }

        // reading string and adding null character at the end
        fgets(string, sizeof(string), stdin);
        // running it through helper function
        endWhiteSpace(string);
    
        // making index values to feed into the function
        Index1 index1 = (Index1)string;
        Index2 index2 = (Index2)integer;

        // checking if the index locations aren't in the matrix
        if (matrix_index_in(matrix, index1, index2) != 1) {
            // setting a new node
            matrix_set(matrix, index1, index2, 1);
        } else {
            // incrementing count if there are duplicates of the indexes 
            const Value *count = matrix_get(matrix, index1, index2);
            // checking that count has been initialized before adding and setting a new node
            if (count != NULL) {
                matrix_set(matrix, index1, index2, *count + 1);
            }
        }
    }

    // print data
    printf("Number\tStreet\t\t\tOccurence\n");
    matrix_list(matrix);

    // freeing memory   
    matrix_destruction(matrix);

    return 0;
}