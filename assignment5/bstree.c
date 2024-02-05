// CS2211a 2023, Section 1
// Assignment 5
// Maya Lekhi
// 251280006
// mlekhi
// Dec 4, 2023

#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

// create a bstree
BStree bstree_ini(void) {
    // allocating memory for a new tree of type BStree_node
    BStree tree = (BStree)malloc(sizeof(BStree_node *));
    // setting the tree to point to a null value
    *tree = NULL;
    // returning pointer
    return tree;
}

// helper function to create a new node
BStree_node *new_node(Key key, Data data) {
    // allocating memory for a new node of type BStree_node
    BStree_node *new_node = (BStree_node *)malloc(sizeof(BStree_node));

    // checking that memory has been allocated properly
    if (new_node == NULL) {
        printf("Error! Memory not allocated correctly");
        // exiting the program
        exit(EXIT_FAILURE);
    }

    // setting the new node's key & data to the given key & data
    new_node->key = key;
    new_node->data = data;
    // pointing the left and right children to null
    new_node->left = NULL;
    new_node->right = NULL;
    // returning new node
    return new_node;
}

// helper function for recursive insertion in tree
void insert_helper(BStree_node **c, Key key, Data data) {
    // inserting node into tree if spot is empty
    if (*c == NULL) {
        // creating a new node in that position with the inputted information 
        *c = new_node(key, data);
        return;
    }

    // going to left subtree if key comparison is less than current
    if (key_comp(key, (*c)->key) < 0) {
        return insert_helper(&((*c)->left), key, data);
    // going to right subtree if key comparison is more than current
    } else if (key_comp(key, (*c)->key) > 0) {
        return insert_helper(&((*c)->right), key, data);
    // returning if key is in tree / if comparison matches
    } else {
        return;
    }
}

// inserting data with key into bstree
void bstree_insert(BStree bst, Key key, Data data) {
    // calling helper function
    insert_helper(bst, key, data);
}

// helper function for recursive searching of tree
Data search_helper(BStree_node *c, Key key) {
    // returning null if the node is null
    if (c == NULL) {
        return NULL;
    }

    // going to left subtree if key comparison is less than current
    if (key_comp(key, c->key) < 0) {
        return search_helper(c->left, key);
    // going to right subtree if key comparison is more than current
    } else if (key_comp(key, c->key) > 0) {
        return search_helper(c->right, key);
    // returning the current node if the key is found / if comparison matches
    } else {
        return c->data;
    }
}

// searching through the binary search tree for key
Data bstree_search(BStree bst, Key key) {
    // calling helper function
    return search_helper(*bst, key);
}

// helper function for recursive traversal of tree
void traverse_helper(BStree_node *c) {
    // cycling inorder through the tree until it reaches a null node
    if (c != NULL) {
        // calling traverse on left subtree first
        traverse_helper(c->left);

        // printing current node info
        printf("%d\t%s", c->key->key2, c->key->key1);
        printf("\t\t\t\t");
        data_print(c->data);
        printf("\n");

        // calling traverse on right subtree last
        traverse_helper(c->right);
    }
}

// in order traversal; printing each node
void bstree_traverse(BStree bst) {
    // calling helper function
    traverse_helper(*bst);
}

// helper function to recursively free the tree nodes
void free_helper(BStree_node *c) {
    // cycling through the tree until null node is reached
    if (c != NULL) {
        // freeing the current node's key & data
        key_free(c->key);
        data_free(c->data);
        // running helper to free the left and right subtree
        free_helper(c->left);
        free_helper(c->right);
        // running helper to check that c is now null
    }
}

// freeing all dynamically allocated memory of bst
void bstree_free(BStree bst) {
    // checking if tree has content
    if (bst != NULL && *bst != NULL) {
        // running helper function
        free_helper(*bst);
        free(*bst);
    }
    // freeing entire tree
    free(bst);
}
