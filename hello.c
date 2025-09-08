#include <stdio.h>
#include <stdlib.h>
#include "arrayOps.h" // Include the custom header file

int main() {
    int size;

    printf("Enter the size of the array: ");
    if (scanf("%d", &size) != 1) {
        printf("Invalid input for array size. Exiting.\n");
        return 1; // Exit with an error code
    }

    int* myArray = createArray(size); // Create the array using the function from the header

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

    printArray(myArray, size); // Print the array using the function from the header

    int arraySize = getArraySize(myArray, size); // Get the array size using the function from the header
    printf("Size of the array: %d\n", arraySize);

    free(myArray); // Free the dynamically allocated memory when you're done with it!
    myArray = NULL;

    return 0; // Exit successfully
}
