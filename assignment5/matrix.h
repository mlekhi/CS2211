// CS2211a 2023, Section 1
// Assignment 5
// Maya Lekhi
// 251280006
// mlekhi
// Dec 4, 2023

#ifndef matrix_H
#define matrix_H
#include "bstree.h"

// type definitions
typedef BStree Matrix;
typedef Key1 Index1;
typedef Key2 Index2;
typedef float Value;

// function prototypes
Matrix matrix_construction(void);
unsigned char matrix_index_in(Matrix m, Index1 index1, Index2 index2);
const Value *matrix_get(Matrix m, Index1 index1, Index2 index2);
void matrix_set(Matrix m, Index1 index1, Index2 index2, Value value);
void matrix_list(Matrix m);
void matrix_destruction(Matrix m);

#endif
