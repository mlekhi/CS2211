// CS2211a 2023, Section 1
// Assignment 5
// Maya Lekhi
// 251280006
// mlekhi
// Dec 4, 2023

#ifndef datatype_H
#define datatype_H

// type definitions
typedef float* Data;
typedef char* Key1;
typedef int Key2;
typedef struct {Key1 key1; Key2 key2;} Key_struct;
typedef Key_struct* Key;

// function prototypes for data
Data data_ini();
void data_set(Data data, float intdata);
void data_print(Data data);
void data_free(Data data);

// function prototypes for key
Key key_ini();
void key_set(Key key, Key1 key1, Key2 key2);
int key_comp(Key key1, Key key2);
void key_print1(Key key);
void key_print2(Key key);
void key_free(Key key);

#endif