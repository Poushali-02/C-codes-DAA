#include <iostream>
using namespace std;

void decimalToBinary(int number){
    int binary [32] = {0};
    // 0 0 0 0 0  ... 
    int index = 0;
    while (number > 0){
        binary[index++] = number % 2;
        number /= 2;
    }
    for (int i = index - 1; i >= 0; i--) {
        cout << binary[i] << " ";
    }
    return;
}
int main(){
    int number;
    cout << "Enter number : ";
    cin >> number;
    decimalToBinary(number);
    return 0;
}