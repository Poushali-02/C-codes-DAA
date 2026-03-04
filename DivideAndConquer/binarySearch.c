#include <stdio.h>

// binary search function
int binarySearch(int arr[], int left, int right, int target){
    if (left > right) {
        return -1;
    }

    int mid = left + (right - left) / 2; 

    if (arr[mid] == target){
        return mid;
    }

    else if (arr[mid] > target){
        return binarySearch(arr, left, mid - 1, target);
    }

    else {
        return binarySearch(arr, mid + 1, right, target);
    }
}

int main() {
    int arr[] = {3, 5, 8, 9, 12, 15, 20};
    int size = sizeof(arr) / sizeof(arr[0]);

    int target;
    printf("Enter target: ");
    scanf("%d", &target);

    int searched = binarySearch(arr, 0, size - 1, target);

    if (searched == -1){
        printf("Target not in array");
    }
    else {
        printf("Target found at index %d", searched + 1);
    }
    
    return 0;
}