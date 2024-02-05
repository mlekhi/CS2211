// CS2211a 2023, Section 1
// Assignment 5
// Maya Lekhi
// 251280006
// mlekhi
// Dec 4, 2023

#ifndef bstree_H
#define bstree_H
#include "datatype.h"

// type definitions
typedef struct BStree_node {
    Key key;
    Data data;
    struct BStree_node *left, *right;
} BStree_node;
typedef BStree_node **BStree;

// function prototypes
BStree bstree_ini(void);
void bstree_insert(BStree bst, Key key, Data data);
Data bstree_search(BStree bst, Key key);
void bstree_traverse(BStree bst);
void bstree_free(BStree bst);

#endif
