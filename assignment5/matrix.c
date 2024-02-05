// CS2211a 2023, Section 1
// Assignment 5
// Maya Lekhi
// 251280006
// mlekhi
// Dec 4, 2023

#include <stdio.h>
#include "matrix.h"

// using bstree_ini to construct a matrix
Matrix matrix_construction(void) {
    BStree matrix = bstree_ini();
    return matrix;
}

// finding index of location in matrix
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2) {
    // creating a key based on the given parameters
    Key search = key_ini();
    // setting the key to the index we want to search at
    key_set(search, index1, index2);

    // searching for the specified key and freeing the key + returning indicator based on search results
    if (bstree_search(m, search) != NULL) {
        key_free(search);
        return 1;
    } else {
        key_free(search);
        return 0;
    }
}

// returning pointer to associated value based on given location
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2) {
    // creating a key based on the given parameters
    Key get = key_ini();
    // setting the key to the index we want to search at
    key_set(get, index1, index2);

    // getting pointer value by using bstree search function
    Data pointer = bstree_search(m, get);
    // freeing key
    key_free(get);

    return pointer;
}

// assigning value Matrix m at location (index1, index2)
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value) {
    // creating a key based on the given parameters
    Key set = key_ini();
    // setting the key to the index we want to search at
    key_set(set, index1, index2);

    // initializing & setting a data based on given parameters
    Data data = data_ini();
    data_set(data, value);

    // checking if the location is defined
    Data existing_data = bstree_search(m, set);
    
    if (existing_data == NULL) {
        bstree_insert(m, set, data);
    } else {
        // overwriting value if the location already has a value
        data_set(existing_data, value);
    }
}

// printing indices and values in the Matrix m
void matrix_list(Matrix m) {
    // using bstree traverse function
    bstree_traverse(m);
}

// freeing allocated space of the entire matrix
void matrix_destruction(Matrix m) {
    // using bstree helper function
    bstree_free(m);
}
