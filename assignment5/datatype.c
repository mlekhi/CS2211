// CS2211a 2023, Section 1
// Assignment 5
// Maya Lekhi
// 251280006
// mlekhi
// Dec 4, 2023

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"

// create a data
Data data_ini() {
    // initializing a data with dynamic memory allocation
    Data data = (Data)malloc(sizeof(float));

    return data;
}

// assign value of data with intdata
void data_set(Data data, float intdata) {
    // setting value with data pointer
    *data = intdata;
}

// print a data
void data_print(Data data) {
    printf("%d", (int)*data);
}

// free memory allocated for data
void data_free(Data data) {
    free(data);
}

// create a key
Key key_ini() {
    // initializing a key dynamic memory allocation
    Key key = (Key)malloc(sizeof(Key_struct));

    // setting key1 & key2 to null
    key->key1 = NULL;
    key->key2 = 0;

    // returning initialized key
    return key;
}

// set key
void key_set(Key key, Key1 key1, Key2 key2) {
    // setting key1 to characters from input; duplicating to avoid pointer issues
    key->key1 = strdup(key1);
    // setting key2 to int from input
    key->key2 = key2;
}

// comparing the key values
int key_comp(Key key1, Key key2) {
        // comparing their first keys if they aren't equal
    if (strcmp(key1->key1, key2->key1) != 0) {
        // returning the value of their first key comparison
        return strcmp(key1->key1, key2->key1);
    // checking if their second keys are equal
    } else if (key1->key2 != key2->key2) {
        // returning the value of their second key comparison
        return key1->key2 - key2->key2;
    }
    // returning 0 if they are equal
    return 0;
}

// print first key then second key
void key_print1(Key key) {
    printf("%s %d", key->key1, key->key2);
}

// print second key then first key
void key_print2(Key key) {
    printf("%d %s", key->key2, key->key1);
}

// freeing memory allocated for key
void key_free(Key key) {
    free(key->key1);
    free(key);
}