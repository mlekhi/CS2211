// CS2211a 2023, Section 1
// Assignment 4
// Maya Lekhi
// 251280006
// mlekhi
// Nov 14, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bst.h"

int main() {
    // declaring a variable to hold the size of the array
    int arr_size;

    // collecting input for the tree node array size
    printf("size of the tree: ");
    scanf("%d", &arr_size);

    // initializing a bst with the given size
    BStree newBst = bstree_ini(arr_size);

    // declaring variables to read the inputted number, string, data
    int number;
    char str[150];
    int data;

    // declaring a variable to read the result of the scanf functions to detect when to break the loop
    int result;

    // loop to read inputted bst node data and insert it into the tree
    for (int i = 0; i < arr_size; i++) {
        
        // scanning the given number for the key
        result = scanf("%d ", &number);
        // checking for if the end of the file was reached or if the input was not valid
        if (result == EOF || result == 0) {
            break;
        }

        // reading the given string on the same line for the key
        fgets(str, sizeof(str), stdin);
        // replacing the new line character in the string with the null character to indicate its completion
        str[strcspn(str, "\n")] = '\0';

        // scanning the given number for the node data
        result = scanf("%d", &data);
        if (result == EOF || result == 0) {
            break;
        }

        // inserting the node information into the bst (and constructing a key in the process)
        bstree_insert(newBst, key_construct(str, number), data);
    }

    // showing the tree traversal and freeing up the memory
    bstree_traversal(newBst);
    bstree_free(newBst);

    return 0;
}
