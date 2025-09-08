#include <stdio.h>
//print array
void printArray(int arr[], int size){
    printf("Printing the array: \n");
    
    for (int i = 0; i < size; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for (int i = 1; i <= size; i++){
        printf("________");
    }
    printf("\n");
}
// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
// Partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}
// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);  // Sort left part
        quickSort(arr, pi + 1, high); // Sort right part
    }
}
//insertion sort algo
void insertSort(int arr[], int size){
    for(int i = 1; i < size; i++){
        int temp = arr[i];
        int j = i;
        while(j > 0 && arr[j - 1] > temp){
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = temp;
    }
}
//selection sort algo
void selectSort(int arr[], int size){
    for (int i = 0; i < size-1; i++){
        int temp = i, var;
        for (int j = i+1; j < size; j++){
            if (arr[j] < arr[temp]){
                temp = j;
            }
        }
        var = arr[i];
        arr[i] = arr[temp];
        arr[temp] = var;
    }
}

int main(){
    int arr[] = {13, 26, 9, 5, 11, 3};
    int size = sizeof(arr)/sizeof(int);
    printf("Original Array: \n");
    printArray(arr, size);
    printf("Sorted Array: \n");
    quickSort(arr, 0, size-1);
    printArray(arr, size);

    return 0;
}
