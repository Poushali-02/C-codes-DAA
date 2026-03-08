#include <iostream>
using namespace std;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(int arr[], int size){
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        swap(start, end);
        start++;
        end--;
    }
}
int main(){
    int size;
    cout << "Enter array size: ";
    cin >> size;
    
    int *arr = new int[size];

    cout << "Enter array elements ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    reverse(arr, size);

    cout << "After reversing array is ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}