// CS2211a 2023, Section 1
// Assignment 4
// Maya Lekhi
// 251280006
// mlekhi
// Nov 14, 2023

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// recursive helper function for tree node insertion
static void bst_insert_helper(Node *tree_nodes, unsigned char *is_free, int index, Key key, int data) {
    // checking if current node is full
    if (is_free[index]) {
        // marking as full
        is_free[index] = 0; 
        
        // filling tree key and data based on parameters/input
        tree_nodes[index].key = key;
        tree_nodes[index].data = data;
    } else {
        // comparing key with key at the current index that is full
        int compare = key_comp(key, tree_nodes[index].key);

        // based on comparison results, inserting on the left subtree
        if (compare < 0) {
            bst_insert_helper(tree_nodes, is_free, 2 * index, key, data);

        // based on comparison results, inserting on the right subtree
        } else if (compare > 0) {
            bst_insert_helper(tree_nodes, is_free, 2 * index + 1, key, data);
        }
    }
}

BStree bstree_ini(int size) {
    // allocate memory for a Node array of size+1 for member tree_nodes
    BStree newBst;
    newBst.tree_nodes = (Node *)malloc((size + 1) * sizeof(Node));
    newBst.is_free = (unsigned char *)malloc((size + 1) * sizeof(unsigned char));
    
    // set member size to ’size’
    newBst.size = size;
    
    // looping through the new bstree
    for (int i = 0; i <= size; i++) {
        newBst.is_free[i] = 1;
    }
    return newBst;
}

// function to insert a node into a binary tree 
void bstree_insert(BStree bst, Key key, int data) {
    // using a helper function I made passing on the original parameters of the function 
    bst_insert_helper(bst.tree_nodes, bst.is_free, 1, key, data);
}

// recursive helper function for tree traversal + printing
void bstree_traversal_helper(Node *tree_nodes, int index) {
    // checking if the current node isn't null/leaf
    if (tree_nodes[index].key.name != NULL) {
        // traversing left subtree
        bstree_traversal_helper(tree_nodes, 2 * index);

        // printing node information
        print_node(tree_nodes[index]);

        // traversing right subtree
        bstree_traversal_helper(tree_nodes, 2 * index + 1);
    }
}

// function to print a traversal of a given bst
void bstree_traversal(BStree bst) {
    // using a helper function I made passing on the original parameters of the function 
    bstree_traversal_helper(bst.tree_nodes, 1);
}

// function to free up memory allocated for the bst
void bstree_free(BStree bst) {
    // using free function to free up the array and the indicators for if something is full
    free(bst.tree_nodes);
    free(bst.is_free);
}
