#include <stdio.h>
#include <stdlib.h> // For dynamic memory allocation (malloc, free)

// Function to create an array of a given size dynamically
int* createArray(int size) {
    if (size <= 0) {
        printf("Array size must be positive. Returning NULL.\n");
        return NULL; // Return NULL to indicate an error
    }

    // Use malloc to allocate memory on the heap
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed. Returning NULL.\n");
        return NULL; // Handle allocation failure
    }

    // Initialize the array elements (optional, but good practice)
    for (int i = 0; i < size; i++) {
        arr[i] = 0; // Initialize all elements to 0
        // Or you could initialize them with some other value, e.g.,
        // arr[i] = i + 1;
    }
    return arr;
}

// Function to print the elements of an array
void printArray(int* arr, int size) {
    if (arr == NULL) {
        printf("Array is NULL. Cannot print.\n");
        return;
    }
    if (size <= 0)
    {
        printf("Array Size is invalid\n");
        return;
    }

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to calculate the size of a dynamically allocated array
// IMPORTANT: This function only works for dynamically allocated arrays
//             where the size was stored separately.  C DOES NOT store the
//             size of an array with the array data itself.
int getArraySize(int* arr, int size) {
    if (arr == NULL) {
        return 0; // Or some other error value, like -1
    }
    return size;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input for array size. Exiting.\n");
        return 1; // Exit with an error code
    }

    int* myArray = createArray(size); // Create the array

    if (myArray == NULL) {
        return 1; // Exit if array creation failed
    }

    // At this point, myArray is a valid pointer to an array of size 'size'

    // Fill the array with some data
    for (int i = 0; i < size; i++) {
        printf("Enter element %d: ", i);
        if (scanf("%d", &myArray[i]) != 1)
        {
            printf("Invalid input\n");
            free(myArray);
            return 1;
        }
    }
    printArray(myArray, size);     // Print the array

    int arraySize = getArraySize(myArray, size); // Get the array size
    printf("Size of the array: %d\n", arraySize);

    free(myArray); // Free the dynamically allocated memory when you're done with it!
    myArray = NULL; //set the pointer to NULL after freeing.

    return 0; // Exit successfully
}

