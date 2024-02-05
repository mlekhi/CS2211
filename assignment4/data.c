// CS2211a 2023, Section 1
// Assignment 4
// Maya Lekhi
// 251280006
// mlekhi
// Nov 14, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// function to create a new key based on the inputted information
Key key_construct(char *in_name, int in_num) {
    // creating a new key to be outputted
    Key new_key;

    // set Key’s num to be in_num 
    new_key.num = in_num;

    // allocating memory for the new key 
    new_key.name = (char *)malloc(strlen(in_name) + 1);
    // copy in_name to Key’s name
    strcpy(new_key.name, in_name);

    return new_key;
}

// function to compare two given keys
int key_comp(Key key1, Key key2) {
    // checking if the comparison between the two keys are
    if (strcmp(key1.name, key2.name) == 0) {
        // if the keys have same name, then returning the comparison between key1.num and key2.num
        return key1.num - key2.num;
    
    // returning value indicating comparison between key1 & key2's names if their names don't match
    } else {
        return strcmp(key1.name, key2.name);
    }
}

// function to print the formatted information of a specified key
void print_key(Key key) {
    // prints the key number and key name
    printf("%d %s ", key.num, key.name);
}

// function to print a given node's formatted information
void print_node(Node node) {
    // using the print key function to print the informatino of the key stored in the node
    print_key(node.key);
    
    // printing the node data of the given node
    printf("%d\n", node.data);
}
