#include <stdio.h>
#include <stdlib.h>

// swap function
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// partition function
int partition(int arr[], int low, int high){
    // pivot element - arr[high]
    int pivot = arr[high];

    int i = low - 1;

    for(int j = low; j <= high - 1; j++){
        if (arr[j] < pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i+1], &arr[high]);
    return i+1;
}

// quick sort function
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// print array function
void printArray(int arr[], int size){
    for (int i=0; i<size; i++)
        printf("%d ", arr[i]);
}

// take array function
void takeArray(int arr[], int size){
    printf("Enter values: ");
    for (int i=0; i<size; i++)
        scanf("%d", &arr[i]);
}

int main() {
    int size;
    printf("Enter size: ");
    scanf("%d", &size);

    int *arr = malloc(size * sizeof(*arr));

    takeArray(arr, size);

    printf("Before sorting\n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);
    
    printf("\nAfter sorting\n");
    printArray(arr, size);
    
    free(arr);
    return 0;
}