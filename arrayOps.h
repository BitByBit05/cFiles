// my_array_utils.h
#ifndef MY_ARRAY_UTILS_H
#define MY_ARRAY_UTILS_H

#include <stdlib.h> // For size_t, which is commonly used for sizes

// Function to create an array of a given size dynamically
int* createArray(int size);

// Function to print the elements of an array
void printArray(int* arr, int size);

// Function to calculate the size of a dynamically allocated array
// IMPORTANT: This function only works for dynamically allocated arrays
//             where the size was stored separately.  C DOES NOT store the
//             size of an array with the array data itself.
int getArraySize(int* arr, int size);

#endif // MY_ARRAY_UTILS_H

